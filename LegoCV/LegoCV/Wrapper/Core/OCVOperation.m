//
//  OCVOperation.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVOperation.h"

@implementation OCVOperation

+ (void)convertColorFromSource:(id<OCVInputArray>)source toDestination:(id<OCVOutputArray>)destination withCode:(NSInteger)code {
    [self convertColorFromSource:source toDestination:destination withCode:code withDestinationCn:0];
}

@end
