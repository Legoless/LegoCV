//
//  OCVInputArray.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
//#import "OCVMat.h"

typedef NS_ENUM(NSInteger, OCVInputArrayType) {
    OCVInputArrayTypeMat        = 65536,
    OCVInputArrayTypeExpression = 393216
};

@interface OCVInputArray : OCVObject

@property (nonatomic, readonly) OCVInputArrayType type;

#pragma mark - Public Methods

- (NSInteger)channels;
- (NSInteger)channelsWithIndex:(NSInteger)index;

- (NSInteger)depth;
- (NSInteger)depthWithIndex:(NSInteger)index;

//- (OCVMat *)mat;

@end
