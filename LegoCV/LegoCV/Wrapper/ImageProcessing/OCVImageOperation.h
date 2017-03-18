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
+ (OCVMat *)structuringElementWithShape:(OCVMorphShape)shape size:(OCVSize)size;
+ (OCVMat *)structuringElementWithShape:(OCVMorphShape)shape size:(OCVSize)size anchorPoint:(OCVPoint)anchorPoint;

/*!
 *  Reference type: cv::medianBlur()
 */
+ (void)medianBlurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size;

/*!
 *  Reference type: cv::GaussianBlur()
 */
+ (void)gaussianBlurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size sigmaX:(double)sigmaX;
+ (void)gaussianBlurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size sigmaX:(double)sigmaX sigmaY:(double)sigmaY;
+ (void)gaussianBlurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size sigmaX:(double)sigmaX sigmaY:(double)sigmaY borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::bilateralFilter()
 */
+ (void)bilateralFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination diameter:(NSInteger)diameter sigmaColor:(double)sigmaColor sigmaSpace:(double)sigmaSpace;
+ (void)bilateralFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination diameter:(NSInteger)diameter sigmaColor:(double)sigmaColor sigmaSpace:(double)sigmaSpace borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::boxFilter()
 */
+ (void)boxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size;
+ (void)boxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint;
+ (void)boxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint normalize:(BOOL)normalize;
+ (void)boxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint normalize:(BOOL)normalize borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::sqrBoxFilter()
 */
+ (void)squareBoxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size;
+ (void)squareBoxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint;
+ (void)squareBoxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint normalize:(BOOL)normalize;
+ (void)squareBoxFilterWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint normalize:(BOOL)normalize borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::blur()
 */
+ (void)blurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size;
+ (void)blurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint;
+ (void)blurWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(NSInteger)size anchorPoint:(OCVPoint)anchorPoint borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::filter2D()
 */
+ (void)filter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernel:(id<OCVInputArrayable>)kernel;
+ (void)filter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernel:(id<OCVInputArrayable>)kernel anchorPoint:(OCVPoint)anchorPoint;
+ (void)filter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernel:(id<OCVInputArrayable>)kernel anchorPoint:(OCVPoint)anchorPoint delta:(double)delta;
+ (void)filter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernel:(id<OCVInputArrayable>)kernel anchorPoint:(OCVPoint)anchorPoint delta:(double)delta borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::sepFilter2D()
 */
+ (void)separableFilter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernelX:(id<OCVInputArrayable>)kernelX kernelY:(id<OCVInputArrayable>)kernelY;
+ (void)separableFilter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernelX:(id<OCVInputArrayable>)kernelX kernelY:(id<OCVInputArrayable>)kernelY anchorPoint:(OCVPoint)anchorPoint;
+ (void)separableFilter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernelX:(id<OCVInputArrayable>)kernelX kernelY:(id<OCVInputArrayable>)kernelY anchorPoint:(OCVPoint)anchorPoint delta:(double)delta;
+ (void)separableFilter2DWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth kernelX:(id<OCVInputArrayable>)kernelX kernelY:(id<OCVInputArrayable>)kernelY anchorPoint:(OCVPoint)anchorPoint delta:(double)delta borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::Sobel()
 */
+ (void)sobelWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy;
+ (void)sobelWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy size:(NSInteger)size;
+ (void)sobelWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy size:(NSInteger)size scale:(double)scale;
+ (void)sobelWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy size:(NSInteger)size scale:(double)scale delta:(double)delta;
+ (void)sobelWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy size:(NSInteger)size scale:(double)scale delta:(double)delta borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::spatialGradient()
 */
+ (void)spatialGradientWithSource:(id<OCVInputArrayable>)source dx:(id<OCVOutputArrayable>)dx dy:(id<OCVOutputArrayable>)dy;
+ (void)spatialGradientWithSource:(id<OCVInputArrayable>)source dx:(id<OCVOutputArrayable>)dx dy:(id<OCVOutputArrayable>)dy size:(NSInteger)size;
+ (void)spatialGradientWithSource:(id<OCVInputArrayable>)source dx:(id<OCVOutputArrayable>)dx dy:(id<OCVOutputArrayable>)dy size:(NSInteger)size borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::Scharr()
 */
+ (void)scharrWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy;
+ (void)scharrWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy scale:(double)scale;
+ (void)scharrWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy scale:(double)scale delta:(double)delta;
+ (void)scharrWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth dx:(NSInteger)dx dy:(NSInteger)dy scale:(double)scale delta:(double)delta borderType:(OCVBorderType)borderType;

/*!
 *  Reference type: cv::Laplacian()
 */
+ (void)laplacianWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth;
+ (void)laplacianWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size;
+ (void)laplacianWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size scale:(double)scale;
+ (void)laplacianWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size scale:(double)scale delta:(double)delta;
+ (void)laplacianWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination depth:(NSInteger)depth size:(NSInteger)size scale:(double)scale delta:(double)delta borderType:(OCVBorderType)borderType;


+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type;
+ (void)convertColorFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination withType:(OCVColorConversionType)type withDestinationCn:(NSInteger)destinationCn;

+ (void)resizeFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination size:(OCVSize)size fx:(double)fx fy:(double)fy interpolation:(OCVInterpolationType)interpolation;

+ (void)equalizeHistogramFromSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;
+ (void)rectangleOnSource:(id<OCVInputOutputArrayable>)source fromPoint:(OCVPoint)point1 toPoint:(OCVPoint)point2 withColor:(OCVScalar)color thickness:(NSInteger)thickness lineType:(NSInteger)lineType shift:(NSInteger)shift;

+ (void)rectangleOnSource:(id<OCVInputOutputArrayable>)source fromRect:(OCVRect)rect withColor:(OCVScalar)color thickness:(NSInteger)thickness lineType:(NSInteger)lineType shift:(NSInteger)shift;

@end
