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

typedef NS_ENUM(NSInteger, OCVRandomType) {
    OCVRandomTypeUniform = 0,
    OCVRandomTypeNormal = 1,
};

/*!
 *  cv::RNG
 */
@interface OCVRandomGenerator : OCVObject

@property (nonatomic, assign) unsigned long long state;

#pragma mark - Initialization

- (instancetype)initWithState:(unsigned long long)state;

#pragma mark - Public Methods

- (char)nextChar;
- (unsigned char)nextUnsignedChar;

- (short)nextShort;
- (unsigned short)nextUnsignedShort;

- (int)nextInt;
- (unsigned int)nextUnsignedInt;

- (unsigned long long)nextUnsignedLong;

- (float)nextFloat;
- (double)nextDouble;

- (int)uniformWithLower:(int)lower upper:(int)upper;
- (float)uniformFloatWithLower:(float)lower upper:(float)upper;
- (double)uniformDoubleWithLower:(double)lower upper:(double)upper;


- (void)fillSource:(id<OCVInputOutputArrayable>)source type:(OCVRandomType)type distributionA:(id<OCVInputArrayable>)distributionA distributionB:(id<OCVInputArrayable>)distributionB;
- (void)fillSource:(id<OCVInputOutputArrayable>)source type:(OCVRandomType)type distributionA:(id<OCVInputArrayable>)distributionA distributionB:(id<OCVInputArrayable>)distributionB saturateRange:(BOOL)saturateRange;

- (double)gaussianForSigma:(double)sigma;

/*!
 *  cv::randShuffle()
 *
 *  @note: While OpenCV provides a static method here for randShuffle, this is an instance method, since it requires random generator object.
 */
- (void)randShuffleToDestination:(id<OCVInputOutputArrayable>)destination;
- (void)randShuffleToDestination:(id<OCVInputOutputArrayable>)destination iterationFactor:(double)iterationFactor;

#pragma mark - Class Methods

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

@end

/*!
 *  cv::RNG_MT19937
 */
@interface OCVMersenneTwisterRandomGenerator : OCVRandomGenerator

- (void)seedWithState:(unsigned long long)state;

@end

