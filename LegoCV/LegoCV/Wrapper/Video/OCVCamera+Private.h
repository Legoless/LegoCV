//
//  OCVCamera+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera.h"

#import <opencv2/videoio/cap_ios.h>

@interface OCVCamera (OpenCV)

@property (nonatomic, strong) CvAbstractCamera *source;

@end
