//
//  OCVFileStorage.h
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

#import "OCVSerializable.h"
#import "OCVInputArrayable.h"


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

@property (nonatomic, readonly) NSInteger state;
@property (nonatomic, readonly) BOOL isOpened;
@property (nullable, nonatomic, readonly) NSString *elementName;

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
//- (void)setObject:(id)obj atIndexedSubscript:(NSString *)idx;

#pragma mark - Write Methods

- (void)writeRawWithFormat:(NSString *)format data:(NSData *)data;
- (void)writeRawWithFormat:(NSString *)format data:(void *)data length:(NSInteger)length;

- (void)writeRawWithDescriptor:(OCVFileStorageFormatDescriptor *)descriptor data:(NSData *)data;
- (void)writeRawWithDescriptor:(OCVFileStorageFormatDescriptor *)descriptor data:(void *)data length:(NSInteger)length;

- (void)writeObject:(id<OCVSerializable>)object withName:(NSString *)name;

- (void)writeDouble:(double)value withName:(NSString *)name;
- (void)writeString:(NSString *)string withName:(NSString *)name;
- (void)writeSource:(id<OCVInputArrayable>)source withName:(NSString *)name;

- (void)writeComment:(NSString *)comment;
- (void)writeComment:(NSString *)comment append:(BOOL)append;

- (void)writeInt:(int)value;
- (void)writeInteger:(NSInteger)value;
- (void)writeFloat:(float)value;
- (void)writeDouble:(double)value;
- (void)writeString:(NSString *)value;

#pragma mark - Class Methods

+ (NSString *)defaultObjectNameForFilename:(NSString *)filename;

@end

NS_ASSUME_NONNULL_END
