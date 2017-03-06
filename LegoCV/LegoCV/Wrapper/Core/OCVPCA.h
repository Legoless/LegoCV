//
//  OCVPCA.h
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
typedef NS_OPTIONS(NSInteger, OCVPCAFlags) {
    OCVPCAFlagDataAsRow             = 0, //!< indicates that the input samples are stored as matrix rows
    OCVPCAFlagDataAsColumn          = 1, //!< indicates that the input samples are stored as matrix columns
    OCVPCAFlagUseAvg                = 2
};

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Principal Component Analysis
 */
@interface OCVPCA : OCVObject

@property (nonatomic, readonly) OCVMat* eigenVectors;
@property (nonatomic, readonly) OCVMat* eigenValues;
@property (nonatomic, readonly) OCVMat* mean;

#pragma mark - Initialization

- (instancetype)initWithData:(id<OCVInputArrayable>)data mean:(id<OCVInputArrayable>)mean flags:(OCVPCAFlags)flags maxComponents:(NSInteger)maxComponents;
- (instancetype)initWithData:(id<OCVInputArrayable>)data mean:(id<OCVInputArrayable>)mean flags:(OCVPCAFlags)flags retainedVariance:(double)retainedVariance;

#pragma mark - Public Methods

- (OCVPCA *)performWithData:(id<OCVInputArrayable>)data mean:(id<OCVInputArrayable>)mean flags:(OCVPCAFlags)flags maxComponents:(NSInteger)maxComponents;
- (OCVPCA *)performWithData:(id<OCVInputArrayable>)data mean:(id<OCVInputArrayable>)mean flags:(OCVPCAFlags)flags retainedVariance:(double)retainedVariance;

- (OCVMat *)projectWithVector:(id<OCVInputArrayable>)vector;
- (void)projectWithVector:(id<OCVInputArrayable>)vector toDestination:(id<OCVOutputArrayable>)destination;

- (OCVMat *)backProjectWithVector:(id<OCVInputArrayable>)vector;
- (void)backProjectWithVector:(id<OCVInputArrayable>)vector toDestination:(id<OCVOutputArrayable>)destination;

//
// TODO: Implement OCV FileStorage and OCV FileNode, for serialization
//
- (void)writeToPath:(NSString *)path;
- (void)loadFrompath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
