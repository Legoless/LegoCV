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

- (cv::OutputArray)_output {
    if ([self.object isKindOfClass:[OCVMatDataAllocator class]]) {
        OCVMatDataAllocator *mat = self.object;
        
        return *(mat.source);
    }
    
    return cv::noArray();
}

@end
