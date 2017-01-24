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
- (instancetype)initWithPath:(NSString *)path;

/*!
 *  Needs to be absolute path to the XML model for classifier: Bundle.main.bundlePath + relativePath
 */
- (void)loadPath:(NSString *)path;
- (void)loadURL:(NSURL *)url;

@end
