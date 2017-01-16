//
//  OCVMat.h
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCVSize.h"
#import "OCVMatExpr.h"
#import "OCVInputArray.h"

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

- (OCVMat *)reshapeWithChannels:(NSInteger)cn;
- (OCVMat *)reshapeWithChannels:(NSInteger)cn rows:(NSInteger)rows;

- (OCVMatExpr *)t;

- (OCVMatExpr *)inv;
- (OCVMatExpr *)invWithMethod:(NSInteger)method;

- (OCVMatExpr *)mulWithArray:(OCVInputArray *)inputArray;
- (OCVMatExpr *)mulWithArray:(OCVInputArray *)inputArray scale:(double)scale;

- (OCVMat *)crossWithArray:(OCVInputArray *)inputArray;

- (double)dotWithArray:(OCVInputArray *)inputArray;

//
// MARK: Factory Methods
//

+ (instancetype)zerosWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
+ (instancetype)zerosWithSize:(OCVSize *)size type:(NSInteger)type;

+ (instancetype)onesWithRows:(NSInteger)rows cols:(NSInteger)cols type:(NSInteger)type;
+ (instancetype)onesWithSize:(OCVSize *)size type:(NSInteger)type;

@end

//
// MARK: Unavailable in Swift, convenience for OpenCV, should be private
//

#import <opencv2/core/mat.hpp>

@interface OCVMat (OpenCV)

- (instancetype)initWithMatInstance:(cv::Mat)mat;

- (cv::Mat)matInstance;

@end
