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
#include "EncoderCinegy.h"
#include "CodecCinegy.h"
#include "Memory.h"
#include "EssenceInfo.h"
#include <map>
#include <mutex>
#include <condition_variable>

#include "../cinegy/include/cinecoder_h.h"

namespace streampunk {

#define TESTCOND(cond,hr) ATLASSERT(cond); if(!(cond)) return (hr)

class AVCiMode {
public:
  AVCiMode() {
    addMode("AVCi50", 1280,  720, 24, CC_AVCI_50_720P_2398);  addMode("AVCi100", 1280,  720, 24, CC_AVCI_100_720P_2398);
    addMode("AVCi50", 1280,  720, 25, CC_AVCI_50_720P_25);    addMode("AVCi100", 1280,  720, 25, CC_AVCI_100_720P_25);
    addMode("AVCi50", 1280,  720, 30, CC_AVCI_50_720P_2997);  addMode("AVCi100", 1280,  720, 30, CC_AVCI_100_720P_2997);
    addMode("AVCi50", 1280,  720, 50, CC_AVCI_50_720P_50);    addMode("AVCi100", 1280,  720, 50, CC_AVCI_100_720P_50);
    addMode("AVCi50", 1280,  720, 60, CC_AVCI_50_720P_5994);  addMode("AVCi100", 1280,  720, 60, CC_AVCI_100_720P_5994);

    addMode("AVCi50", 1920, 1080, 24, CC_AVCI_50_1080P_2398); addMode("AVCi100", 1920, 1080, 24, CC_AVCI_100_1080P_2398);
    addMode("AVCi50", 1920, 1080, 25, CC_AVCI_50_1080P_25);   addMode("AVCi100", 1920, 1080, 25, CC_AVCI_100_1080P_25);
    addMode("AVCi50", 1920, 1080, 30, CC_AVCI_50_1080P_2997); addMode("AVCi100", 1920, 1080, 30, CC_AVCI_100_1080P_2997);
    addMode("AVCi50", 1920, 1080, 50, CC_AVCI_50_1080I_50);   addMode("AVCi100", 1920, 1080, 50, CC_AVCI_100_1080I_50);
    addMode("AVCi50", 1920, 1080, 60, CC_AVCI_50_1080I_5994); addMode("AVCi100", 1920, 1080, 60, CC_AVCI_100_1080I_5994);

                                                              addMode("AVCi800", 3840, 2160, 24, CC_AVCI_4K_422_2398);
                                                              addMode("AVCi800", 3840, 2160, 25, CC_AVCI_4K_422_25);
                                                              addMode("AVCi800", 3840, 2160, 30, CC_AVCI_4K_422_2997);
                                                              addMode("AVCi800", 3840, 2160, 50, CC_AVCI_4K_422_50);
                                                              addMode("AVCi800", 3840, 2160, 60, CC_AVCI_4K_422_5994);
  }
  ~AVCiMode() {}

  CC_AVCI_MODE getMode(std::string cl, uint32_t x, uint32_t y, uint32_t fr) const {
    CC_AVCI_MODE result = CC_AVCI_MODE_UNKNOWN;
    std::map<uint32_t, uint32_t>::const_iterator it = mTable.find(makeHash(cl, x, y, fr));
    if (mTable.end() != it)
      result = (CC_AVCI_MODE)it->second;
    return result;
  }

private:
  std::map<uint32_t, uint32_t> mTable;

  uint32_t makeHash(std::string cl, uint32_t x, uint32_t y, uint32_t fr) const {
    uint32_t clInt = stoul(cl.substr(4, std::string::npos));
    return (clInt << 24) | (fr << 16) | (x * y / 128);
  }

  void addMode(std::string cl, uint32_t x, uint32_t y, uint32_t fr, uint32_t mode) {
    mTable.insert(std::make_pair(makeHash(cl, x, y, fr), mode));
  }
};

class EncoderErrorHandler : public ICC_ErrorHandler {
public:
  EncoderErrorHandler() : mErrStr("") {}
  virtual ~EncoderErrorHandler() {}

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
    // printf("Cinecoder encoder error %08xh (%s) at %s(%d): %s\n", ErrCode, Cinecoder_GetErrorString(ErrCode), pFileName, LineNo, ErrDescription);
    std::stringstream ss;
    ss << "Cinecoder encoder error " <<
      std::hex << ErrCode << "h" <<
      " (" << Cinecoder_GetErrorString(ErrCode) << ")" <<
      " at " << pFileName <<
      "(" << std::dec << LineNo << ")" <<
      ": " << ErrDescription << "\n";
    mErrStr = ss.str();
    return ErrCode;
  }

private:
  std::string mErrStr;
};

class EncodeCallback : public ICC_ByteStreamCallback {
public:
  EncodeCallback() : m(), cv() {}
  virtual ~EncodeCallback() {}

  std::shared_ptr<Memory> getResult() { 
    std::unique_lock<std::mutex> lk(m);
    while(!mEncodedBuf) {
      cv.wait(lk);
    }
    return mEncodedBuf; 
  }

  STDMETHOD(ProcessData)(const BYTE *pbData, DWORD cbSize, CC_TIME /*pts*/, IUnknown *pUnknown) {
    std::lock_guard<std::mutex> lk(m);
    mEncodedBuf = Memory::makeNew((uint8_t *)pbData, (uint32_t)cbSize);
    cv.notify_one();
    return S_OK;
  }

  // IUnknown implementation: AddRef, Release, QueryInterface 
  STDMETHOD_(ULONG, AddRef)(void) { return 2; } //C_StaticUnknown::AddRef();
  STDMETHOD_(ULONG, Release)(void) { return 1; } //C_StaticUnknown::Release();
  STDMETHOD(QueryInterface)(REFIID riid, void **ppv) {
    if (riid == IID_IUnknown || riid == IID_ICC_ByteStreamCallback)
      return GetInterface(static_cast<ICC_ByteStreamCallback*>(this), ppv);
    return E_NOINTERFACE;
  }

protected:
  HRESULT GetInterface(IUnknown *pUnk, void **ppv) {
    TESTCOND(ppv, E_POINTER);
    *ppv = pUnk; 
    pUnk->AddRef(); 
    return S_OK;
  }

private:
  mutable std::mutex m;
  std::condition_variable cv;
  std::shared_ptr<Memory> mEncodedBuf;
};


EncoderCinegy::EncoderCinegy(std::shared_ptr<EssenceInfo> srcInfo, std::shared_ptr<EssenceInfo> dstInfo, const Duration& duration)
  : mSrcPacking(srcInfo->packing()), mDstEncoding(dstInfo->encodingName()), mWidth(srcInfo->width()), mHeight(srcInfo->height()), 
    mFps(25), mSrcFrameSize(0), mVpar(NULL), mEncodeCb(NULL) { 

  if (!((mWidth == 3840) && (mHeight == 2160)) && 
      !((mWidth == 1920) && (mHeight == 1080)) &&
      !((mWidth == 1280) && (mHeight == 720))) {
    std::string err = std::string("Unsupported dimensions \'") + std::to_string(mWidth) + "x" + std::to_string(mHeight) + "\'";
    Nan::ThrowError(err.c_str());
    return; 
  }

  mFps = (duration.denominator() + duration.numerator() - 1) / duration.numerator(); // rounding up
  if (0 != srcInfo->interlace().compare("prog"))
    mFps *= 2;

  CC_VERSION_INFO version = Cinecoder_GetVersion();
  printf("Cinecoder.dll version %d.%02d.%02d\n\n", version.VersionHi, version.VersionLo, version.EditionNo);

  mErrorHandler = new EncoderErrorHandler;
  Cinecoder_SetErrorHandler(mErrorHandler);
    
	HRESULT hr = S_OK;

  CComPtr<ICC_ClassFactory> pFactory;
  if(FAILED(hr = Cinecoder_CreateClassFactory((ICC_ClassFactory**)&pFactory))) {
    Nan::ThrowError("Cinecoder encoder failed to create class factory");
    return;
  }

  pFactory->AssignLicense(COMPANYNAME, LICENSEKEY);
  
  if(FAILED(hr = pFactory->CreateInstance(CLSID_CC_AVCIntraEncoder, IID_ICC_AVCIntraEncoder, (IUnknown**)&mVideoEncoder))) {
    Nan::ThrowError("Cinecoder encoder failed to create AVCi encoder");
    return;
  }
    
  CComPtr<ICC_AVCIntraEncoderSettings> pVideoSettings;
  if(FAILED(hr = pFactory->CreateInstance(CLSID_CC_AVCIntraEncoderSettings, IID_ICC_AVCIntraEncoderSettings, (IUnknown**)&pVideoSettings))) {
    Nan::ThrowError("Cinecoder encoder failed to create AVCi encoder settings");
    return;
  }

  CC_AVCI_MODE mode = AVCiMode().getMode(mDstEncoding, mWidth, mHeight, mFps);
  pVideoSettings->put_Mode(mode);

  // initialize encoder with desired params
  if(FAILED(hr = mVideoEncoder->Init(pVideoSettings))) {
    Nan::ThrowError("Cinecoder encoder failed to initialise AVCi encoder settings");
    return;
  }

  CComPtr<ICC_VideoStreamInfo> pVideoDescr;
  if(FAILED(hr = mVideoEncoder->GetVideoStreamInfo(&pVideoDescr))) {
    Nan::ThrowError("Cinecoder encoder failed to get video stream info");
    return;
  }

	CC_SIZE frame_size;
	CC_RATIONAL frame_rate;
  pVideoDescr->get_FrameSize(&frame_size);
  pVideoDescr->get_FrameRate(&frame_rate);

  // we assume the full (non-anamorph) frame sizes at input
  if(frame_size.cx ==  960) frame_size.cx = 1280;
  if(frame_size.cx == 1440) frame_size.cx = 1920;

  CC_COLOR_FMT color_fmt = CCF_UYVY_10BIT;
  int bpp = 2 << int(color_fmt == CCF_YUY2_10BIT || color_fmt == CCF_UYVY_10BIT);
  int pitch = frame_size.cx * bpp;
  if (0 == mSrcPacking.compare("v210")) {
    color_fmt = CCF_V210;
    pitch = ((frame_size.cx + 47) / 48) * 48 * 8 / 3;
  }
  mSrcFrameSize = pitch * frame_size.cy;

  CC_ADD_VIDEO_FRAME_PARAMS *vpar = new CC_ADD_VIDEO_FRAME_PARAMS;
  vpar->cFormat = color_fmt;
  vpar->szFrame = frame_size;
  vpar->iStride = pitch;
  vpar->rcCrop = { 0, 0, 0, 0 };
  mVpar = vpar;

  // creating the sink for encoded data
  mEncodeCb = new EncodeCallback();
  if(FAILED(hr = mVideoEncoder->put_OutputCallback(static_cast<ICC_ByteStreamCallback*>(mEncodeCb)))) {
    Nan::ThrowError("Cinecoder encoder failed to register encoder callback");
    return;
  }
}

EncoderCinegy::~EncoderCinegy() {}

uint32_t EncoderCinegy::bytesReq() const {
  return 600000;  
}

std::string EncoderCinegy::packingRequired() const {
  return "UYVY10";
}

void EncoderCinegy::encodeFrame (std::shared_ptr<Memory> srcBuf, std::shared_ptr<Memory> dstBuf, uint32_t frameNum, uint32_t *pDstBytes, std::string &errStr) {
  *pDstBytes = 0;
  HRESULT hr = S_OK;
  //if(FAILED(hr = mVideoEncoder->AddFrame(mVpar->cFormat, srcBuf->buf(), mSrcFrameSize, 0, NULL)))
  if (FAILED(hr = mVideoEncoder->AddScaleFrame(srcBuf->buf(), mSrcFrameSize, (CC_ADD_VIDEO_FRAME_PARAMS*)mVpar))) {
    printf("Error calling AddScaleFrame against Cinecoder\n");
    errStr = mErrorHandler->readErrStr();
    return;
  }

  std::shared_ptr<Memory> encodedBuf = mEncodeCb->getResult();
  if (!encodedBuf) {
    printf("Cinecoder encoder failed to encode\n");
    errStr = mErrorHandler->readErrStr();
    return;
  }
  memcpy_s(dstBuf->buf(), dstBuf->numBytes(), encodedBuf->buf(), encodedBuf->numBytes());
  *pDstBytes = encodedBuf->numBytes();
}

} // namespace streampunk
