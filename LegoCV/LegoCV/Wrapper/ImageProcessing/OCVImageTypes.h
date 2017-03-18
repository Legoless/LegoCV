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
 *  Reference type: cv::MorphTypes
 */
typedef NS_ENUM(NSInteger, OCVMorphType) {
    OCVMorphTypeErode      = 0,
    OCVMorphTypeDilate     = 1,
    OCVMorphTypeOpen       = 2,
    OCVMorphTypeClose      = 3,
    OCVMorphTypeGradient   = 4,
    OCVMorphTypeTopHat     = 5,
    OCVMorphTypeBlackHat   = 6,
    OCVMorphTypeHitOrMiss  = 7
};

/*!
 *  Reference type: cv::MorphShapes
 */
typedef NS_ENUM(NSInteger, OCVMorphShape) {
    OCVMorphShapeRect    = 0,
    OCVMorphShapeCross   = 1,
    OCVMorphShapeEllipse = 2
};


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
typedef NS_OPTIONS(NSInteger, OCVFloodFillFlags) {
    OCVFloodFillFlagFixedRange      = 1 << 16,
    OCVFloodFillFlagsMaskOnly       = 1 << 17
};

/*!
 *  Reference type: cv::ConnectedComponentsTypes
 */
typedef NS_ENUM(NSInteger, OCVConnectedComponentType) {
    OCVConnectedComponentTypeLeft   = 0, //!< The leftmost (x) coordinate which is the inclusive start of the bounding
    //!< box in the horizontal direction.
    OCVConnectedComponentTypeTop    = 1, //!< The topmost (y) coordinate which is the inclusive start of the bounding
    //!< box in the vertical direction.
    OCVConnectedComponentTypeWidth  = 2, //!< The horizontal size of the bounding box
    OCVConnectedComponentTypeHeight = 3, //!< The vertical size of the bounding box
    OCVConnectedComponentTypeArea   = 4, //!< The total area (in pixels) of the connected component
    OCVConnectedComponentTypeMax    = 5
};

/*!
 *  Reference type: cv::ConnectedComponentsAlgorithmsTypes
 */
typedef NS_ENUM(NSInteger, OCVConnectedComponentAlgorithmType) {
    OCVConnectedComponentAlgorithmTypeWu      = 0,  //!< SAUF algorithm for 8-way connectivity, SAUF algorithm for 4-way connectivity
    OCVConnectedComponentAlgorithmTypeDefault = -1, //!< BBDT algortihm for 8-way connectivity, SAUF algorithm for 4-way connectivity
    OCVConnectedComponentAlgorithmTypeGrana   = 1   //!< BBDT algorithm for 8-way connectivity, SAUF algorithm for 4-way connectivity
};

/*!
 *  Reference type: cv::RetrievalModes
 */
typedef NS_ENUM(NSInteger, OCVRetrievalMode) {
    OCVRetrievalModeExternal                = 0,
    OCVRetrievalModeList                    = 1,
    OCVRetrievalModeConnectedComponent      = 2,
    OCVRetrievalModeTree                    = 3,
    OCVRetrievalModeFloodFill               = 4
};

/*!
 *  Reference type: cv::ContourApproximationModes
 */
typedef NS_ENUM(NSInteger, OCVContourApproximationMode) {
    OCVContourApproximationModeNone         = 1,
    /** compresses horizontal, vertical, and diagonal segments and leaves only their end points.
     For example, an up-right rectangular contour is encoded with 4 points. */
    OCVContourApproximationModeSimple       = 2,
    /** applies one of the flavors of the Teh-Chin chain approximation algorithm @cite TehChin89 */
    OCVContourApproximationModeTC89L1       = 3,
    /** applies one of the flavors of the Teh-Chin chain approximation algorithm @cite TehChin89 */
    OCVContourApproximationModeC89KCOS      = 4
};

/*!
 *  Reference type: cv::HoughModes
 */
typedef NS_ENUM(NSInteger, OCVHoughMode) {
    OCVHoughModeStandard      = 0,
    OCVHoughModeProbabilistic = 1,
    OCVHoughModeMultiScale    = 2,
    OCVHoughModeGradient      = 3
};

/*!
 *  Reference type: cv::LineSegmentDetectorModes
 */
typedef NS_ENUM(NSInteger, OCVLineSegmentDetectorMode) {
    OCVLineSegmentDetectorModeNone          = 0, //!< No refinement applied
    OCVLineSegmentDetectorModeStandard      = 1, //!< Standard refinement is applied. E.g. breaking arches into smaller straighter line approximations.
    OCVLineSegmentDetectorModeAdvanced      = 2  //!< Advanced refinement. Number of false alarms is calculated, lines are
    //!< refined through increase of precision, decrement in size, etc.
};

/*!
 *  Reference type: cv::HistCompMethods
 */
typedef NS_ENUM(NSInteger, OCVHistogramComparisonMethodType) {
    OCVHistogramComparisonMethodTypeCorrelation             = 0,
    OCVHistogramComparisonMethodTypeChiSquare               = 1,
    OCVHistogramComparisonMethodTypeIntersection            = 2,
    OCVHistogramComparisonMethodTypeBhattacharyya           = 3,
    OCVHistogramComparisonMethodTypeHellinger               = OCVHistogramComparisonMethodTypeBhattacharyya,
    OCVHistogramComparisonMethodTypeChiSquareAlternative    = 4,
    OCVHistogramComparisonMethodTypeKullbackLeibler         = 5
};

/*!
 *  Reference type: cv::RectanglesIntersectTypes
 */
typedef NS_ENUM(NSInteger, OCVRectangleIntersectType) {
    OCVRectangleIntersectTypeNone       = 0, //!< No intersection
    OCVRectangleIntersectTypePartial    = 1, //!< There is a partial intersection
    OCVRectangleIntersectTypeFull       = 2 //!< One of the rectangle is fully enclosed in the other
};


#endif /* OCVImageTypes_h */
