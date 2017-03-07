//
//  OCVLDA.h
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

#import "OCVInputArrayable.h"
#import "OCVMat.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Discriminant Analysis
 */
@interface OCVLDA : OCVObject

@property (nonatomic, readonly) OCVMat *eigenVectors;
@property (nonatomic, readonly) OCVMat *eigenValues;

- (instancetype)initWithNumberOfComponents:(NSInteger)numberOfComponents;
- (instancetype)initWithSource:(NSArray<OCVInputArrayable> *)source labels:(id<OCVInputArrayable>)labels;
- (instancetype)initWithSource:(NSArray<OCVInputArrayable> *)source labels:(id<OCVInputArrayable>)labels numberOfComponents:(NSInteger)numberOfComponents;

//
// TODO: Serializable implementation
//

- (void)computeWithSource:(NSArray<OCVInputArrayable> *)source labels:(id<OCVInputArrayable>)labels;

- (OCVMat *)projectWithSource:(id<OCVInputArrayable>)source;
- (OCVMat *)reconstructWithSource:(id<OCVInputArrayable>)source;

+ (OCVMat *)subspaceProjectWithW:(id<OCVInputArrayable>)w mean:(id<OCVInputArrayable>)mean source:(id<OCVInputArrayable>)source;
+ (OCVMat *)subspaceReconstructWithW:(id<OCVInputArrayable>)w mean:(id<OCVInputArrayable>)mean source:(id<OCVInputArrayable>)source;

@end

NS_ASSUME_NONNULL_END
