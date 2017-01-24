//
//  OCVCascadeClassifier.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVPointerObject.h"

@interface OCVCascadeClassifier : OCVPointerObject

- (instancetype)initWithURL:(NSURL *)url;

- (void)loadURL:(NSURL *)url;

@end
