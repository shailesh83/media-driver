/*
* Copyright (c) 2009-2017, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file      hal_kernelrules_g8.c  
//! \brief         Fast Compositing Kernel DLL rules for gen8  
//!
#include "hal_kerneldll.h"  // Rule definitions
#include "vpkrnheader.h"    // Kernel IDs

extern const Kdll_RuleEntry g_KdllRuleTable_g8[] =
{
    // Kernel Setup

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Begin                        , Kdll_None },
    { RID_SetParserState   , Parser_SetRenderMethod              , Kdll_None },

    // Set rendering method

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SetRenderMethod                  , Kdll_None },
    { RID_IsRenderMethod   , RenderMethod_MediaObject                , Kdll_None },
    { RID_SetKernel        , IDR_VP_VP_Setup                         , Kdll_None },
    { RID_SetParserState   , Parser_SetupLayer0                      , Kdll_None },

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SetRenderMethod                  , Kdll_None },
    { RID_IsRenderMethod   , RenderMethod_MediaObjectWalker          , Kdll_None },
    { RID_SetKernel        , IDR_VP_VP_Setup_MediaWalker_32x32_Color , Kdll_None },
    { RID_SetParserState   , Parser_SetupLayer0                      , Kdll_None },

    // Set Layer 0

    // If first layer is RT, it's colorfill only case. Make sure.
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer0                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },    // If it's RT
    { RID_IsLayerNumber    , 0                                   , Kdll_None },    // If it's first layer.
    { RID_SetParserState   , Parser_SetParamsTarget              , Kdll_None },

    // 1st layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer0                  , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_0                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer0              , Kdll_None },

    // Set Layer 1

    // Please don't change the order of 2 rulesets below.
    // Single layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Any                          , Kdll_None },  // Src0 must be valid for single layer case.
    { RID_SetNextLayer     , -1                                  , Kdll_None },  // backoff one layer
    { RID_SetParserState   , Parser_SampleLayer0                 , Kdll_None },

    // Last layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsTarget              , Kdll_None },  // Setup CSC for render target

    // 2nd layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 1                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_1                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // 3rd layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 2                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_2                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // 4th layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 3                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_3                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // 5th layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 4                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_4                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // 6th layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 5                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_5                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // 7th layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 6                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_6                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // 8th layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupLayer1                  , Kdll_None },
    { RID_IsLayerNumber    , 7                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Layer_7                  , Kdll_None },
    { RID_SetParserState   , Parser_SetParamsLayer1              , Kdll_None },

    // Setup Parameters for Layer 0

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetParamsLayer0              , Kdll_None },
    { RID_SetSrc0Format    , Format_Source                       , Kdll_None },
    { RID_SetSrc0Coeff     , CoeffID_Source                      , Kdll_None },
    { RID_SetSrc0Sampling  , Sample_Source                       , Kdll_None },
    { RID_SetSrc0Rotation  , Rotate_Source                       , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_Source                    , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_Source                      , Kdll_None },
    { RID_SetSrc0Processing, Process_Source                      , Kdll_None },
    { RID_SetNextLayer     , 0                                   , Kdll_None },
    { RID_SetParserState   , Parser_SetupLayer1                  , Kdll_None },

    // Setup Parameters for Layer 1

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetParamsLayer1              , Kdll_None },
    { RID_SetSrc1Format    , Format_Source                       , Kdll_None },
    { RID_SetSrc1Coeff     , CoeffID_Source                      , Kdll_None },
    { RID_SetSrc1Sampling  , Sample_Source                       , Kdll_None },
    { RID_SetSrc1Rotation  , Rotate_Source                       , Kdll_None },
    { RID_SetSrc1LumaKey   , LumaKey_Source                      , Kdll_None },
    { RID_SetSrc1Processing, Process_Source                      , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1                 , Kdll_None },

    // Setup Parameters for Render Target

    //If only RT is present, it's colorfill only case. Go to write directly.
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetParamsTarget              , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_Source                    , Kdll_None },
    { RID_SetSrc0Format    , Format_Source                       , Kdll_None },
    { RID_SetParserState   , Parser_WriteOutput                  , Kdll_None },

    // If CSC0 is done before Mix, then jump to SetupCSC1
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetParamsTarget              , Kdll_None },
    { RID_IsCSCBeforeMix   , true                                , Kdll_None },
    { RID_SetTargetCspace  , CSpace_Source                       , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetParamsTarget              , Kdll_None },
    { RID_SetSrc0Format    , Format_Source                       , Kdll_None },
    { RID_SetSrc0Coeff     , CoeffID_Source                      , Kdll_None },
    { RID_SetTargetCspace  , CSpace_Source                       , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC0                    , Kdll_None },

    // Sample Layer 0

    // Sample (P010 | P016) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample_Unorm progressive scaling
    // Sample (RGB | AYUV | Packed YUV | NV12 | 400P) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444Scale16_Buf_0          , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444Scale16_Buf_1          , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444Scale16_Buf_2          , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444Scale16_Buf_3          , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample NV12 (width or height is not a multiple of 4) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Scale16_Buf_0         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Scale16_Buf_1         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Scale16_Buf_2         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Scale16_Buf_3         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample (PL3 | PL3_RGB) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444Scale16_Buf_0         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444Scale16_Buf_1         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444Scale16_Buf_2         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444Scale16_Buf_3         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample progressive scaling
    // Sample 0.34x (P010 | P016) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample 0.34x (RGB | AYUV | Packed YUV | NV12 | 400P) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444DScale16_Buf_0         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444DScale16_Buf_1         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444DScale16_Buf_2         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444DScale16_Buf_3         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample 0.34x PL2(width or height is not a multiple of 4) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },


    // Sample 0.34x (PL3 | PL3_RGB) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444DScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444DScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444DScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444DScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample_8x8 progressive scaling
    // AVS Sample (RGB | AYUV | Packed YUV | NV12 | 400P) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444AVS16_Buf_0            , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444AVS16_Buf_1            , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444AVS16_Buf_2            , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444AVS16_Buf_3            , Kdll_None },
    { RID_SetParserState   , Parser_ShuffleLayer0                , Kdll_None },

    // AVS Sample PL2(width or height is not a multiple of 4) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444AVS16_Buf_0           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444AVS16_Buf_1           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444AVS16_Buf_2           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444AVS16_Buf_3           , Kdll_None },
    { RID_SetParserState   , Parser_ShuffleLayer0                , Kdll_None },

    // AVS Sample (PL3 | PL3_RGB) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444AVS16_Buf_0           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444AVS16_Buf_1           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444AVS16_Buf_2           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444AVS16_Buf_3           , Kdll_None },
    { RID_SetParserState   , Parser_ShuffleLayer0                , Kdll_None },

     // AVS Interlace Scaling
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_NV12                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_AVS                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iAVS16_Buf_0           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iAVS16_Buf_1           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iAVS16_Buf_2           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iAVS16_Buf_3           , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // AVS Interlace Scaling PL2 -> Src0
    // PL2_444iAVS is not supported, use PL2_444iScale kernel instead
    // May have quality difference than interlaced AVS scaling
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_AVS                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample_Unorm interlaced scaling
    // Interlaced Sample RGB -> Src0
    // jump to sampleLayer0SelectCSC to decide if CSC needed before Mix
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_0         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_1         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_2         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_3         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0SelectCSC        , Kdll_None },

    // Sample (AYUV | Packed YUV | NV12 | 400P) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_0         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_1         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_2         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iScale16_Buf_3         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample PL2(width or height is not a multiple of 4) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample PL3 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample PL3_RGB -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0SelectCSC        , Kdll_None },

    // Sample interlaced scaling
    // Sample 0.34x RGB -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_034x                , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

     // Sample 0.34x (AYUV | Packed YUV | NV12 | 400P) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_034x                , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_0        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_1        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_2        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444iDScale16_Buf_3        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample 0.34x PL2(width or height is not a multiple of 4) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_034x                , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iDScale16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iDScale16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iDScale16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444iDScale16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample 0.34x PL3 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_034x                , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    // Sample 0.34x PL3_RGB -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling_034x                , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444iDScale16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0SelectCSC        , Kdll_None },

    // Select CSC for layer 0 Mix only if Render Target format is NV12
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0SelectCSC        , Kdll_None },
    { RID_IsTargetFormat   , Format_NV12                         , Kdll_None },
    { RID_SetNextLayer     , 2                                   , Kdll_None },   // increase layer number to target layer
    { RID_SetCSCBeforeMix  , true                                , Kdll_None },
    { RID_SetSrc0Coeff     , CoeffID_Source                      , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC0                    , Kdll_None },

    // If Render Target is not NV12, simply call Intermix
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0SelectCSC        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None }, 

    // Intermix the layer 0

    // Interlaced scaling, intermix the top and bottom fields
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0Mix              , Kdll_None },
    { RID_IsTargetFormat   , Format_NV12                         , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_Or   },
    { RID_IsSrc0Sampling   , Sample_iScaling_AVS                 , Kdll_Or   },
    { RID_IsSrc0Sampling   , Sample_iScaling_034x                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_420_16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_420_16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_420_16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_420_16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Interlaced scaling, intermix the top and bottom fields
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0Mix              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_444_16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_444_16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_444_16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Interlace_444_16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Shuffle Layer 0

    // All layers use Sample_8x8
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ShuffleLayer0                , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Mix of Sample_8x8 and normal sampling. Shuffle Sample_8x8 data
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ShuffleLayer0                , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_0       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_1       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_2       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_3       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0ColorFill        , Kdll_None },

    // Sample Layer 0 Colorfill

    // Src0 Sampling is complete, AVS not shuffled yet -> SrcBlend + Luma key + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_IsSrc0Processing , Process_SBlend                      , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_SrcBlend  , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> SrcBlend + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_IsSrc0Processing , Process_SBlend                      , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_SrcBlend  , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> ConstBlend + Luma key + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_CBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                            , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_ConstBlend    , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                           , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> ConstBlend + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_CBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_ConstBlend    , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> ConstSrcBlend + Luma key + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                            , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill                , Kdll_None },
    { RID_IsSrc0Processing , Process_CSBlend                             , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                              , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                                , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                        , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_ConstSrcBlend     , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                             , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                               , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                     , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> ConstSrcBlend + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                            , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill                , Kdll_None },
    { RID_IsSrc0Processing , Process_CSBlend                             , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                              , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                        , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_ConstSrcBlend     , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                             , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                     , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> PartBlend + Luma key + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_PBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                            , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_PartBlend     , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                           , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> PartBlend + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_PBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16_PartBlend     , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> Luma key + colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16           , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Src0 Sampling is complete, AVS not shuffled yet -> colorfill AVS
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444AVS16           , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Src0 Sampling is complete -> SrcBlend + Luma key + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_SBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                            , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_SrcBlend    , Kdll_None },
    { RID_SetSrc0Processing, Process_None                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                           , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                , Kdll_None },

    // Src0 Sampling is complete -> SrcBlend + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_SBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_SrcBlend    , Kdll_None },
    { RID_SetSrc0Processing, Process_None                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                , Kdll_None },

    // Src0 Sampling is complete -> ConstBlend + Luma key + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_CBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                            , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_ConstBlend  , Kdll_None },
    { RID_SetSrc0Processing, Process_None                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                           , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                , Kdll_None },

    // Src0 Sampling is complete -> ConstBlend + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_CBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_ConstBlend  , Kdll_None },
    { RID_SetSrc0Processing, Process_None                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                , Kdll_None },

    // Src0 Sampling is complete -> ConstSrcBlend + Luma key + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                            , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill                , Kdll_None },
    { RID_IsSrc0Processing , Process_CSBlend                             , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                              , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_ConstSrcBlend   , Kdll_None },
    { RID_SetSrc0Processing, Process_None                                , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                             , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                               , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                    , Kdll_None },

    // Src0 Sampling is complete -> ConstSrcBlend + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                            , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill                , Kdll_None },
    { RID_IsSrc0Processing , Process_CSBlend                             , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_ConstSrcBlend   , Kdll_None },
    { RID_SetSrc0Processing, Process_None                                , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                             , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                    , Kdll_None },

    // Src0 Sampling is complete -> PartBlend + Luma key + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_PBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                            , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_PartBlend   , Kdll_None },
    { RID_SetSrc0Processing, Process_None                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                           , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                , Kdll_None },

    // Src0 Sampling is complete -> PartBlend + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill            , Kdll_None },
    { RID_IsSrc0Processing , Process_PBlend                          , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16_PartBlend   , Kdll_None },
    { RID_SetSrc0Processing, Process_None                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check                , Kdll_None },

    // Src0 Sampling is complete, no AVS or already shuffled -> Luma key + colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_IsSrc0LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey_Buf0123      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetSrc0LumaKey   , LumaKey_False                       , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check            , Kdll_None },

    // Src0 Sampling is complete, no AVS or already shuffled -> colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check            , Kdll_None },

    // Src0 Sampling is complete -> no Luma key or colorfill
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0ColorFill        , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0Check            , Kdll_None },

    // PreComp Layer 0 Rotation Check
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0Check            , Kdll_None },
    { RID_IsRTRotate       , true                                , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0Check            , Kdll_None },
    { RID_IsRTRotate       , false                               , Kdll_None },
    { RID_SetParserState   , Parser_RotateLayer0                 , Kdll_None },

    // Src0 PreComp Rotation
       
    // Rotate 0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_IDENTITY             , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 90: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_90                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_90        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 180: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_180                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_180       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 270: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_270                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_270       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Mirror Horizontal: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_MIRROR_HORIZONTAL             , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Mirror_H_L0         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Mirror Vertical: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                           , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_MIRROR_VERTICAL               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Mirror_V_L0         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 90 Mirror Vertical: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                     , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                              , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                             , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                              , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                             , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                               , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATE_90_MIRROR_VERTICAL         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate90_Mirror_V_L0    , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Rotate 90 Mirror Horizontal: (Format_PL2 | Format_400P | Format_RGB | Format_AYUV | Format_PA) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                     , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2                              , Kdll_Or   },
    { RID_IsSrc0Format     , Format_400P                             , Kdll_Or   },
    { RID_IsSrc0Format     , Format_RGB                              , Kdll_Or   },
    { RID_IsSrc0Format     , Format_AYUV                             , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PA                               , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATE_90_MIRROR_HORIZONTAL       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate90_Mirror_H_L0    , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Rotate 90: (Format_PL3 | Format_PL3_RGB) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_90                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_Scale_Rotate_L0_90       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 180: (Format_PL3 | Format_PL3_RGB) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_180                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_Scale_Rotate_L0_180      , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 270: (Format_PL3 | Format_PL3_RGB) -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc0Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_270                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_Scale_Rotate_L0_270      , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // There are no Kernels for PL3 mirroring

    // When there are multiple data formats inside the kernel depending on PL2, PA, AVS, scale
    // Driver is loading the PL2 via AVS sampler then converting internal format to scale before the composition by shuffling.
    // After this operation, the internal data format in the kernel changes and it is no long PL2 scale format but PA format
    // PA_Scale_Rotate kernels should be called in this case
    // Rotate 90: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_90                   , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_90        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 180: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_180                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_180       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 270: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_270                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_270       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Mirror Horizontal: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_MIRROR_HORIZONTAL             , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Mirror_H_L0         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Mirror Vertical: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_MIRROR_VERTICAL               , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Mirror_V_L0         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 90 Mirror Vertical: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                     , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                    , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATE_90_MIRROR_VERTICAL         , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate90_Mirror_V_L0    , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Rotate 90 Mirror Horizontal: Format_PL2_UnAligned -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                     , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                    , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATE_90_MIRROR_HORIZONTAL       , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate90_Mirror_H_L0    , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Rotate 90: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_90                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Rotate_L0_90       , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 180: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_180                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Rotate_L0_180      , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 270: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATION_270                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Rotate_L0_270      , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Mirror Horizontal: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_MIRROR_HORIZONTAL             , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Mirror_H_L0        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Mirror Vertical: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                 , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_MIRROR_VERTICAL               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Mirror_V_L0        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done             , Kdll_None },

    // Rotate 90 Mirror Vertical: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                     , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                    , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                             , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                             , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATE_90_MIRROR_VERTICAL         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Rotate90_Mirror_V_L0   , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Rotate 90 Mirror Horizontal: Format_PL2_UnAligned, Format_P010, Format_P016 -> Src0
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_RotateLayer0                     , Kdll_None },
    { RID_IsSrc0Format     , Format_PL2_UnAligned                    , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P010                             , Kdll_Or   },
    { RID_IsSrc0Format     , Format_P016                             , Kdll_None },
    { RID_IsSrc0Rotation   , VPHAL_ROTATE_90_MIRROR_HORIZONTAL       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_Scale_Rotate90_Mirror_H_L0   , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0Done                 , Kdll_None },

    // Sample Layer 0 Done
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer0Done             , Kdll_None },
    { RID_SetSrc0Sampling  , Sample_None                         , Kdll_None },
    { RID_SetSrc0Format    , Format_None                         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1                 , Kdll_None },

    // Sample Layer 1

    // Sampling for layer0 is not complete, go back
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_Any                          , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer0                 , Kdll_None },

    // Sampling is complete for both layers, perform CSC
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_None                         , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_None                         , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Sample (P010 | P016) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc1Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_4        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_5        , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Sample (RGB | AYUV | Packed YUV | NV12 | 400P) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444Scale16_Buf_4          , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444Scale16_Buf_5          , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // Sample NV12(width or height is not a multiple of 4) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Scale16_Buf_4         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Scale16_Buf_5         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // Sample (PL3 | PL3_RGB) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444Scale16_Buf_4         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444Scale16_Buf_5         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // Sample 0.34x (P010 | P016) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_P010                         , Kdll_Or   },
    { RID_IsSrc1Format     , Format_P016                         , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_4        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_5        , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Sample 0.34x (RGB | AYUV | Packed YUV | NV12 | 400P) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444DScale16_Buf_4         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444DScale16_Buf_5         , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // Sample 0.34x PL2(width or height is not a multiple of 4) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_4        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444Dscale16_Buf_5        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // Sample 0.34x (PL3 | PL3_RGB) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_034x                 , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444DScale16_Buf_4        , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444DScale16_Buf_5        , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // AVS Sample (RGB | AYUV | Packed YUV | NV12 | 400P) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_RGB                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_AYUV                         , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PA                           , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PL2                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_400P                         , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444AVS16_Buf_4            , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_444AVS16_Buf_5            , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // AVS Sample PL2(width or height is not a multiple of 4) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_PL2_UnAligned                , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444AVS16_Buf_4           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL2_444AVS16_Buf_5           , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // AVS Sample (PL3 | PL3_RGB) -> Src1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1                 , Kdll_None },
    { RID_IsSrc1Format     , Format_PL3                          , Kdll_Or   },
    { RID_IsSrc1Format     , Format_PL3_RGB                      , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444AVS16_Buf_4           , Kdll_None },
    { RID_SetKernel        , IDR_VP_PL3_444AVS16_Buf_5           , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1Done             , Kdll_None },

    // Shuffle Layer 1

    // All layers use Sample_8x8
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ShuffleLayer1                , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Mix of Sample_8x8 and normal sampling. Shuffle Sample_8x8 data
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ShuffleLayer1                , Kdll_None },
    { RID_IsShuffling      , Shuffle_All_8x8_Layer               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_4       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Shuffle_444AVS16_Buf_5       , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Sample Layer 1 Done

    // Sample8x8
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1Done             , Kdll_None },
    { RID_IsSrc1Sampling   , Sample_Scaling_AVS                  , Kdll_None },
    { RID_SetParserState   , Parser_ShuffleLayer1                , Kdll_None },

    // Non-Sample8x8
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SampleLayer1Done             , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Setup CSC coefficients for layer 0

    // CSC not present for Render Target
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC0                    , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_None                        , Kdll_None },
    { RID_SetParserState   , Parser_DualOutput                   , Kdll_None },

    // Coeff  0 (CSC+PA), Set Curbe CSC Coefficients
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC0                    , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_0                           , Kdll_None },
    { RID_IsSetCoeffMode   , SetCSCCoeffMethod_Curbe             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CURBE_CSC_Coeff          , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC0                  , Kdll_None },

    // Coeff  0 (CSC+PA), Set Patch CSC Coefficients
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC0                    , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_0                           , Kdll_None },
    { RID_IsSetCoeffMode   , SetCSCCoeffMethod_Patch             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Patched_CSC_Coeff        , Kdll_None },
    { RID_SetPatchData     , PatchKind_CSC_Coeff_Src0            , Kdll_None },      // Patch data source is CSC coeff for Src0
    { RID_SetPatch         , 6                                   , Kdll_None },      // 6 patches : Count (8), Src (8), Dest (16)
    { (Kdll_RuleID) 0x000c , 0x0400                              , Kdll_None },      //             04 00 000c
    { (Kdll_RuleID) 0x001c , 0x0404                              , Kdll_None },      //             04 04 001c
    { (Kdll_RuleID) 0x002c , 0x0408                              , Kdll_None },      //             04 08 002c
    { (Kdll_RuleID) 0x003c , 0x040C                              , Kdll_None },      //             04 0C 003c
    { (Kdll_RuleID) 0x004c , 0x0410                              , Kdll_None },      //             04 10 004c
    { (Kdll_RuleID) 0x005c , 0x0414                              , Kdll_None },      //             04 14 005c
    { RID_SetParserState   , Parser_ExecuteCSC0                  , Kdll_None },

    // Other Matrices ( cannot include PA)
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC0                    , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_Any                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Patched_CSC_Coeff        , Kdll_None },
    { RID_SetPatchData     , PatchKind_CSC_Coeff_Src0            , Kdll_None },      // Patch data source is CSC coeff for Src0
    { RID_SetPatch         , 6                                   , Kdll_None },      // 6 patches : Count (8), Src (8), Dest (16)
    { (Kdll_RuleID) 0x000c , 0x0400                              , Kdll_None },      //             04 00 000c
    { (Kdll_RuleID) 0x001c , 0x0404                              , Kdll_None },      //             04 04 001c
    { (Kdll_RuleID) 0x002c , 0x0408                              , Kdll_None },      //             04 08 002c
    { (Kdll_RuleID) 0x003c , 0x040C                              , Kdll_None },      //             04 0C 003c
    { (Kdll_RuleID) 0x004c , 0x0410                              , Kdll_None },      //             04 10 004c
    { (Kdll_RuleID) 0x005c , 0x0414                              , Kdll_None },      //             04 14 005c
    { RID_SetParserState   , Parser_ExecuteCSC0                  , Kdll_None },

    // Setup CSC coefficients for layer 1

    // No color space conversion for any layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC1                    , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_None                        , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_None                        , Kdll_None },
    { RID_SetParserState   , Parser_Lumakey                      , Kdll_None },

    // Layer 0 not yet converted -> setup/execute CSC for layer 0 and then resume Layer 1
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC1                    , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_Any                         , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC0                    , Kdll_None },

    // Quadrant 2,3 - CSC coefficients already set
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC1                    , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_SetParserState   , Parser_Lumakey                      , Kdll_None },

    // Coeff  0 (CSC+PA), Set Curbe CSC Coefficients
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC1                    , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_0                           , Kdll_None },
    { RID_IsSetCoeffMode   , SetCSCCoeffMethod_Curbe             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CURBE_CSC_Coeff          , Kdll_None },
    { RID_SetParserState   , Parser_Lumakey                      , Kdll_None },

    // Coeff  0 (CSC+PA), Set Patch CSC Coefficients
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC1                    , Kdll_None },
    { RID_IsSrc0Coeff      , CoeffID_0                           , Kdll_None },
    { RID_IsSetCoeffMode   , SetCSCCoeffMethod_Patch             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Patched_CSC_Coeff        , Kdll_None },
    { RID_SetPatchData     , PatchKind_CSC_Coeff_Src1            , Kdll_None },      // Patch data source is CSC coeff for Src0
    { RID_SetPatch         , 6                                   , Kdll_None },      // 6 patches : Count (8), Src (8), Dest (16)
    { (Kdll_RuleID) 0x000c , 0x0400                              , Kdll_None },      //             04 00 000c
    { (Kdll_RuleID) 0x001c , 0x0404                              , Kdll_None },      //             04 04 001c
    { (Kdll_RuleID) 0x002c , 0x0408                              , Kdll_None },      //             04 08 002c
    { (Kdll_RuleID) 0x003c , 0x040C                              , Kdll_None },      //             04 0C 003c
    { (Kdll_RuleID) 0x004c , 0x0410                              , Kdll_None },      //             04 10 004c
    { (Kdll_RuleID) 0x005c , 0x0414                              , Kdll_None },      //             04 14 005c
    { RID_SetParserState   , Parser_Lumakey                      , Kdll_None },

    // Other Matrices (cannot include PA)
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_SetupCSC1                    , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_Any                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Patched_CSC_Coeff        , Kdll_None },
    { RID_SetPatchData     , PatchKind_CSC_Coeff_Src1            , Kdll_None },      // Patch data source is CSC coeff for Src1
    { RID_SetPatch         , 6                                   , Kdll_None },      // 6 patches : Count (8), Src (8), Dest (16)
    { (Kdll_RuleID) 0x000c , 0x0400                              , Kdll_None },      //             04 00 000c
    { (Kdll_RuleID) 0x001c , 0x0404                              , Kdll_None },      //             04 04 001c
    { (Kdll_RuleID) 0x002c , 0x0408                              , Kdll_None },      //             04 08 002c
    { (Kdll_RuleID) 0x003c , 0x040C                              , Kdll_None },      //             04 0C 003c
    { (Kdll_RuleID) 0x004c , 0x0410                              , Kdll_None },      //             04 10 004c
    { (Kdll_RuleID) 0x005c , 0x0414                              , Kdll_None },      //             04 14 005c
    { RID_SetParserState   , Parser_Lumakey                      , Kdll_None },

    // Lumakey
    // lumakey and CSC not needed for current layer.
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Lumakey                      , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_None                        , Kdll_None },
    { RID_IsSrc1LumaKey    , LumaKey_False                       , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayer                 , Kdll_None },

    // lumakey not needed, CSC needed
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Lumakey                      , Kdll_None },
    { RID_IsSrc1LumaKey    , LumaKey_False                       , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_Any                         , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC1                  , Kdll_None },

    // lumakey and CSC - both needed
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Lumakey                      , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_Any                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC1                  , Kdll_None },

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Lumakey                      , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_Any                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC1                  , Kdll_None },

    // Lumakey needed, CSC not needed
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Lumakey                      , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_None                        , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayer                 , Kdll_None },

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_Lumakey                      , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1LumaKey    , LumaKey_True                        , Kdll_None },
    { RID_IsSrc1Coeff      , CoeffID_None                        , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Compute_Lumakey              , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayer                 , Kdll_None },

    // Perform CSC operation for layer 0
    // Src0 -> any to RGB, if Src0 is pre-multiplied content use CSC_Premultiplied
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC0                  , Kdll_None },
    { RID_IsSrc0Processing , Process_PBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf0             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC_Premultiplied       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf1             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC_Premultiplied       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf2             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC_Premultiplied       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf3             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC_Premultiplied       , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC0Done              , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC0                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf0             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf1             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf2             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf3             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC                     , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC0Done              , Kdll_None },

    // CSC0 is complete

    // Check whether go back to intermix layer 0
    // Please not change the order of these two rules
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC0Done              , Kdll_None },
    { RID_IsSrc0Sampling   , Sample_iScaling                     , Kdll_None },
    { RID_SetSrc0Coeff     , CoeffID_None                        , Kdll_None },
    { RID_SetNextLayer     , -2                                  , Kdll_None }, // jump back to main layer
    { RID_SetParserState   , Parser_SampleLayer0Mix              , Kdll_None },

    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC0Done              , Kdll_None },
    { RID_SetSrc0Coeff     , CoeffID_None                        , Kdll_None },
    { RID_SetParserState   , Parser_SetupCSC1                    , Kdll_None },

    // Perform CSC operation for layer 1

    // Src1 -> YUV to RGB, if Src1 is pre-multiplied content use CSC_Premultiplied
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC1                  , Kdll_None },
    { RID_IsSrc1Processing , Process_PBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf4             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC_Premultiplied       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf5             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC_Premultiplied       , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC1Done              , Kdll_None },

    // Src1 -> YUV to RGB
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC1                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf4             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_CSC_Src_Buf5             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_CSC                     , Kdll_None },
    { RID_SetParserState   , Parser_ExecuteCSC1Done              , Kdll_None },

    // Layer 1 CSC is complete - prepare operation
    // Quadrants 0,1 CSC complete
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC1Done              , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayer                 , Kdll_None },

    // Quadrants 2,3 CSC complete
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ExecuteCSC1Done              , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_SetSrc1Coeff     , CoeffID_None                        , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayer                 , Kdll_None },

    // Process layer

    // Render target layer -> write output and finish
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_SetParserState   , Parser_DualOutput                   , Kdll_None },

    // Single layer -> skip processing - prepare CSC for Render Target
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsSrc1Processing , Process_None                        , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Compositing quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_Composite                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_Composite               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_Composite               , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Compositing quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_Composite                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_Composite               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_Composite               , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Constant Blending quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_CBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstBlend              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstBlend              , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Constant Blending quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_CBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstBlend              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstBlend              , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Source Blending quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_SBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend                , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Source Blending quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_SBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend                , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Source Blending (4-bits alpha) quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_SBlend_4bits                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend_4bits          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend_4bits          , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Source Blending (4-bits alpha) quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_SBlend_4bits                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend_4bits          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_SrcBlend_4bits          , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Partial Blending quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_PBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_PartBlend               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_PartBlend               , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Partial Blending quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_PBlend                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_PartBlend               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_PartBlend               , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Constant multitply Sources Blending quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_CSBlend                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstSrcBlend           , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstSrcBlend           , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Constant multiply Sources Blending quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_CSBlend                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstSrcBlend           , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_ConstSrcBlend           , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Constant multitply Partial Blending quadrants 0,1
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_CPBlend                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf0_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_AlphaSrcBlendG          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf1_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_AlphaSrcBlendG          , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Constant multiply Partial Blending quadrants 2,3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayer                 , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_IsSrc1Processing , Process_CPBlend                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf2_Buf4                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_AlphaSrcBlendG          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Buf3_Buf5                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Call_AlphaSrcBlendG          , Kdll_None },
    { RID_SetParserState   , Parser_ProcessLayerDone             , Kdll_None },

    // Layer processing is complete

    // nothing to process - next layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayerDone             , Kdll_None },
    { RID_IsSrc1Processing , Process_None                        , Kdll_None },
    { RID_SetNextLayer     , 0                                   , Kdll_None },
    { RID_SetQuadrant      , 0                                   , Kdll_None },
    { RID_SetParserState   , Parser_SetupLayer1                  , Kdll_None },

    // Quadrants 0,1 are complete - sample/process quadrants 2,3
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayerDone             , Kdll_None },
    { RID_IsQuadrant       , 0                                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Sec_Half_Buf45           , Kdll_None },
    { RID_SetQuadrant      , 2                                   , Kdll_None },
    { RID_SetParserState   , Parser_SampleLayer1                 , Kdll_None },

    // All quadrants are processed - start next layer
    { RID_Op_NewEntry      , RULE_NO_OVERRIDE                    , Kdll_None },
    { RID_IsParserState    , Parser_ProcessLayerDone             , Kdll_None },
    { RID_IsQuadrant       , 2                                   , Kdll_None },
    { RID_SetSrc1Sampling  , Sample_None                         , Kdll_None },
    { RID_SetSrc1Format    , Format_None                         , Kdll_None },
    { RID_SetSrc1Processing, Process_None                        , Kdll_None },
    { RID_SetNextLayer     , 0                                   , Kdll_None },
    { RID_SetQuadrant      , 0                                   , Kdll_None },
    { RID_SetParserState   , Parser_SetupLayer1                  , Kdll_None },

    // dual output mode, non-rotated NV12 is Primary
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DualOutput                       , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_IsDualOutput     , true                                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_NV12               , Kdll_None },
    { RID_SetParserState   , Parser_Rotation                         , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DualOutput                       , Kdll_None },
    { RID_IsDualOutput     , true                                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_NV12             , Kdll_None },
    { RID_SetParserState   , Parser_Rotation                         , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DualOutput                       , Kdll_None },
    { RID_SetParserState   , Parser_Rotation                         , Kdll_None },

    // PL2_Scale_Rotate/Mirroring cases. It requires to keep track of the first 
    // layer (layer 0) format, because the post composition rotation kernel requires 
    // to match the layer 0 input format.
    // For PL3 input, we will use PL2 kernels as PL3 may be replaced by PL2.

    // post composition rotation -> write output
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATION_90                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Rotate_L0_90          , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATION_180                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Rotate_L0_180         , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATION_270                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Rotate_L0_270         , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    // Mirror
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_MIRROR_HORIZONTAL             , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Mirror_H_L0           , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_MIRROR_VERTICAL               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Mirror_V_L0           , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                         , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATE_90_MIRROR_VERTICAL         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Rotate_90_Mirror_V_L0     , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                    , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                         , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                    , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATE_90_MIRROR_HORIZONTAL       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_AVS_Rotate_90_Mirror_H_L0     , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                    , Kdll_None },

    // jump to write output if it's shuffle
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATION_90                   , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_90        , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATION_180                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_180       , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATION_270                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate_L0_270       , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    // Mirror
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_MIRROR_HORIZONTAL             , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Mirror_H_L0         , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                     , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_MIRROR_VERTICAL               , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Mirror_V_L0         , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                         , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATE_90_MIRROR_VERTICAL         , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate90_Mirror_V_L0    , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex               	 , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                         , Kdll_None },
    { RID_IsLayerRotation  , VPHAL_ROTATE_90_MIRROR_HORIZONTAL       , Kdll_None },
    { RID_SetKernel        , IDR_VP_PA_Scale_Rotate90_Mirror_H_L0    , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                    , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_Rotation                         , Kdll_None },
    { RID_SetParserState   , Parser_DestSurfIndex                    , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DestSurfIndex                    , Kdll_None },
    { RID_IsDualOutput     , true                                    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Secondary  , Kdll_None },
    { RID_SetParserState   , Parser_WriteOutput                      , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DestSurfIndex                    , Kdll_None },
    { RID_IsLayerFormat    , Format_YUY2                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YUYV                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YVYU                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_UYVY                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_VYUY                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_NV21                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_PL2                              , Kdll_Or   },
    { RID_IsLayerFormat    , Format_R10G10B10A2                      , Kdll_Or   },
    { RID_IsLayerFormat    , Format_B10G10R10A2                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetParserState   , Parser_WriteOutput                      , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DestSurfIndex                    , Kdll_None },
    { RID_IsLayerFormat    , Format_PL2                              , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetParserState   , Parser_WriteOutput                      , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_DestSurfIndex                    , Kdll_None },
    { RID_SetParserState   , Parser_WriteOutput                      , Kdll_None },

    // Write

    // Colorfill only write rulesets has to be before regular rulesets.

    // Write ARGB with 64B save kernel
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444SCALE16_RGB_64Byte   , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write ARGB
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_RGB          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write RGB with 64B save kernel
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_X8R8G8B8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444SCALE16_RGB_64Byte   , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write RGB
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_X8R8G8B8                     , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_RGB          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write RGB16
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R5G6B5                       , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_RGB16        , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (R10G10B10A2 | B10G10R10A2) - With ColorFill. Note: R10G10B10A2 | B10G10R10A2 should be in front of Format_RGB32
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R10G10B10A2                  , Kdll_Or   },
    { RID_IsLayerFormat    , Format_B10G10R10A2                  , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_R10G10B10    , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write AYUV with legacy save kernel
    { RID_Op_NewEntry      , RULE_DEFAULT                          , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                    , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                    , Kdll_None },
    { RID_IsLayerFormat    , Format_AYUV                           , Kdll_None }, 
    { RID_IsLayerNumber    , 0                                     , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                        , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill   , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16           , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_VUYA           , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                            , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                       , Kdll_None },
    { RID_SetParserState   , Parser_End                            , Kdll_None },

    // Write (YUY2 | YUYV | YVYU | UYVY | VYUY)
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                      , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                      , Kdll_None },
    { RID_IsLayerFormat    , Format_YUY2                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YUYV                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YVYU                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_UYVY                             , Kdll_Or   },
    { RID_IsLayerFormat    , Format_VYUY                             , Kdll_None },
    { RID_IsLayerNumber    , 0                                       , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_PA               , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                              , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_End                              , Kdll_None },

    // Write NV21
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                      , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                      , Kdll_None },
    { RID_IsLayerFormat    , Format_NV21                             , Kdll_None },
    { RID_IsLayerNumber    , 0                                       , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_NV21             , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                              , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_End                              , Kdll_None },

    // Write NV12
    { RID_Op_NewEntry      , RULE_DEFAULT                            , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                      , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                      , Kdll_None },
    { RID_IsLayerFormat    , Format_PL2                              , Kdll_None },
    { RID_IsLayerNumber    , 0                                       , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16             , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Dest_Surf_Indexes_Primary    , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_NV12             , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                              , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                         , Kdll_None },
    { RID_SetParserState   , Parser_End                              , Kdll_None },

    // Write PL3
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_PL3                          , Kdll_None },
    { RID_IsLayerNumber    , 0                                   , Kdll_None },
    { RID_IsSrc0ColorFill  , ColorFill_True                      , Kdll_None },
    { RID_SetKernel        , IDR_VP_Set_Scale_Buf_0123_Colorfill , Kdll_None },
    { RID_SetKernel        , IDR_VP_Colorfill_444Scale16         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_PL3          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetSrc0ColorFill , ColorFill_False                     , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (ARGB | ABGR) with 64B save kernel - Shuffle Save,
    // Save_AVS_ARGB can write out ABGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_IsConstOutAlpha  , false                               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_ARGB_64Byte    , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_IsConstOutAlpha  , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_RGB_64Byte     , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (ARGB | ABGR) - Shuffle Save
    // Save_AVS_ARGB can write out ABGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_IsConstOutAlpha  , false                               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_ARGB           , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_IsConstOutAlpha  , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_RGB            , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (RGB | BGR) with 64B save kernel - Shuffle Save,
    // Save_AVS_RGB can write out BGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_X8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_X8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_RGB_64Byte     , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (RGB | BGR) - Shuffle Save
    // Save_AVS_RGB can write out BGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_X8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_X8B8G8R8                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_RGB            , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write RGB16 - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R5G6B5                       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_RGB16          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (R10G10B10A2 | B10G10R10A2) - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R10G10B10A2                  , Kdll_Or   },
    { RID_IsLayerFormat    , Format_B10G10R10A2                  , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_R10G10B10      , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write AYUV - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_AYUV                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_SrcAYUV        , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (YUY2 | YUYV | YVYU | UYVY | VYUY) - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_YUY2                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YUYV                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YVYU                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_UYVY                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_VYUY                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_PA             , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write NV21 - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_NV21                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_NV21           , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write NV12 - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_PL2                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_NV12           , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write PL3 - Shuffle Save
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsShuffling      , Shuffle_RenderTarget                , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_PL3                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444AVS16_PL3            , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (ARGB | ABGR) with 64B save kernel - Normal Save
    // Sample_8x8 not used or already shuffled
    // Save_ARGB can write out ABGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_IsConstOutAlpha  , false                               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444SCALE16_ARGB_64Byte  , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_IsConstOutAlpha  , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444SCALE16_RGB_64Byte   , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (ARGB | ABGR) - Normal Save
    // Sample_8x8 not used or already shuffled
    // Save_ARGB can write out ABGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_IsConstOutAlpha  , false                               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_ARGB         , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_A8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_A8B8G8R8                     , Kdll_None },
    { RID_IsConstOutAlpha  , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_RGB          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (RGB | BGR) with 64B save kernel - Normal Save
    // Sample_8x8 not used or already shuffled
    // Save_RGB can write out BGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_X8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_X8B8G8R8                     , Kdll_None },
    { RID_Is64BSaveEnabled , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444SCALE16_RGB_64Byte   , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (RGB | BGR) - Normal Save
    // Sample_8x8 not used or already shuffled
    // Save_RGB can write out BGR as well, based on CURBE settings.
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_X8R8G8B8                     , Kdll_Or   },
    { RID_IsLayerFormat    , Format_X8B8G8R8                     , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_RGB          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write RGB16 - Normal Save, Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R5G6B5                       , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_RGB16        , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (R10G10B10A2 | B10G10R10A2) - Normal Save
    // Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R10G10B10A2                  , Kdll_Or   },
    { RID_IsLayerFormat    , Format_B10G10R10A2                  , Kdll_None },
    { RID_IsConstOutAlpha  , false                               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_R10G10B10A2  , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_R10G10B10A2                  , Kdll_Or   },
    { RID_IsLayerFormat    , Format_B10G10R10A2                  , Kdll_None },
    { RID_IsConstOutAlpha  , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_R10G10B10    , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write AYUV - Normal Save, Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_AYUV                         , Kdll_None },
    { RID_IsConstOutAlpha  , false                               , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_SrcVUYA      , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_AYUV                         , Kdll_None },
    { RID_IsConstOutAlpha  , true                                , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_VUYA         , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write (YUY2 | YUYV | YVYU | UYVY | VYUY) - Normal Save, Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_YUY2                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YUYV                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_YVYU                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_UYVY                         , Kdll_Or   },
    { RID_IsLayerFormat    , Format_VYUY                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_PA           , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write NV21 - Normal Save, Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_NV21                         , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_NV21         , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write NV12 - Normal Save, Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_PL2                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_NV12         , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Write PL3 - Normal Save, Sample_8x8 not used or already shuffled
    { RID_Op_NewEntry      , RULE_DEFAULT                        , Kdll_None },
    { RID_IsParserState    , Parser_WriteOutput                  , Kdll_None },
    { RID_IsLayerID        , Layer_RenderTarget                  , Kdll_None },
    { RID_IsLayerFormat    , Format_PL3                          , Kdll_None },
    { RID_SetKernel        , IDR_VP_Save_444Scale16_PL3          , Kdll_None },
    { RID_SetKernel        , IDR_VP_EOT                          , Kdll_None },
    { RID_SetParserState   , Parser_End                          , Kdll_None },

    // Last entry

    { RID_Op_EOF           , 0                                   , Kdll_None }
};
