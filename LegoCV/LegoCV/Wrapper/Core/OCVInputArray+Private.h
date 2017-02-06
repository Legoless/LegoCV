//
//  OCVInputArray+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputArray.h"
#import <opencv2/core/mat.hpp>

@interface OCVInputArray (OpenCV)

@property (nonatomic, readonly) cv::InputArray _input;

@end
