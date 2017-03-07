//
//  OCVInputArrayable.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVInputArray.h"

@protocol OCVInputArrayable <NSObject>

@property (nonatomic, readonly) OCVInputArray *input;

@end
