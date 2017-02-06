//
//  OCVVideoCamera.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera+Private.h"
#import "OCVMatDataAllocator+Private.h"
#import "OCVMat.h"

#import "OCVVideoCamera.h"

@interface OCVVideoCamera () <CvVideoCameraDelegate>

@property (nonatomic, readonly) CvVideoCamera *cameraSource;

@end

@implementation OCVVideoCamera

- (CvVideoCamera *)cameraSource {
    return (CvVideoCamera *)self.source;
}

#pragma mark - Public Properties

- (void)setDelegate:(id<OCVVideoCameraDelegate>)delegate {
    _delegate = delegate;
    
    self.cameraSource.delegate = self;
}

- (BOOL)grayscaleMode {
    return self.cameraSource.grayscaleMode;
}

- (void)setGrayscaleMode:(BOOL)grayscaleMode {
    self.cameraSource.grayscaleMode = grayscaleMode;
}

- (BOOL)recordVideo {
    return self.cameraSource.recordVideo;
}

- (void)setRecordVideo:(BOOL)recordVideo {
    self.cameraSource.recordVideo = recordVideo;
}

- (BOOL)rotateVideo {
    return self.cameraSource.rotateVideo;
}

- (void)setRotateVideo:(BOOL)rotateVideo {
    self.cameraSource.rotateVideo = rotateVideo;
}

- (AVAssetWriterInput *)recordAssetWriterInput {
    return self.cameraSource.recordAssetWriterInput;
}

- (void)setRecordAssetWriterInput:(AVAssetWriterInput *)recordAssetWriterInput {
    self.cameraSource.recordAssetWriterInput = recordAssetWriterInput;
}

- (AVAssetWriterInputPixelBufferAdaptor *)recordPixelBufferAdaptor {
    return self.cameraSource.recordPixelBufferAdaptor;
}

- (void)setRecordPixelBufferAdaptor:(AVAssetWriterInputPixelBufferAdaptor *)recordPixelBufferAdaptor {
    self.cameraSource.recordPixelBufferAdaptor = recordPixelBufferAdaptor;
}

- (AVAssetWriter *)recordAssetWriter {
    return self.cameraSource.recordAssetWriter;
}

- (void)setRecordAssetWriter:(AVAssetWriter *)recordAssetWriter {
    self.cameraSource.recordAssetWriter = recordAssetWriter;
}

#pragma mark - Initialization

- (instancetype)initWithParentView:(UIView *)parent {
    self = [super initWithObject:[[CvVideoCamera alloc] initWithParentView:parent]];
    
    return self;
}

#pragma mark - Public Methods

- (void)adjustLayoutToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    [self.cameraSource adjustLayoutToInterfaceOrientation:interfaceOrientation];
}

- (void)layoutPreviewLayer {
    [self.cameraSource layoutPreviewLayer];
}

- (void)saveVideo {
    [self.cameraSource saveVideo];
}

- (NSURL *)videoFileURL {
    return [self.cameraSource videoFileURL];
}

- (NSString *)videoFileString {
    return [self.cameraSource videoFileString];
}

#pragma mark - CvVideoCameraDelegate

- (void)processImage:(cv::Mat &)image {
    [self.delegate processImage:[[OCVMat alloc] initWithMatInstance:&image]];
}

@end
