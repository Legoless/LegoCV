//
//  OCVMat.m
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core/core.hpp>

#import "OCVMat.h"

@implementation OCVMat


- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)buffer {
    cv::Mat mat = [self.class matFromBuffer:buffer];
    
    return [self initWithMatInstance:mat];
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

@end
