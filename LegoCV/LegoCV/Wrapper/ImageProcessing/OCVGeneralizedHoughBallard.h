//
//  OCVGeneralizedHoughBallard.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVGeneralizedHough.h"

/*!
 *  Reference type: cv::GeneralizedHoughBallard
 */
@interface OCVGeneralizedHoughBallard : OCVGeneralizedHough

@property (nonatomic, assign) NSInteger levels;
@property (nonatomic, assign) NSInteger voteThreshold;

@end
