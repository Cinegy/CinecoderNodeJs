﻿/* Copyright 2017 Cinegy GmbH.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  The version of Cinecoder for these headers should be: 3.28.23.12518
*/

#ifndef __CINECODER_ERRORS_H
#define __CINECODER_ERRORS_H

#include <winerror.h>

#define E_TIMEOUT             __HRESULT_FROM_WIN32(ERROR_TIMEOUT)
#define E_INSUFFICIENT_BUFFER __HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
#define E_MODULE_NOT_FOUND    __HRESULT_FROM_WIN32(ERROR_MOD_NOT_FOUND)

#ifndef __DECLARE_CINECODER_ERROR
#define __DECLARE_CINECODER_ERROR(name,code) name = ((HRESULT)code)
enum CinecoderErrorCodes
#endif
{
 __DECLARE_CINECODER_ERROR(E_OK                                     , S_OK      ),
 __DECLARE_CINECODER_ERROR(S_EOF                                    , S_FALSE   ),
                                                                                  
 __DECLARE_CINECODER_ERROR(E_BREAK                                  , 0x8004F400),
 __DECLARE_CINECODER_ERROR(E_STOPPED                                , 0x8004F401),
 __DECLARE_CINECODER_ERROR(MPG_E_FUNCTION_NOT_ALLOWED               , 0x8004F402),
 __DECLARE_CINECODER_ERROR(MPG_E_DATA_NOT_READY                     , 0x8004F403),
 __DECLARE_CINECODER_ERROR(MPG_E_STREAM_SYNTAX_ERROR                , 0x8004F404),
 __DECLARE_CINECODER_ERROR(MPG_E_STREAM_TYPE_NOT_SUPPORTED          , 0x8004F405),
 __DECLARE_CINECODER_ERROR(MPG_E_FORMAT_NOT_SUPPORTED               , 0x8004F406),
 __DECLARE_CINECODER_ERROR(MPG_E_CPU_NOT_SUPPORTED                  , 0x8004F407),
 __DECLARE_CINECODER_ERROR(MPG_E_DECODER_BUFFER_OVERFLOW            , 0x8004F408),
 __DECLARE_CINECODER_ERROR(MPG_E_INVALID_SEEK_POSITION              , 0x8004F409),
 __DECLARE_CINECODER_ERROR(MPG_E_TOO_MANY_STREAMS                   , 0x8004F40A),
 __DECLARE_CINECODER_ERROR(MPG_E_MAX_PATCH_EXCEEDED                 , 0x8004F40B),
 __DECLARE_CINECODER_ERROR(MPG_E_NOT_INITIALIZED                    , 0x8004F40C),
 __DECLARE_CINECODER_ERROR(MPG_E_NOT_OPENED                         , 0x8004F40D),
 __DECLARE_CINECODER_ERROR(MPG_E_ALREADY_USED                       , 0x8004F40E),
 __DECLARE_CINECODER_ERROR(MPG_E_NO_SPACE                           , 0x8004F40F),
 __DECLARE_CINECODER_ERROR(MPG_E_USER_DATA_TOO_LONG                 , 0x8004F410),
 __DECLARE_CINECODER_ERROR(MPG_E_DESCRIPTOR_TOO_LONG                , 0x8004F411),
 __DECLARE_CINECODER_ERROR(MPG_E_MAX_BITRATE_EXCEEDED               , 0x8004F412),
 __DECLARE_CINECODER_ERROR(MPG_E_SYNC_FAILED                        , 0x8004F413),
 __DECLARE_CINECODER_ERROR(MPG_E_MISSING_SEQ_HEADER                 , 0x8004F413),
 __DECLARE_CINECODER_ERROR(MPG_E_END_OF_STREAM                      , 0x8004F414),
 __DECLARE_CINECODER_ERROR(MPG_E_TIMEOUT                            , 0x8004F415),
 __DECLARE_CINECODER_ERROR(MPG_E_INSUFFICIENT_DATA                  , 0x8004F416),
 __DECLARE_CINECODER_ERROR(MPG_E_MAX_DURATION_EXCEEDED              , 0x8004F417),
 __DECLARE_CINECODER_ERROR(MPG_E_OUT_OF_RANGE                       , 0x8004F418),
 __DECLARE_CINECODER_ERROR(MPG_E_GAP_IN_RANGE                       , 0x8004F419),

 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_CROP_RECT                , 0x8004F420),
 __DECLARE_CINECODER_ERROR(MPG_E_RESIZE_NOT_SUPPORTED               , 0x8004F421),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INDEX_FILE_ERROR                   , 0x8004F430),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_UNEXPECTED                     , 0x8004F440),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_OVERFLOW                       , 0x8004F441),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_UNDERFLOW                      , 0x8004F442),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_PSI_TABLE_OVERFLOW             , 0x8004F443),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_DUPLICATE_STREAM_ID            , 0x8004F444),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_DUPLICATE_PID                  , 0x8004F445),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_INPUT_MISTIMING                , 0x8004F446),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_REORDER_DELAY_CHANGE           , 0x8004F447),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_INCORRECT_CONFIGURATION        , 0x8004F448),
 __DECLARE_CINECODER_ERROR(MPG_E_MUX_INCORRECT_AU_SIZE              , 0x8004F449),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_CALLBACK_ERROR                     , 0x8004F450),
 __DECLARE_CINECODER_ERROR(MPG_E_CALLBACK_RETSIZE_MISMATCH          , 0x8004F451),
 __DECLARE_CINECODER_ERROR(MPG_E_MISSING_CALLBACK                   , 0x8004F452),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_PROFILE_PARSING_ERROR              , 0x8004F480),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_NAME                           , 0x8004F481),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_COMMENT                        , 0x8004F482),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_TAG_SYNTAX                     , 0x8004F483),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_TAG_NAME                       , 0x8004F484),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_ATTRIBUTE_SYNTAX               , 0x8004F485),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_ATTRIBUTE_NAME                 , 0x8004F486),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_ATTRIBUTE_VALUE                , 0x8004F487),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_CHARACTER_SYNTAX               , 0x8004F488),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_DUPLICATED_ATTR                , 0x8004F489),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_XML_MISSING_OBJECT_NAME            , 0x8004F490),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_DUPLICATE_OBJECT_NAME          , 0x8004F491),
 __DECLARE_CINECODER_ERROR(MPG_E_XML_OBJECT_NOT_FOUND               , 0x8004F492),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INTERNAL_ERROR                     , 0x8004F4EE),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INVALID_LICENSE                    , 0x8004F4F0),
 __DECLARE_CINECODER_ERROR(MPG_E_LICENSE_EXPIRED                    , 0x8004F4F1),
 __DECLARE_CINECODER_ERROR(MPG_E_LICENSE_VIOLATION                  , 0x8004F4F2),
 __DECLARE_CINECODER_ERROR(MPG_E_LICENSE_NUM_STREAMS_EXCEEDED       , 0x8004F4F3),
 __DECLARE_CINECODER_ERROR(MPG_E_LICENSE_NUM_VIDEO_STREAMS_EXCEEDED , 0x8004F4F4),
 __DECLARE_CINECODER_ERROR(MPG_E_LICENSE_NUM_PROGRAMS_EXCEEDED      , 0x8004F4F5),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PARAMETER                , 0x8004F500),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_STREAM_TYPE              , 0x8004F501),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_STREAM_ID                , 0x8004F502),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PID                      , 0x8004F503),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PTS                      , 0x8004F504),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PACKET_SIZE              , 0x8004F505),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_ALIGNMENT                , 0x8004F506),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_BUFFER_SIZE              , 0x8004F507),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PADDING                  , 0x8004F508),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_MUXRATE                  , 0x8004F509),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PERIOD                   , 0x8004F50a),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_DESCRIPTOR               , 0x8004F50b),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_DESCRIPTOR_SIZE          , 0x8004F50c),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_STD_BUFFER_SIZE          , 0x8004F50d),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_STD_BUFFER_SCALE         , 0x8004F50e),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_OUTPUT_POLICY            , 0x8004F50f),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_TIMEBASE                 , 0x8004F510),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_LAYER                    , 0x8004F511),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_FRAME_SIZE               , 0x8004F512),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_FRAME_RATE               , 0x8004F513),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_BITRATE                  , 0x8004F514),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_RATE_MODE                , 0x8004F515),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_QUANTIZER                , 0x8004F516),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PROFILE_LEVEL            , 0x8004F517),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_VBV_BUFFER_SIZE          , 0x8004F518),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_CHROMA_FORMAT            , 0x8004F519),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_VIDEO_FORMAT             , 0x8004F51a),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_GOP_SETTINGS             , 0x8004F51b),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_INTRA_DC_PREC            , 0x8004F51c),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_DISPLAY_SIZE             , 0x8004F51d),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_COLOR_COEFS              , 0x8004F51e),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_ASPECT_RATIO             , 0x8004F51f),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_TIMECODE                 , 0x8004F510),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_SEARCH_WINDOW            , 0x8004F521),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_SEARCH_PARMS             , 0x8004F522),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_MOTION_QUALITY           , 0x8004F523),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_MB_STRUCT                , 0x8004F524),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_MB_SCAN                  , 0x8004F525),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PICTURE_STRUCTURE        , 0x8004F526),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_FIELD_ORDER              , 0x8004F527),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_NUM_REF_FRAMES           , 0x8004F528),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_ENTROPY_CODING_MODE      , 0x8004F529),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_NUM_SLICES               , 0x8004F52A),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_BIT_DEPTH                , 0x8004F52B),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_INTERLACE_TYPE           , 0x8004F52C),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_SCALING_MATRIX           , 0x8004F52D),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_WEIGHTED_PRED            , 0x8004F52E),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PICTURE_ORIENTATION      , 0x8004F52F),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_BITRATE_TOO_LOW                    , 0x8004F530),
 __DECLARE_CINECODER_ERROR(MPG_E_VBV_BUFFER_TOO_LOW                 , 0x8004F531),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_CHANNEL_MODE             , 0x8004F540),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_NUMBER_OF_CHANNELS       , 0x8004F541),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_SAMPLE_RATE              , 0x8004F542),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_EMPHASIS                 , 0x8004F543),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_BITS_PER_SAMPLE          , 0x8004F544),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_CRC_PROTECTION           , 0x8004F545),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_FORMAT                   , 0x8004F546),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PROFILE                  , 0x8004F547),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_CODING_MODE              , 0x8004F548),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_CHANNEL_CONFIG           , 0x8004F549),
                                                                                  
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_AFFINITY_MASK            , 0x8004F570),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_PRIORITY                 , 0x8004F571),
 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_THREADS_NUMBER           , 0x8004F572),

 __DECLARE_CINECODER_ERROR(MPG_E_INCORRECT_DEVICE                   , 0x8004F578),
};

#endif
