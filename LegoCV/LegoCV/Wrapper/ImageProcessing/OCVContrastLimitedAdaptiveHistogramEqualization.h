//
//  OCVContrastLimitedAdaptiveHistogramEqualization.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVGeometry.h"
#import "OCVAlgorithm.h"
#import "OCVArrayables.h"

/*!
 *  Reference type: cv::CLAHE
 */
@interface OCVContrastLimitedAdaptiveHistogramEqualization : OCVAlgorithm

@property (nonatomic, assign) double clipLimit;
@property (nonatomic, assign) OCVSize tileGridSize;

- (void)applyWithSource:(id<OCVInputArrayable>)source toDestination:(id<OCVOutputArrayable>)destination;

- (void)collectGarbage;

@end
