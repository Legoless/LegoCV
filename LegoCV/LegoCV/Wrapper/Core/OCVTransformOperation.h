//
//  OCVTransformOperation.h
//  LegoCV
//
//  Created by Dal Rupnik on 04/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//


#import "OCVObject.h"
#import "OCVInputArrayable.h"
#import "OCVOutputArrayable.h"
#import "OCVInputOutputArrayable.h"

#import "OCVGeometry.h"
#import "OCVTypes.h"

#import "OCVVector.h"
#import "OCVUMat.h"
#import "OCVSparseMat.h"

#import "OCVMinimumMaximum.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Wraps transform operations defined in core.hpp such as DFT and DCT
 */
@interface OCVTransformOperation : OCVObject

@end

NS_ASSUME_NONNULL_END
