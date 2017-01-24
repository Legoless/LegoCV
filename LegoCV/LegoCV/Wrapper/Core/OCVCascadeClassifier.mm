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

- (instancetype)initWithPath:(NSString *)path {
    self = [self init];
    
    if (self) {
        [self loadPath:path];
    }
    
    return self;
}

- (instancetype)initWithURL:(NSURL *)url {
    return [self initWithPath:[self.class convertUrlToPath:url]];
}

- (void)loadURL:(NSURL *)url {
    [self loadPath:[self.class convertUrlToPath:url]];
}

- (void)loadPath:(NSString *)path {
    self.classifier->load(path.UTF8String);
}

#pragma mark - Private Class Methods

+ (NSString *)convertUrlToPath:(NSURL *)url {
    //
    // TODO: Correctly handle all path variants, such as file://
    //
    
    return [url absoluteString];
}

@end
