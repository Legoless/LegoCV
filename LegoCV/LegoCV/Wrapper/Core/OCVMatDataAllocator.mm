//
//  OCVMatDataAllocator.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core/core.hpp>

#import "OCVMatDataAllocator.h"

@interface OCVMatDataAllocator () {
    cv::Mat source;
}

@end

@implementation OCVMatDataAllocator

- (cv::Mat)source {
    return source;
}

- (instancetype)initWithMatInstance:(cv::Mat)mat {
    self = [super init];
    
    if (self) {
        self->source = mat;
    }
    
    return self;
}

@end
