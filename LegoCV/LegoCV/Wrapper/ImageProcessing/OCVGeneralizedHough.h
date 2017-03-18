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

- (void)setTemplateWithTemplate:(id<OCVInputArrayable>)template;
- (void)setTemplateWithTemplate:(id<OCVInputArrayable>)template withTemplateCenter:(OCVPoint)templateCenter;

- (void)detectOnImage:(id<OCVInputArrayable>)image toPositions:(id<OCVOutputArrayable>)positions;
- (void)detectOnImage:(id<OCVInputArrayable>)image toPositions:(id<OCVOutputArrayable>)positions withVotes:(id<OCVOutputArrayable>)votes;

- (void)detectEdges:(id<OCVInputArrayable>)edges withDx:(id<OCVInputArrayable>)dx withDy:(id<OCVInputArrayable>)dy toPositions:(id<OCVOutputArrayable>)positions;
- (void)detectEdges:(id<OCVInputArrayable>)edges withDx:(id<OCVInputArrayable>)dx withDy:(id<OCVInputArrayable>)dy toPositions:(id<OCVOutputArrayable>)positions withVotes:(id<OCVOutputArrayable>)votes;

@end
