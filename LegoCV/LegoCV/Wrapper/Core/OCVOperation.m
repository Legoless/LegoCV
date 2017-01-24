//
//  OCVOperation.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVOperation.h"

@implementation OCVOperation

+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type {
    [self convertColorFromSource:source toDestination:destination withType:type withDestinationCn:0];
}

@end
