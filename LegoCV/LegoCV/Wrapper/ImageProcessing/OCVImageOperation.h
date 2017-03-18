//
//  OCVImageOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 04/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVTypes.h"
#import "OCVImageTypes.h"
#import "OCVObject.h"
#import "OCVArrayables.h"

#import "OCVGeometry.h"

#import "OCVColorConversionType.h"
#import "OCVInterpolationType.h"

/*!
 *  Common Image Operations as defined in imgproc.hpp
 */
@interface OCVImageOperation : OCVObject

/*!
 *  Reference type: cv::getGaussianKernel()
 */
+ (OCVMat *)gaussianKernelForApertureSize:(NSInteger)size sigma:(double)sigma;
+ (OCVMat *)gaussianKernelForApertureSize:(NSInteger)size sigma:(double)sigma coefficientDepthType:(OCVDepthType)depthType;

/*!
 *  Reference type: cv::getDerivKernels()
 */
+ (void)derivKernelsWithKx:(id<OCVOutputArrayable>)kx ky:(id<OCVOutputArrayable>)ky dx:(NSInteger)dx dy:(NSInteger)dy apertureSize:(NSInteger)size;
+ (void)derivKernelsWithKx:(id<OCVOutputArrayable>)kx ky:(id<OCVOutputArrayable>)ky dx:(NSInteger)dx dy:(NSInteger)dy apertureSize:(NSInteger)size normalize:(BOOL)normalize;
+ (void)derivKernelsWithKx:(id<OCVOutputArrayable>)kx ky:(id<OCVOutputArrayable>)ky dx:(NSInteger)dx dy:(NSInteger)dy apertureSize:(NSInteger)size normalize:(BOOL)normalize coefficientDepthType:(OCVDepthType)depthType;

/*!
 *  Reference type: cv::getGaborKernel()
 */
+ (OCVMat *)gaborKernelForSize:(OCVSize)size sigma:(double)sigma theta:(double)theta waveLength:(double)lambd gamma:(double)gamma;
+ (OCVMat *)gaborKernelForSize:(OCVSize)size sigma:(double)sigma theta:(double)theta waveLength:(double)lambd gamma:(double)gamma phaseOffset:(double)phaseOffset;
+ (OCVMat *)gaborKernelForSize:(OCVSize)size sigma:(double)sigma theta:(double)theta waveLength:(double)lambd gamma:(double)gamma phaseOffset:(double)phaseOffset coefficientDepthType:(OCVDepthType)depthType;

/*!
 *  Reference type: cv::morphologyDefaultBorderValue()
 */
+ (OCVScalar)morphologyDefaultBorderValue;

/*!
 *  Reference type: cv::getStructuringElement()
 */








+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type;
+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type withDestinationCn:(NSInteger)destinationCn;

+ (void)resizeFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(OCVSize)size fx:(double)fx fy:(double)fy interpolation:(OCVInterpolationType)interpolation;

+ (void)equalizeHistogramFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;
+ (void)rectangleOnSource:(id<OCVInputOutputArrayable>)source fromPoint:(OCVPoint)point1 toPoint:(OCVPoint)point2 withColor:(OCVScalar)color thickness:(NSInteger)thickness lineType:(NSInteger)lineType shift:(NSInteger)shift;

+ (void)rectangleOnSource:(id<OCVInputOutputArrayable>)source fromRect:(OCVRect)rect withColor:(OCVScalar)color thickness:(NSInteger)thickness lineType:(NSInteger)lineType shift:(NSInteger)shift;

@end
