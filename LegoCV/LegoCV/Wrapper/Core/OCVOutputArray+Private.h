//
//  OCVOutputArray+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVOutputArray.h"
#import <opencv2/core/mat.hpp>

@interface OCVOutputArray (OpenCV)

@property (nonatomic, readonly) cv::_OutputArray *_output;

@end
