//
//  OCVVideoCamera.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera+Private.h"
#import "OCVMat+Private.h"

#import "OCVVideoCamera.h"

@interface OCVVideoCamera () <CvVideoCameraDelegate>

@end

@implementation OCVVideoCamera

- (void)setDelegate:(id<OCVVideoCameraDelegate>)delegate {
    ((CvVideoCamera *)self.source).delegate = self;
}

- (instancetype)initWithParentView:(UIView *)parent {
    self = [super initWithObject:[[CvVideoCamera alloc] initWithParentView:parent]];
    
    return self;
}

//
// MARK: CvVideoCameraDelegate
//

- (void)processImage:(cv::Mat &)image {
    [self.delegate processImage:[[OCVMat alloc] initWithMatInstance:image]];
}

@end
