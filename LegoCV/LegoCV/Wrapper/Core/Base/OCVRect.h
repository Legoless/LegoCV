//
//  OCVRect.h
//  LegoCV
//
//  Created by Dal Rupnik on 22/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCVPoint.h"
#import "OCVSize.h"

typedef struct OCVRect
{
    OCVPoint origin;
    OCVSize size;
}
OCVRect;

/*!
 *  Objective-C class immutable wrapper for OCVRect struct
 */
@interface OCVRectValue : NSObject

@property (nonatomic, readonly) OCVRect rect;

- (instancetype)initWithRect:(OCVRect)rect;

@end
