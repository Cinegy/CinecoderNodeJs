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

#ifndef DECODERCINEGY_H
#define DECODERCINEGY_H

#include <memory>

#include <atlbase.h>
#include "iCodecDriver.h"

interface ICC_VideoDecoder;

namespace streampunk {

class Memory;
class Duration;
class EssenceInfo;
class DecodeCallback;
class DecoderCinegy : public iDecoderDriver {
public:
  DecoderCinegy(std::shared_ptr<EssenceInfo> srcInfo, std::shared_ptr<EssenceInfo> dstInfo);
  ~DecoderCinegy();

  uint32_t bytesReq() const;
  void decodeFrame (std::shared_ptr<Memory> srcBuf, std::shared_ptr<Memory> dstBuf, uint32_t frameNum, uint32_t *pDstBytes);

private:
  std::string mSrcEncoding;
  std::string mDstPacking;
  const uint32_t mWidth;
  const uint32_t mHeight;
  uint32_t mFps;
  uint32_t mSrcFrameSize;
  CComPtr<ICC_VideoDecoder> mVideoDecoder;
  DecodeCallback *mDecodeCb;
};

} // namespace streampunk

#endif
