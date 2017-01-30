//
//  OCVScalar.h
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

typedef struct OCVScalar {
    double value[4];
}
OCVScalar;

OCVScalar OCVScalarRGB(double r, double g, double b) {
    OCVScalar scalar;
    scalar.value[0] = r;
    scalar.value[1] = g;
    scalar.value[2] = b;
    scalar.value[3] = 0.0;
    
    return scalar;
}
