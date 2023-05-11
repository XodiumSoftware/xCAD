//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Copyright (C) Menhirs NV. All rights reserved.
//
// AcDbCivilTinSurface.h
// BRX API for BricsCAD Civil TinSurface functionality + interfaces
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include <memory>  // std::shared_ptr

#include "Misc/AcArray.h"
#include "AcDb/AcDbEntity.h"
#include "AcGe/AcGePoint3d.h"

#include "BrxSpecific/civil/AcDbCivilAlignments.h"


// TinSurface style, can be combined
enum ETinSurfaceStyle
{
    eTinStyleNone             = 0x00,
    eTinStyleBoundaryLine     = 0x01,
    eTinStylePoints           = 0x02,
    eTinStyleTriangles        = 0x04,
    eTinStyleContours         = 0x08,
    eTinStyleElevationTooltip = 0x10,
};

enum ETinSurfaceMeshType
{
    eTinSurfaceMeshSurface   = 0,
    eTinSurfaceMeshElevation = 1,
    eTinSurfaceMeshDepth     = 2,
};

enum ETinSurfaceIntersectType
{
    eTinSurfaceFirstOnly = 0,
    eTinSurfaceAll       = 1,
};

enum ETinSurfaceSolidType
{
    eSolidTypeSurfaceSurface   = 0,  // internal use only
    eSolidTypeSurfaceElevation = 1,
    eSolidTypeSurfaceDepth     = 2,
};


// TinSurface helper class to keep the 3 AcGePoint of a Triangle

class BRX_EXPORT TinSurfaceTriangle
{
public:
    TinSurfaceTriangle() {};
    TinSurfaceTriangle(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3)
        : m_p1(p1), m_p2(p2), m_p3(p3)
    {
    };

public:
    AcGePoint3d m_p1;
    AcGePoint3d m_p2;
    AcGePoint3d m_p3;
};
typedef AcArray< TinSurfaceTriangle, AcArrayObjectCopyReallocator<TinSurfaceTriangle> >  AcTinTrianglesArray;


// TinSurface helper classes to handle several constraints conditions

enum ETinConstraintType
{
    eTinBreakline  = 0,
    eTinBoundary   = 1,
    eTinWall       = 2,
};

enum ETinBreaklineType
{
    eTinBreaklineNomal = 0,
    eTinNonDestructive = 1,
};

enum ETinIntersectionElevation
{
    eTinNotAllowed   = 0,
    eTinElevationMin = 1,
    eTinElevationMax = 2,
    eTinElevationMid = 3,
};

enum ETinWallType
{
    eTinWallNomal     = 0,
    eTinWallProjected = 1,
};

enum ETinWallSide
{
    eTinWallLeft  = 0,
    eTinWallRight = 1,
};

enum ETinBoundaryType
{
    eTinShow  = 0,
    eTinHide  = 1,
    eTinOuter = 2,
};

// TinSurfaceConstraint : base class for all constraints
class BRX_EXPORT TinSurfaceConstraint
{
    friend class AcDbCivilTinSurface;

protected:
    // ! underlying core data - for internal use only !
    std::shared_ptr<class TinConstraint>  m_constraint = nullptr;

public:
    TinSurfaceConstraint();
    TinSurfaceConstraint(const ETinConstraintType type);
    TinSurfaceConstraint(const TinSurfaceConstraint& other);
    virtual ~TinSurfaceConstraint();

    TinSurfaceConstraint& operator=(const TinSurfaceConstraint& other);

    ETinConstraintType constraintType() const;

    void setData(const Adesk::UInt64 id, const AcGePoint3dArray& points);
    void setData(const AcDbObjectId& id, const double midOrdinateDist);
    AcGePoint3dArray data() const;
    Adesk::UInt64 id() const;

    // the 'mid-ordinate distance' is the distance of the curve's midpoint, to the arc center;
    // similar to arc's bulge; used as a kind of tolerance
    // https://civil3dplus.wordpress.com/2012/12/23/surfaces-and-the-mid-ordinate-distance/
    void   setMidOrdinateDistance(const double midOrdinateDist);
    double midOrdinateDistance() const;

    void setIsDbResident(const bool isResident);
    bool isDbResident() const;
};
typedef AcArray<TinSurfaceConstraint>  AcTinSurfaceConstraintArray;

// TinSurfaceBreakline : breakline constraint
class BRX_EXPORT TinSurfaceBreakline : public TinSurfaceConstraint
{
public:
    TinSurfaceBreakline(const ETinBreaklineType type);

    ETinBreaklineType breaklineType() const;

    ETinIntersectionElevation intersectionElevation() const;
    void setIntersectionElevation(const ETinIntersectionElevation elevationType);
};

// TinSurfaceWall : wall constraint
class BRX_EXPORT TinSurfaceWall : public TinSurfaceConstraint
{
public:
    TinSurfaceWall(const ETinWallType wallType);

    ETinWallType wallType() const;

    double height() const;
    void setHeight(const double height);

    void setWallSide(const ETinWallSide side);
    ETinWallSide wallSide() const;
};

// TinSurfaceBoundary : boundary constraint
class BRX_EXPORT TinSurfaceBoundary : public TinSurfaceConstraint
{
public:
    TinSurfaceBoundary(const ETinBoundaryType boundaryType);

    ETinBoundaryType boundaryType() const;
};


//========================== AcDbCivilTinSurface ===============================

class AcDbCivilTinSurface;
class AcCivilTinTriangle;
class AcCivilTinPoint;

/** class to hold a TinPoint, keeps references to underlying Civil TinSurface Point */
class BRX_EXPORT AcCivilTinPoint
{
    friend AcCivilTinTriangle;
    friend AcDbCivilTinSurface;

    void* m_pImpl = nullptr;

public:
    AcCivilTinPoint();
    virtual ~AcCivilTinPoint();

    operator void*() const;

    // returns the triangle object which contains this 'AcCivilTinPoint' point object
    AcCivilTinTriangle triangleWithPoint() const;

    // returns the geometric location/point for this 'AcCivilTinPoint' point object
    AcGePoint3d location() const;

    // returns whether this 'AcCivilTinPoint' point object is valid (not empty)
    bool        isValid() const;
};
typedef AcArray< AcCivilTinPoint, AcArrayObjectCopyReallocator<AcCivilTinPoint> >  AcCivilTinPointArray;


/** class to hold a TinTriangle, keeps references to underlying Civil TinSurface Triangle */
class BRX_EXPORT AcCivilTinTriangle
{
    friend AcCivilTinPoint;
    friend AcDbCivilTinSurface;

    void* m_pImpl = nullptr;

public:
    AcCivilTinTriangle();
    virtual ~AcCivilTinTriangle();

    operator void*() const;

    // returns the tin point object for this 'AcCivilTinTriangle' triangle object,
    // for the specified index (0...2)
    AcCivilTinPoint pointAt(const Adesk::UInt16 index) const;

    // returns the geometric location/point for this 'AcCivilTinTriangle' triangle object,
    // for the specified index (0...2)
    AcGePoint3d     locationAt(const Adesk::UInt16 index) const;

    // returns whether this 'AcCivilTinTriangle' triangle object is visible (false, if not a valid triangle)
    bool            isVisible() const;

    // returns whether this 'AcCivilTinTriangle' triangle object is valid (not empty)
    bool            isValid() const;

    // returns the neighboring tin triangle for this 'AcCivilTinTriangle' triangle object,
    // for the specified index (0...2)
    AcCivilTinTriangle neighborAt(const Adesk::UInt16 index) const;
};
typedef AcArray< AcCivilTinTriangle, AcArrayObjectCopyReallocator<AcCivilTinTriangle> >  AcCivilTinTriangleArray;


// support for std::unordered_set<> and std::unordered_map<>, using AcCivilTinPoint and AcCivilTinTriangle
namespace std
{
    template<> struct hash<AcCivilTinPoint>
    {
        size_t operator()(const AcCivilTinPoint& tinPoint) const
        {
            return hash<void*>()((void*)tinPoint);
        }
    };
    template<> struct hash<AcCivilTinTriangle>
    {
        size_t operator()(const AcCivilTinTriangle& tinTriangle) const
        {
            return hash<void*>()((void*)tinTriangle);
        }
    };
}


/** _ */
class BRX_EXPORT AcDbCivilTinSurface: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbCivilTinSurface);

    AcDbCivilTinSurface();
    virtual ~AcDbCivilTinSurface();

    // formal setup of the TinSurface, mainly for optimal memory handling
    // (the specified bounds are not enforced)
    virtual void initialize(const AcGePoint3d& minPt, const AcGePoint3d& maxPt, const size_t numOfPoints);

    // the TinSurface updates internal data (i.e. after adding points or parameters or constraints etc.)
    // automatically when the TinSurface object closes;
    // this function enforces synchronisation, when the TinSurface object is actually still open
    // (should be necessary in rare cases only)
    virtual void updateObjectData();

    //========== Edit Functions ==========

    // get/set the name of the TinSurface (or derived) entity
    // note : the "name" property is just informative, are not enforced to be unique,
    //        and there are no further requirements or implicit constraints related to "name"
    virtual const ACHAR* name() const;
    virtual void         setName(const ACHAR* szName);

    // get/set the description of the TinSurface (or derived) entity
    virtual const ACHAR* description() const;
    virtual void         setDescription(const ACHAR* szDescription);

    // adds a single point to the TinSurface
    virtual bool addPoint(const AcGePoint3d& point);

    // adds a set of points to the TinSurface
    virtual bool addPoints(const AcGePoint3dArray& points);

    // removes a single point to the TinSurface
    virtual bool removePoint(const AcGePoint3d& points);

    // removes a set of points to the TinSurface
    virtual bool removePoints(const AcGePoint3dArray& points);

    // moves a single point, or a set of points, to a new position
    virtual bool movePoint(const AcGePoint3d& from, const AcGePoint3d& to);
    virtual bool movePoints(const AcGePoint3dArray& from, const AcGePoint3dArray& to);

    // swap the edge which is closest to the specified point
    virtual bool swapEdge(const AcGePoint3d& atPoint);

    // sets the style of the TinSurface, bit-flag
    virtual bool setStyle(const ETinSurfaceStyle style);

    // sets whether the TinSurface is associative or not
    virtual bool setAssociative(const bool isAssociative);

    // translates the TinSurface by 'offset' in Z direction
    virtual bool raiseSurface(const double offset);

    // sets an overall elevation for the TinSurface (all points are set to Z=elevation)
    virtual bool setSurfaceElevation(const double elevation);

    // changes the specified points to new Z values (1-1 relation between the 2 arrays)
    virtual bool changePointsElevations(const AcGePoint3dArray& points, const AcGeDoubleArray& newZValues);

    // sets the interval for the minor contour levels
    virtual bool setMinorContoursInterval(const double interval);

    // sets the interval for the major contour levels
    virtual bool setMajorContoursInterval(const double interval);

    // sets the index color for the minor contour levels
    virtual bool setMinorContoursColor(const Adesk::UInt16 colorIndex);

    // sets the index color for the major contour levels
    virtual bool setMajorContoursColor(const Adesk::UInt16 colorIndex);

    // merge another surface into this surface entity
    virtual bool merge(const AcDbCivilTinSurface* theOther);

    // merge 2 surfaces and create new surface
    static AcDbCivilTinSurface* merge(const AcDbCivilTinSurface* theOne, const AcDbCivilTinSurface* theOther);


    //========== Query Functions ==========

    // returns the used geometric points (all or visible only)
    virtual bool getPoints(AcGePoint3dArray& points, const bool visibleOnly = false) const;

    // returns the used tin points as array of 'AcCivilTinPoint*'
    virtual bool getTinPoints(AcCivilTinPointArray& tinPoints) const;

    // returns the tin point at geometric location of 'pnt'
    virtual bool findTinPointAt(AcCivilTinPoint& tinPoint, const AcGePoint3d& pnt) const;

    // returns the array of TinSurfaceTriangle (each triangle is 'TinSurfaceTriangle')
    virtual bool triangles(AcTinTrianglesArray& triangles, const bool visibleOnly = false) const;

    // returns the used tin triangles as array of 'AcCivilTinTriangle'
    virtual bool tinTriangles(AcCivilTinTriangleArray& tinTriangles) const;

    // returns the tin triangles (as array of 'AcCivilTinTriangle') sharing the geometric location of 'pnt'
    virtual bool findTinTrianglesAt(AcCivilTinTriangleArray& tinTriangles, const AcGePoint3d& pnt) const;

    // returns the number of used points (all or visible only)
    virtual size_t pointsCount(const bool visibleOnly = false) const;

    // returns number of used triangles (all or visible only)
    virtual size_t trianglesCount(const bool visibleOnly = false) const;

    // returns the 2d area
    virtual double area2d(const bool visibleOnly = false) const;

    // returns the 3d area
    virtual double area3d(const bool visibleOnly = false) const;

    // returns the min. surface elevation
    virtual double minElevation(const bool visibleOnly = false) const;

    // returns the max. surface elevation
    virtual double maxElevation(const bool visibleOnly = false) const;

    // verifies whether this TinSurface contains the specified point
    virtual bool contains(const AcGePoint3d& point) const;

    // returns the elevation at the specified point in 'elevation', if the function succeeds
    // (else the specified point is not in the geometric range of the TinSurface)
    virtual bool elevationAtPoint(const AcGePoint3d& point, double& elevation) const;

    // returns the TinSurface point, which is closest to the specified point
    virtual AcGePoint3d closestPointTo(const AcGePoint3d& point) const;

    // returns the geometric extents of the TinSurface
    virtual bool boundingBox(AcGePoint2d& ptMin, AcGePoint2d& ptMax) const;

    // returns the set of points located inside the specified polygon of the TinSurface
    virtual AcGePoint3dArray getPointsInsidePolygon(const AcGePoint3dArray& polygon, bool includeOnEdge = true) const;

    // returns the style of the TinSurface
    virtual ETinSurfaceStyle style() const;

    // returns whether the TinSurface is associative or not
    virtual bool isAssociative() const;

    // returns an AcArray of borders (each border is an AcGePoint3dArray) for the TinSurface;
    // outermost border is the first array entry
    virtual bool getBorders(AcArray<AcGePoint3dArray>& borders) const;

    // returns the interval for the minor contour levels
    virtual bool minorContoursInterval(double& interval) const;

    // returns the color index for the major contour levels
    virtual bool majorContoursInterval(double& interval) const;

    // returns the color index for the minor contour levels
    virtual bool minorContoursColor(Adesk::UInt16& colorIndex) const;

    // returns the color index for the major contour levels
    virtual bool majorContoursColor(Adesk::UInt16& colorIndex) const;

    // returns the array of minor contour levels
    virtual bool minorContours(AcArray<AcGePoint3dArray>& minContours) const;

    // returns the array of major contour levels
    virtual bool majorContours(AcArray<AcGePoint3dArray>& majContours) const;

    // returns the AcArray of closed contour polygons (each as AcGePoint3dArray) at specified elevation
    virtual bool contoursAtElevation(AcArray<AcGePoint3dArray>& contours, const double elevation) const;

    // creates a non-database-resident AcDbSubDMesh entity from the TinSurface using specified ETinSurfaceMeshType
    virtual AcDbSubDMesh* subDMesh(const ETinSurfaceMeshType surfaceType, const double depthOrElevation) const;

    // creates a non-database-resident AcDbSubDMesh entity from extraction between this and the 'other' surface
    virtual AcDbSubDMesh* subDMesh(const AcDbCivilTinSurface* other) const;

    // creates a non-database-resident AcDbSubDMesh entity from the TinSurface using internal defaults
    virtual AcDbSubDMesh* subDMesh() const;

    // creates a non-database-resident AcDb3dSolid entity from this surface with some thickness (or to fixed elevation)
    virtual AcDb3dSolid* solid3d(const ETinSurfaceSolidType solidType, const double thickness) const;

    // creates a non-database-resident AcDb3dSolid entity from extraction between this and the 'other' surface
    virtual AcDb3dSolid* solid3d(const AcDbCivilTinSurface* other) const;

    // drapes the TinSurface using the provided 'points', returns an array of curves
    // (each array can be used to create an AcDb3dPolyline)
    virtual bool drape(AcArray<AcGePoint3dArray>& resCurves, const AcGePoint3dArray& points) const;

    // drapes the TinSurface using the provided entity, returns an array of curves
    // (the entity should be a 2d/3d AcDbCurve based entity, or an AcDb3dFace)
    // (each array can be used to create an AcDb3dPolyline)
    virtual bool drape(AcArray<AcGePoint3dArray>& resCurves, const AcDbObjectId& entId) const;

    // calculates the intersection of a 'line' with the TinSurface; 'type' defines the intersection mode (all or first only);
    // can use all TinSurface faces or visible faces only
    virtual bool intersectionsWithLine(AcGePoint3dArray& resPoints,
                                       const AcGePoint3d& ptLineStart,
                                       const AcGePoint3d& ptLineEnd,
                                       const ETinSurfaceIntersectType type,
                                       const bool visibleOnly = false) const;

    //========= Constraint Functions ==========

    // returns the array of constraint objects, if any (true is returned if array is not empty);
    // the array contains allocated instances of 'TinSurfaceConstraint*' instances,
    // caller is responsible to delete the array instances
    virtual bool getConstraints(AcTinSurfaceConstraintArray& constraints) const;

    // returns the constraint with the specified integer ident
    virtual TinSurfaceConstraint getConstraint(const Adesk::UInt64 id) const;

    // returns that constraint which is based on the geometric points, defined by the given entity
    virtual TinSurfaceConstraint getConstraint(const AcDbObjectId& id) const;

    // add the specified constraint to this TinSurface entity
    virtual bool addConstraint(const TinSurfaceConstraint& constraint, const bool addReactor = true);

    // add the specified constraints to this TinSurface entity
    virtual bool addConstraints(const AcTinSurfaceConstraintArray& constraints, const bool addReactor = true);

    // updates this TinSurface entity for the specified constraint
    virtual bool updateConstraint(const TinSurfaceConstraint& constraint);

    // remove the specified constraint from this TinSurface entity
    virtual bool eraseConstraint(const Adesk::UInt64 id, const bool removeReactor = true);

    // removes the constraint points, as defined by 'dbEntity', from this TinSurface entity
    virtual bool eraseConstraint(const AcDbObjectId& entityId, const bool removeReactor = true);

    // remove all specified constraints from this TinSurface entity
    bool eraseConstraints(const AcArray<Adesk::UInt64>& ids, const bool removeReactor = true);

    // removes all specified constraint points from this TinSurface entity
    bool eraseConstraints(const AcDbObjectIdArray& entityIds, const bool removeReactor = true);
};


//======================== AcDbCivilTinVolumeSurface ===========================

enum ETinVolumeSurfaceType
{
    eTinVolumeBaseComparison = 0,
    eTinVolumeToElevation    = 1,
    eTinVolumeToDepth        = 2,
};

/** _ */
class BRX_EXPORT AcDbCivilTinVolumeSurface : public AcDbCivilTinSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbCivilTinVolumeSurface);

    AcDbCivilTinVolumeSurface();
    virtual ~AcDbCivilTinVolumeSurface();

    // initializes the TinVolumeSurface based on 2 surfaces, and a bounding contour
    virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                            const AcDbCivilTinSurface* compSurface,
                            const AcGePoint3dArray& boundingPolygon);

    // initializes the TinVolumeSurface based on 2 surfaces, and a bounding contour
    // taken from specified contour entity (using midOrdinateDist to determine the smoothness)
    virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                            const AcDbCivilTinSurface* compSurface,
                            const AcDbObjectId& boundingPolygonId,
                            const double midOrdinateDist);

    // initializes the TinVolumeSurface based on a surfaces with depth and bounding contour
    virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                            const double depthElevation, const ETinVolumeSurfaceType type,
                            const AcGePoint3dArray& boundingPolygon);

    // initializes the TinVolumeSurface based on a surfaces with depth and bounding contour
    // taken from specified contour entity (using midOrdinateDist to determine the smoothness)
    virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                            const double depthElevation, const ETinVolumeSurfaceType type,
                            const AcDbObjectId& boundingPolygonId,
                            const double midOrdinateDist);

    // returns the surface type
    virtual ETinVolumeSurfaceType type() const;

    // returns the entity which defines the base surface
    virtual AcDbObjectId baseSurfaceObjectId() const;

    // returns the entity which defines the surface to compare with
    virtual AcDbObjectId comparisonSurfaceObjectId() const;

    // returns the entity which defines the bounding contour
    virtual AcDbObjectId boundingPolygonObjectId() const;

    // returns the array of points which define the bounding contour
    virtual AcGePoint3dArray boundingPolygon() const;

    // returns the 'fill' volume between the 2 surfaces
    virtual double fillVolume() const;

    // returns the 'cut' volume between the 2 surfaces
    virtual double cutVolume() const;

    // returns the defined 'depth elevation'
    virtual double depthElevation() const;
};


//=========================== AcDbCivilTinGrading ==============================

//---------- TinGradingRule objects ----------
// definition of several grading rules

enum ETinGradingSide
{
    eGradingSideNone  = -1,
    eGradingSideLeft  =  0,
    eGradingSideRight =  1,
};

enum ETinGradingType
{
    eGradingTypeNone         = -1,
    eGradingTypeSlopeSurface =  0,
    eGradingTypeSlopeOffset  =  1,
};

enum ETinSlopeFormat
{
    eSlopeNoFormat = -1,
    eSlopeRiseRun  =  0,
    eSlopeDegrees  =  1,
    eSlopePercent  =  2,
    eSlopeRadians  =  3,
};

// ! underlying core data - for internal use only !
#ifndef BRX_API // proxy class
class CivilGradingRulePtr {};
#endif

//---------- TinGradingRule
// base class for the TinGradingRule objects
class BRX_EXPORT TinGradingRule
{
    friend class TinSlopeSurfaceRule;
    friend class TinSlopeOffsetRule;
    friend class AcDbCivilTinGrading;

    // ! underlying core data - for internal use only !
    CivilGradingRulePtr  m_rule;

public:
    TinGradingRule();
    TinGradingRule(const TinGradingRule& other);
    virtual ~TinGradingRule();

    virtual TinGradingRule& operator=(const TinGradingRule& other);

    virtual bool            release();
    virtual bool            isNull() const;

    virtual ETinGradingType type() const;

    virtual ETinSlopeFormat slopeFormat() const;
    virtual bool            setSlopeFormat(const ETinSlopeFormat format);

    virtual ETinGradingSide side() const;
    virtual bool            setSide(const ETinGradingSide side);

    static double convertSlopeToRad(const ETinSlopeFormat format, const double slope);
    static double convertRadToSlope(const ETinSlopeFormat format, const double angle);
};

//---------- TinSlopeSurfaceRule
class BRX_EXPORT TinSlopeSurfaceRule : public TinGradingRule
{
public:
    TinSlopeSurfaceRule();
    TinSlopeSurfaceRule(const AcDbObjectId& surfId, const double cutSlope, const double fillSlope);

    virtual ~TinSlopeSurfaceRule();

    virtual AcDbObjectId surfaceId() const;
    virtual bool         setSurfaceId(const AcDbObjectId& surfId);

    virtual double cutSlope() const;
    virtual bool   setCutSlope(const double cutSlope);

    virtual double fillSlope() const;
    virtual bool   setFillSlope(const double fillSlope);
};

//---------- TinSlopeOffsetRule
class BRX_EXPORT TinSlopeOffsetRule : public TinGradingRule
{
public:
    TinSlopeOffsetRule();
    TinSlopeOffsetRule(const double slope, const double offset);

    virtual ~TinSlopeOffsetRule();

    virtual double slope() const;
    virtual bool   setSlope(const double slope);

    virtual double offset() const;
    virtual bool   setOffset(const double offset);
};


//---------- AcDbCivilTinGrading ----------

enum ETinGradingStatus  // bit flags to combine
{
    eGradingNoStatus                = 0x0000,
    eGradingOk                      = 0x0001,
    eGradingUpdateNeeded            = 0x0002,
    eGradingIncorrectInputData      = 0x0004,
    eGradingSurfaceMissing          = 0x0008,
    eGradingRuleMissing             = 0x0010,
    eGradingInputDataOutsideSurface = 0x0020,
    eGradingGradingOutsideSurface   = 0x0040,
    eGradingOffsetFailed            = 0x0080,
    eGradingMultipleOffsetResult    = 0x0100,
    eGradingZeroGrading             = 0x0200,
    eGradingUnknownError            = 0x0400,
    eGradingInputDataMissing        = 0x0800,
    eGradingInvalidInput            = 0x1000,
    eGradingInvalidRule             = 0x2000,
    eGradingTimeout                 = 0x4000,
};

enum ETinGradingCalculationMethod
{
    eGradingAccurate = 0,
    eGradingFast     = 1,
};

enum ETinGradingVisualStyle  // bit flags to combine
{
    eGradingDrawNothing  = 0x00,
    eGradingDrawSurface  = 0x01,
    eGradingDrawRays     = 0x02,
    eGradingDrawDaylight = 0x04,
};

//---------- TinGrading
class BRX_EXPORT AcDbCivilTinGrading : public AcDbCivilTinSurface
{
public:
    ACDB_DECLARE_MEMBERS(AcDbCivilTinGrading);

    AcDbCivilTinGrading();
    virtual ~AcDbCivilTinGrading();

    virtual ETinGradingStatus update(const bool forceUpdate = false);

    virtual ETinGradingStatus setInputData(const AcDbObjectId& id);
    virtual ETinGradingStatus setInputData(const AcDbCurve* pCurve);
    virtual AcDbObjectId getInputEntityId() const;

    virtual TinGradingRule    rule() const;
    virtual ETinGradingStatus setRule(const TinGradingRule& rule);

    virtual bool isClosed() const;

    virtual AcDbObjectId targetSurface() const;

    virtual bool resultDayLight(AcArray<AcGePoint3dArray>& contours) const;

    virtual AcGeCurve3d* getCalculationCurve() const;

    virtual ETinGradingCalculationMethod getCalculationMethod() const;
    virtual bool                         setCalculationMethod(const ETinGradingCalculationMethod method);

    virtual double            getRegionStart() const;
    virtual ETinGradingStatus setRegionStart(const double startParam);

    virtual double            getRegionEnd() const;
    virtual ETinGradingStatus setRegionEnd(const double endParam);

    virtual bool              getIsDrawInfill() const;
    virtual ETinGradingStatus setDrawInfill(const bool drawInfill);

    virtual double            getSegmentMaxLength() const;
    virtual ETinGradingStatus setSegmentMaxLength(const double maxLength);

    virtual double            getSegmentMaxAngle() const;
    virtual ETinGradingStatus setSegmentMaxAngle(const double maxAngle);

    virtual double            getMidOrdinateDist() const;
    virtual ETinGradingStatus setMidOrdinateDist(const double midOrdinateDist);

    virtual bool              getIsAssociative() const;
    virtual bool              setIsAssociative(const bool associative);

    virtual ETinGradingVisualStyle getGradingVisualStyle() const;
    virtual bool                   setGradingVisualStyle(const ETinGradingVisualStyle style);
};
