//
//  OCVCascadeClassifier.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core/core.hpp>
#import <opencv2/objdetect/objdetect.hpp>

#import "OCVCascadeClassifier.h"

@interface OCVCascadeClassifier ()

@property (nonatomic, readonly) cv::CascadeClassifier* classifier;

@end

@implementation OCVCascadeClassifier

- (cv::CascadeClassifier *)classifier {
    return (cv::CascadeClassifier *)pointer;
}

- (instancetype)init {
    cv::CascadeClassifier* classifier = new cv::CascadeClassifier();
    
    self = [super initWithPointer:classifier];
    
    return self;
}

@end
