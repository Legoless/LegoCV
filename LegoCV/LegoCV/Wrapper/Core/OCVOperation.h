//
//  OCVOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
#import "OCVInputArrayable.h"
#import "OCVOutputArrayable.h"
#import "OCVInputOutputArrayable.h"

#import "OCVGeometry.h"
#import "OCVTypes.h"

#import "OCVUMat.h"
#import "OCVSparseMat.h"

#import "OCVMinimumMaximum.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Wraps operations defined in core.hpp
 */
@interface OCVOperation : OCVObject

+ (void)swapMat:(OCVMat *)a toMat:(OCVMat *)b;
+ (void)swapUMat:(OCVUMat *)a toUMat:(OCVUMat *)b;

+ (NSInteger)borderInterpolateWithPixel:(NSInteger)pixel ofLength:(NSInteger)length withBorderType:(OCVBorderType)borderType;

/*!
 *  cv::copyMakeBorder()
 */
+ (OCVScalar)copyMakeBorderFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withTop:(NSInteger)top withBottom:(NSInteger)bottom withLeft:(NSInteger)left withRight:(NSInteger)right withBorderType:(OCVBorderType)borderType;

/*!
 *  cv::copyMakeBorder() - Convenience method with custom struct
 */
+ (OCVScalar)copyMakeBorderFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withEdges:(OCVEdges)edges withBorderType:(OCVBorderType)borderType;

#pragma mark - Basic operations

/*!
 *  cv::add()
 */
+ (void)addSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)addSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask;
+ (void)addSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask ofDepthType:(NSInteger)depthType;

/*!
 *  cv::subtract()
 */
+ (void)subtractSource:(id<OCVInputArrayable>)source1 fromSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)subtractSource:(id<OCVInputArrayable>)source1 fromSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask;
+ (void)subtractSource:(id<OCVInputArrayable>)source1 fromSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask ofDepthType:(NSInteger)depthType;

/*!
 *  cv::multiply()
 */
+ (void)multiplySource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)multiplySource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withScale:(double)scale;
+ (void)multiplySource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withScale:(double)scale ofDepthType:(NSInteger)depthType;

/*!
 *  cv::divide()
 */
+ (void)divideSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)divideSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withScale:(double)scale;
+ (void)divideSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withScale:(double)scale ofDepthType:(NSInteger)depthType;

+ (void)divideScale:(double)scale withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)divideScale:(double)scale withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType;

/*!
 *  cv::scaleAdd()
 */
+ (void)scaleAddSource:(id<OCVInputArrayable>)source1 withAlpha:(double)alpha withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;

/*!
 *  cv::addWeighted()
 */
+ (void)addWeightedSource:(id<OCVInputArrayable>)source1 withAlpha:(double)alpha withSource:(id<OCVInputArrayable>)source2 withBeta:(double)beta withGamma:(double)gamma toDestination:(id<OCVOutputArrayable>)destination;
+ (void)addWeightedSource:(id<OCVInputArrayable>)source1 withAlpha:(double)alpha withSource:(id<OCVInputArrayable>)source2 withBeta:(double)beta withGamma:(double)gamma toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType;

/*!
 *  cv::convertScaleAbs()
 */
+ (void)convertScaleAbsoluteWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;
+ (void)convertScaleAbsoluteWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withAlpha:(double)alpha;
+ (void)convertScaleAbsoluteWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withAlpha:(double)alpha withBeta:(double)beta;

/*!
 *  cv::convertFp16()
 */
+ (void)convertFp16Source:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;

/*!
 *  cv::LUT()
 */
+ (void)lookupTableTransformWithSource:(id<OCVInputArrayable>)source withLookupTable:(id<OCVInputArrayable>)lookupTable toDestination:(id<OCVOutputArrayable>)destination;

/*!
 *  cv::sum()
 */
+ (OCVScalar)sumOfSource:(id<OCVInputArrayable>)source;

/*!
 *  cv::countNonZero()
 */
+ (NSInteger)countNonZeroInSource:(id<OCVInputArrayable>)source;

/*!
 *  cv::findNonZero()
 */
+ (void)findNonZeroInSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;

/*!
 *  cv::mean()
 */
+ (OCVScalar)meanOfSource:(id<OCVInputArrayable>)source;
+ (OCVScalar)meanOfSource:(id<OCVInputArrayable>)source withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::meanStdDev()
 */
+ (void)meanStandardDeviationOfSource:(id<OCVInputArrayable>)source withMean:(id<OCVOutputArrayable>)mean withStandardDeviation:(id<OCVOutputArrayable>)standardDeviation;
+ (void)meanStandardDeviationOfSource:(id<OCVInputArrayable>)source withMean:(id<OCVOutputArrayable>)mean withStandardDeviation:(id<OCVOutputArrayable>)standardDeviation withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::norm()
 */
+ (double)normOfSource:(id<OCVInputArrayable>)source;
+ (double)normOfSource:(id<OCVInputArrayable>)source withType:(OCVNormType)normType;
+ (double)normOfSource:(id<OCVInputArrayable>)source withType:(OCVNormType)normType withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::PSNR()
 */
+ (double)PSNROfSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2;

/*!
 *  cv::batchDistance()
 */
+ (void)batchDistanceOfSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType toIndex:(id<OCVOutputArrayable>)index;
+ (void)batchDistanceOfSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType toIndex:(id<OCVOutputArrayable>)index withNormType:(OCVNormType)normType;
+ (void)batchDistanceOfSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType toIndex:(id<OCVOutputArrayable>)index withNormType:(OCVNormType)normType withK:(NSInteger)k;
+ (void)batchDistanceOfSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType toIndex:(id<OCVOutputArrayable>)index withNormType:(OCVNormType)normType withK:(NSInteger)k withMask:(id<OCVInputArrayable>)mask;
+ (void)batchDistanceOfSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType toIndex:(id<OCVOutputArrayable>)index withNormType:(OCVNormType)normType withK:(NSInteger)k withMask:(id<OCVInputArrayable>)mask withUpdate:(NSInteger)update;
+ (void)batchDistanceOfSource:(id<OCVInputArrayable>)source1 toSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType toIndex:(id<OCVOutputArrayable>)index withNormType:(OCVNormType)normType withK:(NSInteger)k withMask:(id<OCVInputArrayable>)mask withUpdate:(NSInteger)update withCrosscheck:(BOOL)crosscheck;

/*!
 *  cv::normalize()
 */
+ (void)normalizeWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVInputOutputArrayable>)destination;
+ (void)normalizeWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVInputOutputArrayable>)destination withAlpha:(double)alpha;
+ (void)normalizeWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVInputOutputArrayable>)destination withAlpha:(double)alpha withBeta:(double)beta;
+ (void)normalizeWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVInputOutputArrayable>)destination withAlpha:(double)alpha withBeta:(double)beta withNormType:(OCVNormType)normType;
+ (void)normalizeWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVInputOutputArrayable>)destination withAlpha:(double)alpha withBeta:(double)beta withNormType:(OCVNormType)normType ofDepthType:(NSInteger)depthType;
+ (void)normalizeWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVInputOutputArrayable>)destination withAlpha:(double)alpha withBeta:(double)beta withNormType:(OCVNormType)normType ofDepthType:(NSInteger)depthType withMask:(id<OCVInputArrayable>)mask;

+ (void)normalizeWithSource:(OCVSparseMat *)source toDestination:(OCVSparseMat *)destination withAlpha:(double)alpha withNormType:(OCVNormType)normType;

/*!
 *  cv::minMaxLoc()
 */
+ (void)minimumMaximumLocationInSource:(id<OCVInputArrayable>)source withMinValue:(double *)minValue withMaxValue:(double *)maxValue withMinLocation:(OCVPoint *)minLocation withMaxLocation:(OCVPoint *)maxLocation withMask:(id<OCVInputArrayable>)mask;

+ (void)minimumMaximumLocationInSource:(OCVSparseMat *)mat withMinValue:(double *)minValue withMaxValue:(double *)maxValue withMinIndex:(NSInteger *)minIndex withMaxIndex:(NSInteger *)maxIndex;

// Convenience of LegoCV
+ (OCVMinimumMaximumLocation *)minimumMaximumLocationInSource:(id<OCVInputArrayable>)source;
+ (OCVMinimumMaximumLocation *)minimumMaximumLocationInSource:(id<OCVInputArrayable>)source withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::minMaxIdx()
 */
+ (void)minimumMaximumIndexInSource:(id<OCVInputArrayable>)source withMinValue:(double *)minValue withMaxValue:(double *)maxValue  withMaxValue:(double *)maxValue withMinIndex:(NSInteger *)minIndex withMaxIndex:(NSInteger *)maxIndex withMask:(id<OCVInputArrayable>)mask;

// Convenience of LegoCV
+ (OCVMinimumMaximumIndex *)minimumMaximumIndexInSource:(id<OCVInputArrayable>)source;
+ (OCVMinimumMaximumIndex *)minimumMaximumIndexInSource:(id<OCVInputArrayable>)source withMask:(id<OCVInputArrayable>)mask;

@end

NS_ASSUME_NONNULL_END
