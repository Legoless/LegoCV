//
//  OCVMinimumMaximumResult.h
//  LegoCV
//
//  Created by Dal Rupnik on 04/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVGeometry.h"

#import "OCVObject.h"

@interface OCVMinimumMaximumResult : OCVObject

@property (nonatomic, assign) double minimumValue;
@property (nonatomic, assign) double maximumValue;
@property (nonatomic, assign) OCVPoint minimumLocation;
@property (nonatomic, assign) OCVPoint maximumLocation;

@end
