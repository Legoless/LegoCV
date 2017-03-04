//
//  OCVColorConversionType.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#ifndef OCVColorConversionType_h
#define OCVColorConversionType_h

typedef NS_ENUM(NSInteger, OCVColorConversionType) {
    OCVColorConversionTypeBGR2BGRA    =0,
    OCVColorConversionTypeRGB2RGBA    =OCVColorConversionTypeBGR2BGRA,
    
    OCVColorConversionTypeBGRA2BGR    =1,
    OCVColorConversionTypeRGBA2RGB    =OCVColorConversionTypeBGRA2BGR,
    
    OCVColorConversionTypeBGR2RGBA    =2,
    OCVColorConversionTypeRGB2BGRA    =OCVColorConversionTypeBGR2RGBA,
    
    OCVColorConversionTypeRGBA2BGR    =3,
    OCVColorConversionTypeBGRA2RGB    =OCVColorConversionTypeRGBA2BGR,
    
    OCVColorConversionTypeBGR2RGB     =4,
    OCVColorConversionTypeRGB2BGR     =OCVColorConversionTypeBGR2RGB,
    
    OCVColorConversionTypeBGRA2RGBA   =5,
    OCVColorConversionTypeRGBA2BGRA   =OCVColorConversionTypeBGRA2RGBA,
    
    OCVColorConversionTypeBGR2GRAY    =6,
    OCVColorConversionTypeRGB2GRAY    =7,
    OCVColorConversionTypeGRAY2BGR    =8,
    OCVColorConversionTypeGRAY2RGB    =OCVColorConversionTypeGRAY2BGR,
    OCVColorConversionTypeGRAY2BGRA   =9,
    OCVColorConversionTypeGRAY2RGBA   =OCVColorConversionTypeGRAY2BGRA,
    OCVColorConversionTypeBGRA2GRAY   =10,
    OCVColorConversionTypeRGBA2GRAY   =11,
    
    OCVColorConversionTypeBGR2BGR565  =12,
    OCVColorConversionTypeRGB2BGR565  =13,
    OCVColorConversionTypeBGR5652BGR  =14,
    OCVColorConversionTypeBGR5652RGB  =15,
    OCVColorConversionTypeBGRA2BGR565 =16,
    OCVColorConversionTypeRGBA2BGR565 =17,
    OCVColorConversionTypeBGR5652BGRA =18,
    OCVColorConversionTypeBGR5652RGBA =19,
    
    OCVColorConversionTypeGRAY2BGR565 =20,
    OCVColorConversionTypeBGR5652GRAY =21,
    
    OCVColorConversionTypeBGR2BGR555  =22,
    OCVColorConversionTypeRGB2BGR555  =23,
    OCVColorConversionTypeBGR5552BGR  =24,
    OCVColorConversionTypeBGR5552RGB  =25,
    OCVColorConversionTypeBGRA2BGR555 =26,
    OCVColorConversionTypeRGBA2BGR555 =27,
    OCVColorConversionTypeBGR5552BGRA =28,
    OCVColorConversionTypeBGR5552RGBA =29,
    
    OCVColorConversionTypeGRAY2BGR555 =30,
    OCVColorConversionTypeBGR5552GRAY =31,
    
    OCVColorConversionTypeBGR2XYZ     =32,
    OCVColorConversionTypeRGB2XYZ     =33,
    OCVColorConversionTypeXYZ2BGR     =34,
    OCVColorConversionTypeXYZ2RGB     =35,
    
    OCVColorConversionTypeBGR2YCrCb   =36,
    OCVColorConversionTypeRGB2YCrCb   =37,
    OCVColorConversionTypeYCrCb2BGR   =38,
    OCVColorConversionTypeYCrCb2RGB   =39,
    
    OCVColorConversionTypeBGR2HSV     =40,
    OCVColorConversionTypeRGB2HSV     =41,
    
    OCVColorConversionTypeBGR2Lab     =44,
    OCVColorConversionTypeRGB2Lab     =45,
    
    OCVColorConversionTypeBayerBG2BGR =46,
    OCVColorConversionTypeBayerGB2BGR =47,
    OCVColorConversionTypeBayerRG2BGR =48,
    OCVColorConversionTypeBayerGR2BGR =49,
    
    OCVColorConversionTypeBayerBG2RGB =OCVColorConversionTypeBayerRG2BGR,
    OCVColorConversionTypeBayerGB2RGB =OCVColorConversionTypeBayerGR2BGR,
    OCVColorConversionTypeBayerRG2RGB =OCVColorConversionTypeBayerBG2BGR,
    OCVColorConversionTypeBayerGR2RGB =OCVColorConversionTypeBayerGB2BGR,
    
    OCVColorConversionTypeBGR2Luv     =50,
    OCVColorConversionTypeRGB2Luv     =51,
    OCVColorConversionTypeBGR2HLS     =52,
    OCVColorConversionTypeRGB2HLS     =53,
    
    OCVColorConversionTypeHSV2BGR     =54,
    OCVColorConversionTypeHSV2RGB     =55,
    
    OCVColorConversionTypeLab2BGR     =56,
    OCVColorConversionTypeLab2RGB     =57,
    OCVColorConversionTypeLuv2BGR     =58,
    OCVColorConversionTypeLuv2RGB     =59,
    OCVColorConversionTypeHLS2BGR     =60,
    OCVColorConversionTypeHLS2RGB     =61,
    
    OCVColorConversionTypeBayerBG2BGR_VNG =62,
    OCVColorConversionTypeBayerGB2BGR_VNG =63,
    OCVColorConversionTypeBayerRG2BGR_VNG =64,
    OCVColorConversionTypeBayerGR2BGR_VNG =65,
    
    OCVColorConversionTypeBayerBG2RGB_VNG =OCVColorConversionTypeBayerRG2BGR_VNG,
    OCVColorConversionTypeBayerGB2RGB_VNG =OCVColorConversionTypeBayerGR2BGR_VNG,
    OCVColorConversionTypeBayerRG2RGB_VNG =OCVColorConversionTypeBayerBG2BGR_VNG,
    OCVColorConversionTypeBayerGR2RGB_VNG =OCVColorConversionTypeBayerGB2BGR_VNG,
    
    OCVColorConversionTypeBGR2HSV_FULL = 66,
    OCVColorConversionTypeRGB2HSV_FULL = 67,
    OCVColorConversionTypeBGR2HLS_FULL = 68,
    OCVColorConversionTypeRGB2HLS_FULL = 69,
    
    OCVColorConversionTypeHSV2BGR_FULL = 70,
    OCVColorConversionTypeHSV2RGB_FULL = 71,
    OCVColorConversionTypeHLS2BGR_FULL = 72,
    OCVColorConversionTypeHLS2RGB_FULL = 73,
    
    OCVColorConversionTypeLBGR2Lab     = 74,
    OCVColorConversionTypeLRGB2Lab     = 75,
    OCVColorConversionTypeLBGR2Luv     = 76,
    OCVColorConversionTypeLRGB2Luv     = 77,
    
    OCVColorConversionTypeLab2LBGR     = 78,
    OCVColorConversionTypeLab2LRGB     = 79,
    OCVColorConversionTypeLuv2LBGR     = 80,
    OCVColorConversionTypeLuv2LRGB     = 81,
    
    OCVColorConversionTypeBGR2YUV      = 82,
    OCVColorConversionTypeRGB2YUV      = 83,
    OCVColorConversionTypeYUV2BGR      = 84,
    OCVColorConversionTypeYUV2RGB      = 85,
    
    OCVColorConversionTypeBayerBG2GRAY = 86,
    OCVColorConversionTypeBayerGB2GRAY = 87,
    OCVColorConversionTypeBayerRG2GRAY = 88,
    OCVColorConversionTypeBayerGR2GRAY = 89,
    
    //YUV 4:2:0 formats family
    OCVColorConversionTypeYUV2RGB_NV12 = 90,
    OCVColorConversionTypeYUV2BGR_NV12 = 91,
    OCVColorConversionTypeYUV2RGB_NV21 = 92,
    OCVColorConversionTypeYUV2BGR_NV21 = 93,
    OCVColorConversionTypeYUV420sp2RGB = OCVColorConversionTypeYUV2RGB_NV21,
    OCVColorConversionTypeYUV420sp2BGR = OCVColorConversionTypeYUV2BGR_NV21,
    
    OCVColorConversionTypeYUV2RGBA_NV12 = 94,
    OCVColorConversionTypeYUV2BGRA_NV12 = 95,
    OCVColorConversionTypeYUV2RGBA_NV21 = 96,
    OCVColorConversionTypeYUV2BGRA_NV21 = 97,
    OCVColorConversionTypeYUV420sp2RGBA = OCVColorConversionTypeYUV2RGBA_NV21,
    OCVColorConversionTypeYUV420sp2BGRA = OCVColorConversionTypeYUV2BGRA_NV21,
    
    OCVColorConversionTypeYUV2RGB_YV12 = 98,
    OCVColorConversionTypeYUV2BGR_YV12 = 99,
    OCVColorConversionTypeYUV2RGB_IYUV = 100,
    OCVColorConversionTypeYUV2BGR_IYUV = 101,
    OCVColorConversionTypeYUV2RGB_I420 = OCVColorConversionTypeYUV2RGB_IYUV,
    OCVColorConversionTypeYUV2BGR_I420 = OCVColorConversionTypeYUV2BGR_IYUV,
    OCVColorConversionTypeYUV420p2RGB = OCVColorConversionTypeYUV2RGB_YV12,
    OCVColorConversionTypeYUV420p2BGR = OCVColorConversionTypeYUV2BGR_YV12,
    
    OCVColorConversionTypeYUV2RGBA_YV12 = 102,
    OCVColorConversionTypeYUV2BGRA_YV12 = 103,
    OCVColorConversionTypeYUV2RGBA_IYUV = 104,
    OCVColorConversionTypeYUV2BGRA_IYUV = 105,
    OCVColorConversionTypeYUV2RGBA_I420 = OCVColorConversionTypeYUV2RGBA_IYUV,
    OCVColorConversionTypeYUV2BGRA_I420 = OCVColorConversionTypeYUV2BGRA_IYUV,
    OCVColorConversionTypeYUV420p2RGBA = OCVColorConversionTypeYUV2RGBA_YV12,
    OCVColorConversionTypeYUV420p2BGRA = OCVColorConversionTypeYUV2BGRA_YV12,
    
    OCVColorConversionTypeYUV2GRAY_420 = 106,
    OCVColorConversionTypeYUV2GRAY_NV21 = OCVColorConversionTypeYUV2GRAY_420,
    OCVColorConversionTypeYUV2GRAY_NV12 = OCVColorConversionTypeYUV2GRAY_420,
    OCVColorConversionTypeYUV2GRAY_YV12 = OCVColorConversionTypeYUV2GRAY_420,
    OCVColorConversionTypeYUV2GRAY_IYUV = OCVColorConversionTypeYUV2GRAY_420,
    OCVColorConversionTypeYUV2GRAY_I420 = OCVColorConversionTypeYUV2GRAY_420,
    OCVColorConversionTypeYUV420sp2GRAY = OCVColorConversionTypeYUV2GRAY_420,
    OCVColorConversionTypeYUV420p2GRAY = OCVColorConversionTypeYUV2GRAY_420,
    
    //YUV 4:2:2 formats family
    OCVColorConversionTypeYUV2RGB_UYVY = 107,
    OCVColorConversionTypeYUV2BGR_UYVY = 108,
    //OCVColorConversionTypeYUV2RGB_VYUY = 109,
    //OCVColorConversionTypeYUV2BGR_VYUY = 110,
    OCVColorConversionTypeYUV2RGB_Y422 = OCVColorConversionTypeYUV2RGB_UYVY,
    OCVColorConversionTypeYUV2BGR_Y422 = OCVColorConversionTypeYUV2BGR_UYVY,
    OCVColorConversionTypeYUV2RGB_UYNV = OCVColorConversionTypeYUV2RGB_UYVY,
    OCVColorConversionTypeYUV2BGR_UYNV = OCVColorConversionTypeYUV2BGR_UYVY,
    
    OCVColorConversionTypeYUV2RGBA_UYVY = 111,
    OCVColorConversionTypeYUV2BGRA_UYVY = 112,
    //OCVColorConversionTypeYUV2RGBA_VYUY = 113,
    //OCVColorConversionTypeYUV2BGRA_VYUY = 114,
    OCVColorConversionTypeYUV2RGBA_Y422 = OCVColorConversionTypeYUV2RGBA_UYVY,
    OCVColorConversionTypeYUV2BGRA_Y422 = OCVColorConversionTypeYUV2BGRA_UYVY,
    OCVColorConversionTypeYUV2RGBA_UYNV = OCVColorConversionTypeYUV2RGBA_UYVY,
    OCVColorConversionTypeYUV2BGRA_UYNV = OCVColorConversionTypeYUV2BGRA_UYVY,
    
    OCVColorConversionTypeYUV2RGB_YUY2 = 115,
    OCVColorConversionTypeYUV2BGR_YUY2 = 116,
    OCVColorConversionTypeYUV2RGB_YVYU = 117,
    OCVColorConversionTypeYUV2BGR_YVYU = 118,
    OCVColorConversionTypeYUV2RGB_YUYV = OCVColorConversionTypeYUV2RGB_YUY2,
    OCVColorConversionTypeYUV2BGR_YUYV = OCVColorConversionTypeYUV2BGR_YUY2,
    OCVColorConversionTypeYUV2RGB_YUNV = OCVColorConversionTypeYUV2RGB_YUY2,
    OCVColorConversionTypeYUV2BGR_YUNV = OCVColorConversionTypeYUV2BGR_YUY2,
    
    OCVColorConversionTypeYUV2RGBA_YUY2 = 119,
    OCVColorConversionTypeYUV2BGRA_YUY2 = 120,
    OCVColorConversionTypeYUV2RGBA_YVYU = 121,
    OCVColorConversionTypeYUV2BGRA_YVYU = 122,
    OCVColorConversionTypeYUV2RGBA_YUYV = OCVColorConversionTypeYUV2RGBA_YUY2,
    OCVColorConversionTypeYUV2BGRA_YUYV = OCVColorConversionTypeYUV2BGRA_YUY2,
    OCVColorConversionTypeYUV2RGBA_YUNV = OCVColorConversionTypeYUV2RGBA_YUY2,
    OCVColorConversionTypeYUV2BGRA_YUNV = OCVColorConversionTypeYUV2BGRA_YUY2,
    
    OCVColorConversionTypeYUV2GRAY_UYVY = 123,
    OCVColorConversionTypeYUV2GRAY_YUY2 = 124,
    //OCVColorConversionTypeYUV2GRAY_VYUY = OCVColorConversionTypeYUV2GRAY_UYVY,
    OCVColorConversionTypeYUV2GRAY_Y422 = OCVColorConversionTypeYUV2GRAY_UYVY,
    OCVColorConversionTypeYUV2GRAY_UYNV = OCVColorConversionTypeYUV2GRAY_UYVY,
    OCVColorConversionTypeYUV2GRAY_YVYU = OCVColorConversionTypeYUV2GRAY_YUY2,
    OCVColorConversionTypeYUV2GRAY_YUYV = OCVColorConversionTypeYUV2GRAY_YUY2,
    OCVColorConversionTypeYUV2GRAY_YUNV = OCVColorConversionTypeYUV2GRAY_YUY2,
    
    // alpha premultiplication
    OCVColorConversionTypeRGBA2mRGBA = 125,
    OCVColorConversionTypemRGBA2RGBA = 126,
    
    OCVColorConversionTypeRGB2YUV_I420 = 127,
    OCVColorConversionTypeBGR2YUV_I420 = 128,
    OCVColorConversionTypeRGB2YUV_IYUV = OCVColorConversionTypeRGB2YUV_I420,
    OCVColorConversionTypeBGR2YUV_IYUV = OCVColorConversionTypeBGR2YUV_I420,
    
    OCVColorConversionTypeRGBA2YUV_I420 = 129,
    OCVColorConversionTypeBGRA2YUV_I420 = 130,
    OCVColorConversionTypeRGBA2YUV_IYUV = OCVColorConversionTypeRGBA2YUV_I420,
    OCVColorConversionTypeBGRA2YUV_IYUV = OCVColorConversionTypeBGRA2YUV_I420,
    OCVColorConversionTypeRGB2YUV_YV12  = 131,
    OCVColorConversionTypeBGR2YUV_YV12  = 132,
    OCVColorConversionTypeRGBA2YUV_YV12 = 133,
    OCVColorConversionTypeBGRA2YUV_YV12 = 134,
    
    OCVColorConversionTypeCOLORCVT_MAX  = 135
};

#endif /* OCVColorConversionType_h */
