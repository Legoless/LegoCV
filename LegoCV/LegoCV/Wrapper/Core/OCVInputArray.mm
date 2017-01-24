//
//  OCVInputArray.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputArray+Private.h"

#import "OCVInputArray.h"

#import "OCVMat+Private.h"

@interface OCVInputArray () {
    cv::_InputArray source;
}

@end

@implementation OCVInputArray

- (cv::_InputArray)source {
    return source;
}

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

- (instancetype)initWithArrayInstance:(cv::_InputArray)inputArray {
    self = [super init];
    
    if (self) {
        self->source = inputArray;
    }
    
    return self;
}

#pragma mark - Public Methods

- (NSInteger)channelsWithIndex:(NSInteger)index {
    return self.source.channels((int)index);
}

- (NSInteger)depthWithIndex:(NSInteger)index {
    return self.source.depth((int)index);
}

- (NSInteger)dimsWithIndex:(NSInteger)index {
    return self.source.dims((int)index);
}

- (OCVMat *)mat {
    return [self matWithIndex:-1];
}

- (OCVMat *)matWithIndex:(NSInteger)index {
    return [[OCVMat alloc] initWithMatInstance:self.source.getMat()];
}

@end
