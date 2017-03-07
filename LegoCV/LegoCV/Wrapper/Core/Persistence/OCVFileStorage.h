//
//  OCVFileStorage.h
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

/*!
 *  Reference type: cv::FileStorage Mode
 */
typedef NS_OPTIONS(NSInteger, OCVFileStorageModes) {
    OCVFileStorageModeRead          = 0,        //!< value, open the file for reading
    OCVFileStorageModeWrite         = 1,        //!< value, open the file for writing
    OCVFileStorageModeAppend        = 2,        //!< value, open the file for appending
    OCVFileStorageModeMemory        = 4,        //!< flag, read data from source or write data to the internal buffer (which is
    OCVFileStorageModeFormatMask    = (7<<3),   //!< mask for format flags
    OCVFileStorageModeFormatAuto    = 0,        //!< flag, auto format
    OCVFileStorageModeFormatXml     = (1<<3),   //!< flag, XML format
    OCVFileStorageModeFormatYaml    = (2<<3),   //!< flag, YAML format
    OCVFileStorageModeFormatJson    = (3<<3),   //!< flag, JSON format
    
    OCVFileStorageModeBase64        = 64,       //!< flag, write rawdata in Base64 by default. (consider using OCVFileStorageModeWriteBase64)
    OCVFileStorageModeWriteBase64   = OCVFileStorageModeBase64 | OCVFileStorageModeWrite, //!< flag, enable both Write and Base64
};

/*!
 *  cv::FileStorage
 */
@interface OCVFileStorage : OCVObject

@end
