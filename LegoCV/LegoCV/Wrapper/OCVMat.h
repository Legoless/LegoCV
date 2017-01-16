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

//
// MARK: Initialization
//

- (instancetype)initWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
- (instancetype)initWithSize:(OCVSize *)size type:(NSInteger)type;
- (instancetype)initWithMat:(OCVMat *)mat;

//
// MARK: Public Methods
//


//
// MARK: Factory Methods
//

+ (instancetype)zerosWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
+ (instancetype)zerosWithSize:(OCVSize *)size type:(NSInteger)type;

+ (instancetype)onesWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
+ (instancetype)onesWithSize:(OCVSize *)size type:(NSInteger)type;

@end

//
// MARK: Unavailable in Swift, convenience for OpenCV
//

#import <opencv2/core/mat.hpp>

@interface OCVMat (OpenCV)

- (cv::Mat)matInstance;

@end
