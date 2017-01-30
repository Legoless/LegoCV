//
//  OCVPointerObject.m
//  LegoCV
//
//  Created by Dal Rupnik on 22/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVPointerObject.h"

@implementation OCVPointerObject

- (instancetype)initWithPointer:(void *)unsafePointer {
    self = [super init];
    
    if (self) {
        pointer = unsafePointer;
    }
    
    return self;
}

- (void)dealloc {
    if (pointer != NULL) {
        free(pointer);
    }
}

@end
