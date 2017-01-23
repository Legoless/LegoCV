//
//  OCVOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
#import "OCVInputArray.h"
#import "OCVOutputArray.h"

@interface OCVOperation : OCVObject

+ (void)convertColorFromSource:(id<OCVInputArray>)source toDestination:(id<OCVOutputArray>)destination withCode:(NSInteger)code;
+ (void)convertColorFromSource:(id<OCVInputArray>)source toDestination:(id<OCVOutputArray>)destination withCode:(NSInteger)code withDestinationCn:(NSInteger)destinationCn;

@end
