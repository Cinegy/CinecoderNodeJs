# Copyright 2016 Streampunk Media Ltd.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

{
  "targets": [
    {
      "target_name": "cinecoder",
      "sources": [ "src/cinecoder.cc",
                   "src/Decoder.cc",
                   "src/Encoder.cc",
                   "src/DecoderCinegy.cc",
                   "src/EncoderCinegy.cc" ],
      "include_dirs": [ "<!(node -e \"require('nan')\")" ],
      'conditions': [
        ['OS=="linux"', {
          "cflags_cc!": [ 
            "-fno-rtti",
            "-fno-exceptions" 
          ],
          "cflags_cc": [
            "-std=c++11",
            "-fexceptions"
          ],
          "link_settings": {
            "libraries": [
            ],
            "ldflags": [
              "-L<@(module_root_dir)/build/Release",
              "-Wl,-rpath,<@(module_root_dir)/build/Release"
            ]
          },
          "copies": [
            {
              "destination": "build/Release/",
              "files": [
                # "cinegy/bin/cinecoder.so"
              ]
            }
          ] 
        }],
        ['OS=="win"', {
          "variables": {
            "CinecoderRoot": "cinegy/Cinecoder.3.30.33.14182"
          },
          "sources" : [ "<(CinecoderRoot)/sources/Cinecoder_i.c" ],
          "configurations": {
            "Release": {
              "msvs_settings": {
                "VCCLCompilerTool": {
                  "RuntimeTypeInfo": "true",
                  "ExceptionHandling": 1
                }
              }
            }
          },
          "libraries": [ 
            "-l../<(CinecoderRoot)/libs/native/x64/cinecoder.lib",
            "-l../<(CinecoderRoot)/libs/native/x64/D2_CUDA_lib.lib"
          ],
          "copies": [
            { 
              "destination": "build/Release/",
              "files": [
                "<(CinecoderRoot)/libs/native/x64/Cinecoder.dll",
                "<(CinecoderRoot)/libs/native/x64/cudart64_80.dll",
                "<(CinecoderRoot)/libs/native/x64/D2_CUDA_lib.dll"
              ]
            }
          ]
        }]
      ],
    }
  ]
}
