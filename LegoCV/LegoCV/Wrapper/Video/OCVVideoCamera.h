//
//  OCVVideoCamera.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

#import "OCVCamera.h"
#import "OCVMat.h"

@protocol OCVVideoCameraDelegate <NSObject>

- (void)processImage:(OCVMat *)image;

@end

@interface OCVVideoCamera : OCVCamera

@property (nonatomic, strong) AVCaptureVideoDataOutput* videoDataOutput;
@property (nonatomic, strong) dispatch_queue_t videoDataOutputQueue;
@property (nonatomic, strong) CALayer *customPreviewLayer;
@property (nonatomic, assign) CMTime lastSampleTime;

@property (nonatomic, weak) id<OCVVideoCameraDelegate> delegate;
@property (nonatomic, assign) BOOL grayscaleMode;

@property (nonatomic, assign) BOOL recordVideo;
@property (nonatomic, assign) BOOL rotateVideo;
@property (nonatomic, strong) AVAssetWriterInput* recordAssetWriterInput;
@property (nonatomic, strong) AVAssetWriterInputPixelBufferAdaptor* recordPixelBufferAdaptor;
@property (nonatomic, strong) AVAssetWriter* recordAssetWriter;

- (void)adjustLayoutToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (void)layoutPreviewLayer;
- (void)saveVideo;
- (NSURL *)videoFileURL;
- (NSString *)videoFileString;

@end
