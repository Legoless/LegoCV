//
//  OCVMat.h
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCVTypes.h"
#import "OCVSize.h"
#import "OCVMatExpr.h"
#import "OCVInputArray.h"

/*!
 *  OCVMat is a simple Objective-C wrapper around cv::Mat instance.
 */
@interface OCVMat : NSObject

//
// MARK: Public Properties
//

@property (nonatomic, readonly) NSInteger rows;
@property (nonatomic, readonly) NSInteger cols;

@property (nonatomic, readonly) NSInteger dims;

@property (nonatomic, readonly) BOOL isSubmatrix;
@property (nonatomic, readonly) BOOL isContinuous;

@property (nonatomic, readonly) BOOL isEmpty;
@property (nonatomic, readonly) NSInteger total;

@property (nonatomic, readonly) NSInteger elemSize;
@property (nonatomic, readonly) NSInteger elemSize1;
@property (nonatomic, readonly) OCVChannelType type;

@property (nonatomic, readonly) NSInteger depth;
@property (nonatomic, readonly) NSInteger channels;

//
// MARK: Initialization
//

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols type:(OCVChannelType)type;
- (instancetype)initWithSize:(OCVSize *)size type:(NSInteger)type;
- (instancetype)initWithMat:(OCVMat *)mat;

//
// MARK: Public Methods
//


//
// MARK: Operations
//

- (OCVMat *)reshapeWithChannels:(NSInteger)cn;
- (OCVMat *)reshapeWithChannels:(NSInteger)cn rows:(NSInteger)rows;

- (OCVMatExpr *)t;

- (OCVMatExpr *)inv;
- (OCVMatExpr *)invWithMethod:(NSInteger)method;

- (OCVMatExpr *)mulWithArray:(OCVInputArray *)inputArray;
- (OCVMatExpr *)mulWithArray:(OCVInputArray *)inputArray scale:(double)scale;

- (OCVMat *)crossWithArray:(OCVInputArray *)inputArray;

- (double)dotWithArray:(OCVInputArray *)inputArray;

//
// MARK: Factory Methods
//

+ (instancetype)zerosWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
+ (instancetype)zerosWithSize:(OCVSize *)size type:(NSInteger)type;

+ (instancetype)onesWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
+ (instancetype)onesWithSize:(OCVSize *)size type:(NSInteger)type;

@end

//
// MARK: UIKit / CoreGraphics Extensions
//

#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>

@interface OCVMat (UIKit)

- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithImageRef:(CGImageRef)imageRef;
- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)buffer;

/*!
 *  Construct image reference and returns it
 */
- (CGImageRef)imageRef;
- (UIImage *)image;

@end

//
// MARK: Unavailable in Swift, convenience for OpenCV, should be private
//

#import <opencv2/core/mat.hpp>
#import <CoreVideo/CoreVideo.h>

@interface OCVMat (OpenCV)

@property (nonatomic, readonly) cv::Mat source;

- (instancetype)initWithMatInstance:(cv::Mat)mat;


@end
