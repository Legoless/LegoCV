//
//  OCVOutputArray.m
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVMatDataAllocator+Private.h"

#import "OCVOutputArray.h"
#import "OCVInputArray+Private.h"

@implementation OCVOutputArray

- (cv::_OutputArray *)_output {
    [self setup];
    
    return (cv::_OutputArray *)self.arrayReference;
}

- (void)setup {
    if ([self.object isKindOfClass:[OCVMatDataAllocator class]]) {
        cv::Mat *mat = [self.object source];
        
        self.arrayReference = new cv::_OutputArray(*mat);
    }
}

@end
