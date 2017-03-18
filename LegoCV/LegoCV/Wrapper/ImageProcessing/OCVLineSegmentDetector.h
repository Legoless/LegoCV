//
//  OCVLineSegmentDetector.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
#import "OCVImageTypes.h"
#import "OCVGeometry.h"
#import "OCVArrayables.h"
#import "OCVAlgorithm.h"

@interface OCVLineSegmentDetectorOptions : OCVObject

@property (nonatomic, assign) OCVLineSegmentDetectorMode mode;
@property (nonatomic, assign) double scale;
@property (nonatomic, assign) double sigmaScale;
@property (nonatomic, assign) double quantization;
@property (nonatomic, assign) double gradientAngleTolerance;
@property (nonatomic, assign) double logEps;
@property (nonatomic, assign) double minimalDensity;
@property (nonatomic, assign) NSInteger numberOfBins;

+ (instancetype)defaultOptions;

@end

@interface OCVLineSegmentDetector : OCVAlgorithm

- (instancetype)initWitOptions:(OCVLineSegmentDetectorOptions *)options;

- (void)detectOnImage:(id<OCVInputArrayable>)image toLines:(id<OCVOutputArrayable>)lines;
- (void)detectOnImage:(id<OCVInputArrayable>)image toLines:(id<OCVOutputArrayable>)lines widthRegions:(id<OCVOutputArrayable>)widthRegions;
- (void)detectOnImage:(id<OCVInputArrayable>)image toLines:(id<OCVOutputArrayable>)lines widthRegions:(id<OCVOutputArrayable>)widthRegions precisions:(id<OCVOutputArrayable>)precisions;
- (void)detectOnImage:(id<OCVInputArrayable>)image toLines:(id<OCVOutputArrayable>)lines widthRegions:(id<OCVOutputArrayable>)widthRegions precisions:(id<OCVOutputArrayable>)precisions falseAlarms:(id<OCVOutputArrayable>)falseAlarms;

- (void)drawSegmentsOnImage:(id<OCVInputOutputArrayable>)image lines:(id<OCVInputArrayable>)lines;

- (NSInteger)compareSegmentsInSize:(OCVSize)size lines1:(id<OCVInputArrayable>)lines1 lines2:(id<OCVInputArrayable>)lines2;
- (NSInteger)compareSegmentsInSize:(OCVSize)size lines1:(id<OCVInputArrayable>)lines1 lines2:(id<OCVInputArrayable>)lines2 onImage:(id<OCVInputOutputArrayable>)image;

@end
