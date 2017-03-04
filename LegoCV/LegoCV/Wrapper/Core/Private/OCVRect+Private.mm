//
//  OCVRect+Private.m
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVRect+Private.h"

#import <opencv2/core.hpp>

cv::Rect convertRect(OCVRect rect) {
    cv::Rect finalRect;
    
    finalRect.x = (int)rect.origin.x;
    finalRect.y = (int)rect.origin.y;
    finalRect.width = (int)rect.size.width;
    finalRect.height = (int)rect.size.height;
    
    return finalRect;
}

OCVRect convertRect(cv::Rect rect) {
    OCVRect finalRect;
    finalRect.origin.x = rect.x;
    finalRect.origin.y = rect.y;
    finalRect.size.width = rect.width;
    finalRect.size.height = rect.height;
    
    return finalRect;
}

