//
//  OCVInputArray.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core/core.hpp>

#import "OCVInputArray.h"

@interface OCVInputArray () {
    cv::_InputArray source;
}

@end

@implementation OCVInputArray

- (NSInteger)channels {
    return [self channelsWithIndex:-1];
}

- (NSInteger)depth {
    return [self depthWithIndex:-1];
}

- (NSInteger)dims {
    return [self dimsWithIndex:-1];
}

@end
