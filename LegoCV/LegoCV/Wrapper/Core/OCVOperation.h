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
+ (void)addWeightedSource:(id<OCVInputArrayable>)source1 withAlpha:(double)alpha withSource:(id<OCVInputArrayable>)source2 withBeta:(double)beta withGamma:(double)gamma toDestination:(id<OCVOutputArrayable>)destination;
+ (void)addWeightedSource:(id<OCVInputArrayable>)source1 withAlpha:(double)alpha withSource:(id<OCVInputArrayable>)source2 withBeta:(double)beta withGamma:(double)gamma toDestination:(id<OCVOutputArrayable>)destination ofDepthType:(NSInteger)depthType;

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

@end
