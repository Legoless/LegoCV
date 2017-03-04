//
//  OCVOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
#import "OCVInputArrayable.h"
#import "OCVOutputArrayable.h"
#import "OCVInputOutputArrayable.h"

#import "OCVGeometry.h"

@interface OCVOperation : OCVObject

+ (void)copyMakeBorderFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;

@end
