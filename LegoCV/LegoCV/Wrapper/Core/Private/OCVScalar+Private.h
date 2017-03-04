//
//  OCVScalar+Private.h
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVScalar.h"

#import <opencv2/core.hpp>

CvScalar convertScalar(OCVScalar scalar);

OCVScalar convertScalar(CvScalar rect);
