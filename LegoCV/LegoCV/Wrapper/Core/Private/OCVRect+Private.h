//
//  OCVRect+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVRect.h"

#import <opencv2/core.hpp>

cv::Rect convertRect(OCVRect rect);
OCVRect convertRect(cv::Rect rect);
