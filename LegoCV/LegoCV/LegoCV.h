//
//  LegoCV.h
//  LegoCV
//
//  Created by Dal Rupnik on 14/01/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

@import Foundation;

//! Project version number for LegoCV.
FOUNDATION_EXPORT double LegoCVVersionNumber;

//! Project version string for LegoCV.
FOUNDATION_EXPORT const unsigned char LegoCVVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LegoCV/PublicHeader.h>

#if __has_include("OCVCore.h")
#import "OCVCore.h"
#endif

#if __has_include("OCVImageProcessing.h")
#import "OCVImageProcessing.h"
#endif

#if __has_include("OCVVideo.h")
#import "OCVVideo.h"
#endif
