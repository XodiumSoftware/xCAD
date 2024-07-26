// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil TinSurface functionality + interfaces

#include <memory>

#include "Misc/AcArray.h"
#include "AcDb/AcDbEntity.h"
#include "AcGe/AcGePoint3d.h"

#include "BrxSpecific/civil/BrxCvDbEntity.h"
#include "BrxSpecific/civil/BrxCvDbTinSurfaceDefinition.h"

// BrxCvDbTinSurfaceConstraint : base class for all constraints
class BRX_EXPORT BrxCvDbTinSurfaceConstraint
{
    friend class BrxCvDbTinSurface;

protected:
    // ! underlying core data - for internal use only !
    std::shared_ptr<class TinConstraint>  m_constraint = nullptr;

public:
    enum class ETinConstraintType
    {
        eTinBreakline  = 0,
        eTinBoundary   = 1,
        eTinWall       = 2,
    };

    BrxCvDbTinSurfaceConstraint();
    BrxCvDbTinSurfaceConstraint(const ETinConstraintType type);
    BrxCvDbTinSurfaceConstraint(const BrxCvDbTinSurfaceConstraint& other);
    virtual ~BrxCvDbTinSurfaceConstraint();

    BrxCvDbTinSurfaceConstraint& operator=(const BrxCvDbTinSurfaceConstraint& other);

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
typedef AcArray<BrxCvDbTinSurfaceConstraint> BrxCvDbTinSurfaceConstraintArray;

// TinSurfaceBreakline : breakline constraint
class BRX_EXPORT BrxCvDbTinSurfaceBreakline : public BrxCvDbTinSurfaceConstraint
{
public:
    enum class ETinBreaklineType
    {
        eTinBreaklineNormal = 0,
        eTinNonDestructive  = 1,
        //
        eTinBreaklineNomal  = eTinBreaklineNormal, //deprecated
    };

    // identical to 'BrxCvDbTinSurfaceDefinitionAddDrawingObjects::ETinIntersectionElevation'
    enum class ETinIntersectionElevation : Adesk::UInt16
    {
        eTinNotAllowed   = 0,
        eTinElevationMin = 1,
        eTinElevationMax = 2,
        eTinElevationMid = 3,
    };

    BrxCvDbTinSurfaceBreakline(const ETinBreaklineType type);

    ETinBreaklineType breaklineType() const;

    ETinIntersectionElevation intersectionElevation() const;
    void setIntersectionElevation(const ETinIntersectionElevation elevationType);
};

// BrxCvDbTinSurfaceWall : wall constraint
class BRX_EXPORT BrxCvDbTinSurfaceWall : public BrxCvDbTinSurfaceConstraint
{
public:
    enum class ETinWallType
    {
        eTinWallNormal    = 0,
        eTinWallProjected = 1,
        //
        eTinWallNomal     = eTinWallNormal, //deprecated
    };

    enum class ETinWallSide
    {
        eTinWallLeft  = 0,
        eTinWallRight = 1,
    };

    BrxCvDbTinSurfaceWall(const ETinWallType wallType);

    ETinWallType wallType() const;

    double height() const;
    void setHeight(const double height);

    void setWallSide(const ETinWallSide side);
    ETinWallSide wallSide() const;
};

// TinSurfaceBoundary : boundary constraint
class BRX_EXPORT BrxCvDbTinSurfaceBoundary : public BrxCvDbTinSurfaceConstraint
{
public:
    enum class ETinBoundaryType
    {
        eTinShow  = 0,
        eTinHide  = 1,
        eTinOuter = 2,
    };

    BrxCvDbTinSurfaceBoundary(const ETinBoundaryType boundaryType);

    ETinBoundaryType boundaryType() const;
};


//========================== BrxCvDbTinSurface ===============================

class BrxCvDbTinSurface;
class BrxCvTinTriangle;
class BrxCvTinPoint;

/** class to hold a TinPoint, keeps references to underlying Civil TinSurface Point */
class BRX_EXPORT BrxCvTinPoint
{
    friend BrxCvTinTriangle;
    friend BrxCvDbTinSurface;

    void* m_pImpl = nullptr;

public:
    BrxCvTinPoint();
    virtual ~BrxCvTinPoint();

    operator void*() const;

    // returns the triangle object which contains this 'BrxCvTinPoint' point object
    BrxCvTinTriangle triangleWithPoint() const;

    // returns the geometric location/point for this 'BrxCvTinPoint' point object
    AcGePoint3d location() const;

    // returns whether this 'BrxCvTinPoint' point object is valid (not empty)
    bool        isValid() const;
};
typedef AcArray< BrxCvTinPoint, AcArrayObjectCopyReallocator<BrxCvTinPoint> >  BrxCvTinPointArray;


/** class to hold a TinTriangle, keeps references to underlying Civil TinSurface Triangle */
class BRX_EXPORT BrxCvTinTriangle
{
    friend BrxCvTinPoint;
    friend BrxCvDbTinSurface;

    void* m_pImpl = nullptr;

public:
    BrxCvTinTriangle();
    virtual ~BrxCvTinTriangle();

    operator void*() const;

    // returns the tin point object for this 'BrxCvTinTriangle' triangle object,
    // for the specified index (0...2)
    BrxCvTinPoint pointAt(const Adesk::UInt16 index) const;

    // returns the geometric location/point for this 'BrxCvTinTriangle' triangle object,
    // for the specified index (0...2)
    AcGePoint3d     locationAt(const Adesk::UInt16 index) const;

    // returns whether this 'BrxCvTinTriangle' triangle object is visible (false, if not a valid triangle)
    bool            isVisible() const;

    // returns whether this 'BrxCvTinTriangle' triangle object is valid (not empty)
    bool            isValid() const;

    // returns the neighboring tin triangle for this 'BrxCvTinTriangle' triangle object,
    // for the specified index (0...2)
    BrxCvTinTriangle neighborAt(const Adesk::UInt16 index) const;
};
typedef AcArray< BrxCvTinTriangle, AcArrayObjectCopyReallocator<BrxCvTinTriangle> >  BrxCvTinTriangleArray;


// support for std::unordered_set<> and std::unordered_map<>, using BrxCvTinPoint and BrxCvTinTriangle
namespace std
{
    template<> struct hash<BrxCvTinPoint>
    {
        size_t operator()(const BrxCvTinPoint& tinPoint) const
        {
            return hash<void*>()((void*)tinPoint);
        }
    };
    template<> struct hash<BrxCvTinTriangle>
    {
        size_t operator()(const BrxCvTinTriangle& tinTriangle) const
        {
            return hash<void*>()((void*)tinTriangle);
        }
    };
}


/** _ */
class BRX_EXPORT BrxCvDbTinSurface: public BrxCvDbEntity
{
public:
    // TinSurface style, can be combined
    enum ETinSurfaceStyle
    {
        eTinStyleNone = 0x00,
        eTinStyleBoundaryLine = 0x01,
        eTinStylePoints = 0x02,
        eTinStyleTriangles = 0x04,
        eTinStyleContours = 0x08,
        eTinStyleElevationTooltip = 0x10,
    };

    enum class ETinSurfaceMeshType
    {
        eTinSurfaceMeshSurface = 0,
        eTinSurfaceMeshElevation = 1,
        eTinSurfaceMeshDepth = 2,
    };

    enum class ETinSurfaceIntersectType
    {
        eTinSurfaceFirstOnly = 0,
        eTinSurfaceAll = 1,
    };

    enum class ETinSurfaceSolidType
    {
        eSolidTypeSurfaceSurface = 0,  // internal use only
        eSolidTypeSurfaceElevation = 1,
        eSolidTypeSurfaceDepth = 2,
    };

    ACDB_DECLARE_MEMBERS(BrxCvDbTinSurface);

    BrxCvDbTinSurface();
    virtual ~BrxCvDbTinSurface();

    // formal setup of the TinSurface, mainly for optimal memory handling
    // (the specified bounds are not enforced)
    void initialize(const AcGePoint3d& minPt, const AcGePoint3d& maxPt, const size_t numOfPoints);

    // the TinSurface updates internal data (i.e. after adding points or parameters or constraints etc.)
    // automatically when the TinSurface object closes;
    // this function enforces synchronisation, when the TinSurface object is actually still open
    // (should be necessary in rare cases only)
    void updateObjectData();

    //========== Edit Functions ==========

    // adds a single point to the TinSurface
    bool addPoint(const AcGePoint3d& point);

    // adds a set of points to the TinSurface
    bool addPoints(const AcGePoint3dArray& points);

    // removes a single point to the TinSurface
    bool removePoint(const AcGePoint3d& points);

    // removes a set of points to the TinSurface
    bool removePoints(const AcGePoint3dArray& points);

    // moves a single point, or a set of points, to a new position
    bool movePoint(const AcGePoint3d& from, const AcGePoint3d& to);
    bool movePoints(const AcGePoint3dArray& from, const AcGePoint3dArray& to);

    // swap the edge which is closest to the specified point
    bool swapEdge(const AcGePoint3d& atPoint);

    // sets the style of the TinSurface, bit-flag
    bool setStyle(const ETinSurfaceStyle style);

    // sets whether the TinSurface is associative or not
    bool setAssociative(const bool isAssociative);

    // translates the TinSurface by 'offset' in Z direction
    bool raiseSurface(const double offset);

    // sets an overall elevation for the TinSurface (all points are set to Z=elevation)
    bool setSurfaceElevation(const double elevation);

    // changes the specified points to new Z values (1-1 relation between the 2 arrays)
    bool changePointsElevations(const AcGePoint3dArray& points, const AcGeDoubleArray& newZValues);

    // sets the interval for the minor contour levels
    bool setMinorContoursInterval(const double interval);

    // sets the interval for the major contour levels
    bool setMajorContoursInterval(const double interval);

    // sets the index color for the minor contour levels
    bool setMinorContoursColor(const Adesk::UInt16 colorIndex);

    // sets the index color for the major contour levels
    bool setMajorContoursColor(const Adesk::UInt16 colorIndex);

    // merge another surface into this surface entity
    bool merge(const BrxCvDbTinSurface* theOther);

    // merge 2 surfaces and create new surface
    static BrxCvDbTinSurface* merge(const BrxCvDbTinSurface* theOne, const BrxCvDbTinSurface* theOther);


    //========== Query Functions ==========

    // returns the used geometric points (all or visible only)
    bool getPoints(AcGePoint3dArray& points, const bool visibleOnly = false) const;

    // returns the used tin points as array of 'BrxCvTinPoint*'
    bool getTinPoints(BrxCvTinPointArray& tinPoints) const;

    // returns the tin point at geometric location of 'pnt'
    bool findTinPointAt(BrxCvTinPoint& tinPoint, const AcGePoint3d& pnt) const;


    // helper class to keep the 3 AcGePoint of a Triangle

    class Triangle
    {
    public:
        Triangle() {}
        Triangle(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3)
            : m_p1(p1), m_p2(p2), m_p3(p3)
        {
        }

    public:
        AcGePoint3d m_p1;
        AcGePoint3d m_p2;
        AcGePoint3d m_p3;
    };
    typedef AcArray< Triangle, AcArrayObjectCopyReallocator<Triangle> > TriangleArray;

    // returns the array of TinSurfaceTriangle (each triangle is 'TinSurfaceTriangle')
    bool triangles(TriangleArray& triangles, const bool visibleOnly = false) const;

    // returns the used tin triangles as array of 'BrxCvTinTriangle'
    bool tinTriangles(BrxCvTinTriangleArray& tinTriangles) const;

    // returns the tin triangles (as array of 'BrxCvTinTriangle') sharing the geometric location of 'pnt'
    bool findTinTrianglesAt(BrxCvTinTriangleArray& tinTriangles, const AcGePoint3d& pnt) const;

    // returns the number of used points (all or visible only)
    size_t pointsCount(const bool visibleOnly = false) const;

    // returns number of used triangles (all or visible only)
    size_t trianglesCount(const bool visibleOnly = false) const;

    // returns the 2d area
    double area2d(const bool visibleOnly = false) const;

    // returns the 3d area
    double area3d(const bool visibleOnly = false) const;

    // returns the min. surface elevation
    double minElevation(const bool visibleOnly = false) const;

    // returns the max. surface elevation
    double maxElevation(const bool visibleOnly = false) const;

    // verifies whether this TinSurface contains the specified point
    bool contains(const AcGePoint3d& point) const;

    // returns the elevation at the specified point in 'elevation', if the function succeeds
    // (else the specified point is not in the geometric range of the TinSurface)
    bool elevationAtPoint(const AcGePoint3d& point, double& elevation) const;

    // returns the TinSurface point, which is closest to the specified point
    AcGePoint3d closestPointTo(const AcGePoint3d& point) const;

    // returns the geometric extents of the TinSurface
    bool boundingBox(AcGePoint2d& ptMin, AcGePoint2d& ptMax) const;

    // returns the set of points located inside the specified polygon of the TinSurface
    AcGePoint3dArray getPointsInsidePolygon(const AcGePoint3dArray& polygon, bool includeOnEdge = true) const;

    // returns the style of the TinSurface
    ETinSurfaceStyle style() const;

    // returns whether the TinSurface is associative or not
    bool isAssociative() const;

    // returns an AcArray of borders (each border is an AcGePoint3dArray) for the TinSurface;
    // outermost border is the first array entry
    bool getBorders(AcArray<AcGePoint3dArray>& borders) const;

    // returns the interval for the minor contour levels
    bool minorContoursInterval(double& interval) const;

    // returns the color index for the major contour levels
    bool majorContoursInterval(double& interval) const;

    // returns the color index for the minor contour levels
    bool minorContoursColor(Adesk::UInt16& colorIndex) const;

    // returns the color index for the major contour levels
    bool majorContoursColor(Adesk::UInt16& colorIndex) const;

    // returns the array of minor contour levels
    bool minorContours(AcArray<AcGePoint3dArray>& minContours) const;

    // returns the array of major contour levels
    bool majorContours(AcArray<AcGePoint3dArray>& majContours) const;

    // returns the AcArray of closed contour polygons (each as AcGePoint3dArray) at specified elevation
    bool contoursAtElevation(AcArray<AcGePoint3dArray>& contours, const double elevation) const;

    // creates a non-database-resident AcDbSubDMesh entity from the TinSurface using specified TinSurfaceMeshType
    AcDbSubDMesh* subDMesh(const ETinSurfaceMeshType surfaceType, const double depthOrElevation) const;

    // creates a non-database-resident AcDbSubDMesh entity from extraction between this and the 'other' surface
    AcDbSubDMesh* subDMesh(const BrxCvDbTinSurface* other) const;

    // creates a non-database-resident AcDbSubDMesh entity from the TinSurface using internal defaults
    AcDbSubDMesh* subDMesh() const;

    // creates a non-database-resident AcDb3dSolid entity from this surface with some thickness (or to fixed elevation)
    AcDb3dSolid* solid3d(const ETinSurfaceSolidType solidType, const double thickness) const;

    // creates a non-database-resident AcDb3dSolid entity from extraction between this and the 'other' surface
    AcDb3dSolid* solid3d(const BrxCvDbTinSurface* other) const;

    // drapes the TinSurface using the provided 'points', returns an array of curves
    // (each array can be used to create an AcDb3dPolyline)
    bool drape(AcArray<AcGePoint3dArray>& resCurves, const AcGePoint3dArray& points) const;

    // drapes the TinSurface using the provided entity, returns an array of curves
    // (the entity should be a 2d/3d AcDbCurve based entity, or an AcDb3dFace)
    // (each array can be used to create an AcDb3dPolyline)
    bool drape(AcArray<AcGePoint3dArray>& resCurves, const AcDbObjectId& entId) const;

    // calculates the intersection of a 'line' with the TinSurface; 'type' defines the intersection mode (all or first only);
    // can use all TinSurface faces or visible faces only
    bool intersectionsWithLine(AcGePoint3dArray& resPoints,
                               const AcGePoint3d& ptLineStart,
                               const AcGePoint3d& ptLineEnd,
                               const ETinSurfaceIntersectType type,
                               const bool visibleOnly = false) const;

    //========= Constraint Functions ==========

    // returns the array of constraint objects, if any (true is returned if array is not empty);
    // the array contains allocated instances of 'TinSurfaceConstraint*' instances,
    // caller is responsible to delete the array instances
    bool getConstraints(BrxCvDbTinSurfaceConstraintArray& constraints) const;

    // returns the constraint with the specified integer ident
    BrxCvDbTinSurfaceConstraint getConstraint(const Adesk::UInt64 id) const;

    // returns that constraint which is based on the geometric points, defined by the given entity
    BrxCvDbTinSurfaceConstraint getConstraint(const AcDbObjectId& id) const;

    // add the specified constraint to this TinSurface entity
    bool addConstraint(const BrxCvDbTinSurfaceConstraint& constraint, const bool addReactor = true);

    // add the specified constraints to this TinSurface entity
    bool addConstraints(const BrxCvDbTinSurfaceConstraintArray& constraints, const bool addReactor = true);

    // updates this TinSurface entity for the specified constraint
    bool updateConstraint(const BrxCvDbTinSurfaceConstraint& constraint);

    // remove the specified constraint from this TinSurface entity
    bool eraseConstraint(const Adesk::UInt64 id, const bool removeReactor = true);

    // removes the constraint points, as defined by 'dbEntity', from this TinSurface entity
    bool eraseConstraint(const AcDbObjectId& entityId, const bool removeReactor = true);

    // remove all specified constraints from this TinSurface entity
    bool eraseConstraints(const AcArray<Adesk::UInt64>& ids, const bool removeReactor = true);

    // removes all specified constraint points from this TinSurface entity
    bool eraseConstraints(const AcDbObjectIdArray& entityIds, const bool removeReactor = true);

    //----------- begin since V24

    // snapshot related functions
    bool hasSnapshot() const;
    bool isSnapshotUpdateNeeded() const;
    Adesk::UInt32 createSnapshot();
    bool rebuildSnapshot();
    bool removeSnapshot();

    // rebuild + update related functions
    bool isUpdateNeeded() const;
    bool isRebuildPossible() const;
    bool rebuild(const bool rebuildSnapshotIfNeeded = false);

    // get + set whether the automatic redraw (display update) is active
    bool isAutoUpdate() const;
    bool setIsAutoUpdate(const bool autoUpdateOn = true);

    // SurfaceDefinition related functions
    Adesk::UInt32 definitionCount() const;
    Adesk::UInt32 addDefinition(const BrxCvDbTinSurfaceDefinition& surfaceDefinition);
    Adesk::UInt32 insertDefinitionAt(const Adesk::UInt32 index, const BrxCvDbTinSurfaceDefinition& surfaceDefinition);
    bool definitionIndex(const BrxCvDbTinSurfaceDefinition& surfaceDefinition, Adesk::UInt32& index) const;
    BrxCvDbTinSurfaceDefinitionPtr definitionAt(const Adesk::UInt32 index) const;
    BrxCvDbTinSurfaceDefinitionPtr findDefinition(const Adesk::UInt64 definitionId) const;
    Adesk::UInt32 moveDefinition(const Adesk::UInt32 fromIndex, const Adesk::UInt32 toIndex);
    bool removeDefinitionAt(const Adesk::UInt32 index);
    Adesk::UInt32 removeAllDefinitions();

    //----------- end since V24
};


//======================== BrxCvDbVolumeSurface ===========================

/** _ */
class BRX_EXPORT BrxCvDbVolumeSurface : public BrxCvDbTinSurface
{
public:
    enum class EVolumeSurfaceType
    {
        eTinVolumeBaseComparison = 0,
        eTinVolumeToElevation    = 1,
        eTinVolumeToDepth        = 2,
    };

    ACDB_DECLARE_MEMBERS(BrxCvDbVolumeSurface);

    BrxCvDbVolumeSurface();
    virtual ~BrxCvDbVolumeSurface();

    // initializes the VolumeSurface based on 2 surfaces, and a bounding contour
    bool initialize(const BrxCvDbTinSurface* baseSurface,
                    const BrxCvDbTinSurface* compSurface,
                    const AcGePoint3dArray& boundingPolygon);

    // initializes the VolumeSurface based on 2 surfaces, and a bounding contour
    // taken from specified contour entity (using midOrdinateDist to determine the smoothness)
    bool initialize(const BrxCvDbTinSurface* baseSurface,
                    const BrxCvDbTinSurface* compSurface,
                    const AcDbObjectId& boundingPolygonId,
                    const double midOrdinateDist);

    // initializes the VolumeSurface based on a surfaces with depth and bounding contour
    bool initialize(const BrxCvDbTinSurface* baseSurface,
                    const double referenceElevation, const EVolumeSurfaceType type,
                    const AcGePoint3dArray& boundingPolygon);

    // initializes the VolumeSurface based on a surfaces with depth and bounding contour
    // taken from specified contour entity (using midOrdinateDist to determine the smoothness)
    bool initialize(const BrxCvDbTinSurface* baseSurface,
                    const double referenceElevation, const EVolumeSurfaceType type,
                    const AcDbObjectId& boundingPolygonId,
                    const double midOrdinateDist);

    // returns the surface type
    EVolumeSurfaceType type() const;

    // returns the entity which defines the base surface
    AcDbObjectId baseSurfaceObjectId() const;

    // returns the entity which defines the surface to compare with
    AcDbObjectId comparisonSurfaceObjectId() const;

    // returns the entity which defines the bounding contour
    AcDbObjectId boundingPolygonObjectId() const;

    // returns the array of points which define the bounding contour
    AcGePoint3dArray boundingPolygon() const;

    // returns the 'fill' volume between the 2 surfaces
    double fillVolume() const;

    // returns the 'cut' volume between the 2 surfaces
    double cutVolume() const;

    // returns the defined 'depth elevation'
    double depthElevation() const;
};


//=========================== BrxCvDbGrading ==============================

//---------- GradingRule objects ----------
// definition of several grading rules

//---------- GradingRule
// base class for the GradingRule objects
class BRX_EXPORT BrxCvGradingRule
{
    friend class BrxCvDbGrading;

    // ! underlying core data - for internal use only !
    class GradingRuleImp;
protected:
    GradingRuleImp* m_rule;

public:
    enum class EGradingSide
    {
        eGradingSideNone  = -1,
        eGradingSideLeft  =  0,
        eGradingSideRight =  1,
    };

    enum class EGradingType
    {
        eGradingTypeNone         = -1,
        eGradingTypeSlopeSurface =  0,
        eGradingTypeSlopeOffset  =  1,
    };

    enum class EGradingSlopeFormat
    {
        eSlopeNoFormat = -1,
        eSlopeRiseRun  =  0,
        eSlopeDegrees  =  1,
        eSlopePercent  =  2,
        eSlopeRadians  =  3,
    };

    BrxCvGradingRule();
    BrxCvGradingRule(const BrxCvGradingRule& other);
    virtual ~BrxCvGradingRule();

    BrxCvGradingRule& operator=(const BrxCvGradingRule& other);

    bool            release();
    bool            isNull() const;

    EGradingType    type() const;

    EGradingSlopeFormat slopeFormat() const;
    bool                setSlopeFormat(const EGradingSlopeFormat format);

    EGradingSide    side() const;
    bool            setSide(const EGradingSide side);

    static double convertSlopeToRad(const EGradingSlopeFormat format, const double slope);
    static double convertRadToSlope(const EGradingSlopeFormat format, const double angle);
};

//---------- BrxCvGradingSlopeSurfaceRule
class BRX_EXPORT BrxCvGradingSlopeSurfaceRule : public BrxCvGradingRule
{
public:
    BrxCvGradingSlopeSurfaceRule();
    BrxCvGradingSlopeSurfaceRule(const AcDbObjectId& surfId, const double cutSlope, const double fillSlope);

    virtual ~BrxCvGradingSlopeSurfaceRule();

    AcDbObjectId surfaceId() const;
    bool         setSurfaceId(const AcDbObjectId& surfId);

    double cutSlope() const;
    bool   setCutSlope(const double cutSlope);

    double fillSlope() const;
    bool   setFillSlope(const double fillSlope);
};

//---------- BrxCvGradingSlopeOffsetRule
class BRX_EXPORT BrxCvGradingSlopeOffsetRule : public BrxCvGradingRule
{
public:
    BrxCvGradingSlopeOffsetRule();
    BrxCvGradingSlopeOffsetRule(const double slope, const double offset);

    virtual ~BrxCvGradingSlopeOffsetRule();

    double slope() const;
    bool   setSlope(const double slope);

    double offset() const;
    bool   setOffset(const double offset);
};


//---------- BrxCvDbGrading ----------

//---------- Grading
class BRX_EXPORT BrxCvDbGrading : public BrxCvDbTinSurface
{
public:
    enum EGradingStatus  // bit flags to combine
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

    enum class EGradingCalculationMethod
    {
        eGradingAccurate = 0,
        eGradingFast     = 1,
    };

    enum EGradingVisualStyle  // bit flags to combine
    {
        eGradingDrawNothing  = 0x00,
        eGradingDrawSurface  = 0x01,
        eGradingDrawRays     = 0x02,
        eGradingDrawDaylight = 0x04,
    };

    ACDB_DECLARE_MEMBERS(BrxCvDbGrading);

    BrxCvDbGrading();
    virtual ~BrxCvDbGrading();

    EGradingStatus update(const bool forceUpdate = false);

    EGradingStatus setInputData(const AcDbObjectId& id);
    EGradingStatus setInputData(const AcDbCurve* pCurve);
    AcDbObjectId getInputEntityId() const;

    BrxCvGradingRule rule() const;
    EGradingStatus setRule(const BrxCvGradingRule& rule);

    bool isClosed() const;

    AcDbObjectId targetSurface() const;

    bool resultDayLight(AcArray<AcGePoint3dArray>& contours) const;

    AcGeCurve3d* getCalculationCurve() const;

    EGradingCalculationMethod getCalculationMethod() const;
    bool              setCalculationMethod(const EGradingCalculationMethod method);

    double            getRegionStart() const;
    EGradingStatus    setRegionStart(const double startParam);

    double            getRegionEnd() const;
    EGradingStatus    setRegionEnd(const double endParam);

    bool              getIsDrawInfill() const;
    EGradingStatus    setDrawInfill(const bool drawInfill);

    double            getSegmentMaxLength() const;
    EGradingStatus    setSegmentMaxLength(const double maxLength);

    double            getSegmentMaxAngle() const;
    EGradingStatus    setSegmentMaxAngle(const double maxAngle);

    double            getMidOrdinateDist() const;
    EGradingStatus    setMidOrdinateDist(const double midOrdinateDist);

    bool              getIsAssociative() const;
    bool              setIsAssociative(const bool associative);

    EGradingVisualStyle getGradingVisualStyle() const;
    bool              setGradingVisualStyle(const EGradingVisualStyle style);
};
