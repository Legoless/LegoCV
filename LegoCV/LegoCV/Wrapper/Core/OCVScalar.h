//
//  OCVScalar.h
//  LegoCV
//
//  Created by Dal Rupnik on 30/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct OCVScalar {
    double value[4];
}
OCVScalar;

OCVScalar OCVScalarRGB(double r, double g, double b) CF_SWIFT_NAME(OCVScalar.init(r:g:b:));
