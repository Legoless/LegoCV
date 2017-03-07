//
//  OCVFileNode.h
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"

#import "OCVFileStorageFormatDescriptor.h"

@class OCVMat;

typedef NS_ENUM(NSInteger, OCVFileNodeType) {
    OCVFileNodeTypeNone      = 0, //!< empty node
    OCVFileNodeTypeInteger   = 1, //!< an integer
    OCVFileNodeTypeReal      = 2, //!< floating-point number
    OCVFileNodeTypeString    = 3, //!< text string in UTF-8 encoding
    OCVFileNodeTypeReference = 4, //!< integer of size size_t. Typically used for storing complex dynamic structures where some elements reference the others
    OCVFileNodeTypeSequence  = 5, //!< sequence
    OCVFileNodeTypeMap       = 6, //!< mapping
    OCVFileNodeTypeTypeMask  = 7,
    OCVFileNodeTypeFlow      = 8,  //!< compact representation of a sequence or mapping. Used only by YAML writer
    OCVFileNodeTypeUser      = 16, //!< a registered object (e.g. a matrix)
    OCVFileNodeTypeEmpty     = 32, //!< empty structure (sequence or mapping)
    OCVFileNodeTypeNamed     = 64  //!< the node has a name (i.e. it is element of a mapping)};
};

NS_ASSUME_NONNULL_BEGIN

@interface OCVFileNode : OCVObject

@property (nonatomic, readonly) OCVFileNodeType type;

@property (nonatomic, readonly) BOOL isEmpty;

@property (nullable, nonatomic, readonly) NSString* name;

@property (nonatomic, readonly) NSInteger size;

- (instancetype)initWithNode:(OCVFileNode *)node;

//
// MARK: Subscript
//

/*!
 *  Only available if type == map
 */
- (nullable OCVFileNode *)objectAtIndexedSubscript:(NSString *)idx;

/*!
 *  Only available if type == sequence
 */
- (nullable OCVFileNode *)objectAtIndex:(NSInteger)index;

//
// TODO: Add File Node Iterator??
//

#pragma mark - Read methods

- (NSData *)readRawWithFormat:(NSString *)format;
- (NSData *)readRawWithDescriptor:(OCVFileStorageFormatDescriptor *)descriptor;

//
// Following methods mimic Foundation NSNumber API.
//

- (nullable id)objectValue;
- (int)intValue;
- (NSInteger)integerValue;
- (float)floatValue;
- (double)doubleValue;
- (nullable NSString *)stringValue;

- (nullable OCVMat *)matValue;

@end

NS_ASSUME_NONNULL_END
