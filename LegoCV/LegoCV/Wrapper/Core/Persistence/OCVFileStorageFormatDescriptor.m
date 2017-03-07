//
//  OCVFileStorageFormatDescriptor.m
//  LegoCV
//
//  Created by Dal Rupnik on 07/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVFileStorageFormatDescriptor.h"

NSString* NSStringFromFileStorageFormatType(OCVFileStorageFormatType type) {
    switch (type) {
        case OCVFileStorageFormatType8BitUnsigned:
            return @"u";
        case OCVFileStorageFormatType8BitSigned:
            return @"c";
        case OCVFileStorageFormatType16BitUnsigned:
            return @"w";
        case OCVFileStorageFormatType16BitSigned:
            return @"s";
        case OCVFileStorageFormatType32BitSigned:
            return @"i";
        case OCVFileStorageFormatTypeSinglePrecisionFloat:
            return @"f";
        case OCVFileStorageFormatTypeDoublePrecisionFloat:
            return @"d";
        case OCVFileStorageFormatType32BitPointer:
            return @"r";
        default:
            return @"";
    }
}

@interface OCVFileStorageFormatDescriptor ()

@property (nonatomic, strong) NSMutableString *formatStore;

@end

@implementation OCVFileStorageFormatDescriptor

#pragma mark - Properties

- (NSMutableString *)formatStore {
    if (!_formatStore) {
        _formatStore = [[NSMutableString alloc] init];
    }
    
    return _formatStore;
}

- (NSString *)format {
    return [self.formatStore copy];
}

#pragma mark - Public Methods

- (void)addFormatOfType:(OCVFileStorageFormatType)type {
    [self.formatStore appendString:NSStringFromFileStorageFormatType(type)];
}

- (void)addFormatOfType:(OCVFileStorageFormatType)type withCount:(NSInteger)count {
    if (count > 1) {
        [self.formatStore appendFormat:@"%ldd", (long)count];
    }
    
    [self.formatStore appendString:NSStringFromFileStorageFormatType(type)];
}

@end

