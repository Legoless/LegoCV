//
//  OCVInputArray.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputArray+Private.h"

#import "OCVInputArray.h"

#import "OCVMatDataAllocator+Private.h"
#import "OCVMat.h"

@interface OCVInputArray () {
    cv::_InputArray *source;
}

@end

@implementation OCVInputArray

- (cv::_InputArray *)source {
    return source;
}

- (cv::_InputArray)_input {
    return *(source);
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

- (instancetype)initWithArrayInstance:(cv::_InputArray *)array {
    self = [super init];
    
    if (self) {
        self->source = array;
    }
    
    return self;
}

#pragma mark - Public Methods

- (NSInteger)channelsWithIndex:(NSInteger)index {
    return source->channels((int)index);
}

- (NSInteger)depthWithIndex:(NSInteger)index {
    return source->depth((int)index);
}

- (NSInteger)dimsWithIndex:(NSInteger)index {
    return source->dims((int)index);
}

- (OCVMat *)mat {
    return [self matWithIndex:-1];
}

- (OCVMat *)matWithIndex:(NSInteger)index {
    
    cv::Mat mat = source->getMat((int)index);
    return [[OCVMat alloc] initWithMatInstance:&mat];
}

#pragma mark - Factory Methods

+ (OCVInputArray *)empty {
    cv::_InputArray array = cv::_InputArray();
    return [[OCVInputArray alloc] initWithArrayInstance:&array];
}

@end
