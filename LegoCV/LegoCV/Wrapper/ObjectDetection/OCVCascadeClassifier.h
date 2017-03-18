//
//  OCVCascadeClassifier.h
//  LegoCV
//
//  Created by Dal Rupnik on 24/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVBaseCascadeClassifier.h"
#import "OCVInputArrayable.h"
#import "OCVSize.h"
#import "OCVRect.h"
#import "OCVPersistence.h"

NS_ASSUME_NONNULL_BEGIN

@interface OCVCascadeClassifier : OCVBaseCascadeClassifier

- (void)readWithNode:(OCVFileNode *)node;

@end

NS_ASSUME_NONNULL_END
