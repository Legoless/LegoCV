//
//  OCVMat.mm
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVGeometry+Private.h"
#import "OCVMatDataAllocator+Private.h"
#import "OCVInputArray+Private.h"
#import "OCVOutputArray.h"
#import "OCVInputOutputArray.h"

#import "OCVMat.h"

@interface OCVMat ()

// A reference to output array proxy, to guarantee a single one is passed.
@property (nonatomic, strong) OCVInputOutputArray* inputOutput;

@end

@implementation OCVMat

#pragma mark - Private Properties

#pragma mark - Public Properties
- (BOOL)isSubmatrix {
    return self.source->isSubmatrix();
}

- (NSInteger)rows {
    return self.source->rows;
}

- (NSInteger)cols {
    return self.source->cols;
}

- (NSInteger)channels {
    return self.source->channels();
}

- (OCVDepthType)type {
    return (OCVDepthType)self.source->depth();
}

- (OCVSize)size {
    return convertSize(self.source->size());
}

- (NSString *)description {
    return [NSString stringWithFormat:@"OCVMat: [%ld, %ld], channels: %ld, type: %ld]", (long)self.rows, (long)self.cols, (long)self.channels, (long)self.type];
}

#pragma mark - Initialization

- (instancetype)init {
    return [super initWithMatInstance:new cv::Mat()];
}

- (instancetype)initWithSize:(OCVSize)size type:(OCVDepthType)type channels:(NSInteger)channels {
    return [self initWithRows:size.height cols:size.width type:type channels:channels];
}

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols {
    return [self initWithRows:rows cols:cols type:OCVDepthTypeCv8U channels:4];
}

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols type:(OCVDepthType)type channels:(NSInteger)channels {
    // Convert type to OpenCV type
    int cvType = (int)CV_MAKETYPE(type, channels);

    return [super initWithMatInstance:new cv::Mat((int)rows, (int)cols, cvType)];
}

#pragma mark - Convenience Initialization

- (instancetype)initWithMat:(OCVMat *)mat {
    cv::Mat *matSource = new cv::Mat(mat.source->clone());
    
    return [self initWithMatInstance:matSource];
}

- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)buffer {
    cv::Mat mat = [self.class matFromBuffer:buffer];
    
    return [self initWithMatInstance:&mat];
}

- (instancetype)initWithImage:(UIImage *)image {
    cv::Mat mat = [self.class matFromImage:image];
    
    return [self initWithMatInstance:&mat];
}

- (instancetype)initWithImageRef:(CGImageRef)imageRef {
    cv::Mat mat = [self.class matFromImageRef:imageRef];
    
    return [self initWithMatInstance:&mat];
}

- (instancetype)initWithCGSize:(CGSize)size {
    return [self initWithCGSize:size type:OCVDepthTypeCv8U channels:4];
}

- (instancetype)initWithCGSize:(CGSize)size type:(OCVDepthType)type channels:(NSInteger)channels {
    return [self initWithRows:(NSInteger)size.height cols:(NSInteger)size.width type:type channels:channels];
}

#pragma mark - NSCopying

- (instancetype)copyWithZone:(NSZone *)zone {
    return [[[self class] alloc] initWithMat:self];
}

#pragma mark - Public Methods

- (OCVMat *)clone {
    cv::Mat *mat = new cv::Mat(self.source->clone());
    
    return [[OCVMat alloc] initWithMatInstance:mat];
}

- (OCVMat *)submatrixWithRect:(OCVRect)rect {
    cv::Mat sourceMat = *self.source;
    
    cv::Mat mat = sourceMat(convertRect(rect));
    
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

- (CGImageRef)imageRef {
    if (self.source == NULL) {
        return nil;
    }
    
    return [self.class imageRefFromMat:*(self.source)];
}

- (UIImage *)image {
    CGImageRef imageRef = [self imageRef];
    
    return [UIImage imageWithCGImage:imageRef];
}

- (OCVMat *)reshapeWithChannels:(NSInteger)channels {
    return [self reshapeWithChannels:channels rows:0];
}

- (OCVMat *)reshapeWithChannels:(NSInteger)channels rows:(NSInteger)rows {
    cv::Mat mat = self.source->reshape((int)channels, (int)rows);
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

- (OCVMat *)transpose {
    cv::Mat mat = self.source->t();
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

- (OCVMat *)inverse {
    return [self inverseWithMethod:OCVDecompositionTypeLU];
}

- (OCVMat *)inverseWithMethod:(OCVDecompositionType)method {
    cv::Mat mat = self.source->inv((int)method);
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

- (OCVMat *)multiplyWithArray:(id<OCVInputArrayable>)inputArray {
    return [self multiplyWithArray:inputArray scale:1];
}

- (OCVMat *)multiplyWithArray:(id<OCVInputArrayable>)inputArray scale:(double)scale {
    cv::Mat mat = self.source->mul(*inputArray.input._input, scale);
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

- (OCVMat *)crossWithArray:(id<OCVInputArrayable>)inputArray {
    cv::Mat mat = self.source->cross(*inputArray.input._input);
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

- (double)dotWithArray:(id<OCVInputArrayable>)inputArray {
    return self.source->dot(*inputArray.input._input);
}

#pragma mark - OCVInputOutputArrayable

- (OCVInputOutputArray *)inputOutput {
    if (!_inputOutput) {
        _inputOutput = [[OCVInputOutputArray alloc] initWithObject:self];
    }
    
    return _inputOutput;
}

#pragma mark - OCVInputArrayable

- (OCVInputArray *)input {
    return self.inputOutput;
}

#pragma mark - OCVOutputArrayable

- (OCVOutputArray *)output {
    return self.inputOutput;
}

#pragma mark - Public Factory Methods

+ (instancetype)zerosWithSize:(OCVSize)size type:(OCVDepthType)type channels:(NSInteger)channels {
    return [self zerosWithRows:size.height cols:size.width type:type channels:channels];
}

+ (instancetype)zerosWithRows:(NSInteger)rows cols:(NSInteger)cols type:(OCVDepthType)type channels:(NSInteger)channels {
    int cvType = (int)CV_MAKETYPE(type, channels);
    
    cv::Mat mat = cv::Mat::zeros((int)rows, (int)cols, cvType);
    
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
}

+ (instancetype)onesWithSize:(OCVSize)size type:(OCVDepthType)type channels:(NSInteger)channels {
    return [self onesWithRows:size.height cols:size.width type:type channels:channels];
}

+ (instancetype)onesWithRows:(NSInteger)rows cols:(NSInteger)cols type:(OCVDepthType)type channels:(NSInteger)channels {
    int cvType = (int)CV_MAKETYPE(type, channels);
    
    cv::Mat mat = cv::Mat::ones((int)rows, (int)cols, cvType);
    
    return [[OCVMat alloc] initWithMatInstance:new cv::Mat(mat)];
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
