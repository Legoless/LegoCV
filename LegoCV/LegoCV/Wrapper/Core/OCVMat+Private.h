//
//  OCVMat+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

//
// MARK: Unavailable in Swift, convenience for OpenCV, should be private
//

#import <opencv2/core/mat.hpp>
#import <CoreVideo/CoreVideo.h>

@interface OCVMat (OpenCV)

@property (nonatomic, readonly) cv::Mat source;

- (instancetype)initWithMatInstance:(cv::Mat)mat;

@end
