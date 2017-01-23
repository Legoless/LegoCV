//
//  OCVReferenceObject.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVReferenceObject.h"

@implementation OCVReferenceObject

- (instancetype)initWithObject:(id)object {
    self = [super init];
    
    if (self) {
        self.object = object;
    }
    
    return self;
}

@end
