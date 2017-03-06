//
//  OCVInputOutputArray+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputOutputArray.h"
#import <opencv2/core/mat.hpp>

@interface OCVInputOutputArray (OpenCV)

@property (nonatomic, readonly) cv::_InputOutputArray *_inputOutput;

@end
