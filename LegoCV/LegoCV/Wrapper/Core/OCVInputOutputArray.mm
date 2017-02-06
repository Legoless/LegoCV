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

- (cv::InputOutputArray)_inputOutput {
    if ([self.object isKindOfClass:[OCVMatDataAllocator class]]) {
        OCVMatDataAllocator *mat = self.object;
        
        return *(mat.source);
    }
    
    return cv::noArray();
}

@end
