//
//  OCVBitwiseOperation.h
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
 *  Wraps bitwise operations defined in core.hpp
 */
@interface OCVBitwiseOperation : OCVObject

/*!
 *  cv::bitwise_and()
 */
+ (void)bitwiseAndWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)bitwiseAndWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::bitwise_or()
 */
+ (void)bitwiseOrWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)bitwiseOrWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::bitwise_xor()
 */
+ (void)bitwiseXorWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination;
+ (void)bitwiseXorWithSource:(id<OCVInputArrayable>)source1 withSource:(id<OCVInputArrayable>)source2 toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask;

/*!
 *  cv::bitwise_not()
 */
+ (void)bitwiseNotWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;
+ (void)bitwiseNotWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withMask:(id<OCVInputArrayable>)mask;

@end

NS_ASSUME_NONNULL_END
