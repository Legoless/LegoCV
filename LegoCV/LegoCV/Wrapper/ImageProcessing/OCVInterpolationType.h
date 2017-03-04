//
//  OCVInterpolationType.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#ifndef OCVInterpolationType_h
#define OCVInterpolationType_h

typedef NS_ENUM(NSInteger, OCVInterpolationType) {
    OCVInterpolationTypeNearest     = 0,
    OCVInterpolationTypeLinear      = 1,
    OCVInterpolationTypeCubic       = 2,
    OCVInterpolationTypeArea        = 3,
    OCVInterpolationTypeLanczos4    = 4
};

#endif /* OCVInterpolationType_h */
