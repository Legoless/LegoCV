//
//  OCVSVD.h
//  LegoCV
//
//  Created by Dal Rupnik on 06/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

#import "OCVInputArrayable.h"
#import "OCVOutputArrayable.h"

#import "OCVMat.h"

/*!
 *  Reference type: cv::PCA Flags
 */
typedef NS_OPTIONS(NSInteger, OCVSVDFlags) {
    OCVSVDModifyA = 0,
    OCVSVDNoUV    = 1,
    OCVSVDFullUV  = 4
};

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Singular Value Decomposition
 */
@interface OCVSVD : OCVObject

@property (nonatomic, strong) OCVMat* u;
@property (nonatomic, strong) OCVMat* w;
@property (nonatomic, strong) OCVMat* vt;

- (instancetype)initWithSource:(id<OCVInputArrayable>)source;
- (instancetype)initWithSource:(id<OCVInputArrayable>)source flags:(OCVSVDFlags)flags;

- (OCVSVD *)performWithSource:(id<OCVInputArrayable>)source;
- (OCVSVD *)performWithSource:(id<OCVInputArrayable>)source flags:(OCVSVDFlags)flags;

+ (void)computeWithSource:(id<OCVInputArrayable>)source w:(id<OCVInputArrayable>)w u:(id<OCVOutputArrayable>)u vt:(id<OCVOutputArrayable>)vt;
+ (void)computeWithSource:(id<OCVInputArrayable>)source w:(id<OCVInputArrayable>)w u:(id<OCVOutputArrayable>)u vt:(id<OCVOutputArrayable>)vt flags:(OCVSVDFlags)flags;

+ (void)computeWithSource:(id<OCVInputArrayable>)source w:(id<OCVOutputArrayable>)w;
+ (void)computeWithSource:(id<OCVInputArrayable>)source w:(id<OCVOutputArrayable>)w flags:(OCVSVDFlags)flags;

+ (void)backSubstitutionWithW:(id<OCVInputArrayable>)w u:(id<OCVInputArrayable>)u vt:(id<OCVInputArrayable>)vt rightHandSide:(id<OCVInputArrayable>)rightHandSide toDestination:(id<OCVOutputArrayable>)destination;

+ (void)solveZWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;

+ (void)backSubstitutionWithRightHandSide:(id<OCVInputArrayable>)rightHandSide toDestination:(id<OCVOutputArrayable>)destination;

@end

NS_ASSUME_NONNULL_END
