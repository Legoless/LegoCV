//
//  OCVCamera.m
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVCamera.h"
#import "OCVCamera+Private.h"

@implementation OCVCamera

- (CvAbstractCamera *)source {
    return (CvAbstractCamera *)self.object;
}

@end
