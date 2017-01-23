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

@property (nonatomic, readonly) CvPhotoCamera *cameraSource;

@end

@implementation OCVPhotoCamera

- (CvPhotoCamera *)cameraSource {
    return (CvPhotoCamera *)self.source;
}

- (void)setDelegate:(id<OCVPhotoCameraDelegate>)delegate {
    _delegate = delegate;
    
    self.cameraSource.delegate = self;
}

- (instancetype)initWithParentView:(UIView *)parent {
    self = [super initWithObject:[[CvPhotoCamera alloc] initWithParentView:parent]];
        
    return self;
}

- (void)takePicture {
    [self.cameraSource takePicture];
}

#pragma mark - CvPhotoCameraDelegate

- (void)photoCamera:(CvPhotoCamera*)photoCamera capturedImage:(UIImage *)image {
    [self.delegate photoCamera:self capturedImage:image];
}
- (void)photoCameraCancel:(CvPhotoCamera*)photoCamera {
    [self.delegate photoCameraCancel:self];
}

@end
