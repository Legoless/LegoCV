//
//  OCVSize.h
//  LegoCV
//
//  Created by Dal Rupnik on 16/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCVSize : NSObject

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height;
- (instancetype)initWithSize:(OCVSize *)size;

@end
