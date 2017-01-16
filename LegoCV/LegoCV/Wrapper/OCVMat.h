//
//  OCVMat.h
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCVSize.h"

@interface OCVMat : NSObject

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
- (instancetype)initWithSize:(OCVSize *)size type:(NSInteger)type;
- (instancetype)initWithMat:(OCVMat *)mat;

@end

//
// MARK: Unavailable in Swift, convenience for OpenCV
//

#import <opencv2/core/mat.hpp>

@interface OCVMat (OpenCV)

- (cv::Mat)matInstance;

@end
