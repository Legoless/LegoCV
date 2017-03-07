//
//  OCVTypes.h
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVEdges.h"

typedef NS_ENUM(NSInteger, OCVDepthType) {
    OCVDepthTypeDefault = -1,
    OCVDepthTypeCv8U    = 0,
    OCVDepthTypeCv8S    = 1,
    OCVDepthTypeCv16U   = 2,
    OCVDepthTypeCv16S   = 3,
    OCVDepthTypeCv32S   = 4,
    OCVDepthTypeCv32F   = 5,
    OCVDepthTypeCv64F   = 6
};

#pragma mark - Types from base.hpp

/*!
 *  Reference type: cv::DecompTypes
 */
typedef NS_ENUM(NSInteger, OCVDecompositionType) {
    OCVDecompositionTypeLU       = 0,
    OCVDecompositionTypeSVD      = 1,
    OCVDecompositionTypeEIG      = 2,
    OCVDecompositionTypeCholesky = 3,
    OCVDecompositionTypeQR       = 4,
    OCVDecompositionTypeNormal   = 16
};

/*!
 *  Reference type: cv::BorderTypes
 */
typedef NS_ENUM(NSInteger, OCVBorderType) {
    OCVBorderTypeConstant    = 0, //!< `iiiiii|abcdefgh|iiiiiii`  with some specified `i`
    OCVBorderTypeReplicate   = 1, //!< `aaaaaa|abcdefgh|hhhhhhh`
    OCVBorderTypeReflect     = 2, //!< `fedcba|abcdefgh|hgfedcb`
    OCVBorderTypeWrap        = 3, //!< `cdefgh|abcdefgh|abcdefg`
    OCVBorderTypeReflect101  = 4, //!< `gfedcb|abcdefgh|gfedcba`
    OCVBorderTypeTransparent = 5, //!< `uvwxyz|absdefgh|ijklmno`
    OCVBorderTypeDefault     = OCVBorderTypeReflect101, //!< same as OCVBorderTypeReflect101
    OCVBorderTypeIsolated    = 16 //!< do not look outside of ROI
};

/*!
 *  Reference type: cv::NormTypes
 */
typedef NS_ENUM(NSInteger, OCVNormType) {
    OCVNormTypeINF       = 1,
    OCVNormTypeL1        = 2,
    OCVNormTypeL2        = 4,
    OCVNormTypeL2SQR     = 5,
    OCVNormTypeHamming   = 6,
    OCVNormTypeHamming2  = 7,
    OCVNormTypeMask      = 7,
    OCVNormTypeRelative  = 8, //!< flag
    OCVNormTypeMinMax    = 32 //!< flag
};

/*!
 *  Reference type: cv::CmpTypes
 */
typedef NS_ENUM(NSInteger, OCVCompareType) {
    OCVCompareTypeEqual             = 0, //!< src1 is equal to src2.
    OCVCompareTypeGreater           = 1, //!< src1 is greater than src2.
    OCVCompareTypeGreaterOrEqual    = 2, //!< src1 is greater than or equal to src2.
    OCVCompareTypeLess              = 3, //!< src1 is less than src2.
    OCVCompareTypeLessOrEqual       = 4, //!< src1 is less than or equal to src2.
    OCVCompareTypeNotEqual          = 5  //!< src1 is unequal to src2.
};

/*!
 *  Reference type: cv::GemmFlags
 */
typedef NS_OPTIONS(NSInteger, OCVGemmFlags) {
    OCVGemmFlag1T = 1, //!< transposes src1
    OCVGemmFlag2T = 2, //!< transposes src2
    OCVGemmFlag3T = 4  //!< transposes src3
};

/*!
 *  Reference type: cv::DftFlags
 */
typedef NS_OPTIONS(NSInteger, OCVTransformFlags) {
    OCVTransformInverse        = 1,
    OCVTransformScale          = 2,
    OCVTransformRows           = 4,
    OCVTransformComplexOutput  = 16,
    OCVTransformRealOutput     = 32,
};

#pragma mark - Types from core.hpp

/*!
 *  Reference type: cv::KmeansFlags
 */
typedef NS_OPTIONS(NSInteger, OCVKMeansTypes) {
    OCVKMeansTypeRandomCenters = 0,
    OCVKMeansPPCenters         = 2,
    OCVKMeansUseInitialLabels  = 1
};

/*!
 *  Reference type: cv::LineTypes
 */
typedef NS_ENUM(NSInteger, OCVLineType) {
    OCVLineTypeFilled = -1,
    OCVLineTypeLine4  = 4, //!< 4-connected line
    OCVLineTypeLine8  = 8, //!< 8-connected line
    OCVLineTypeLineAA = 16 //!< antialiased line
};

/*!
 *  Reference type: cv::HersheyFonts
 */
typedef NS_ENUM(NSInteger, OCVHersheyFont) {
    OCVHersheyFontSimplex        = 0, //!< normal size sans-serif font
    OCVHersheyFontPlain          = 1, //!< small size sans-serif font
    OCVHersheyFontDuplex         = 2, //!< normal size sans-serif font (more complex than FONT_HERSHEY_SIMPLEX)
    OCVHersheyFontComplex        = 3, //!< normal size serif font
    OCVHersheyFontTriplex        = 4, //!< normal size serif font (more complex than FONT_HERSHEY_COMPLEX)
    OCVHersheyFontComplexSmall   = 5, //!< smaller version of FONT_HERSHEY_COMPLEX
    OCVHersheyFontScriptSimplex  = 6, //!< hand-writing style font
    OCVHersheyFontScriptComplex  = 7, //!< more complex variant of FONT_HERSHEY_SCRIPT_SIMPLEX
    OCVHersheyFontItalic         = 16 //!< flag for italic font
};

/*!
 *  Reference type: cv::ReduceTypes
 */
typedef NS_ENUM(NSInteger, OCVReduceType) {
    OCVReduceTypeSum = 0, //!< the output is the sum of all rows/columns of the matrix.
    OCVReduceTypeAvg = 1, //!< the output is the mean vector of all rows/columns of the matrix.
    OCVReduceTypeMax = 2, //!< the output is the maximum (column/row-wise) of all rows/columns of the matrix.
    OCVReduceTypeMin = 3  //!< the output is the minimum (column/row-wise) of all rows/columns of the matrix.
};

/*!
 *  Reference type: core.hpp cv::flip() function codes
 */
typedef NS_ENUM(NSInteger, OCVFlipCode) {
    OCVFlipCodeXAxis = 0,
    OCVFlipCodeYAxis = 1,
    OCVFlipCodeBoth = -1
};

/*!
 *  Reference type: cv::RotateFlags
 */
typedef NS_OPTIONS(NSInteger, OCVRotationTypes) {
    OCVRotationType90Clockwise            = 0, //Rotate 90 degrees clockwise
    OCVRotationType180                    = 1, //Rotate 180 degrees clockwise
    OCVRotationType90CounterClockwise     = 2, //Rotate 270 degrees clockwise
};

/*!
 *  Reference type: cv::SortFlags
 */
typedef NS_OPTIONS(NSInteger, OCVSortTypes) {
    OCVSortTypeEveryRow     = 0, //!< each matrix row is sorted independently
    OCVSortTypeEveryColumn  = 1, //!< each matrix column is sorted
    //!< independently; this flag and the previous one are
    //!< mutually exclusive.
    OCVSortTypeAscending    = 0, //!< each matrix row is sorted in the ascending
    //!< order.
    OCVSortTypeDescending   = 16 //!< each matrix row is sorted in the
    //!< descending order; this flag and the previous one are also
    //!< mutually exclusive.
};

/*!
 *  Reference type: cv::CovarFlags
 */
typedef NS_OPTIONS(NSInteger, OCVCovarTypes) {
    OCVCovarTypeScrambled = 0,
    OCVCovarTypeNormal    = 1,
    OCVCovarTypeUseAvg    = 2,
    OCVCovarTypeScale     = 4,
    OCVCovarTypeRows      = 8,
    OCVCovarTypeCols      = 16
};

