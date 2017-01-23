//
//  OCVPhotoCamera.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera+Private.h"

#import "OCVPhotoCamera.h"

@interface OCVPhotoCamera () <CvPhotoCameraDelegate>

@end

@implementation OCVPhotoCamera

- (void)setDelegate:(id<OCVPhotoCameraDelegate>)delegate {
    ((CvPhotoCamera *)self.source).delegate = self;
}

- (instancetype)initWithParentView:(UIView *)parent {
    self = [super initWithObject:[[CvPhotoCamera alloc] initWithParentView:parent]];
        
    return self;
}

- (void)takePicture {
    [((CvPhotoCamera *)self.source) takePicture];
}

//
// MARK: CvPhotoCameraDelegate
//

- (void)photoCamera:(CvPhotoCamera*)photoCamera capturedImage:(UIImage *)image {
    [self.delegate photoCamera:self capturedImage:image];
}
- (void)photoCameraCancel:(CvPhotoCamera*)photoCamera {
    [self.delegate photoCameraCancel:self];
}

@end
