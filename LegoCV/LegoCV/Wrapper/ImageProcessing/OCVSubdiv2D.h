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

typedef NS_ENUM(NSInteger, OCVSubdiv2DRotationType) {
    OCVSubdiv2DRotationTypeInputEdge                = 0,
    OCVSubdiv2DRotationTypeRotatedEdge              = 1,
    OCVSubdiv2DRotationTypeReversedEdge             = 2,
    OCVSubdiv2DRotationTypeReversedRotatedEdge      = 3
};

//
// MARK: Utility classes and structs to improve API design
//


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

typedef struct OCVSubdiv2DVertexResult {
    OCVPoint2f vertex;
    NSInteger firstEdge;
} OCVSubdiv2DVertexResult;

typedef struct OCVSubdiv2DEdgePointResult {
    NSInteger edge;
    OCVPoint2f point;
} OCVSubdiv2DEdgePointResult;

NS_ASSUME_NONNULL_BEGIN

@interface OCVVoronoiFacetResult : OCVObject

//
// TODO: Implement type here, array of arrays of OCVPoint2f
//
@property (nonatomic, strong) NSArray <NSArray *> * facets;

//
// TODO: Implement type here, array of OCVPoint2f
//
@property (nonatomic, strong) NSArray* facetCenters;

@end

/*!
 *  Reference type: cv::Subdiv2D
 */
@interface OCVSubdiv2D : OCVObject

//
// TODO: Implement type here, an array of Vec4f elements
//
@property (nonatomic, readonly) NSArray* edges;

//
// TODO: Implement Swift wrapper, numbers are all integers
//
@property (nonatomic, readonly) NSArray<NSNumber *>* leadingEdges;

//
// TODO: Implement type here, an array of Vec6f elements
//
@property (nonatomic, readonly) NSArray* triangles;


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

- (OCVVoronoiFacetResult *)voronoiFacetListWithIndexes:(NSArray<NSNumber *> *)indexes;

- (OCVSubdiv2DVertexResult)vertexResultWithId:(NSInteger)vertex;

- (NSInteger)edgeWithEdge:(NSInteger)edge nextEdgeType:(OCVSubdiv2DEdgeType)nextEdgeType;
- (NSInteger)nextEdgeWithEdge:(NSInteger)edge;

- (NSInteger)rotateEdgeWithEdge:(NSInteger)edge rotationType:(OCVSubdiv2DRotationType)rotationType;
- (NSInteger)symEdgeWithEdge:(NSInteger)edge;

- (OCVSubdiv2DEdgePointResult)edgeOriginWithEdge:(NSInteger)edge;
- (OCVSubdiv2DEdgePointResult)edgeDistanceToEdge:(NSInteger)edge;

@end

NS_ASSUME_NONNULL_END
