//
//  OCVGeneralizedHoughGuil.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVGeneralizedHough.h"

/*!
 *  Reference type: cv::GeneralizedHoughGuil
 */
@interface OCVGeneralizedHoughGuil : OCVGeneralizedHough

@property (nonatomic, assign) double xi;
@property (nonatomic, assign) NSInteger levels;
@property (nonatomic, assign) double angleEpsilon;
@property (nonatomic, assign) double minAngle;
@property (nonatomic, assign) double maxAngle;
@property (nonatomic, assign) double angleStep;
@property (nonatomic, assign) NSInteger angleThreshold;
@property (nonatomic, assign) double maxScale;
@property (nonatomic, assign) double scaleStep;
@property (nonatomic, assign) NSInteger scaleThreshold;
@property (nonatomic, assign) NSInteger positionThreshold;

@end
