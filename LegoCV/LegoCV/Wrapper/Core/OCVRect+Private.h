//
//  OCVRect+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVRect.h"

#import <opencv2/core/core.hpp>

cv::Rect convertRect(OCVRect rect) {
    cv::Rect finalRect;
    
    finalRect.x = (int)rect.origin.x;
    finalRect.y = (int)rect.origin.y;
    finalRect.width = (int)rect.size.width;
    finalRect.height = (int)rect.size.height;
    
    return finalRect;
}
