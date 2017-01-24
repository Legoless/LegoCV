//
//  OCVMat.mm
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core/core.hpp>

#import "OCVMat.h"

@interface OCVMat () {
    cv::Mat source;
}

@end

@implementation OCVMat

#pragma mark - Public Properties

- (NSInteger)rows {
    return source.rows;
}

- (NSInteger)cols {
    return source.cols;
}

- (cv::Mat)source {
    return source;
}

#pragma mark - Initialization

- (instancetype)init {
    [NSException raise:@"InitNotImplemented" format:@"Use another initializer instead of default one."];
    
    return nil;
}

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols {
    return [self initWithRows:rows cols:cols type:OCVDepthTypeCv8U channels:4];
}

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols type:(OCVDepthType)type channels:(NSInteger)channels {
    self = [super init];
    
    if (self) {
        // Convert type to OpenCV type
        int cvType = (int)CV_MAKETYPE(type, channels);
        
        self->source = cv::Mat((int)rows, (int)cols, cvType);
    }
    
    return self;
}

- (instancetype)initWithMatInstance:(cv::Mat)mat {
    self = [super init];
    
    if (self) {
        self->source = cv::Mat(mat);
    }
    
    return self;
}

#pragma mark - Convenience Initialization

- (instancetype)initWithMat:(OCVMat *)mat {
    cv::Mat sourceMat = mat.source;
    
    return [self initWithMatInstance:sourceMat];
}

- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)buffer {
    cv::Mat mat = [self.class matFromBuffer:buffer];
    
    return [self initWithMatInstance:mat];
}

- (instancetype)initWithImage:(UIImage *)image {
    cv::Mat mat = [self.class matFromImage:image];
    
    return [self initWithMatInstance:mat];
}

- (instancetype)initWithImageRef:(CGImageRef)imageRef {
    cv::Mat mat = [self.class matFromImageRef:imageRef];
    
    return [self initWithMatInstance:mat];
}

- (instancetype)initWithCGSize:(CGSize)size {
    return [self initWithCGSize:size type:OCVDepthTypeCv8U channels:4];
}

- (instancetype)initWithCGSize:(CGSize)size type:(OCVDepthType)type channels:(NSInteger)channels {
    return [self initWithRows:(NSInteger)size.width cols:(NSInteger)size.height type:type channels:channels];
}

#pragma mark - Public Methods

- (OCVMat *)clone {
    cv::Mat mat = source.clone();
    
    return [[OCVMat alloc] initWithMatInstance:mat];
}

- (CGImageRef)imageRef {
    return [self.class imageRefFromMat:self->source];
}

- (UIImage *)image {
    CGImageRef imageRef = [self imageRef];
    
    return [UIImage imageWithCGImage:imageRef];
}

#pragma mark - Private Utility Methods

+ (cv::Mat)matFromImageRef:(CGImageRef)imageRef {
    CGColorSpaceRef colorSpace = CGImageGetColorSpace(imageRef);
    size_t cols = CGImageGetWidth(imageRef);
    size_t rows = CGImageGetHeight(imageRef);
    
    cv::Mat cvMat((int)rows, (int)cols, CV_8UC4);
    
    CGContextRef contextRef = CGBitmapContextCreate(
                                                    cvMat.data,                 // Pointer to  data
                                                    cols,                       // Width of bitmap
                                                    rows,                       // Height of bitmap
                                                    8,                          // Bits per component
                                                    cvMat.step[0],              // Bytes per row
                                                    colorSpace,                 // Colorspace
                                                    kCGImageAlphaNoneSkipLast|kCGBitmapByteOrderDefault // Bitmap info flags
                                                    );
    
    CGContextDrawImage(contextRef, CGRectMake(0, 0, cols, rows), imageRef);
    CGContextRelease(contextRef);
    CGColorSpaceRelease(colorSpace);
    
    return cvMat;
}


+ (cv::Mat)matFromImage:(UIImage *)image {
    CGColorSpaceRef colorSpace = CGImageGetColorSpace(image.CGImage);
    CGFloat cols = image.size.width;
    CGFloat rows = image.size.height;
    
    cv::Mat cvMat(rows, cols, CV_8UC4);
    
    CGContextRef contextRef = CGBitmapContextCreate(
                                                    cvMat.data,                 // Pointer to  data
                                                    cols,                       // Width of bitmap
                                                    rows,                       // Height of bitmap
                                                    8,                          // Bits per component
                                                    cvMat.step[0],              // Bytes per row
                                                    colorSpace,                 // Colorspace
                                                    kCGImageAlphaNoneSkipLast|kCGBitmapByteOrderDefault // Bitmap info flags
                                                    );
    
    CGContextDrawImage(contextRef, CGRectMake(0, 0, cols, rows), image.CGImage);
    CGContextRelease(contextRef);
    CGColorSpaceRelease(colorSpace);
    
    return cvMat;
}

+ (cv::Mat)matFromBuffer:(CVPixelBufferRef)buffer {
    size_t cols = CVPixelBufferGetWidth(buffer);
    size_t rows = CVPixelBufferGetHeight(buffer);
    
    cv::Mat cvMat((int)rows, (int)cols, CV_8UC4); // 8 bits per component, 4 channels (color channels + alpha)
    
    CVPixelBufferLockBaseAddress(buffer, 0);
    
    void *baseAddress = CVPixelBufferGetBaseAddress(buffer);
    
    size_t dataSize = CVPixelBufferGetDataSize(buffer);
    
    size_t targetDataSize = rows * cols * 4;
    
    if (dataSize >= targetDataSize) {
        std::memcpy(cvMat.data, baseAddress, targetDataSize);
    }
    
    CVPixelBufferUnlockBaseAddress(buffer, 0);
    
    return cvMat;
}


+ (CGImageRef)imageRefFromMat:(cv::Mat)cvMat {
    
    NSData *data = [NSData dataWithBytes:cvMat.data length:cvMat.elemSize()*cvMat.total()];
    
    CGColorSpaceRef colorSpace;
    CGBitmapInfo bitmapInfo;
    
    if (cvMat.elemSize() == 1) {
        colorSpace = CGColorSpaceCreateDeviceGray();
        bitmapInfo = kCGImageAlphaNone | kCGBitmapByteOrderDefault;
    }
    else {
        colorSpace = CGColorSpaceCreateDeviceRGB();
        bitmapInfo = kCGImageAlphaLast | kCGBitmapByteOrderDefault;
    }
    
    CGDataProviderRef provider = CGDataProviderCreateWithCFData((__bridge CFDataRef)data);
    
    CGImageRef imageRef = CGImageCreate(
                                        cvMat.cols,                 //width
                                        cvMat.rows,                 //height
                                        8,                          //bits per component
                                        8 * cvMat.elemSize(),       //bits per pixel
                                        cvMat.step[0],              //bytesPerRow
                                        colorSpace,                 //colorspace
                                        bitmapInfo,                 // bitmap info
                                        provider,                   //CGDataProviderRef
                                        NULL,                       //decode
                                        false,                      //should interpolate
                                        kCGRenderingIntentDefault   //intent
                                        );
    
    CGDataProviderRelease(provider);
    CGColorSpaceRelease(colorSpace);
    
    return imageRef;
}

@end
