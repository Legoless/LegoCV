//
//  OCVImageOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 04/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
#import "OCVInputArrayable.h"
#import "OCVOutputArrayable.h"
#import "OCVInputOutputArrayable.h"

#import "OCVGeometry.h"

#import "OCVColorConversionType.h"
#import "OCVInterpolationType.h"

/*!
 *  Common Image Operations as defined in imgproc.hpp
 */
@interface OCVImageOperation : OCVObject

//+ (id<OCVOutputArrayable>)convertColorFromSource:(id<OCVInputArrayable>)source withType:(OCVColorConversionType)type withDestinationCn:(NSInteger)destinationCn;

+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type;
+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type withDestinationCn:(NSInteger)destinationCn;

+ (void)resizeFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(OCVSize)size fx:(double)fx fy:(double)fy interpolation:(OCVInterpolationType)interpolation;

+ (void)equalizeHistogramFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;
+ (void)rectangleOnSource:(id<OCVInputOutputArrayable>)source fromPoint:(OCVPoint)point1 toPoint:(OCVPoint)point2 withColor:(OCVScalar)color thickness:(NSInteger)thickness lineType:(NSInteger)lineType shift:(NSInteger)shift;

+ (void)rectangleOnSource:(id<OCVInputOutputArrayable>)source fromRect:(OCVRect)rect withColor:(OCVScalar)color thickness:(NSInteger)thickness lineType:(NSInteger)lineType shift:(NSInteger)shift;

@end
