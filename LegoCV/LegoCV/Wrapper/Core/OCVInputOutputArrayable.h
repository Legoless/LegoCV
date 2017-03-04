//
//  OCVInputOutputArrayable.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputOutputArray.h"

@protocol OCVInputOutputArrayable <NSObject>

@property (nonatomic, readonly) OCVInputOutputArray *inputOutput;

@end
