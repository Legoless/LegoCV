//
//  OCVInterpolationType.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#ifndef OCVInterpolationType_h
#define OCVInterpolationType_h

/*!
 *  Reference type: cv::InterpolationFlags
 */
typedef NS_OPTIONS(NSInteger, OCVInterpolationType) {
    OCVInterpolationTypeNearest             = 0,
    OCVInterpolationTypeLinear              = 1,
    OCVInterpolationTypeCubic               = 2,
    OCVInterpolationTypeArea                = 3,
    OCVInterpolationTypeLanczos4            = 4,
    OCVInterpolationTypeMax                 = 7,
    OCVInterpolationTypeWarpFillOutliers    = 8,
    OCVInterpolationTypeWarpInverseMap      = 9
};

/*!
 *  Reference type: cv::InterpolationMasks
 */
typedef NS_OPTIONS(NSInteger, OCVInterpolationMasks) {
    OCVInterpolationMaskBits      = 5,
    OCVInterpolationMaskBits2     = OCVInterpolationMaskBits * 2,
    OCVInterpolationMaskTabSize   = 1 << OCVInterpolationMaskBits,
    OCVInterpolationMaskTabSize2  = OCVInterpolationMaskTabSize * OCVInterpolationMaskTabSize
};


#endif /* OCVInterpolationType_h */
