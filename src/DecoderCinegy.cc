/* Copyright 2016 Streampunk Media Ltd.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <nan.h>
#include <sstream>
#include "DecoderCinegy.h"
#include "CodecCinegy.h"
#include "Memory.h"
#include "EssenceInfo.h"
#include <mutex>
#include <condition_variable>

#include <cinecoder_h.h>

namespace streampunk {

#define TESTCOND(cond,hr) ATLASSERT(cond); if(!(cond)) return (hr)

class DecoderErrorHandler : public ICC_ErrorHandler {
public:
  DecoderErrorHandler() : mErrStr("") {}
  virtual ~DecoderErrorHandler() {}

  std::string readErrStr() { 
    std::string errStr(mErrStr);
    mErrStr.clear();
    return errStr; 
  }

  STDMETHOD(QueryInterface)(REFIID riid, void**p) {
    if (p == NULL)
      return E_POINTER;

    *p = NULL;
    if(riid != IID_ICC_ErrorHandler && riid != IID_IUnknown)
      return E_NOINTERFACE;

    *p = static_cast<ICC_ErrorHandler*>(this);
    return S_OK;
  }
  STDMETHOD_(ULONG,AddRef)() {
    return 2;
  }
  STDMETHOD_(ULONG,Release)() {
    return 1;
  }
  STDMETHOD(ErrorHandlerFunc)(HRESULT ErrCode, LPCSTR ErrDescription, LPCSTR pFileName, INT LineNo) {
    // printf("Cinecoder decoder error %08xh (%s) at %s(%d): %s\n", ErrCode, Cinecoder_GetErrorString(ErrCode), pFileName, LineNo, ErrDescription);
    std::stringstream ss;
    ss << "Cinecoder decoder error " <<
      std::hex << ErrCode << "h" <<
      " (" << Cinecoder_GetErrorString(ErrCode) << ")" <<
      " at " << pFileName <<
      "(" << std::dec << LineNo << ")" <<
      ": " << ErrDescription;
    mErrStr = ss.str();
    return ErrCode;
  }

private:
  std::string mErrStr;
};

class DecodeCallback : public ICC_DataReadyCallback {
public:
  DecodeCallback(std::shared_ptr<EssenceInfo> dstInfo)
    : m(), cv(), mDstInfo(dstInfo), mDecodeDone(false), mFirstFrame(true), mColorFmt(CCF_UYVY_10BIT) {
    if (0 == mDstInfo->packing().compare("v210"))
      mColorFmt = CCF_V210;
  }
  virtual ~DecodeCallback() {}

  void setDecodeBuffer(std::shared_ptr<Memory> buf)  { 
    mDecodeDone = false;
    mErrStr.clear();
    mDecodeBuffer = buf;
  }

  void waitResult(std::string &errStr) { 
    std::unique_lock<std::mutex> lk(m);
    while(!mDecodeDone) {
      cv.wait(lk);
    }
    errStr = mErrStr;
  }

  // IUnknown implementation: AddRef, Release, QueryInterface 
  STDMETHOD_(ULONG, AddRef)(void)   { return 2;  }
  STDMETHOD_(ULONG, Release)(void)  { return 1;  }
  STDMETHOD(QueryInterface)(REFIID riid, void **ppv) {
    if(ppv == NULL)
      return E_POINTER;

    *ppv = NULL;
    if (riid != IID_IUnknown && riid != IID_ICC_DataReadyCallback)
      return E_NOINTERFACE;

    *ppv = static_cast<ICC_DataReadyCallback*>(this);
    return S_OK;
  }

  STDMETHOD(DataReady)(IUnknown *pUnk) {
    HRESULT hr = S_OK;
    CComPtr<ICC_VideoProducer> spProducer;
    if(FAILED(hr = pUnk->QueryInterface(IID_ICC_VideoProducer, (void**)&spProducer)))
      return hr;

    CComPtr<ICC_VideoStreamInfo> spVideoInfo;
    if(FAILED(hr = spProducer->GetVideoStreamInfo(&spVideoInfo)))
      return hr;

    SIZE szFrame;
    if(spVideoInfo->get_FrameSize(&szFrame) != S_OK)
	    return E_UNEXPECTED;

    if(mFirstFrame) {
      printf("Decoder: frame size %dx%d, frame rate ", szFrame.cx, szFrame.cy);

	    CC_FRAME_RATE rFrameRate;
      if(S_OK == spVideoInfo->get_FrameRate(&rFrameRate))
        printf("%g\n", double(rFrameRate.num) / rFrameRate.denom);
      else
        printf("<unknown>\n");
      mFirstFrame = false;
    }

    CComPtr<ICC_VideoFrameInfo> spFrame;
    if(FAILED(hr = spProducer->GetVideoFrameInfo(&spFrame)))
      return hr;

    DWORD dwFrameNumber = 0;
    if(FAILED(hr = spFrame->get_Number(&dwFrameNumber)))
      return hr;

    int pitch = szFrame.cx*4;
    if (CCF_V210 == mColorFmt)
      pitch = ((szFrame.cx + 47) / 48) * 48 * 8 / 3;

    DWORD dwBytesWrote = 0;
    if(FAILED(hr = spProducer->GetFrame(mColorFmt, mDecodeBuffer->buf(), mDecodeBuffer->numBytes(), pitch, &dwBytesWrote))) {
      std::stringstream ss;
      ss << "Cinecoder decoder error " <<
        std::hex << hr << "h" <<
        " (" << Cinecoder_GetErrorString(hr) << ")";
      mErrStr = ss.str();
    }
    std::lock_guard<std::mutex> lk(m);
    mDecodeDone = true;
    cv.notify_one();

    return hr;
  }

private:
  mutable std::mutex m;
  std::condition_variable cv;
  std::shared_ptr<EssenceInfo> mDstInfo;
  bool mDecodeDone;
  bool mFirstFrame;
  CC_COLOR_FMT mColorFmt;
  std::string mErrStr;
  std::shared_ptr<Memory> mDecodeBuffer;
};


DecoderCinegy::DecoderCinegy(std::shared_ptr<EssenceInfo> srcInfo, std::shared_ptr<EssenceInfo> dstInfo)
  : mSrcEncoding(srcInfo->encodingName()), mDstPacking(dstInfo->packing()), mWidth(srcInfo->width()), mHeight(srcInfo->height()), 
    mFps(25), mSrcFrameSize(0), mDecodeCb(NULL) {

  CC_VERSION_INFO version = Cinecoder_GetVersion();
  printf("Cinecoder.dll version %d.%02d.%02d\n\n", version.VersionHi, version.VersionLo, version.EditionNo);

  mErrorHandler = new DecoderErrorHandler;
  Cinecoder_SetErrorHandler(mErrorHandler);
    
	HRESULT hr = S_OK;

  CComPtr<ICC_ClassFactory> pFactory;
  if(FAILED(hr = Cinecoder_CreateClassFactory((ICC_ClassFactory**)&pFactory))) {
    Nan::ThrowError("Cinecoder decoder failed to create class factory");
    return;
  }

  pFactory->AssignLicense(COMPANYNAME, LICENSEKEY);

  if(FAILED(hr = pFactory->CreateInstance(CLSID_CC_H264VideoDecoder, IID_ICC_VideoDecoder, (IUnknown**)&mVideoDecoder))) {
    std::stringstream ss;
    ss << "Cinecoder decoder failed to create h264 decoder:\n  " << mErrorHandler->readErrStr();
    Nan::ThrowError(ss.str().c_str());
    return;
  }

  mDecodeCb = new DecodeCallback(dstInfo);
  if(FAILED(hr = mVideoDecoder->put_OutputCallback(mDecodeCb))) {
    std::stringstream ss;
    ss << "Cinecoder decoder failed to register decoder callback:\n  " << mErrorHandler->readErrStr();
    Nan::ThrowError(ss.str().c_str());
    return;
  }
}

DecoderCinegy::~DecoderCinegy() {}

uint32_t DecoderCinegy::bytesReq() const {
  uint32_t pitch = mSrcEncoding.compare("AVCi50") ? mWidth * 4 : mWidth * 3; // Decoder doesn't support unsqueeze yet so 1920 -> 1440, 1280 -> 960 
  if (0 == mDstPacking.compare("v210"))
    pitch = ((mWidth + 47) / 48) * 48 * 8 / 3;
  return pitch * mHeight;
}

void DecoderCinegy::decodeFrame (std::shared_ptr<Memory> srcBuf, std::shared_ptr<Memory> dstBuf, uint32_t frameNum, uint32_t *pDstBytes, std::string &errStr) {
  *pDstBytes = 0;
  mDecodeCb->setDecodeBuffer(dstBuf);

  HRESULT hr = S_OK;
  DWORD dwBytesProcessed = 0;
  if(FAILED(hr = mVideoDecoder->ProcessData(srcBuf->buf(), (int)srcBuf->numBytes(), 0, -1, &dwBytesProcessed))) {
    printf("Cinecoder decoder failed to process frame\n");
    errStr = mErrorHandler->readErrStr();
    return;
  }
  mVideoDecoder->Break(CC_TRUE); // flush decoder frames immediately

  mDecodeCb->waitResult(errStr);
  *pDstBytes = dstBuf->numBytes();  
}

} // namespace streampunk
