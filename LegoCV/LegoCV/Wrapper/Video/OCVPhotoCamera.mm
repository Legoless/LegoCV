//
//  OCVPhotoCamera.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera+Private.h"

#import "OCVPhotoCamera.h"

@interface OCVPhotoCamera ()

@end

@implementation OCVPhotoCamera

- (instancetype)initWithParentView:(UIView *)parent {
    self = [super initWithParentView:parent];
    
    if (self) {
        self.source = [[CvPhotoCamera alloc] initWithParentView:parent];
    }
    
    return self;
}

- (void)takePicture {
    [((CvPhotoCamera *)self.source) takePicture];
}

@end
