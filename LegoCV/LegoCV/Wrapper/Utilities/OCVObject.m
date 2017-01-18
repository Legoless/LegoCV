//
//  OCVObject.m
//  LegoCV
//
//  Created by Dal Rupnik on 18/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

@implementation OCVObject

- (instancetype)initWithUnsafePointer:(void *)unsafePointer {
    self = [super init];
    
    if (self) {
        pointer = unsafePointer;
    }
    
    return self;
}

@end
