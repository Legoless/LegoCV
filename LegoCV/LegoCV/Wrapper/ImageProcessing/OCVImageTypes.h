//
//  OCVImageTypes.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#ifndef OCVImageTypes_h
#define OCVImageTypes_h

/*!
 *  Reference type: cv::DistanceTypes
 */
typedef NS_ENUM(NSInteger, OCVDistanceType) {
    OCVDistanceTypeUser    = -1,  //!< User defined distance
    OCVDistanceTypeL1      = 1,   //!< distance = |x1-x2| + |y1-y2|
    OCVDistanceTypeL2      = 2,   //!< the simple euclidean distance
    OCVDistanceTypeC       = 3,   //!< distance = max(|x1-x2|,|y1-y2|)
    OCVDistanceTypeL12     = 4,   //!< L1-L2 metric: distance = 2(sqrt(1+x*x/2) - 1))
    OCVDistanceTypeFair    = 5,   //!< distance = c^2(|x|/c-log(1+|x|/c)), c = 1.3998
    OCVDistanceTypeWelsch  = 6,   //!< distance = c^2/2(1-exp(-(x/c)^2)), c = 2.9846
    OCVDistanceTypeHubar   = 7    //!< distance = |x|<c ? x^2/2 : c(|x|-c/2), c=1.345
};

/*!
 *  Reference type: cv::DistanceTransformMasks
 */
typedef NS_OPTIONS(NSInteger, OCVDistanceTransformMasks) {
    OCVDistanceTransformMask3       = 3, //!< mask=3
    OCVDistanceTransformMask5       = 5, //!< mask=5
    OCVDistanceTransformMaskPrecise = 0  //!<
};

/*!
 *  Reference type: cv::ThresholdTypes
 */
typedef NS_ENUM(NSInteger, OCVThresholdType) {
    OCVThresholdTypeBinary          = 0,
    OCVThresholdTypeBinaryInverse   = 1,
    OCVThresholdTypeTruncate        = 2,
    OCVThresholdTypeToZero          = 3,
    OCVThresholdTypeToZeroInverse   = 4,
    OCVThresholdTypeMask            = 7,
    OCVThresholdTypeOtsu            = 8, //!< flag, use Otsu algorithm to choose the optimal threshold value
    OCVThresholdTypeTriangle        = 16 //!< flag, use Triangle algorithm to choose the optimal threshold value
};

/*!
 *  Reference type: cv::AdaptiveThresholdTypes
 */
typedef NS_ENUM(NSInteger, OCVAdaptiveThresholdType) {
    OCVAdaptiveThresholdTypeMeanC     = 0,
    OCVAdaptiveThresholdTypeGaussianC = 1
};

/*!
 *  Reference type: cv::UndistortTypes
 */
typedef NS_ENUM(NSInteger, OCVUndistortType) {
    OCVUndistortTypeProjectionSphericalOrthogonal     = 0,
    OCVUndistortTypeProjectionSphericalEqualRectangle = 1
};

/*!
 *  Reference type: cv::GrabCutClasses
 */
typedef NS_ENUM(NSInteger, OCVGrabCutClassType) {
    OCVGrabCutClassTypeBackground           = 0,  //!< an obvious background pixels
    OCVGrabCutClassTypeForeground           = 1,  //!< an obvious foreground (object) pixel
    OCVGrabCutClassTypePossibleBackground   = 2,  //!< a possible background pixel
    OCVGrabCutClassTypePossibleForeground   = 3   //!< a possible foreground pixel
};

/*!
 *  Reference type: cv::GrabCutModes
 */
typedef NS_ENUM(NSInteger, OCVGrabCutMode) {
    OCVGrabCutModeInitWithRect  = 0,
    OCVGrabCutModeInitWithMask  = 1,
    OCVGrabCutModeEval          = 2
};

/*!
 *  Reference type: cv::DistanceTransformLabelTypes
 */
typedef NS_ENUM(NSInteger, OCVDistanceTransformLabelType) {
    OCVDistanceTransformLabelTypeConnectedComponent = 0,
    OCVDistanceTransformLabelTypePixel              = 1
};

/*!
 *  Reference type: cv::FloodFillFlags
 */
typedef NS_ENUM(NSInteger, OCVFloodFillFlags) {
    OCVFloodFillFlagFixedRange      = 1 << 16,
    OCVFloodFillFlagsMaskOnly       = 1 << 17
};




#endif /* OCVImageTypes_h */
