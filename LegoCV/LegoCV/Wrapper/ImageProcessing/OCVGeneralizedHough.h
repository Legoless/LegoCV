//
//  OCVGeneralizedHough.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVGeometry.h"
#import "OCVArrayables.h"
#import "OCVAlgorithm.h"

/*!
 *  Reference type: cv::GeneralizedHough
 */
@interface OCVGeneralizedHough : OCVAlgorithm

@property (nonatomic, assign) NSInteger cannyLowThreshold;
@property (nonatomic, assign) NSInteger cannyHighThreshold;
@property (nonatomic, assign) double minimumDistance;
@property (nonatomic, assign) double dp;

@property (nonatomic, assign) NSInteger maxBufferSize;

@end
