//
//  OCVImageTypes.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#ifndef OCVImageTypes_h
#define OCVImageTypes_h

/*!
 *  Reference type: cv::DistanceTypes
 */
typedef NS_ENUM(NSInteger, OCVDistanceType) {
    OCVDistanceTypeUser    = -1,  //!< User defined distance
    OCVDistanceTypeL1      = 1,   //!< distance = |x1-x2| + |y1-y2|
    OCVDistanceTypeL2      = 2,   //!< the simple euclidean distance
    OCVDistanceTypeC       = 3,   //!< distance = max(|x1-x2|,|y1-y2|)
    OCVDistanceTypeL12     = 4,   //!< L1-L2 metric: distance = 2(sqrt(1+x*x/2) - 1))
    OCVDistanceTypeFair    = 5,   //!< distance = c^2(|x|/c-log(1+|x|/c)), c = 1.3998
    OCVDistanceTypeWelsch  = 6,   //!< distance = c^2/2(1-exp(-(x/c)^2)), c = 2.9846
    OCVDistanceTypeHubar   = 7    //!< distance = |x|<c ? x^2/2 : c(|x|-c/2), c=1.345
};

#endif /* OCVImageTypes_h */
