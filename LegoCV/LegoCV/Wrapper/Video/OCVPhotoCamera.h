//
//  OCVPhotoCamera.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera.h"

@class OCVPhotoCamera;

@protocol OCVPhotoCameraDelegate <NSObject>

- (void)photoCamera:(OCVPhotoCamera *)photoCamera capturedImage:(UIImage *)image;
- (void)photoCameraCancel:(OCVPhotoCamera *)photoCamera;

@end

@interface OCVPhotoCamera : OCVCamera

@property (nonatomic, weak) id<OCVPhotoCameraDelegate> delegate;

- (void)takePicture;

@end
