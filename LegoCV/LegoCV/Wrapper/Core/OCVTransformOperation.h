//
//  OCVTransformOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 04/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//


#import "OCVObject.h"
#import "OCVInputArrayable.h"
#import "OCVOutputArrayable.h"
#import "OCVInputOutputArrayable.h"

#import "OCVGeometry.h"
#import "OCVTypes.h"

#import "OCVVector.h"
#import "OCVUMat.h"
#import "OCVSparseMat.h"

#import "OCVMinimumMaximum.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Wraps transform operations defined in core.hpp such as DFT and DCT
 */
@interface OCVTransformOperation : OCVObject

/*!
 *  cv::dft()
 */
+ (BOOL)dftWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destinatio;
+ (BOOL)dftWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags;
+ (BOOL)dftWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags nonZeroRows:(NSInteger)nonZeroRows;

/*!
 *  cv::idft()
 */
+ (BOOL)idftWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destinatio;
+ (BOOL)idftWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags;
+ (BOOL)idftWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags nonZeroRows:(NSInteger)nonZeroRows;

/*!
 *  cv::dct()
 */
+ (BOOL)dctWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destinatio;
+ (BOOL)dctWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags;
+ (BOOL)dctWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags nonZeroRows:(NSInteger)nonZeroRows;

/*!
 *  cv::idct()
 */
+ (BOOL)idctWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destinatio;
+ (BOOL)idctWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags;
+ (BOOL)idctWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags nonZeroRows:(NSInteger)nonZeroRows;

/*!
 *  cv::mulSpectrums()
 */
+ (BOOL)multiplySpectrumsWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destinatio;
+ (BOOL)multiplySpectrumsWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags;
+ (BOOL)multiplySpectrumsWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination flags:(OCVTransformFlags)flags conjugateSecond:(BOOL)conjugateSecond;

/*!
 *  cv::getOptimalDFTSize()
 */
+ (NSInteger)optimalDFTSizeForVectorSize:(NSInteger)vectorSize;

@end

NS_ASSUME_NONNULL_END
