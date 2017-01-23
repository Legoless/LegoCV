//
//  OCVReferenceObject.h
//  LegoCV
//
//  Created by Dal Rupnik on 23/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

@interface OCVReferenceObject : OCVObject

@property (nonatomic, strong) id object;

- (instancetype)initWithObject:(id)object;

@end
