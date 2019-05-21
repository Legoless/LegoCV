//
//  OCVCascadeClassifier.mm
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <opencv2/core.hpp>
#import <opencv2/objdetect.hpp>

#import "OCVCascadeClassifier.h"
#import "OCVInputArray+Private.h"

#import "OCVRect+Private.h"
#import "OCVSize+Private.h"

@interface OCVCascadeClassifier ()

@property (nonatomic, readonly) cv::CascadeClassifier* classifier;

@end

@implementation OCVCascadeClassifier

- (BOOL)isOldFormatCascade {
    return self.classifier->isOldFormatCascade();
}

- (OCVSize)originalWindowSize {
    return convertSize(self.classifier->getOriginalWindowSize());
}

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

#pragma mark - Public Methods

- (void)loadURL:(NSURL *)url {
    [self loadPath:[self.class convertUrlToPath:url]];
}

- (void)loadPath:(NSString *)path {
    self.classifier->load(path.UTF8String);
}

/*
 - (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor;
 - (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours;
 - (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags;
 - (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags minSize:(OCVSize)minSize;
 - (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags minSize:(OCVSize)minSize maxSize:(OCVSize)maxSize;

 */

- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image {
    return [self detectMultiScaleOnImage:image scaleFactor:1.1];
}

- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor {
    return [self detectMultiScaleOnImage:image scaleFactor:scaleFactor minNeighbours:3];
}

- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours {
    return [self detectMultiScaleOnImage:image scaleFactor:scaleFactor minNeighbours:minNeighbours flags:0];
}

- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags {
    return [self detectMultiScaleOnImage:image scaleFactor:scaleFactor minNeighbours:minNeighbours flags:flags minSize:OCVSize()];
}

- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags minSize:(OCVSize)minSize {
    return [self detectMultiScaleOnImage:image scaleFactor:scaleFactor minNeighbours:minNeighbours flags:flags minSize:minSize maxSize:OCVSize()];
}

- (NSArray<OCVRectValue *>*)detectMultiScaleOnImage:(id<OCVInputArrayable>)image scaleFactor:(double)scaleFactor minNeighbours:(NSInteger)minNeighbours flags:(NSInteger)flags minSize:(OCVSize)minSize maxSize:(OCVSize)maxSize {
    
    std::vector<cv::Rect> faceRects;
    
    self.classifier->detectMultiScale(*image.input._input, faceRects, scaleFactor, (int)minNeighbours, (int)flags, convertSize(minSize), convertSize(maxSize));
    
    return [self convertRects:faceRects];
}

#pragma mark - Private Methods

- (NSArray<OCVRectValue *>*)convertRects:(std::vector<cv::Rect>)rects {
    NSMutableArray *values = [NSMutableArray array];
    int i = 0;
    
    //
    // Convert Face Rects into OCVRectValue wrappers to return correctly.
    //
    
    for (std::vector<cv::Rect>::const_iterator r = rects.begin(); r != rects.end(); r++, i++) {
        OCVRect rect = convertRect(rects[i]);
        
        [values addObject:[[OCVRectValue alloc] initWithRect:rect]];
    }
    
    return values.copy;
}

#pragma mark - Private Class Methods

+ (NSString *)convertUrlToPath:(NSURL *)url {
    //
    // TODO: Correctly handle all path variants, such as file://
    //
    
    return [url absoluteString];
}

@end
