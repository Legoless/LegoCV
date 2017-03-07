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
    cv::_InputArray *_arrayReference;
}

@end

@implementation OCVInputArray

- (cv::_InputArray *)arrayReference {
    return _arrayReference;
}

- (void)setArrayReference:(cv::_InputArray *)arrayReference {
    _arrayReference = arrayReference;
}

- (cv::_InputArray *)_input {
    [self setup];
    
    return self.arrayReference;
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

- (void)dealloc {
    if (_arrayReference != NULL) {
        free(_arrayReference);
    }
    
    _arrayReference = NULL;
}

#pragma mark - Public Methods

- (NSInteger)channelsWithIndex:(NSInteger)index {
    return self._input->channels((int)index);
}

- (NSInteger)depthWithIndex:(NSInteger)index {
    return self._input->depth((int)index);
}

- (NSInteger)dimsWithIndex:(NSInteger)index {
    return self._input->dims((int)index);
}

- (OCVMat *)mat {
    return [self matWithIndex:-1];
}

- (OCVMat *)matWithIndex:(NSInteger)index {
    
    cv::Mat mat = self._input->getMat((int)index);
    return [[OCVMat alloc] initWithMatInstance:&mat];
}

#pragma mark - Protected Methods

- (void)setup {
    if ([self.object isKindOfClass:[OCVMatDataAllocator class]]) {
        cv::Mat *mat = [self.object source];
        
        _arrayReference = new cv::_InputArray(*mat);
    }
}


#pragma mark - Factory Methods


@end
