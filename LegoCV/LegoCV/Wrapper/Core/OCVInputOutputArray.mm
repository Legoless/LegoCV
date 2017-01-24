//
//  OCVInputOutputArray.m
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputOutputArray.h"
#import "OCVInputOutputArray+Private.h"
#import "OCVInputArray+Private.h"

@implementation OCVInputOutputArray

- (cv::_InputOutputArray)_inputOutput {
    return *((cv::_InputOutputArray *)self.source);
}

@end
