//
//  OCVRandomGenerator.h
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
#import "OCVTypes.h"

@interface OCVRandomGenerator : OCVObject

/*!
 *  cv::theRNG()
 */
+ (instancetype)defaultGenerator;

/*!
 *  cv::setRNGSeed()
 */
+ (void)setSeed:(NSInteger)seed;

/*!
 *  cv::randu()
 */
+ (void)randUniformToDestination:(id<OCVInputOutputArrayable>)destination withLowBoundary:(id<OCVInputArrayable>)lowBoundary withHighBoundary:(id<OCVInputArrayable>)highBoundary;

/*!
 *  cv::randn()
 */
+ (void)randNormallyToDestination:(id<OCVInputOutputArrayable>)destination mean:(id<OCVInputArrayable>)mean standardDeviation:(id<OCVInputArrayable>)standardDeviation;

/*!
 *  cv::randShuffle()
 */
- (void)randShuffleToDestination:(id<OCVInputOutputArrayable>)destination;
- (void)randShuffleToDestination:(id<OCVInputOutputArrayable>)destination iterationFactor:(double)iterationFactor;
@end
