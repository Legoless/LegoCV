//
//  OCVFileStorage.h
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

#import "OCVFileNode.h"

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
    OCVFileStorageModeFormatXML     = (1<<3),   //!< flag, XML format
    OCVFileStorageModeFormatYAML    = (2<<3),   //!< flag, YAML format
    OCVFileStorageModeFormatJSON    = (3<<3),   //!< flag, JSON format
    
    OCVFileStorageModeBase64        = 64,       //!< flag, write rawdata in Base64 by default. (consider using OCVFileStorageModeWriteBase64)
    OCVFileStorageModeWriteBase64   = OCVFileStorageModeBase64 | OCVFileStorageModeWrite, //!< flag, enable both Write and Base64
};

NS_ASSUME_NONNULL_BEGIN

/*!
 *  cv::FileStorage
 */
@interface OCVFileStorage : OCVObject

#pragma mark - Public Properties

@property (nonatomic, readonly) BOOL isOpened;

#pragma mark - Initialization

- (instancetype)initWithPath:(NSString *)path mode:(OCVFileStorageModes)mode;

- (instancetype)initWithPath:(NSString *)path mode:(OCVFileStorageModes)mode encoding:(NSStringEncoding)encoding;

#pragma mark - Public Methods

- (void)openWithPath:(NSString *)path mode:(OCVFileStorageModes)mode;
- (void)openWithPath:(NSString *)path mode:(OCVFileStorageModes)mode encoding:(NSStringEncoding)encoding;

- (nullable OCVFileNode *)firstTopLevelNode;

- (nullable OCVFileNode *)root;
- (nullable OCVFileNode *)rootWithStreamIndex:(NSInteger)streamIndex;

//
// MARK: Subscript
//
- (nullable OCVFileNode *)objectAtIndexedSubscript:(NSString *)idx;

// Should do nothing, only allows access.
- (void)setObject:(id)obj atIndexedSubscript:(NSString *)idx;

//
// MARK: Writing
//

@end

NS_ASSUME_NONNULL_END
