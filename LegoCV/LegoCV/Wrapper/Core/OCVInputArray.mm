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

@interface OCVInputArray ()
@end

@implementation OCVInputArray

- (cv::InputArray)_input {
    if ([self.object isKindOfClass:[OCVMatDataAllocator class]]) {
        OCVMatDataAllocator *mat = self.object;
        
        return *(mat.source);
    }
    
    return cv::noArray();
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

#pragma mark - Public Methods

- (NSInteger)channelsWithIndex:(NSInteger)index {
    return self._input.channels((int)index);
}

- (NSInteger)depthWithIndex:(NSInteger)index {
    return self._input.depth((int)index);
}

- (NSInteger)dimsWithIndex:(NSInteger)index {
    return self._input.dims((int)index);
}

- (OCVMat *)mat {
    return [self matWithIndex:-1];
}

- (OCVMat *)matWithIndex:(NSInteger)index {
    
    cv::Mat mat = self._input.getMat((int)index);
    return [[OCVMat alloc] initWithMatInstance:&mat];
}

#pragma mark - Factory Methods


@end
