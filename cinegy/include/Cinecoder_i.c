

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Oct 11 15:55:24 2017
 */
/* Compiler settings for Cinecoder.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ICC_ClassFactory,0xe7d4b675,0x63d4,0x43f4,0x91,0xfa,0x0a,0xf2,0x30,0x11,0x1d,0x10);


MIDL_DEFINE_GUID(IID, IID_ICC_Schema,0x48b6acc6,0x3d65,0x41f4,0x80,0x05,0xcf,0x19,0x05,0x8a,0xfc,0x7e);


MIDL_DEFINE_GUID(IID, IID_ICC_ClassCreator,0x4735fb44,0x54bc,0x478a,0x8f,0xfa,0x3a,0xc6,0xcb,0x32,0x0a,0x1a);


MIDL_DEFINE_GUID(IID, IID_ICC_ErrorHandler,0x1fb875da,0xbdf4,0x4de9,0xb5,0x91,0xa3,0xdc,0x77,0xd3,0x70,0xc9);


MIDL_DEFINE_GUID(IID, IID_ICC_ErrorHandlerGetter,0xa84dee36,0x545b,0x4c77,0xb6,0x88,0x08,0xb2,0x13,0xb1,0xc1,0x54);


MIDL_DEFINE_GUID(IID, IID_ICC_ErrorHandlerProp,0x2cff007c,0x31c3,0x45bf,0x8a,0xc1,0x3b,0x16,0x9c,0x4c,0xcd,0x7b);


MIDL_DEFINE_GUID(IID, IID_ICC_ClassFactoryProvider,0xdea107a0,0x559e,0x4908,0x94,0xfc,0x8e,0x17,0xb9,0xf0,0xe1,0xad);


MIDL_DEFINE_GUID(IID, IID_ICC_PluginDescr,0xaa304da6,0xc855,0x4fda,0x82,0x2c,0x32,0xda,0x58,0xbc,0xba,0xf3);


MIDL_DEFINE_GUID(IID, IID_ICC_Object,0x42d33946,0xc343,0x43c5,0x9c,0xa0,0x85,0xa3,0x36,0x21,0x02,0xc4);


MIDL_DEFINE_GUID(IID, IID_ICC_Settings,0xAA8AE4DE,0x938F,0x4eb3,0xAD,0x44,0x36,0x34,0x64,0xD1,0x0A,0x5D);


MIDL_DEFINE_GUID(IID, IID_ICC_StreamProcessor,0xf43bfdf8,0x1ae4,0x4626,0x85,0x35,0x15,0xc4,0x92,0x13,0xd2,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_ByteStreamProducer,0xBA54F9EB,0x498D,0x471c,0x8C,0x01,0xA8,0x88,0x30,0xC6,0xEC,0x01);


MIDL_DEFINE_GUID(IID, IID_ICC_ByteStreamConsumer,0x2D8791E2,0x227D,0x4898,0xA6,0x4B,0x52,0x5A,0xBA,0xE5,0x83,0xDA);


MIDL_DEFINE_GUID(IID, IID_ICC_Breakable,0x96218572,0x1941,0x41de,0x85,0x4B,0x0F,0xD5,0xF9,0x38,0xBA,0x0E);


MIDL_DEFINE_GUID(IID, IID_ICC_Decoder,0x5E8AF531,0xFB3F,0x4345,0xA6,0xE9,0x50,0xDF,0x4A,0x40,0x30,0xEB);


MIDL_DEFINE_GUID(IID, IID_ICC_Encoder,0xc5352932,0xd890,0x4631,0xa4,0x1b,0x05,0x4e,0xf9,0x32,0xd5,0x8f);


MIDL_DEFINE_GUID(IID, IID_ICC_Transcoder,0xeb28dcba,0xd1a5,0x4a53,0xa6,0x9d,0x9e,0x00,0x0e,0xfd,0x98,0x04);


MIDL_DEFINE_GUID(IID, IID_ICC_Splitter,0x0920768f,0xe355,0x40df,0xa9,0xc9,0x2e,0x5b,0x08,0x71,0xdb,0x7f);


MIDL_DEFINE_GUID(IID, IID_ICC_Cutter,0x562e7dae,0x48ab,0x4805,0xa5,0x83,0x10,0x8d,0xdb,0x87,0xaa,0x33);


MIDL_DEFINE_GUID(IID, IID_ICC_IndexWriter,0x52911b83,0xe54e,0x401a,0xb9,0x52,0xa1,0x41,0x3e,0xec,0x82,0xaa);


MIDL_DEFINE_GUID(IID, IID_ICC_ByteStreamCallback,0x3190F038,0xCC19,0x405b,0xB6,0x5B,0xFE,0xD9,0x81,0xE3,0x8F,0x0D);


MIDL_DEFINE_GUID(IID, IID_ICC_DataReadyCallback,0x55813708,0xa883,0x4bca,0xbe,0x08,0x06,0x1a,0x54,0x6e,0x0d,0x3f);


MIDL_DEFINE_GUID(IID, IID_ICC_TimeBaseProp,0xBF96E276,0x449C,0x47ec,0xBF,0xA0,0x0B,0xAC,0xB3,0x44,0x7F,0x1D);


MIDL_DEFINE_GUID(IID, IID_ICC_InitialTimeCodeProp,0x020CC64E,0x0BCD,0x4d5b,0xB6,0x8A,0xE2,0x10,0x71,0x6F,0x2D,0x9E);


MIDL_DEFINE_GUID(IID, IID_ICC_BitRateProp,0x146273cc,0x9a1e,0x4faa,0xb4,0x5a,0xa3,0x4a,0x6d,0xc8,0x0a,0x7a);


MIDL_DEFINE_GUID(IID, IID_ICC_FrameRateProp,0x003f7114,0x3a9c,0x41f3,0xb0,0x34,0x60,0x80,0x1d,0xa8,0x5d,0x6f);


MIDL_DEFINE_GUID(IID, IID_ICC_BufferAllocator,0xCFB56A68,0xB3F4,0x422d,0xB9,0x76,0x1C,0x26,0x5A,0x1D,0x30,0x64);


MIDL_DEFINE_GUID(IID, IID_ICC_StreamRecovery,0xDE7A69AB,0x560E,0x4777,0xBA,0xAA,0x57,0x3F,0x9D,0xEF,0xE7,0xEC);


MIDL_DEFINE_GUID(IID, IID_ICC_ThreadsCountProp,0x8f73a09e,0x3419,0x42f9,0xb6,0xe5,0x28,0x42,0x54,0x43,0xfc,0x5d);


MIDL_DEFINE_GUID(IID, IID_ICC_ThreadsAffinityProp,0x452854e9,0x2033,0x46a3,0xa3,0xcd,0xa9,0x5a,0xa1,0xf4,0x66,0xc1);


MIDL_DEFINE_GUID(IID, IID_ICC_ThreadsPriorityProp,0x635a623f,0xf077,0x4083,0x96,0x3d,0x6a,0xa6,0x62,0x68,0xb0,0xc8);


MIDL_DEFINE_GUID(IID, IID_ICC_InputBufferControl,0xd96ad003,0xb4ed,0x4154,0xaf,0xed,0xc0,0xf7,0x78,0x05,0x14,0x15);


MIDL_DEFINE_GUID(IID, IID_ICC_ReferenceAlisProp,0x8CDA674D,0xA513,0x4b24,0x8B,0x6C,0x0D,0x34,0xB2,0xE8,0xFC,0xD1);


MIDL_DEFINE_GUID(IID, IID_ICC_ProcessDataPolicyProp,0x9bfc95b3,0x67ff,0x4dce,0x92,0x58,0x65,0x45,0xa5,0x1f,0xd0,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AddUserDataCtrl,0x8616e94c,0x3950,0x4df7,0x8c,0x90,0xd7,0x76,0xe8,0x64,0x50,0x61);


MIDL_DEFINE_GUID(IID, IID_ICC_ConcurrencyLevelProp,0x610330b7,0x3359,0x471e,0xbd,0xc0,0x2a,0x5a,0xc7,0x2b,0xe3,0x72);


MIDL_DEFINE_GUID(IID, IID_ICC_DataWriter,0xc7689044,0x8834,0x41b0,0x8d,0xfe,0xa5,0xc4,0x07,0xf8,0xa2,0x5b);


MIDL_DEFINE_GUID(IID, IID_ICC_DataWriterEx,0x07d72818,0x5aa6,0x4f0d,0xbd,0xf2,0xc0,0xf8,0x15,0x90,0x15,0x37);


MIDL_DEFINE_GUID(IID, IID_ICC_DataReader,0x05ebcab5,0xb9d7,0x4024,0xaa,0x3e,0xb6,0x3b,0x1d,0x5e,0x04,0x6d);


MIDL_DEFINE_GUID(IID, IID_ICC_DataReaderEx,0xb7f45fbd,0x8e48,0x4c72,0x9b,0xf6,0x51,0xf4,0x75,0x3f,0xb7,0x23);


MIDL_DEFINE_GUID(IID, IID_ICC_StreamPositionProp,0x7082a2e8,0xe87b,0x4f0b,0xb1,0xeb,0xc0,0x71,0xac,0xa2,0xb6,0x76);


MIDL_DEFINE_GUID(IID, IID_ICC_StreamLengthProp,0x56e7b348,0x2a5c,0x4d67,0xb6,0x24,0x55,0x0d,0xc8,0x7e,0x87,0xdb);


MIDL_DEFINE_GUID(IID, IID_ICC_InputStream,0x1fe2f5d7,0xed48,0x4362,0x9e,0xbd,0x2a,0xa0,0x04,0x29,0xb0,0xdd);


MIDL_DEFINE_GUID(IID, IID_ICC_File,0x4a4806fb,0xd622,0x4c14,0xa1,0x9c,0x93,0x5a,0xcc,0xc9,0xb4,0x50);


MIDL_DEFINE_GUID(IID, IID_ICC_InputFile,0xfac59d98,0x7bd4,0x4100,0xb8,0x07,0xec,0xcd,0x2f,0xbe,0x1c,0xbf);


MIDL_DEFINE_GUID(IID, IID_ICC_OutputFile,0x4682af7b,0x926a,0x4d47,0xbe,0x2b,0x8b,0xb5,0xd5,0x55,0x33,0x1d);


MIDL_DEFINE_GUID(IID, IID_ICC_ElementaryStreamInfo,0x03AF145E,0x6633,0x4cbd,0xB6,0xCF,0x28,0x64,0x73,0xE5,0x58,0x60);


MIDL_DEFINE_GUID(IID, IID_ICC_ElementaryStreamSettings,0x89157059,0xe318,0x4a9b,0x88,0x21,0x1c,0xfc,0x97,0x9a,0xc1,0x19);


MIDL_DEFINE_GUID(IID, IID_ICC_ByteStreamDataInfo,0xad2b6c6e,0xc53d,0x4421,0x9b,0x7b,0x3b,0x02,0x24,0x20,0x52,0x57);


MIDL_DEFINE_GUID(IID, IID_ICC_ElementaryDataInfo,0xD2C8A578,0x2495,0x4271,0x8F,0x99,0x1D,0xFC,0x46,0x9E,0x7B,0x32);


MIDL_DEFINE_GUID(IID, IID_ICC_CodedStreamHeaderProp,0x923d7d85,0x60e1,0x479b,0xa5,0x46,0x0f,0x8c,0x16,0x64,0xc4,0x3a);


MIDL_DEFINE_GUID(IID, IID_ICC_ExecutiveDeviceMaskProp,0x703087c5,0x31bc,0x4156,0xbf,0xd8,0x78,0x04,0x8a,0xc8,0xe4,0xf4);


MIDL_DEFINE_GUID(IID, IID_ICC_CollectionHandler,0x2B55773E,0x6140,0x4B82,0x88,0xAD,0xB0,0xF2,0x65,0x68,0x35,0xBA);


MIDL_DEFINE_GUID(IID, IID_ICC_ReadOnlyCollection,0x0579CA5C,0x09EE,0x4215,0x88,0x0A,0x9B,0xDE,0x78,0xE8,0xD5,0xA4);


MIDL_DEFINE_GUID(IID, IID_ICC_Collection,0xCEEABD5A,0x2915,0x4585,0xA5,0x58,0xA9,0xC5,0x58,0x58,0x7D,0xA4);


MIDL_DEFINE_GUID(IID, IID_ICC_CollectionChanged,0x1A05F3A9,0x0943,0x4D65,0xAC,0x76,0x21,0x00,0xE4,0xEC,0x6E,0xA7);


MIDL_DEFINE_GUID(IID, IID_ICC_CollectionFilter,0xC61A9F1F,0x2ABF,0x4CB2,0x9C,0x5D,0x14,0x05,0x16,0x66,0x3D,0xCE);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioStreamInfo,0x00003301,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioEncoderSettings,0xa12bf062,0xfd75,0x44a1,0x9a,0xdf,0xad,0x6d,0x1a,0x35,0x3f,0x74);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioFrameInfo,0x00003302,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioProducer,0x00003001,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioConsumer,0x00003002,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioProducerExt,0xf865713b,0x9ed0,0x42de,0xae,0x47,0x27,0xec,0x45,0x43,0xd4,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioConsumerExt,0x6ad320eb,0x7ec1,0x487d,0xad,0x90,0x1a,0x68,0xe7,0x0f,0xf8,0xdb);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioDecoder,0x00003700,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioEncoder,0x00003400,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioSplitter,0xeab5d8d8,0xc8f0,0x4ded,0xa2,0xd3,0x31,0xc5,0xfd,0x60,0xa0,0x5a);


MIDL_DEFINE_GUID(IID, IID_ICC_AudioFilter,0x403ac16e,0x9b0c,0x47e5,0xb3,0xfa,0xd7,0xec,0x1d,0x3a,0xf0,0x93);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegAudioStreamInfo,0x16bd8d1b,0x5245,0x4f88,0xa4,0x3f,0x23,0x63,0xef,0x8f,0x4b,0x2b);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegAudioFrameInfo,0xbeff73fd,0x2452,0x41e3,0xae,0xfb,0xc7,0xf3,0x90,0x34,0x9f,0x4b);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegAudioEncoderSettings,0x40858c51,0x86e4,0x496c,0xa6,0xe8,0x81,0xcb,0xfe,0x2d,0xcc,0x1c);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegAudioDecoder,0x7b9c9deb,0xd2c4,0x4239,0xbd,0x19,0x37,0x21,0x4a,0xe2,0x7b,0x58);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegAudioEncoder,0xa8810f12,0xbaf4,0x449f,0xa5,0xd7,0x05,0x2e,0x24,0xad,0xb3,0x56);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegAudioSplitter,0x3ea678d6,0xfbfa,0x4aeb,0x84,0xb5,0xff,0xca,0x91,0xb7,0xaa,0x84);


MIDL_DEFINE_GUID(IID, IID_ICC_Aes3AudioStreamInfo,0x6a7d55ae,0x19f4,0x46e8,0x87,0xc9,0x27,0xd9,0x57,0x12,0xe9,0x66);


MIDL_DEFINE_GUID(IID, IID_ICC_Aes3AudioEncoderSettings,0x0aac0e66,0x5eb9,0x4f8e,0x98,0x88,0x8d,0xc5,0x11,0xff,0xa6,0x69);


MIDL_DEFINE_GUID(IID, IID_ICC_Aes3AudioFrameInfo,0x30f5700b,0xdd51,0x4266,0xb9,0x9e,0x0a,0x62,0x83,0xad,0xf4,0x85);


MIDL_DEFINE_GUID(IID, IID_ICC_Aes3AudioDecoder,0x9d054d64,0xc980,0x4108,0x91,0x8c,0x34,0x96,0x37,0x33,0x14,0xfc);


MIDL_DEFINE_GUID(IID, IID_ICC_Aes3AudioEncoder,0x17a5ca65,0xd735,0x4e22,0xa2,0xf9,0x29,0x71,0xce,0xe7,0xe8,0x1e);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioStreamInfo,0x8d85d96b,0x1359,0x4173,0x99,0xf1,0xd9,0x40,0x42,0x04,0x26,0xcc);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioFrameInfo,0xa212acd4,0xc2d2,0x45ed,0x85,0x6f,0x0c,0xae,0x23,0xf1,0x43,0x52);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioStreamSettings,0xc48df702,0x21a4,0x454d,0xbc,0xb6,0x28,0xcb,0x0e,0x1c,0x36,0x9f);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioEncoderSettings,0x393e9fcf,0xeed3,0x4e74,0x86,0xd1,0x2c,0xe0,0x34,0xbc,0x68,0x0c);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioDecoder,0x461528f1,0xd3d3,0x4349,0xb7,0x28,0xc5,0xa2,0x7e,0xd9,0xaf,0xdc);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioEncoder,0xb0fb4156,0xbb6a,0x4000,0xb3,0xc5,0xc7,0x5c,0x93,0xf6,0x07,0xa7);


MIDL_DEFINE_GUID(IID, IID_ICC_AAC_AudioSplitter,0x0d395265,0xfdf2,0x4c5d,0xb6,0x3e,0xc1,0x4e,0x59,0x7f,0x5e,0x74);


MIDL_DEFINE_GUID(IID, IID_ICC_LATM_AAC_AudioDecoder,0x94f6f31b,0xcb5d,0x4813,0x9c,0x1e,0x3e,0x04,0x74,0x78,0xd0,0x63);


MIDL_DEFINE_GUID(IID, IID_ICC_LPCM_AudioStreamInfo,0xfd104508,0x54d6,0x47cb,0x8f,0x2b,0x5d,0x4a,0xc2,0x08,0x74,0xab);


MIDL_DEFINE_GUID(IID, IID_ICC_LPCM_AudioEncoderSettings,0x6da5badf,0x910b,0x4c6a,0xae,0x8c,0xe1,0x85,0xe8,0x8f,0xbd,0x01);


MIDL_DEFINE_GUID(IID, IID_ICC_LPCM_AudioDecoder,0x45c1f3b6,0x4f4b,0x4007,0xa0,0x55,0x19,0xfd,0x19,0x60,0x34,0x7f);


MIDL_DEFINE_GUID(IID, IID_ICC_LPCM_AudioEncoder,0x7f60463f,0xbb23,0x4334,0x8e,0x95,0xc2,0xa3,0x8f,0x74,0x92,0xea);


MIDL_DEFINE_GUID(IID, IID_ICC_BluRay_PCM_AudioDecoder,0x69c5f8f2,0xa863,0x47d4,0xaa,0xec,0xfb,0x63,0xca,0x98,0x77,0x75);


MIDL_DEFINE_GUID(IID, IID_ICC_AC3_AudioStreamInfo,0xd766dec9,0x3649,0x4958,0x96,0xd4,0x50,0x88,0x62,0x42,0x0f,0xa7);


MIDL_DEFINE_GUID(IID, IID_ICC_AC3_AudioFrameInfo,0x9b8e0766,0x3118,0x46f4,0x81,0x5b,0x7d,0x2a,0xf4,0xec,0xed,0xb2);


MIDL_DEFINE_GUID(IID, IID_ICC_AC3_AudioEncoderSettings,0xb1e0805e,0x11b6,0x4f3e,0x81,0x29,0x24,0xde,0x36,0x83,0x34,0xa3);


MIDL_DEFINE_GUID(IID, IID_ICC_AC3_AudioEncoder,0xb5779e7c,0x0d45,0x40e6,0x8f,0xb6,0xcc,0xba,0x6f,0x19,0xe9,0x84);


MIDL_DEFINE_GUID(IID, IID_ICC_AC3_AudioDecoder,0x7dd6b14b,0x3eaf,0x4bb5,0xb4,0xe7,0x71,0x44,0xa0,0x78,0xe5,0xc3);


MIDL_DEFINE_GUID(IID, IID_ICC_AC3_AudioSplitter,0xc0d3bba8,0xad71,0x48c1,0x91,0x1e,0xbb,0x35,0xdd,0xc2,0xe3,0xf3);


MIDL_DEFINE_GUID(IID, IID_ICC_WavAudioStreamInfo,0xfe1c44c6,0xf691,0x4ee9,0xb6,0x40,0x70,0xf4,0x8d,0xef,0xb6,0x00);


MIDL_DEFINE_GUID(IID, IID_ICC_WavAudioEncoderSettings,0x7fbfb34a,0x7005,0x479d,0x96,0xb5,0x25,0xa9,0x01,0x49,0x6c,0x26);


MIDL_DEFINE_GUID(IID, IID_ICC_WavAudioEncoder,0x92366695,0x3047,0x4744,0xaa,0x87,0x8d,0x93,0x9c,0x6e,0x8a,0x69);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoStreamInfo,0x00002201,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoStreamInfoExt,0x344748d5,0xe5b1,0x48cf,0x8a,0xc0,0x0b,0x18,0x35,0x87,0x23,0xda);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoFrameInfo,0x00002203,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoFrameSecondFieldProp,0x204d5e69,0x3539,0x4bc7,0x83,0x64,0x89,0x72,0x51,0xf2,0x73,0x9a);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoFrameUserDataProp,0x37ad7e37,0x5275,0x44ea,0x88,0xa3,0x71,0x97,0x8c,0x71,0x2b,0x40);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoFrameQualityInfo,0x00002205,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_PsnrCalculationProp,0xa011f6c3,0x59ad,0x4ad9,0xaf,0xe0,0x4a,0xba,0xde,0x61,0x97,0x1e);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoProducer,0x00002002,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoConsumer,0x00002003,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoConsumerExt,0x00002004,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoConsumerExtAsync,0xa54e5863,0x382b,0x4a9c,0xbf,0x2d,0x28,0x7d,0x5f,0xbd,0xb0,0xa8);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoProducerExt,0x71ac7c0a,0x7ca3,0x4774,0x94,0x5b,0x2b,0x17,0xe9,0x55,0xea,0x01);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoDecoder,0x00002005,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoEncoder,0x00002006,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_VideoSplitter,0x61149ac1,0xd826,0x46be,0x82,0xa9,0xc7,0xa8,0xfd,0xf1,0x9b,0x15);


MIDL_DEFINE_GUID(IID, IID_ICC_VDecFrameOutputOrderProp,0xdc5e98b4,0x0c61,0x4d00,0x9e,0xe0,0x24,0x53,0xf7,0xe5,0x3e,0xde);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegVideoStreamInfo,0x00002202,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegVideoFrameInfo,0x00002204,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegVideoDecoder,0x00002700,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegVideoEncoder,0x00002400,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegVideoEncoderSettings,0x00002401,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_MpegVideoSplitter,0x17adf111,0x3450,0x4cf6,0x93,0x71,0xe0,0x2e,0xed,0x72,0x0c,0xd4);


MIDL_DEFINE_GUID(IID, IID_ICC_D10VideoEncoderSettings,0xd6baaecc,0x900a,0x4fce,0xbb,0x7a,0x5f,0xeb,0x66,0x5b,0xe2,0x75);


MIDL_DEFINE_GUID(IID, IID_ICC_D10VideoEncoder,0xaa7effd7,0x7830,0x4400,0xb5,0x1e,0xac,0x7b,0x35,0x10,0xf9,0xc1);


MIDL_DEFINE_GUID(IID, IID_ICC_H264VideoStreamInfo,0x63cf41b3,0xb6ac,0x448f,0xac,0x25,0x5b,0x21,0x60,0x82,0x5d,0x9c);


MIDL_DEFINE_GUID(IID, IID_ICC_H264VideoEncoderSettings,0x7baac45c,0x1da0,0x4fa6,0xb6,0x45,0xf9,0xaf,0xdd,0x84,0x24,0x6f);


MIDL_DEFINE_GUID(IID, IID_ICC_H264VideoFrameInfo,0xecfd3260,0x3a6b,0x474a,0x94,0xe5,0x7d,0x35,0xc7,0x48,0x2c,0x8b);


MIDL_DEFINE_GUID(IID, IID_ICC_H264VideoEncoder,0x60DAA884,0x1861,0x4771,0xBF,0x4D,0x4A,0x82,0x57,0x0D,0xDC,0x8E);


MIDL_DEFINE_GUID(IID, IID_ICC_H264VideoDecoder,0xf7b72085,0xb7b8,0x42a2,0xa6,0xec,0xe8,0x18,0x14,0xe8,0x4f,0x32);


MIDL_DEFINE_GUID(IID, IID_ICC_AVC1VideoDecoder,0x0976d3ec,0x341a,0x4805,0x95,0x4a,0x3a,0x8c,0xb0,0xd1,0xd3,0x3a);


MIDL_DEFINE_GUID(IID, IID_ICC_H264VideoSplitter,0xec6d9953,0x2ea1,0x422e,0xbf,0x66,0x9d,0xb8,0xb2,0x4f,0x0f,0xc8);


MIDL_DEFINE_GUID(IID, IID_ICC_HEVCVideoStreamInfo,0x59d8bbc4,0x4f9e,0x4e91,0xa1,0x13,0x5d,0x4d,0x01,0x26,0x25,0x79);


MIDL_DEFINE_GUID(IID, IID_ICC_HEVCVideoFrameInfo,0xed49d3da,0x7b4d,0x4f43,0xad,0xfe,0x96,0x1a,0xac,0x27,0x49,0x2c);


MIDL_DEFINE_GUID(IID, IID_ICC_HEVCVideoDecoder,0xb0584a0a,0xa32c,0x4040,0xa7,0x96,0xa6,0x24,0xf2,0xdc,0xa3,0x7f);


MIDL_DEFINE_GUID(IID, IID_ICC_HEVCVideoSplitter,0x693b38d6,0xa8cf,0x4d96,0x90,0x99,0xa1,0x2f,0xad,0xa9,0xb7,0x69);


MIDL_DEFINE_GUID(IID, IID_ICC_HEVCVideoEncoder,0x78058b0d,0xb691,0x4ea1,0xb3,0x6e,0x59,0x9b,0x80,0x4f,0xda,0x66);


MIDL_DEFINE_GUID(IID, IID_ICC_HEVCVideoEncoderSettings,0xe9d5616d,0xb262,0x44d5,0x88,0x69,0x96,0xae,0xc9,0xf7,0x8a,0xa9);


MIDL_DEFINE_GUID(IID, IID_ICC_AVCIntraEncoderSettings,0x54761d8c,0x4180,0x46c7,0x83,0x64,0x14,0x4a,0x64,0xed,0x1e,0x8e);


MIDL_DEFINE_GUID(IID, IID_ICC_AVCIntraEncoder,0x0242b581,0x180a,0x430e,0xbb,0x9c,0x1a,0x78,0xe6,0x0d,0xe3,0xe5);


MIDL_DEFINE_GUID(IID, IID_ICC_AVCIntraDecoder,0x6c54b9dd,0x6608,0x4b3c,0x83,0x25,0x3d,0x45,0xa6,0x12,0xcb,0xb9);


MIDL_DEFINE_GUID(IID, IID_ICC_AVCIntraDecoder2,0x1a5e58f3,0x876d,0x4efa,0xaa,0x2b,0x8d,0x68,0xd5,0xf9,0xda,0x4e);


MIDL_DEFINE_GUID(IID, IID_ICC_Mpeg4VideoStreamInfo,0x63ebe1fe,0x888a,0x468e,0x9e,0x07,0xc7,0xc6,0x1d,0xa1,0xe3,0x9b);


MIDL_DEFINE_GUID(IID, IID_ICC_Mpeg4VideoFrameInfo,0xdf8c0ede,0xb2ea,0x41d4,0xa4,0x47,0x83,0x36,0x4a,0x37,0x7e,0x47);


MIDL_DEFINE_GUID(IID, IID_ICC_Mpeg4VideoDecoder,0x31c651b2,0xbfa1,0x41e8,0xb7,0xe6,0xfe,0x1f,0x99,0xd2,0x80,0xcd);


MIDL_DEFINE_GUID(IID, IID_ICC_J2K_VideoStreamInfo,0xabfb14e8,0x4aa5,0x40b3,0x8f,0xc7,0xc8,0xdc,0x22,0x7a,0x62,0xc9);


MIDL_DEFINE_GUID(IID, IID_ICC_J2K_VideoFrameInfo,0x23c787fa,0x1d2d,0x436c,0x95,0xdc,0x26,0x4f,0x18,0x06,0xe5,0x57);


MIDL_DEFINE_GUID(IID, IID_ICC_J2K_VideoSplitter,0xf341b209,0xd017,0x40a7,0xb9,0xa1,0x26,0x82,0xd0,0x8a,0xe1,0x23);


MIDL_DEFINE_GUID(IID, IID_ICC_J2K_VideoDecoder,0x1c4dfcfd,0x6afc,0x471d,0xbd,0x09,0x65,0xb2,0xa4,0xbd,0x9a,0x13);


MIDL_DEFINE_GUID(IID, IID_ICC_SonyRaw_VideoStreamInfo,0xae5cdb5b,0xd9f0,0x4053,0x8c,0x03,0x44,0xa5,0xa3,0x05,0xef,0x03);


MIDL_DEFINE_GUID(IID, IID_ICC_SonyRaw_VideoFrameInfo,0x5a17fce5,0xa435,0x4e0d,0x90,0x83,0x10,0x70,0x96,0x0b,0xde,0x1b);


MIDL_DEFINE_GUID(IID, IID_ICC_SonyRaw_VideoDecoder,0xf7a23e0b,0x1d09,0x458d,0xba,0x4f,0x62,0x33,0x56,0xad,0x93,0x61);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoStreamInfo,0xfd99aee9,0x6b26,0x43ec,0xbb,0xd1,0xff,0x65,0x8e,0xf6,0xd8,0x64);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoFrameInfo,0x5e60a260,0xffc6,0x4325,0xb6,0xb1,0xf7,0x43,0xaa,0x10,0x46,0xb5);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoSplitter,0x25f3f204,0x1537,0x4c7b,0x97,0xbd,0xa5,0xeb,0x76,0x78,0x85,0x09);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoDecoder,0x2070fe32,0xe7b4,0x4063,0xac,0x68,0x86,0xb1,0x34,0xf1,0xe8,0xbd);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoEncoderSettings,0x5f03f830,0x497f,0x471a,0xbc,0xc1,0xd5,0xcf,0xb4,0x17,0xf5,0x44);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoEncoderSettings_CUDA,0x64310105,0xefcc,0x4027,0x9c,0x46,0xac,0xba,0x00,0x14,0xc7,0x03);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoEncoder,0xecab2803,0x01f0,0x4233,0xa3,0x46,0x3a,0xb9,0x0e,0x19,0x71,0x29);


MIDL_DEFINE_GUID(IID, IID_ICC_D2D_GetUpdateVideoBufferPtrProp,0xf14dab53,0x5dc0,0x4edd,0x88,0xe6,0x63,0xd0,0x58,0xf2,0x78,0xb8);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoDecoder_CUDA,0x60966b59,0xa6fb,0x4742,0xa5,0x62,0x22,0x3f,0x7e,0x4c,0x45,0xe3);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoEncoder_CUDA,0x9a156bd1,0xf05f,0x4d3c,0x9b,0x55,0xc4,0x9f,0x65,0x20,0x03,0x42);


MIDL_DEFINE_GUID(IID, IID_ICC_DanielVideoDecoder_CudaPlayer,0x0add9766,0xf751,0x4a15,0xb8,0x91,0x14,0x95,0x60,0x5e,0xef,0x3b);


MIDL_DEFINE_GUID(IID, IID_ICC_D2D_GetFrameDecodingParamsProp,0xd45d4f96,0xa218,0x4c54,0x96,0xfc,0x23,0x0f,0x2c,0x15,0x37,0xa7);


MIDL_DEFINE_GUID(IID, IID_ICC_Y4M_VideoStreamInfo,0x5ad9b3a9,0x9a15,0x44ed,0x93,0x41,0x71,0x15,0x67,0x0e,0x7c,0x77);


MIDL_DEFINE_GUID(IID, IID_ICC_Y4M_VideoFrameInfo,0x43e44fc2,0x99d9,0x4e78,0xaa,0x60,0x24,0x7d,0xf8,0x29,0x32,0x31);


MIDL_DEFINE_GUID(IID, IID_ICC_Y4M_VideoSplitter,0x876b52d4,0xd01c,0x49e2,0x98,0xd7,0x74,0x49,0xd4,0x98,0x9c,0xbb);


MIDL_DEFINE_GUID(IID, IID_ICC_Y4M_VideoDecoder,0x569d8d00,0x59e0,0x440b,0x83,0x04,0xfc,0xc3,0x56,0x13,0x5f,0x9e);


MIDL_DEFINE_GUID(IID, IID_ICC_Y4M_VideoEncoderSettings,0xbc708f85,0x7200,0x4056,0x80,0xd1,0x93,0x62,0x8c,0x65,0xe5,0xf6);


MIDL_DEFINE_GUID(IID, IID_ICC_Y4M_VideoEncoder,0xc753bffb,0xf306,0x44b4,0xb1,0x64,0xec,0x2f,0x19,0x39,0xee,0xc9);


MIDL_DEFINE_GUID(IID, IID_ICC_MultiplexedDataDescr,0x022813a8,0x3467,0x4f49,0xb1,0x7a,0x57,0xbf,0xfd,0x5f,0xd2,0x1f);


MIDL_DEFINE_GUID(IID, IID_ICC_SystemDescriptorsReader,0x00001ffe,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_SystemDescriptorsManager,0x00001fff,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_PES_Info,0x00001801,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_ProgramInfo,0x00001802,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_MultiplexedStreamInfo,0x00001803,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_BaseMultiplexerSettings,0x00001A01,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_BaseMultiplexerPinSettings,0x00001A02,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_SystemMuxerPinSettings,0x00001B11,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_SystemMuxerSettings,0x00001B01,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_ProgramMuxerPinSettings,0x00001B12,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_ProgramMultiplexerSettings,0x00001B02,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_TransportMuxerPinSettings,0x00001C21,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_TransportMultiplexerSettings,0x00001C01,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_TS_ProgramDescr,0x00001C11,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_M2TSMP_MultiplexerSettings,0x00001C02,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_HDV1MuxerSettings,0x00001D01,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_HDV2MuxerSettings,0x00001D02,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_Multiplexer,0x6EEBE83C,0x8F8B,0x4321,0x8C,0x1E,0xD9,0x50,0xC7,0xE0,0xA2,0x82);


MIDL_DEFINE_GUID(IID, IID_ICC_DemultiplexedDataCallback,0x00001101,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_DemultiplexedDataCallbackExt,0xa3a2d00f,0x72e6,0x4611,0xb4,0xf6,0xde,0x49,0x41,0x39,0x3a,0xcf);


MIDL_DEFINE_GUID(IID, IID_ICC_StreamClockReferenceProp,0x1c420773,0xd168,0x404a,0x85,0xf2,0x07,0xb2,0xb6,0xec,0x54,0x55);


MIDL_DEFINE_GUID(IID, IID_ICC_ProgramClockReferencePidProp,0x43a07dea,0x9101,0x4b35,0xb6,0xc2,0xc9,0xdd,0xa5,0x51,0xb0,0x8b);


MIDL_DEFINE_GUID(IID, IID_ICC_Demultiplexer,0x00001102,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_HDV2_Multiplexer,0x00001D12,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_StreamRecognizer,0x00007777,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(IID, IID_ICC_DebugDumpIncomingDataToFile,0x3aaf6ee8,0x11db,0x4801,0x92,0x29,0x99,0x93,0xd7,0x43,0xa0,0xea);


MIDL_DEFINE_GUID(IID, IID_ICC_PCR_Callback,0x0fdcdb5a,0x5eee,0x4152,0x9a,0x14,0xd9,0xda,0xaa,0x75,0x5b,0xe8);


MIDL_DEFINE_GUID(IID, IID_ICC_PCR_CallbackProp,0xc83bc0f4,0xdffb,0x4061,0xb6,0x0e,0x60,0x89,0x5f,0x1d,0x4f,0x7d);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_Multiplexer,0x4a4fc69f,0x4a41,0x4785,0x97,0xd6,0x8f,0xa3,0x75,0x07,0x76,0x9c);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_MultiplexerSettings,0x29d573e4,0xe709,0x41e8,0xa7,0x3c,0x70,0x87,0x6f,0x01,0xa5,0x78);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_MuxerPinSettings,0xbc0a4c83,0xd677,0x4a69,0x85,0x14,0x5b,0xe2,0x34,0xb1,0x4b,0xda);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_MuxerVideoPinSettings,0xc08d455e,0xb958,0x4cda,0xab,0x53,0x66,0x82,0xf4,0xfb,0x24,0x92);


MIDL_DEFINE_GUID(IID, IID_ICC_ReferenceDataConsumer,0x64e71555,0xddd3,0x4106,0xa8,0x65,0x6b,0x0e,0x6e,0x9e,0x63,0xcf);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_FragmentedPin,0xb26b77e5,0xa8a2,0x41d6,0xa9,0x3f,0x18,0xac,0x48,0x91,0xb9,0x23);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_InitialTimeCodeProp,0xA3BA7AF7,0xE739,0x43d5,0x8D,0x90,0x8E,0xF2,0x56,0xCE,0xD5,0xB7);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4_MpegDashSettings,0x53919957,0xD8DA,0x41BC,0xB7,0x67,0x40,0x34,0x4E,0xDD,0xD5,0x57);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4ChunkInfo,0x875370A3,0x312E,0x4D45,0xBD,0x6F,0x4E,0xAF,0x62,0xC0,0x94,0x4A);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4Fragment,0x39D64FEB,0x4AFC,0x43B7,0xA3,0x19,0x67,0x74,0x01,0x04,0xCE,0x44);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4InitFragment,0x80BDD2C9,0x678A,0x407A,0xBA,0x3C,0x50,0x3C,0x45,0x2E,0xB4,0x33);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4RandomAccessFragment,0xA8795B72,0xCA30,0x4FF5,0x98,0x99,0x3F,0x7D,0xBF,0xAD,0x4A,0xA9);


MIDL_DEFINE_GUID(IID, IID_ICC_MP4Producer,0xACCD0235,0xEE69,0x4E40,0xB8,0xAA,0xE4,0xD1,0xD4,0x4E,0x6D,0xD6);


MIDL_DEFINE_GUID(IID, IID_ICC_HLS_MultiplexerSettings,0xf6397d60,0xf204,0x4acc,0x83,0x39,0xd9,0x4d,0xba,0x6f,0xa4,0xdd);


MIDL_DEFINE_GUID(IID, IID_ICC_MediaReader,0x91aa62eb,0xeb08,0x48ee,0x9b,0xd0,0x5e,0x6c,0x68,0x6e,0x77,0x73);


MIDL_DEFINE_GUID(IID, IID_ICC_MediaReader2,0xdbd2ea98,0x407b,0x4a3a,0xa8,0x5a,0x3d,0x7e,0x42,0x96,0x42,0x70);


MIDL_DEFINE_GUID(IID, LIBID_Cinecoder,0x80011100,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CinecoderLibrary,0x00000000,0xbe08,0x11dc,0xaa,0x88,0x00,0x50,0x56,0xc0,0x00,0x08);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoEncoderSettings,0x80011101,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoEncoder,0x80011102,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoEncoder2,0xeb953846,0x1fbc,0x408a,0x91,0xf9,0xf7,0xa8,0xac,0xda,0x02,0xd1);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoDecoder,0x80011203,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoDecoder0,0xa13ea19d,0xf813,0x4abd,0xae,0x8f,0x88,0x9e,0x4f,0x53,0x5c,0x21);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoDecoder2,0x475e4d15,0x7f66,0x4176,0xbc,0x85,0x8c,0x9c,0x38,0x05,0xb4,0xcd);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_D10VideoEncoderSettings,0x80011108,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_D10VideoEncoder,0x80011109,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegVideoSplitter,0xb0effac6,0x56e3,0x42f1,0x8f,0xf7,0x78,0xf8,0xf0,0xfc,0x47,0x06);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegAudioEncoderSettings,0x80011103,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegAudioEncoder,0x80011104,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegAudioEncoderOld,0xfde7ec62,0x213f,0x4dc7,0xaf,0x34,0xc9,0xb4,0x71,0x47,0x2f,0xc5);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_Aes3AudioEncoderSettings,0x80011105,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_Aes3AudioEncoder,0x80011106,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegAudioDecoder,0x80011204,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegAudioDecoderOld,0x516b31da,0xedff,0x4c2f,0xbe,0x28,0x9d,0x49,0xbf,0x21,0xa7,0x5f);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegAudioSplitter,0xfcc7a5e3,0x3627,0x4a13,0x8f,0x3f,0xf3,0x68,0x41,0xe2,0x58,0xc7);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_Aes3AudioDecoder,0x80011205,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_ProgramStreamMultiplexer,0x80011402,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_TransportStreamMultiplexer,0x80011403,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HDV1_Multiplexer,0x80011404,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HDV2_Multiplexer,0x80011405,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_ProgramMultiplexerSettings,0x80011302,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_TransportMultiplexerSettings,0x80011303,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MuxPinSettings,0x80011304,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_ProgramMuxerPinSettings,0x78360ef9,0xf2ce,0x4065,0x97,0xb2,0xb7,0x4c,0x65,0xab,0x25,0x13);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_TransportMuxerPinSettings,0xf2af2b0e,0x5691,0x48f6,0xbc,0x86,0x90,0x2d,0xf2,0x8e,0xdf,0xb0);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_SystemsDescriptionManager,0xE828C337,0x9811,0x418d,0xB6,0xE9,0xDD,0xF4,0x0B,0x91,0x98,0x8D);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MpegDemultiplexer,0x80011500,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_ProgramStreamDemultiplexer,0x80011502,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_TransportStreamDemultiplexer,0x80011503,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_H264VideoDecoder,0x80011601,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_H264VideoDecoder0,0x24f7109a,0xd910,0x411c,0x96,0x30,0xde,0x39,0xef,0xb0,0x28,0xb3);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AVC1VideoDecoder,0x80011602,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AVC1VideoDecoder0,0xc618cb66,0x1a6d,0x468a,0xb7,0xbf,0xa9,0xc4,0xda,0x6b,0xa0,0xc5);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_H264VideoEncoder,0x80011603,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_H264VideoEncoderSettings,0x80011604,0x0315,0x11dc,0xa9,0x83,0x00,0x18,0xf3,0xfe,0x41,0x1b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_H264VideoSplitter,0x839555ed,0x00c2,0x4081,0x93,0x23,0xbe,0x34,0xcd,0x1b,0xb4,0x95);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MP4_Multiplexer,0xdf24d3d2,0x9fe6,0x4a81,0xaf,0x22,0xe5,0x02,0xb6,0x9e,0x50,0x8a);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MP4_MultiplexerSettings,0xc8344888,0xca73,0x4819,0xb9,0x47,0x41,0xe3,0x84,0x2f,0xcc,0x46);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MOV_Multiplexer,0xdf24d3d3,0x9fe6,0x4a81,0xaf,0x22,0xe5,0x02,0xb6,0x9e,0x50,0x8a);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MP4_MuxerPinSettings,0xec5dc6db,0x99f2,0x44f2,0x96,0x57,0xeb,0x62,0x9c,0xfb,0x70,0x5b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MP4_MuxerVideoPinSettings,0x403de721,0xdade,0x4365,0xa5,0x87,0x58,0x9e,0xb2,0x42,0x15,0xcf);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MP4_MpegDashSettings,0x9954375D,0x1EFA,0x49A4,0xB2,0xE4,0xC5,0xA6,0xC5,0x35,0x2B,0xA4);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AAC_AudioDecoder,0xc19bf495,0x813d,0x4e19,0x92,0x34,0x57,0x8e,0x74,0x5c,0xdd,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_LATM_AAC_AudioDecoder,0x9bd13af0,0xca9a,0x4909,0x86,0x74,0x3d,0x4d,0xff,0x42,0xe4,0x25);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AAC_AudioEncoder,0xc8064a72,0x1d96,0x47e0,0x8b,0x20,0x72,0xae,0x4f,0xf0,0xfe,0x8d);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AAC_AudioEncoderSettings,0xf13e8488,0x4700,0x4e65,0x81,0xd9,0x42,0xde,0x3e,0xa8,0x55,0x49);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AAC_AudioSplitter,0x174b4d90,0x827b,0x48af,0xb5,0x7d,0x4f,0xc1,0x25,0x97,0xb0,0x99);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AC3_AudioDecoder,0xab977b61,0x58be,0x4d78,0x88,0xcf,0x27,0x69,0xfb,0xea,0x46,0xf9);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AC3_AudioSplitter,0x86ab00cd,0x9c3f,0x405c,0xb1,0x64,0x8b,0xb9,0x91,0xd7,0x87,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AC3_AudioEncoder,0x94a89306,0xb460,0x4670,0x92,0x81,0x36,0xb6,0x43,0x1e,0xf3,0x93);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AC3_AudioEncoderSettings,0xd066604f,0x7ccd,0x4e8d,0x8a,0xcd,0x01,0xbc,0xef,0x8e,0x99,0xc3);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AVCIntraDecoder,0x4907c8e2,0xef67,0x480e,0xb9,0x0d,0xbd,0xba,0x3f,0x4a,0x57,0x0a);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AVCIntraDecoder2,0x0cfa6ce8,0x0cd0,0x47d6,0x8e,0x8e,0x3d,0xc6,0xb1,0xe0,0x2e,0x6f);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AVCIntraEncoder,0x8ad378a7,0x88cb,0x4c1c,0x81,0x50,0xd6,0x1e,0x15,0x8a,0x73,0x26);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_AVCIntraEncoderSettings,0x2cd550f9,0x27ae,0x44c5,0x9b,0x20,0xc4,0x60,0x28,0xc5,0x26,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_Mpeg4VideoDecoder,0x5b97f2d2,0x2ae8,0x4c76,0x84,0x0a,0x66,0x1a,0x08,0x15,0xd5,0xf6);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MvxWriter,0x13397d8e,0xa4f7,0x4f67,0xb3,0x46,0xd6,0x16,0x84,0x55,0x37,0x16);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_BluRay_PCM_AudioDecoder,0x152e6383,0x46fd,0x4c20,0xbe,0xe9,0x12,0x6d,0xbc,0x49,0x8f,0xb5);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_LPCM_AudioEncoder,0xc1d5d4aa,0xd523,0x45a2,0xb7,0xfa,0x57,0xbc,0x99,0xae,0xc9,0xee);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_LPCM_AudioEncoderSettings,0xdd0b84e0,0x8c97,0x48a9,0xbf,0x32,0xd5,0x8d,0x27,0x7b,0x8d,0x53);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HLS_Multiplexer,0x6232dc00,0x73aa,0x46f6,0xbc,0x40,0x42,0x93,0x73,0x7b,0xb1,0x1f);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HLS_MultiplexerSettings,0xe33e35bc,0xe11f,0x4d77,0x96,0xa0,0x48,0x0a,0x76,0x8e,0xee,0x3d);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_J2K_VideoSplitter,0x095e2bed,0x9610,0x4550,0x95,0x05,0xb4,0xd0,0xa3,0x19,0x85,0x11);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_J2K_VideoDecoder,0xc8069cc9,0x67bf,0x40cd,0xa7,0x8c,0x69,0x65,0x2e,0xe1,0x7f,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_SonyRaw_VideoDecoder,0x8c1e236a,0x2602,0x41b2,0x89,0xb0,0x97,0x81,0x00,0x70,0xa0,0x89);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoSplitter,0x76bef61e,0xf17d,0x4079,0x8f,0x22,0x0c,0x18,0xfb,0xf3,0x8e,0x65);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoDecoder,0x0236cdb4,0x3541,0x4c66,0xa2,0x11,0x49,0x6e,0x91,0x92,0x2d,0xba);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoDecoder_CUDA,0x00a25ffa,0xf7bf,0x4876,0xa5,0x92,0x73,0xf9,0x44,0x93,0x6a,0x6f);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoDecoder_CudaPlayer,0x942d0694,0x04ec,0x4995,0xb4,0xaf,0x85,0x86,0x9f,0x5c,0x60,0x5e);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoEncoder,0x5fd43ca9,0x0f0f,0x40e0,0xa2,0x0a,0x74,0xc9,0xa5,0xed,0xbe,0xc8);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoEncoder_CUDA,0x6e0bf254,0xf734,0x4d75,0xab,0x2f,0xde,0x59,0x8b,0xe1,0x56,0x16);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoEncoderSettings,0xfd5a7ff2,0xa1fe,0x41af,0xb2,0x7a,0x0d,0x78,0x6a,0x73,0x84,0x73);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_DanielVideoEncoderSettings_CUDA,0x2faf33b7,0xbb91,0x401b,0x82,0xde,0x36,0x3e,0x3c,0xd5,0xd3,0x09);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_MediaReader,0x331cbbb5,0x6dd6,0x4bcb,0x92,0xae,0x03,0x7d,0xf2,0x5f,0xe9,0x2e);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_InputFile,0x1d200482,0x6ddc,0x420a,0x8a,0x6c,0x25,0x57,0x02,0x91,0x1a,0xe7);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_OutputFile,0x3b0a99b4,0x809c,0x4a6e,0xbe,0x17,0x90,0x81,0x49,0x53,0xe7,0x08);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_WavAudioEncoder,0xbda1912f,0x7051,0x47fe,0x88,0x3f,0x6c,0xd4,0x2a,0xf5,0x50,0x85);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_WavAudioEncoderSettings,0xad9b9cfb,0x0644,0x4cce,0x85,0x9c,0x4a,0xee,0x1e,0xc4,0xf7,0x48);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HEVCVideoEncoder,0x0d9505f9,0xf31a,0x4351,0xbb,0x39,0xd3,0x69,0x95,0x04,0x39,0xa9);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HEVCVideoEncoderSettings,0xc7e8a86e,0xe4f8,0x4865,0xa3,0x13,0xb1,0xdc,0xb6,0x4b,0x86,0xcd);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HEVCVideoSplitter,0xe53dc514,0x51cc,0x4844,0xb1,0x7e,0xed,0xfa,0x0e,0xe3,0x2c,0x17);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HEVCVideoDecoder,0x4013d46c,0xce5f,0x4e6c,0x94,0x9b,0x0a,0x87,0x2f,0x57,0x5b,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_HEVCVideoDecoder0,0xd4ce1c4f,0x60d6,0x442d,0xb2,0xbb,0x45,0xb5,0xd5,0xc6,0xde,0x9b);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_Y4M_VideoEncoder,0x6c6e79c1,0xd644,0x4d66,0x88,0x4d,0x7e,0x9d,0x9b,0x0b,0xbb,0xda);


MIDL_DEFINE_GUID(CLSID, CLSID_CC_Y4M_VideoEncoderSettings,0xbc7a18e4,0x14eb,0x485d,0xbc,0x43,0xc8,0x93,0x2d,0x25,0x09,0x70);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



