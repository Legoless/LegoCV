//
//  OCVCascadeClassifierOptions.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVSize.h"
#import "OCVObject.h"

/*!
 *  Reference type: cv::BaseCascadeClassifier enum
 */
typedef NS_OPTIONS(NSInteger, OCVCascadeClassifierFlags) {
    OCVCascadeClassifierFlagDoCannyPruning     = 1,
    OCVCascadeClassifierFlagScaleImage         = 2,
    OCVCascadeClassifierFlagFindBiggestObject  = 4,
    OCVCascadeClassifierFlagDoRoughSearch      = 8
};

/*!
 *  Simple object wrapper around options for cv::BaseCascadeClassifier::detectMultiScale() function.
 *  Options effectively affect the contents of the returned result object.
 *  
 *  @note: If outputLevelWeights property is set to YES, outputNumberOfDetections property is ignored,
 *         if set to NO (default), outputRejectLevels property is ignored.
 */
@interface OCVCascadeClassifierOptions : OCVObject

@property (nonatomic, assign) BOOL outputNumberOfDetections;
@property (nonatomic, assign) BOOL outputLevelWeights;
@property (nonatomic, assign) BOOL outputRejectLevels;
 
@property (nonatomic, assign) double scaleFactor;
@property (nonatomic, assign) NSInteger minNeighbors;
@property (nonatomic, assign) OCVCascadeClassifierFlags flags;
@property (nonatomic, assign) OCVSize minSize;
@property (nonatomic, assign) OCVSize maxSize;

/*!
 *  Default options will only return objects.
 */
+ (nonnull instancetype)defaultOptions;

@end
