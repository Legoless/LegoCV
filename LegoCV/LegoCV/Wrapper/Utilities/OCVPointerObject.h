//
//  OCVPointerObject.h
//  LegoCV
//
//  Created by Dal Rupnik on 22/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

@interface OCVPointerObject : OCVObject {
   
@public
    void *pointer;
}

- (instancetype)initWithPointer:(void *)unsafePointer;

@end
