//
//  OCVOutputArray.m
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVOutputArray.h"
#import "OCVInputArray+Private.h"

@implementation OCVOutputArray

- (cv::_OutputArray)_output {
    return *((cv::_OutputArray *)self.source);
}

@end
