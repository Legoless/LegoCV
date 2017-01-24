//
//  OCVInputArray.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputArray+Private.h"

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

#pragma mark - Initialization

- (instancetype)init {
    [NSException raise:@"InitNotImplemented" format:@"Direct initialization not supported."];
    
    return nil;
}

- (instancetype)initWithInstance:(cv::_InputArray)inputArray {
    self = [super init];
    
    if (self) {
        self->source = inputArray;
    }
    
    return self;
}

@end
