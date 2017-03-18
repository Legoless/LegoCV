//
//  OCVPoint.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  Reference type: cv::Point, cv::Point2i, cv::Point_<int>
 */
typedef struct OCVPoint
{
    NSInteger x;
    NSInteger y;
}
OCVPoint;

/*!
 *  Reference type: cv::Point2f, cv::Point_<float>
 */
typedef struct OCVPoint2f {
    float x;
    float y;
} OCVPoint2f;
