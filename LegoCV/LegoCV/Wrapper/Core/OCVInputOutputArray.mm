//
//  OCVInputOutputArray.m
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVMatDataAllocator+Private.h"
#import "OCVInputOutputArray.h"
#import "OCVInputOutputArray+Private.h"
#import "OCVInputArray+Private.h"

@implementation OCVInputOutputArray

- (cv::_InputOutputArray *)_inputOutput {
    [self setup];
    
    return (cv::_InputOutputArray *)self.arrayReference;
}

- (void)setup {
    if ([self.object isKindOfClass:[OCVMatDataAllocator class]]) {
        cv::Mat *mat = [self.object source];
        
        self.arrayReference = new cv::_InputOutputArray(*mat);
    }
}

@end
