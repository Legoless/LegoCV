//
//  OCVVideoCamera.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

#import "OCVCamera.h"

@class OCVMat;

NS_ASSUME_NONNULL_BEGIN

@protocol OCVVideoCameraDelegate <NSObject>

- (void)processImage:(OCVMat *)image;

@end

@interface OCVVideoCamera : OCVCamera

@property (nullable, nonatomic, weak) id<OCVVideoCameraDelegate> delegate;
@property (nonatomic, assign) BOOL grayscaleMode;

@property (nonatomic, assign) BOOL recordVideo;
@property (nonatomic, assign) BOOL rotateVideo;
@property (nullable, nonatomic, strong) AVAssetWriterInput* recordAssetWriterInput;
@property (nullable, nonatomic, strong) AVAssetWriterInputPixelBufferAdaptor* recordPixelBufferAdaptor;
@property (nullable, nonatomic, strong) AVAssetWriter* recordAssetWriter;

- (void)adjustLayoutToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (void)layoutPreviewLayer;
- (void)saveVideo;
- (NSURL * _Nullable)videoFileURL;
- (NSString * _Nullable)videoFileString;

@end

NS_ASSUME_NONNULL_END
