//
//  OCVScalar+Private.m
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVScalar+Private.h"

CvScalar convertScalar(OCVScalar scalar) {
    CvScalar finalScalar;
    finalScalar.val[0] = scalar.value[0];
    finalScalar.val[1] = scalar.value[1];
    finalScalar.val[2] = scalar.value[2];
    finalScalar.val[3] = scalar.value[3];
    
    return finalScalar;
}

OCVScalar convertScalar(CvScalar scalar) {
    OCVScalar finalScalar;
    finalScalar.value[0] = scalar.val[0];
    finalScalar.value[1] = scalar.val[1];
    finalScalar.value[2] = scalar.val[2];
    finalScalar.value[3] = scalar.val[3];
    
    return finalScalar;
}
