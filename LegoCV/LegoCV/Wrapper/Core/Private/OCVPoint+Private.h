//
//  OCVPoint+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVPoint.h"

#import <opencv2/core.hpp>

cv::Point convertPoint(OCVPoint point);
OCVPoint convertPoint(cv::Point point);
