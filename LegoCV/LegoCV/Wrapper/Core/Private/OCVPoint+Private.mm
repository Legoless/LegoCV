//
//  OCVPoint+Private.m
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVPoint+Private.h"

cv::Point convertPoint(OCVPoint point) {
    cv::Point finalPoint;
    finalPoint.x = (int)point.x;
    finalPoint.y = (int)point.y;

    return finalPoint;
}

OCVPoint convertPoint(cv::Point point) {
    OCVPoint finalPoint;
    finalPoint.x = point.x;
    finalPoint.y = point.y;
    
    return finalPoint;
}
