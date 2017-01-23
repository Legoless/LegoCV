//
//  OCVCamera.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera.h"
#import "OCVCamera+Private.h"

@implementation OCVCamera

#pragma mark - Private Properties

- (CvAbstractCamera *)source {
    return (CvAbstractCamera *)self.object;
}

#pragma mark - Public Properties

- (AVCaptureSession *)captureSession {
    return self.source.captureSession;
}

- (void)setCaptureSession:(AVCaptureSession *)captureSession {
    self.source.captureSession = captureSession;
}

- (AVCaptureConnection *)videoCaptureConnection {
    return self.source.videoCaptureConnection;
}

- (void)setVideoCaptureConnection:(AVCaptureConnection *)videoCaptureConnection {
    self.source.videoCaptureConnection = videoCaptureConnection;
}

- (BOOL)running {
    return self.source.running;
}

- (BOOL)captureSessionLoaded {
    return self.source.captureSessionLoaded;
}

- (int)defaultFPS {
    return self.source.defaultFPS;
}

- (void)setDefaultFPS:(int)defaultFPS {
    self.source.defaultFPS = defaultFPS;
}

- (AVCaptureVideoPreviewLayer *)captureVideoPreviewLayer {
    return self.source.captureVideoPreviewLayer;
}

- (AVCaptureDevicePosition)defaultAVCaptureDevicePosition {
    return self.source.defaultAVCaptureDevicePosition;
}

- (void)setDefaultAVCaptureDevicePosition:(AVCaptureDevicePosition)defaultAVCaptureDevicePosition {
    self.source.defaultAVCaptureDevicePosition = defaultAVCaptureDevicePosition;
}

- (AVCaptureVideoOrientation)defaultAVCaptureVideoOrientation {
    return self.source.defaultAVCaptureVideoOrientation;
}

- (void)setDefaultAVCaptureVideoOrientation:(AVCaptureVideoOrientation)defaultAVCaptureVideoOrientation {
    self.source.defaultAVCaptureVideoOrientation = defaultAVCaptureVideoOrientation;
}

- (BOOL)useAVCaptureVideoPreviewLayer {
    return self.source.useAVCaptureVideoPreviewLayer;
}

- (void)setUseAVCaptureVideoPreviewLayer:(BOOL)useAVCaptureVideoPreviewLayer {
    self.source.useAVCaptureVideoPreviewLayer = useAVCaptureVideoPreviewLayer;
}

- (NSString *)defaultAVCaptureSessionPreset {
    return self.source.defaultAVCaptureSessionPreset;
}

- (void)setDefaultAVCaptureSessionPreset:(NSString *)defaultAVCaptureSessionPreset {
    self.source.defaultAVCaptureSessionPreset = defaultAVCaptureSessionPreset;
}

- (int)imageWidth {
    return self.source.imageWidth;
}

- (void)setImageWidth:(int)imageWidth {
    self.source.imageWidth = imageWidth;
}

- (int)imageHeight {
    return self.source.imageHeight;
}

- (void)setImageHeight:(int)imageHeight {
    self.source.imageHeight = imageHeight;
}

- (UIView *)parentView {
    return self.source.parentView;
}

- (void)setParentView:(UIView *)parentView {
    self.source.parentView = parentView;
}

#pragma mark - Initialization

- (instancetype)initWithParentView:(UIView *)parent {
    [NSException raise:@"InitNotImplemented" format:@"This method is abstract and is not implemented."];
    
    return nil;
}

#pragma mark - Public Methods

- (void)start {
    [self.source start];
}

- (void)stop {
    [self.source stop];
}

- (void)switchCameras {
    [self.source switchCameras];
}

- (void)createCaptureOutput {
    [self.source createCaptureOutput];
}

- (void)createVideoPreviewLayer {
    [self.source createVideoPreviewLayer];
}

- (void)updateOrientation {
    [self.source updateOrientation];
}

- (void)lockFocus {
    [self.source lockFocus];
}
- (void)unlockFocus {
    [self.source unlockFocus];
}
- (void)lockExposure {
    [self.source lockExposure];
}
- (void)unlockExposure {
    [self.source unlockExposure];
}
- (void)lockBalance {
    [self.source lockBalance];
}
- (void)unlockBalance {
    [self.source unlockBalance];
}

@end
