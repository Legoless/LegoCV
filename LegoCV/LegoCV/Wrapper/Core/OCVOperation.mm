//
//  OCVOperation.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core/core.hpp>
#import <opencv2/imgproc/imgproc.hpp>

#import "OCVInputArray+Private.h"
#import "OCVOutputArray+Private.h"

#import "OCVOperation.h"

@implementation OCVOperation

+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type {
    [self convertColorFromSource:source toDestination:destination withType:type withDestinationCn:0];
}

+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type withDestinationCn:(NSInteger)destinationCn {
    
    cv::cvtColor(source.input._input, destination.output._output, (int)type, (int)destinationCn);
}

@end
