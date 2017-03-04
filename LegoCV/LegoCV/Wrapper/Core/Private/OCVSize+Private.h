//
//  OCVSize+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVSize.h"
#import <opencv2/core.hpp>

cv::Size convertSize(OCVSize size);
OCVSize convertSize(cv::Size size);
