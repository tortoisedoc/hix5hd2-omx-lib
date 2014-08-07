/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OMX_VideoExt_h
#define OMX_VideoExt_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Each OMX header shall include all required header files to allow the
 * header to compile without errors.  The includes below are required
 * for this header file to compile successfully
 */
#include <OMX_Core.h>
#include <OMX_Component.h>
#include <OMX_Index.h>

/* CodecType Relative */
#define OMX_VDEC_COMPONENT_NAME            "OMX.hisi.video.decoder"

#define OMX_COMPONENTROLES_H264            "video_decoder.avc"
#define OMX_COMPONENTROLES_MPEG2           "video_decoder.mpeg2"
#define OMX_COMPONENTROLES_MPEG4           "video_decoder.mpeg4"
#define OMX_COMPONENTROLES_H263            "video_decoder.h263"
#define OMX_COMPONENTROLES_SORENSON        "video_decoder.sorenson"
#define OMX_COMPONENTROLES_AVS             "video_decoder.avs"
#define OMX_COMPONENTROLES_VC1             "video_decoder.vc1"
#define OMX_COMPONENTROLES_WMV             "video_decoder.wmv"
#define OMX_COMPONENTROLES_DIVX3           "video_decoder.divx3"
#define OMX_COMPONENTROLES_VP6             "video_decoder.vp6"
#define OMX_COMPONENTROLES_VP8             "video_decoder.vp8"
#define OMX_COMPONENTROLES_RV              "video_decoder.rv"
#define OMX_COMPONENTROLES_MJPEG           "video_decoder.mjpeg"

/** Enum for video codingtype extensions */
typedef enum OMX_VIDEO_CODINGEXTTYPE {
    OMX_VIDEO_ExtCodingUnused = OMX_VIDEO_CodingKhronosExtensions,
    OMX_VIDEO_CodingDIVX3,      /**< Divx3 */
    OMX_VIDEO_CodingVP6,        /**< VP6 */
    OMX_VIDEO_CodingMSMPEG4,    /**< MSMPEG4 */
    OMX_VIDEO_CodingAVS,        /**< AVS */
    OMX_VIDEO_CodingSorenson,   /**< Sorenson */
    OMX_VIDEO_CodingButt,       /**< MAX */
} OMX_VIDEO_CODINGEXTTYPE;

/** VP6 Versions */
typedef enum OMX_VIDEO_VP6FORMATTYPE {
    OMX_VIDEO_VP6FormatUnused = 0x01,   /**< Format unused or unknown */
    OMX_VIDEO_VP6      = 0x02,   /**< On2 VP6 */
    OMX_VIDEO_VP6F     = 0x04,   /**< On2 VP6 (Flash version) */
    OMX_VIDEO_VP6A     = 0x08,   /**< On2 VP6 (Flash version, with alpha channel) */
    OMX_VIDEO_VP6FormatKhronosExtensions = 0x6F000000, /**< Reserved region for introducing Khronos 
                                                            Standard Extensions */
    OMX_VIDEO_VP6FormatVendorStartUnused = 0x7F000000, /**< Reserved region for introducing Vendor Extensions */
    OMX_VIDEO_VP6FormatMax    = 0x7FFFFFFF
} OMX_VIDEO_VP6FORMATTYPE;

/**
  * VP6 Params
  *
  * STRUCT MEMBERS:
  *  nSize      : Size of the structure in bytes
  *  nVersion   : OMX specification version information
  *  nPortIndex : Port that this structure applies to
  *  eFormat    : VP6 format
  */
typedef struct OMX_VIDEO_PARAM_VP6TYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_VIDEO_VP6FORMATTYPE eFormat;
} OMX_VIDEO_PARAM_VP6TYPE;


/*========================================================================
Open MAX   Component: Video Decoder
This module contains the class definition for openMAX decoder component.
author: y00226912
==========================================================================*/

typedef enum OMX_HISI_EXTERN_INDEXTYPE {
	OMX_HisiIndexChannelAttributes = (OMX_IndexVendorStartUnused + 1),
	OMX_GoogleIndexEnableAndroidNativeBuffers,
	OMX_GoogleIndexGetAndroidNativeBufferUsage,
	OMX_GoogleIndexUseAndroidNativeBuffer,
	OMX_GoogleIndexUseAndroidNativeBuffer2
}OMX_HISI_EXTERN_INDEXTYPE;

/**
* A pointer to this struct is passed to the OMX_SetParameter when the extension
* index for the 'OMX.Hisi.Index.ChannelAttributes' extension
* is given.
* The corresponding extension Index is OMX_HisiIndexChannelAttributes.
*/
typedef struct OMX_HISI_PARAM_CHANNELATTRIBUTES  {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPrior;
    OMX_U32 nErrorThreshold;
    OMX_U32 nStreamOverflowThreshold;
    OMX_U32 nDecodeMode;
    OMX_U32 nPictureOrder;
}  OMX_HISI_PARAM_CHANNELATTRIBUTES;

#ifdef ANDROID // native buffer
/**
* A pointer to this struct is passed to the OMX_SetParameter when the extension
* index for the 'OMX.google.android.index.enableAndroidNativeBuffers' extension
* is given.
* The corresponding extension Index is OMX_GoogleIndexUseAndroidNativeBuffer.
* This will be used to inform OMX about the presence of gralloc pointers
instead
* of virtual pointers
*/
typedef struct EnableAndroidNativeBuffersParams  {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_BOOL bEnable;
} EnableAndroidNativeBuffersParams;

/**
* A pointer to this struct is passed to OMX_GetParameter when the extension
* index for the 'OMX.google.android.index.getAndroidNativeBufferUsage'
* extension is given.
* The corresponding extension Index is OMX_GoogleIndexGetAndroidNativeBufferUsage.
* The usage bits returned from this query will be used to allocate the Gralloc
* buffers that get passed to the useAndroidNativeBuffer command.
*/
typedef struct GetAndroidNativeBufferUsageParams  {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_U32 nUsage;
} GetAndroidNativeBufferUsageParams;

#endif




























#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OMX_VideoExt_h */
