//
//  OCVBaseCascadeClassifier.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVPointerObject.h"
#import "OCVArrayables.h"
#import "OCVSize.h"
#import "OCVRect.h"

#import "OCVCascadeClassifierResult.h"
#import "OCVCascadeClassifierOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface OCVMaskGenerator : OCVObject

- (instancetype)initWithSource:(OCVMat *)source;
- (OCVMat *)generateMaskWithSource:(OCVMat *)source;

@end


@interface OCVBaseCascadeClassifier : OCVPointerObject

@property (nonatomic, readonly) BOOL isEmpty;
@property (nonatomic, readonly) NSInteger featureType;

@property (nullable, nonatomic, strong) OCVMaskGenerator *maskGenerator;

@property (nonatomic, readonly) BOOL isOldFormatCascade;
@property (nonatomic, readonly) OCVSize originalWindowSize;

- (instancetype)initWithURL:(NSURL *)url;
- (instancetype)initWithPath:(NSString *)path;

/*!
 *  Needs to be absolute path to the XML model for classifier: Bundle.main.bundlePath + relativePath
 */
- (void)loadPath:(NSString *)path;
- (void)loadURL:(NSURL *)url;

//
// TODO: Add Swift wrapper method to return OCVRect directly.
//
- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor;
- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours;
- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags;
- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags minSize:(OCVSize)minSize;
- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags minSize:(OCVSize)minSize maxSize:(OCVSize)maxSize;

/*!
 *  Objective wrapper call by specifying options.
 */
- (OCVCascadeClassifierResult *)detectMultiScaleOnImage:(id<OCVInputArrayable>)image;
- (OCVCascadeClassifierResult *)detectMultiScaleOnImage:(id<OCVInputArrayable>)image withOptions:(OCVCascadeClassifierOptions *)options;

@end

NS_ASSUME_NONNULL_END
