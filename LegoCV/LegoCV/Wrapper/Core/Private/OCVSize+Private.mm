//
//  OCVSize+Private.m
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVSize+Private.h"
#import <opencv2/core.hpp>

cv::Size convertSize(OCVSize size) {
    cv::Size finalSize;
    finalSize.width = (int)size.width;
    finalSize.height = (int)size.height;
    
    return finalSize;
}

OCVSize convertSize(cv::Size size) {
    OCVSize finalSize;
    finalSize.width = size.width;
    finalSize.height = size.height;
    
    return finalSize;
}
