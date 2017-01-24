//
//  OCVRect.m
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVRect.h"

@interface OCVRectValue ()

@property (nonatomic, readwrite, assign) OCVRect rect;

@end

@implementation OCVRectValue

- (instancetype)initWithRect:(OCVRect)rect {
    self = [super init];
    
    if (self) {
        self.rect = rect;
    }
    
    return self;
}

@end
