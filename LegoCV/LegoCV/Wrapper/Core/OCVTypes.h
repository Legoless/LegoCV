//
//  OCVTypes.h
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

typedef NS_ENUM(NSInteger, OCVDepthType) {
    OCVDepthTypeDefault = -1,
    OCVDepthTypeCv8U = 0,
    OCVDepthTypeCv8S = 1,
    OCVDepthTypeCv16U = 2,
    OCVDepthTypeCv16S = 3,
    OCVDepthTypeCv32S = 4,
    OCVDepthTypeCv32F = 5,
    OCVDepthTypeCv64F = 6
};
