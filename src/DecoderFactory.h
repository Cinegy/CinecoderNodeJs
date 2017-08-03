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

#ifndef DECODERFACTORY_H
#define DECODERFACTORY_H

#include <memory>
#include "EssenceInfo.h"
#if defined _WIN32
  #include "DecoderCinegy.h"
#elif defined _LINUX
#endif

namespace streampunk {

class DecoderFactory {
public:
  static std::shared_ptr<iDecoderDriver> createDecoder(std::shared_ptr<EssenceInfo> srcInfo, std::shared_ptr<EssenceInfo> dstInfo) {
    if (0 == srcInfo->encodingName().substr(0, 4).compare("AVCi")) {
      #if defined _WIN32
        return std::make_shared<DecoderCinegy>(srcInfo, dstInfo);
      #else
        throw std::runtime_error("No implementation of AVCi decoder available");
      #endif
    }
    else {
      std::string err = std::string("No implementation of \'") + srcInfo->encodingName() + "\' decoder available";
      throw std::runtime_error(err.c_str());
    }
  }
};

} // namespace streampunk

#endif
