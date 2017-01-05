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
#include "DecoderCinegy.h"
#include "CodecCinegy.h"
#include "Memory.h"
#include "EssenceInfo.h"

#include "../cinegy/include/cinecoder_h.h"

namespace streampunk {

#define TESTCOND(cond,hr) ATLASSERT(cond); if(!(cond)) return (hr)

class C_DecoderErrorHandler : public ICC_ErrorHandler {
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
    printf("Cinecoder decoder error %08xh (%s) at %s(%d): %s\n", ErrCode, Cinecoder_GetErrorString(ErrCode), pFileName, LineNo, ErrDescription);
    return ErrCode;
  }
};
C_DecoderErrorHandler DecodeErrorHandler;

class DecodeCallback : public ICC_DataReadyCallback {
public:
  DecodeCallback() : mFirstFrame(true) {}
  virtual ~DecodeCallback() {}

  void setDecodeBuffer(std::shared_ptr<Memory> buf)  { mDecodeBuffer = buf; }

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

    DWORD dwBytesWrote = 0;
    if(FAILED(hr = spProducer->GetFrame(CCF_UYVY_10BIT, mDecodeBuffer->buf(), mDecodeBuffer->numBytes(), szFrame.cx*4, &dwBytesWrote)))
      return hr;

    return S_OK;
  }

private:
  bool mFirstFrame;
  std::shared_ptr<Memory> mDecodeBuffer;
};


DecoderCinegy::DecoderCinegy(std::shared_ptr<EssenceInfo> srcInfo, std::shared_ptr<EssenceInfo> dstInfo)
  : mSrcEncoding(srcInfo->encodingName()), mDstPacking(dstInfo->packing()), mWidth(srcInfo->width()), mHeight(srcInfo->height()), 
    mFps(25), mSrcFrameSize(0), mDecodeCb(NULL) {

  CC_VERSION_INFO version = Cinecoder_GetVersion();
  printf("Cinecoder.dll version %d.%02d.%02d\n\n", version.VersionHi, version.VersionLo, version.EditionNo);

  Cinecoder_SetErrorHandler(&DecodeErrorHandler);
    
	HRESULT hr = S_OK;

  CComPtr<ICC_ClassFactory> pFactory;
  if(FAILED(hr = Cinecoder_CreateClassFactory((ICC_ClassFactory**)&pFactory))) {
    Nan::ThrowError("Cinecoder decoder failed to create class factory");
    return;
  }

  pFactory->AssignLicense(COMPANYNAME, LICENSEKEY);

  if(FAILED(hr = pFactory->CreateInstance(CLSID_CC_H264VideoDecoder, IID_ICC_VideoDecoder, (IUnknown**)&mVideoDecoder))) {
    Nan::ThrowError("Cinecoder decoder failed to create h264 decoder");
    return;
  }

  mDecodeCb = new DecodeCallback();
  if(FAILED(hr = mVideoDecoder->put_OutputCallback(mDecodeCb))) {
    Nan::ThrowError("Cinecoder decoder failed to register decoder callback");
    return;
  }
}

DecoderCinegy::~DecoderCinegy() {}

uint32_t DecoderCinegy::bytesReq() const {
  return mWidth * 4 * 3 / 4 * mHeight; // Decoder doesn't support unsqueeze yet so 1920 -> 1440, 1280 -> 960  
}

void DecoderCinegy::decodeFrame (std::shared_ptr<Memory> srcBuf, std::shared_ptr<Memory> dstBuf, uint32_t frameNum, uint32_t *pDstBytes) {

  mDecodeCb->setDecodeBuffer(dstBuf);

  HRESULT hr = S_OK;
  DWORD dwBytesProcessed = 0;
  if(FAILED(hr = mVideoDecoder->ProcessData(srcBuf->buf(), (int)srcBuf->numBytes(), 0, -1, &dwBytesProcessed)))
    printf("Cinecoder decoder failed to process frame\n");
  mVideoDecoder->Break(CC_TRUE); // flush decoder frames immediately

  *pDstBytes = dstBuf->numBytes();  
}

} // namespace streampunk
