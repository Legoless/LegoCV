//
//  OCVMatDataAllocator+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

//
// MARK: Unavailable in Swift, convenience for OpenCV, should be private
//

#import "OCVMatDataAllocator.h"
#import <opencv2/core/mat.hpp>

@interface OCVMatDataAllocator (OpenCV)

@property (nonatomic, readonly) cv::Mat *source;

- (instancetype)initWithMatInstance:(cv::Mat *)mat;

@end
