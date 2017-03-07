//
//  OCVFileStorageFormatDescriptor.h
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

typedef NS_ENUM(NSInteger, OCVFileStorageFormatType) {
    OCVFileStorageFormatType8BitUnsigned,
    OCVFileStorageFormatType8BitSigned,
    OCVFileStorageFormatType16BitUnsigned,
    OCVFileStorageFormatType16BitSigned,
    OCVFileStorageFormatType32BitSigned,
    OCVFileStorageFormatTypeSinglePrecisionFloat,
    OCVFileStorageFormatTypeDoublePrecisionFloat,
    OCVFileStorageFormatType32BitPointer
};

NS_ASSUME_NONNULL_BEGIN
/*!
 *  See @format_spec in OpenCV
 *
 *  Describes format of the array being written.
 */
@interface OCVFileStorageFormatDescriptor : OCVObject

/*!
 *  Converted format for OpenCV
 */
@property (nonatomic, readonly) NSString *format;

- (void)addFormatOfType:(OCVFileStorageFormatType)type;
- (void)addFormatOfType:(OCVFileStorageFormatType)type withCount:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
