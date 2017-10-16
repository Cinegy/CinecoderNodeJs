/* Copyright 2017 Streampunk Media Ltd.

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

#ifndef ENCODEPARAMS_H
#define ENCODEPARAMS_H

#include <nan.h>
#include <sstream>
#include "Params.h"

using namespace v8;

namespace streampunk {

class EncodeParams : public Params {
public:
  EncodeParams(Local<Object> tags) {}
  ~EncodeParams() {}

  std::string toString() const  { 
    std::stringstream ss;
    ss << "Video encode ";
    return ss.str();
  }

private:
};

} // namespace streampunk

#endif
