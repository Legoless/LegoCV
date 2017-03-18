//
//  OCVSubdiv2D.h
//  LegoCV
//
//  Created by Dal Rupnik on 18/03/2017.
//  Copyright © 2017 Unified Sense. All rights reserved.
//

#import "OCVObject.h"
#import "OCVGeometry.h"

/*!
 *  Reference type: cv::Subdiv2D::Point location cases
 */
typedef NS_ENUM(NSInteger, OCVSubdiv2DPointLocationType) {
    OCVSubdiv2DPointLocationTypeError        = -2, //!< Point location error
    OCVSubdiv2DPointLocationTypeOutsideRect  = -1, //!< Point outside the subdivision bounding rect
    OCVSubdiv2DPointLocationTypeInside       = 0, //!< Point inside some facet
    OCVSubdiv2DPointLocationTypeVertex       = 1, //!< Point coincides with one of the subdivision vertices
    OCVSubdiv2DPointLocationTypeOnEdge       = 2  //!< Point on some edge
};

/*!
 *  Reference type: cv::Subdiv2D::Edge type navigation
 */
typedef NS_ENUM(NSInteger, OCVSubdiv2DEdgeType) {
    OCVSubdiv2DEdgeTypeNextAroundOrg        = 0x00,
    OCVSubdiv2DEdgeTypeNextAroundDst        = 0x22,
    OCVSubdiv2DEdgeTypePreviousAroundOrg    = 0x11,
    OCVSubdiv2DEdgeTypePreviousAroundDst    = 0x33,
    OCVSubdiv2DEdgeTypeNextAroundLeft       = 0x13,
    OCVSubdiv2DEdgeTypeNextAroundRight      = 0x31,
    OCVSubdiv2DEdgeTypePreviousAroundLeft   = 0x20,
    OCVSubdiv2DEdgeTypePreviousAroundRight  = 0x02
};

/*!
 *  Used with locating point methods
 */
typedef struct OCVSubdiv2DLocateResult {
    OCVSubdiv2DEdgeType edgeType;
    NSInteger edge;
    NSInteger vertex;
} OCVSubdiv2DLocateResult;

typedef struct OCVSubdiv2DNearestResult {
    OCVPoint2f nearestPoint;
    NSInteger vertex;
} OCVSubdiv2DNearestResult;

NS_ASSUME_NONNULL_BEGIN

/*!
 *  Reference type: cv::Subdiv2D
 */
@interface OCVSubdiv2D : OCVObject

- (instancetype)initWithRect:(OCVRect)rect;

- (void)setupDelaunayWithRect:(OCVRect)rect;
- (NSInteger)insertPoint:(OCVPoint2f)point;

/*!
 *  Inserts vector of OCVPoint2f structs
 *
 *  TODO: Add Swift wrapper for this
 */
- (NSInteger)insertArray:(NSArray<NSValue *> *)array;

- (OCVSubdiv2DLocateResult)locatePoint:(OCVPoint2f)point;

- (OCVSubdiv2DNearestResult)findNearestWithPoint:(OCVPoint2f)point;

@end

NS_ASSUME_NONNULL_END
