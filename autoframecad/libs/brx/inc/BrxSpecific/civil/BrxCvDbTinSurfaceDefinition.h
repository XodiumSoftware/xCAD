// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil TinSurface Definitions functionality + interfaces

#include <memory.h>

#include "Misc/AcArray.h"
#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeMatrix3d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGeLineSeg2d.h"

#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbFace.h"

#include "BrxSpecific/AcSharedPtr.h"

#include "BrxSpecific/civil/BrxCvDbObject.h"
#include "BrxSpecific/civil/BrxCvDbSubObject.h"

typedef AcArray<AcGeLineSeg2d>  AcGeLineSeg2dArray;
typedef AcArray<AcDbFace*>      AcDbFacePtrArray;

/** Civil TinSurface Definition base class */
class BRX_EXPORT BrxCvDbTinSurfaceDefinition : public BrxCvDbSubObject
{
protected:
    BrxCvDbTinSurfaceDefinition();
    BrxCvDbTinSurfaceDefinition(const BrxCvDbTinSurfaceDefinition&);

public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinition);

    enum class EType : Adesk::UInt16
    {
        eNone                      = 0,
        eTransform                 = 1,
        eAddPoint                  = 2,
        eAddPoints                 = 3,
        eDeletePoint               = 4,
        eDeletePoints              = 5,
        eSwapEdge                  = 6,
        eMovePoint                 = 7,
        eMovePoints                = 8,
        eAddBreaklines             = 9,
        eAddBoundaries             = 10,
        eAddWalls                  = 11,
        eVolume                    = 12,
        eMerge                     = 13,
        eDeleteEdge                = 14,
        eDeleteEdges               = 15,
        eAddLine                   = 16,
        eAddLines                  = 17,
        eModifyPointElevation      = 18,
        eModifyPointsElevation     = 19,
        eModifyPointsElevations    = 20,
        eCreateFromFaces           = 21,
        eAddDrawingObjects         = 22,
        eCreateSnapshot            = 23,
        eRiseLower                 = 24,
        eLandXML                   = 25,
        eAddPointFiles             = 26,
        eAddPointGroups            = 27,
        eAddPointClouds            = 28,
        eGroupDefinitions          = 29,
        eDeform                    = 30,
        eSmoothen                  = 31,
        eCreateMerged              = 32,
        eIFC                       = 33,
        eCreateTypedSnapshot       = 34,
        eCreateFromCorridor        = 35,
        eCreateFromC3D             = 36,
        eRemoveOuterEdges          = 37,
        eCreateFromContours        = 38,
        eMinimizeFlatAreas         = 39,
        eTrianglesVisibility       = 40,
        eRemoveBelowAboveElevation = 41,
    };

    virtual ~BrxCvDbTinSurfaceDefinition();

    // get/set TinSurface Definition name
    const ACHAR* name() const;
    bool setName(const ACHAR* szName);

    // get/set TinSurface Definition description
    const ACHAR* description() const;
    bool setDescription(const ACHAR* szDescription);

    // returns the type of the TinSurface Definition object
    EType type() const;

    // returns whether an update of the TinSurface Definition object is pending
    bool isUpdateNeeded() const;

    // returns whether the TinSurface Definition object is a Sub-Definition
    bool isSubDefinition() const;

    // returns whether the TinSurface Definition object is valid
    bool isValid() const;

    // query and modify the 'enabled' status of the TinSurface Definition object
    bool isEnabled() const;
    bool setEnabled(const bool enabled);

    // query and modify the 'readonly' status of the TinSurface Definition object
    bool isReadOnly() const;
    bool setReadOnly(const bool readOnly);

    // returns the ID of the TinSurface Definition object
    Adesk::UInt64 id() const;
};

typedef AcSharedPtr<BrxCvDbTinSurfaceDefinition> BrxCvDbTinSurfaceDefinitionPtr;

// SurfaceDefinition "Group Definitions"
class BrxCvDbTinSurfaceDefinitionGroupDefs : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionGroupDefs);

    BrxCvDbTinSurfaceDefinitionGroupDefs();
    BrxCvDbTinSurfaceDefinitionGroupDefs(const BrxCvDbTinSurfaceDefinitionGroupDefs& other);
    BrxCvDbTinSurfaceDefinitionGroupDefs& operator=(const BrxCvDbTinSurfaceDefinitionGroupDefs& other);
    virtual ~BrxCvDbTinSurfaceDefinitionGroupDefs();

    // returns the number of sub-definitions contained by this group
    Adesk::UInt32 numSubDefinitions() const;

    // returns the array index of the definition specified by its ID
    bool findSubDefinition(const Adesk::UInt64 definitionId, Adesk::UInt32& index) const;

    // adds the specified sub-definition to the definition array, returns the index
    Adesk::UInt32 addSubDefinition(const BrxCvDbTinSurfaceDefinition& subDefinition);

    // returns a clone of the sub-definition at specified array index
    BrxCvDbTinSurfaceDefinitionPtr getSubDefinitionAt(const Adesk::UInt32 index) const;

    // removes the sub-definition, specified by array index, from the definition array
    bool removeSubDefinitionAt(const Adesk::UInt32 index);
};

// SurfaceDefinition "Transform"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionTransform : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionTransform);

    BrxCvDbTinSurfaceDefinitionTransform();
    BrxCvDbTinSurfaceDefinitionTransform(const AcGeMatrix3d& mtx);
    BrxCvDbTinSurfaceDefinitionTransform(const BrxCvDbTinSurfaceDefinitionTransform& other);
    BrxCvDbTinSurfaceDefinitionTransform& operator=(const BrxCvDbTinSurfaceDefinitionTransform& other);
    virtual ~BrxCvDbTinSurfaceDefinitionTransform();

    // get and set the transformation matrix
    AcGeMatrix3d transformationMatrix() const;
    bool setTransformationMatrix(const AcGeMatrix3d& mtx);
};

// SurfaceDefinition "AddPoint"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddPoint : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddPoint);

    BrxCvDbTinSurfaceDefinitionAddPoint();
    BrxCvDbTinSurfaceDefinitionAddPoint(const AcGePoint3d& position);
    BrxCvDbTinSurfaceDefinitionAddPoint(const BrxCvDbTinSurfaceDefinitionAddPoint& other);
    BrxCvDbTinSurfaceDefinitionAddPoint& operator=(const BrxCvDbTinSurfaceDefinitionAddPoint& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddPoint();

    // get and set the 3d point position
    AcGePoint3d position() const;
    bool setPosition(const AcGePoint3d& position);
};

// SurfaceDefinition "AddPoints"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddPoints : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddPoints);

    BrxCvDbTinSurfaceDefinitionAddPoints();
    BrxCvDbTinSurfaceDefinitionAddPoints(const AcGePoint3dArray& positions);
    BrxCvDbTinSurfaceDefinitionAddPoints(const BrxCvDbTinSurfaceDefinitionAddPoints& other);
    BrxCvDbTinSurfaceDefinitionAddPoints& operator=(const BrxCvDbTinSurfaceDefinitionAddPoints& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddPoints();

    // get and set the 3d points position array
    AcGePoint3dArray positions() const;
    bool setPositions(const AcGePoint3dArray& positions);
};

// SurfaceDefinition "DeletePoint"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionDeletePoint : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionDeletePoint);

    BrxCvDbTinSurfaceDefinitionDeletePoint();
    BrxCvDbTinSurfaceDefinitionDeletePoint(const AcGePoint2d& position);
    BrxCvDbTinSurfaceDefinitionDeletePoint(const BrxCvDbTinSurfaceDefinitionDeletePoint& other);
    BrxCvDbTinSurfaceDefinitionDeletePoint& operator=(const BrxCvDbTinSurfaceDefinitionDeletePoint& other);
    virtual ~BrxCvDbTinSurfaceDefinitionDeletePoint();

    // get and set the 2d point position
    AcGePoint2d position() const;
    bool setPosition(const AcGePoint2d& position);
};

// SurfaceDefinition "DeletePoints"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionDeletePoints : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionDeletePoints);

    BrxCvDbTinSurfaceDefinitionDeletePoints();
    BrxCvDbTinSurfaceDefinitionDeletePoints(const AcGePoint2dArray& position);
    BrxCvDbTinSurfaceDefinitionDeletePoints(const BrxCvDbTinSurfaceDefinitionDeletePoints& other);
    BrxCvDbTinSurfaceDefinitionDeletePoints& operator=(const BrxCvDbTinSurfaceDefinitionDeletePoints& other);
    virtual ~BrxCvDbTinSurfaceDefinitionDeletePoints();

    // get and set the 2d pointa array position
    AcGePoint2dArray positions() const;
    bool setPositions(const AcGePoint2dArray& positions);
};

// SurfaceDefinition "SwapEdge"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionSwapEdge : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionSwapEdge);

    BrxCvDbTinSurfaceDefinitionSwapEdge();
    BrxCvDbTinSurfaceDefinitionSwapEdge(const AcGePoint2d& position);
    BrxCvDbTinSurfaceDefinitionSwapEdge(const BrxCvDbTinSurfaceDefinitionSwapEdge& other);
    BrxCvDbTinSurfaceDefinitionSwapEdge& operator=(const BrxCvDbTinSurfaceDefinitionSwapEdge& other);
    virtual ~BrxCvDbTinSurfaceDefinitionSwapEdge();

    // get and set the 2d point position
    AcGePoint2d position() const;
    bool setPosition(const AcGePoint2d& position);
};

// SurfaceDefinition "MovePoint"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionMovePoint : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionMovePoint);

    BrxCvDbTinSurfaceDefinitionMovePoint();
    BrxCvDbTinSurfaceDefinitionMovePoint(const AcGePoint2d& fromPoint, const AcGePoint2d& toPoint);
    BrxCvDbTinSurfaceDefinitionMovePoint(const BrxCvDbTinSurfaceDefinitionMovePoint& other);
    BrxCvDbTinSurfaceDefinitionMovePoint& operator=(const BrxCvDbTinSurfaceDefinitionMovePoint& other);
    virtual ~BrxCvDbTinSurfaceDefinitionMovePoint();

    // get and set the 2d point 'move from' position
    AcGePoint2d fromPosition() const;
    bool setFromPosition(const AcGePoint2d& fromPoint);

    // get and set the 2d point 'move to' position
    AcGePoint2d toPosition() const;
    bool setToPosition(const AcGePoint2d& toPoint);
};

// SurfaceDefinition "MovePoints"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionMovePoints : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionMovePoints);

    BrxCvDbTinSurfaceDefinitionMovePoints();
    BrxCvDbTinSurfaceDefinitionMovePoints(const AcGePoint2dArray& fromPoints, const AcGeVector2d& displacement);
    BrxCvDbTinSurfaceDefinitionMovePoints(const BrxCvDbTinSurfaceDefinitionMovePoints& other);
    BrxCvDbTinSurfaceDefinitionMovePoints& operator=(const BrxCvDbTinSurfaceDefinitionMovePoints& other);
    virtual ~BrxCvDbTinSurfaceDefinitionMovePoints();

    // get and set the 2d point positions
    AcGePoint2dArray fromPoints() const;
    bool setFromPoints(const AcGePoint2dArray& fromPoints);

    // get and set the 2d displacement vector
    AcGeVector2d displacement() const;
    bool setDisplacement(const AcGeVector2d& displacement);
};

// SurfaceDefinition "DeleteEdge"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionDeleteEdge : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionDeleteEdge);

    BrxCvDbTinSurfaceDefinitionDeleteEdge();
    BrxCvDbTinSurfaceDefinitionDeleteEdge(const AcGePoint2d& edgePoint);
    BrxCvDbTinSurfaceDefinitionDeleteEdge(const BrxCvDbTinSurfaceDefinitionDeleteEdge& other);
    BrxCvDbTinSurfaceDefinitionDeleteEdge& operator=(const BrxCvDbTinSurfaceDefinitionDeleteEdge& other);
    virtual ~BrxCvDbTinSurfaceDefinitionDeleteEdge();

    // get and set the edge defined by its 2d point position
    AcGePoint2d position() const;
    bool setPosition(const AcGePoint2d& edgePoint);
};

// SurfaceDefinition "DeleteEdges"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionDeleteEdges : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionDeleteEdges);

    BrxCvDbTinSurfaceDefinitionDeleteEdges();
    BrxCvDbTinSurfaceDefinitionDeleteEdges(const BrxCvDbTinSurfaceDefinitionDeleteEdges& other);
    BrxCvDbTinSurfaceDefinitionDeleteEdges& operator=(const BrxCvDbTinSurfaceDefinitionDeleteEdges& other);
    virtual ~BrxCvDbTinSurfaceDefinitionDeleteEdges();

    Adesk::UInt32 polygonsCount() const;
    AcGePoint2dArray polygonAt(const Adesk::UInt32 index, bool& includeIntersected) const;

    bool addPolygon(const AcGePoint2dArray& edgePolygon, const bool includeIntersected);
    bool removePolygonAt(const Adesk::UInt32 index);
    bool removeAllPolygons();
};

// SurfaceDefinition "AddLine"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddLine : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddLine);

    BrxCvDbTinSurfaceDefinitionAddLine();
    BrxCvDbTinSurfaceDefinitionAddLine(const AcGeLineSeg2d& line);
    BrxCvDbTinSurfaceDefinitionAddLine(const BrxCvDbTinSurfaceDefinitionAddLine& other);
    BrxCvDbTinSurfaceDefinitionAddLine& operator=(const BrxCvDbTinSurfaceDefinitionAddLine& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddLine();

    // get and set the 2d line segment
    AcGeLineSeg2d line() const;
    bool setLine(const AcGeLineSeg2d& line);
};

// SurfaceDefinition "AddLines"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddLines : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddLines);

    BrxCvDbTinSurfaceDefinitionAddLines();
    BrxCvDbTinSurfaceDefinitionAddLines(const AcGeLineSeg2dArray& line);
    BrxCvDbTinSurfaceDefinitionAddLines(const BrxCvDbTinSurfaceDefinitionAddLines& other);
    BrxCvDbTinSurfaceDefinitionAddLines& operator=(const BrxCvDbTinSurfaceDefinitionAddLines& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddLines();

    // get and set the 2d line segment
    AcGeLineSeg2dArray lines() const;
    bool setLines(const AcGeLineSeg2dArray& line);
};

// SurfaceDefinition "ModifyPointElevation"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionModifyPointElevation : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionModifyPointElevation);

    BrxCvDbTinSurfaceDefinitionModifyPointElevation();
    BrxCvDbTinSurfaceDefinitionModifyPointElevation(const AcGePoint2d& position, const double elevation, const bool isDeltaElevation);
    BrxCvDbTinSurfaceDefinitionModifyPointElevation(const BrxCvDbTinSurfaceDefinitionModifyPointElevation& other);
    BrxCvDbTinSurfaceDefinitionModifyPointElevation& operator=(const BrxCvDbTinSurfaceDefinitionModifyPointElevation& other);
    virtual ~BrxCvDbTinSurfaceDefinitionModifyPointElevation();

    // get and set the 2d point position
    AcGePoint2d position() const;
    bool setPosition(const AcGePoint2d& position);

    // get and set the elevation to be applied
    double elevation() const;
    bool setElevation(const double elevation);
    
    // defines whether the elevation is absolute or relative
    bool isDeltaElevation() const;
    bool setIsDeltaElevation(const bool isDeltaElevation);
};

// SurfaceDefinition "ModifyPointsElevation"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionModifyPointsElevation : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionModifyPointsElevation);

    BrxCvDbTinSurfaceDefinitionModifyPointsElevation();
    BrxCvDbTinSurfaceDefinitionModifyPointsElevation(const AcGePoint2dArray& positions, const double elevation, const bool isDeltaElevation);
    BrxCvDbTinSurfaceDefinitionModifyPointsElevation(const BrxCvDbTinSurfaceDefinitionModifyPointsElevation& other);
    BrxCvDbTinSurfaceDefinitionModifyPointsElevation& operator=(const BrxCvDbTinSurfaceDefinitionModifyPointsElevation& other);
    virtual ~BrxCvDbTinSurfaceDefinitionModifyPointsElevation();

    // get and set the 2d point positions array
    AcGePoint2dArray positions() const;
    bool setPositions(const AcGePoint2dArray& positions);

    // get and set the elevation to be applied
    double elevation() const;
    bool setElevation(const double elevation);
    
    // defines whether the elevation is absolute or relative
    bool isDeltaElevation() const;
    bool setIsDeltaElevation(const bool isDeltaElevation);
};

// SurfaceDefinition "ModifyPointsElevations"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionModifyPointsElevations : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionModifyPointsElevations);

    BrxCvDbTinSurfaceDefinitionModifyPointsElevations();
    BrxCvDbTinSurfaceDefinitionModifyPointsElevations(const BrxCvDbTinSurfaceDefinitionModifyPointsElevations& other);
    BrxCvDbTinSurfaceDefinitionModifyPointsElevations& operator=(const BrxCvDbTinSurfaceDefinitionModifyPointsElevations& other);
    virtual ~BrxCvDbTinSurfaceDefinitionModifyPointsElevations();

    // returns the number of defined point elevations
    Adesk::UInt32 pointElevationsCount() const;

    // get and set the 2d point position and elevation pair
    bool pointElevationAt(const Adesk::UInt32 index, AcGePoint2d& position, double& elevation) const;
    bool addPointElevation(const AcGePoint2d& position, const double elevation);

    bool removePointElevationAt(const Adesk::UInt32 index);
    bool removeAllPointElevations();
};

// SurfaceDefinition "CreateFromFaces"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionCreateFromFaces : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionCreateFromFaces);

    BrxCvDbTinSurfaceDefinitionCreateFromFaces();
    // construct from non-database-resident AcDb3dFace entities
    BrxCvDbTinSurfaceDefinitionCreateFromFaces(const AcDbFacePtrArray& faces, const bool applyEdgesVisibility);
    // construct from database-resident AcDb3dFace entities
    BrxCvDbTinSurfaceDefinitionCreateFromFaces(const AcDbObjectIdArray& facesIds, const bool applyEdgesVisibility);
    // construct from face geometry definition points (4 points per face, mandatory)
    BrxCvDbTinSurfaceDefinitionCreateFromFaces(const AcGePoint3dArray& facesPoints, const bool applyEdgesVisibility);

    BrxCvDbTinSurfaceDefinitionCreateFromFaces(const BrxCvDbTinSurfaceDefinitionCreateFromFaces& other);
    BrxCvDbTinSurfaceDefinitionCreateFromFaces& operator=(const BrxCvDbTinSurfaceDefinitionCreateFromFaces& other);
    virtual ~BrxCvDbTinSurfaceDefinitionCreateFromFaces();

    // returns the number of defined faces
    Adesk::UInt32 facesCount() const;

    // returns a clone of the AcDbFace entity, caller must delete the AcDbFace* object
    bool faceAt(const Adesk::UInt32 index, AcDbFace*& dbFace) const;

    // returns the face definition points (each face uses 4 points always)
    AcGePoint3dArray points() const;

    // get and set the "apply edges visibility" flag
    bool isApplyEdgesVisibility() const;
    bool setIsApplyEdgesVisibility(const bool isApplyEdges);
};

// SurfaceDefinition "AddDrawingObjects"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddDrawingObjects : public BrxCvDbTinSurfaceDefinition
{
public :
    enum class EDrawingObjectType : Adesk::UInt32
    {
        eUnknown    = 0,
        ePoint      = 1,
        eBlock      = 2,
        eText       = 3,
        eLine       = 4,
        eFace       = 5,
        ePolyline   = 6,
        eCivilPoint = 7,
    };

    // identical to 'BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation'
    enum class ETinIntersectionElevation : Adesk::UInt16
    {
        eTinNotAllowed   = 0,
        eTinElevationMin = 1,
        eTinElevationMax = 2,
        eTinElevationMid = 3,
    };

    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddDrawingObjects);

    BrxCvDbTinSurfaceDefinitionAddDrawingObjects();
    BrxCvDbTinSurfaceDefinitionAddDrawingObjects(const BrxCvDbTinSurfaceDefinitionAddDrawingObjects& other);
    BrxCvDbTinSurfaceDefinitionAddDrawingObjects& operator=(const BrxCvDbTinSurfaceDefinitionAddDrawingObjects& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddDrawingObjects();

    // the 'mid-ordinate distance' is the distance of the curve's midpoint, to the arc center;
    // similar to arc's bulge; used as a kind of tolerance
    // https://civil3dplus.wordpress.com/2012/12/23/surfaces-and-the-mid-ordinate-distance/

    // construct from non-database-resident entities
    BrxCvDbTinSurfaceDefinitionAddDrawingObjects(const AcDbEntityPtrArray& entities, const double midOrdinateDistance,
                                                 const bool applyEdges, const ETinIntersectionElevation crossingsElevation);
    // construct from database-resident entities
    BrxCvDbTinSurfaceDefinitionAddDrawingObjects(const AcDbObjectIdArray& entityIds, const double midOrdinateDistance,
                                                 const bool applyEdges, const ETinIntersectionElevation crossingsElevation);

    bool addEntity(const AcDbEntity* pEntity);
    bool addEntity(const AcDbObjectId& entityId);

    Adesk::UInt32 drawingObjectsCount() const;
    bool drawingObjectAt(const Adesk::UInt32 index, EDrawingObjectType& type, AcGePoint3dArray& points) const;

    ETinIntersectionElevation crossingsElevation() const;
    bool setCrossingsElevation(const ETinIntersectionElevation crossingsElevation);

    bool isApplyEdges() const;
    bool setIsApplyEdges(const bool isApplyEdges);

    bool removeDrawingObjectAt(const Adesk::UInt32 index);
    bool removeAllDrawingObjects();
};

// SurfaceDefinition "RiseLower"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionRiseLower : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionRiseLower);

    BrxCvDbTinSurfaceDefinitionRiseLower();
    BrxCvDbTinSurfaceDefinitionRiseLower(const double offset);
    BrxCvDbTinSurfaceDefinitionRiseLower(const BrxCvDbTinSurfaceDefinitionRiseLower& other);
    BrxCvDbTinSurfaceDefinitionRiseLower& operator=(const BrxCvDbTinSurfaceDefinitionRiseLower& other);
    virtual ~BrxCvDbTinSurfaceDefinitionRiseLower();

    // get and set the surface offset
    double offset() const;
    bool setOffset(const double offset);
};

// SurfaceDefinition "CreateFromLandXML"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionCreateFromLandXML : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionCreateFromLandXML);

    BrxCvDbTinSurfaceDefinitionCreateFromLandXML();
    BrxCvDbTinSurfaceDefinitionCreateFromLandXML(const ACHAR* filePath, const ACHAR* surfaceName,
                                                 const AcDb::UnitsValue dwgUnits, const bool scaleToDwgUnits);
    BrxCvDbTinSurfaceDefinitionCreateFromLandXML(const BrxCvDbTinSurfaceDefinitionCreateFromLandXML& other);
    BrxCvDbTinSurfaceDefinitionCreateFromLandXML& operator=(const BrxCvDbTinSurfaceDefinitionCreateFromLandXML& other);
    virtual ~BrxCvDbTinSurfaceDefinitionCreateFromLandXML();

    // get and set xml file path
    const ACHAR* filePath() const;
    bool setFilePath(const ACHAR* filePath);

    // get and set assigned surface name
    const ACHAR* surfaceName() const;
    bool setSurfaceName(const ACHAR* surfaceName);

    // get and set the scaling option
    bool scaleToDwgUnits() const;
    bool setScaleToDwgUnits(const bool scaleToDwgUnits);

    // get and set dwg units
    AcDb::UnitsValue dwgUnits() const;
    bool setDwgUnits(const AcDb::UnitsValue dwgUnits);
};

// Data/Parameter class to control "densification" of a Civil Surface
class BRX_EXPORT BrxCvSurfaceDensify
{
    friend class BrxCvSurfaceDensifyImpl;
    BrxCvSurfaceDensify() {};

public:
    struct DensifyParams
    {
        // input + output parameters
        AcGePoint2dArray  m_polygon;
        double            m_deltaElevation;
        // output parameters (filled-in on a query), ignored on input
        bool              m_affectsEntireSurface;
        Adesk::UInt32     m_numPointsAddedByDensify;
    };

public:
    virtual ~BrxCvSurfaceDensify() {};

    // query, enable/disable the densification mode
    bool isEnabled() const;
    bool setIsEnabled(const bool enabled); // can only be enabled if simplify is also enabled !

    // returns the number of densification parameters
    Adesk::UInt32 count() const;

    // returns the densification parameter set at specified index
    bool getAt(const Adesk::UInt32 index, DensifyParams& params) const;

    // appends a densification parameter set
    bool append(const DensifyParams& params);

    // removes the densification parameter set at specified index
    bool removeAt(const Adesk::UInt32 index);

    // clears all densification parameters
    bool removeAll();
};

typedef AcSharedPtr<BrxCvSurfaceDensify> BrxCvSurfaceDensifyPtr;

// Data/Parameter class to control "simplification" of a Civil Surface
class BRX_EXPORT BrxCvSurfaceSimplify
{
    friend class BrxCvSurfaceSimplifyImpl;
    BrxCvSurfaceSimplify() {};

public:
    virtual ~BrxCvSurfaceSimplify() {};

    // query, enable/disable the simplification mode
    bool isEnabled() const;
    bool setIsEnabled(const bool enabled);

    // get + set the radius (range/area) for simplification
    double simplificationRadius() const;
    bool setSimplificationRadius(const double simplificationRadius);

    // get + set the elevations delta for simplification
    double simplificationElevationDiff() const;
    bool setSimplificationElevationDiff(const double elevationDiff);

    // query original + simplified points count
    Adesk::UInt32 originalPointsCount() const;
    Adesk::UInt32 simplifiedPointsCount() const;
};

typedef AcSharedPtr<BrxCvSurfaceSimplify> BrxCvSurfaceSimplifyPtr;

// SurfaceDefinition "AddFromFiles"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddFromFiles : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddFromFiles);

    BrxCvDbTinSurfaceDefinitionAddFromFiles();
    BrxCvDbTinSurfaceDefinitionAddFromFiles(const AcStringArray& filesPaths, const AcDbObjectId& fileFormatId);

    BrxCvDbTinSurfaceDefinitionAddFromFiles(const BrxCvDbTinSurfaceDefinitionAddFromFiles& other);
    BrxCvDbTinSurfaceDefinitionAddFromFiles& operator=(const BrxCvDbTinSurfaceDefinitionAddFromFiles& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddFromFiles();

    // get and set the input files
    AcStringArray filesPaths() const;
    bool setFilesPaths(const AcStringArray& filesPaths);

    // get and set the input files format
    AcDbObjectId fileFormatId() const;
    bool setFileFormatId(const AcDbObjectId& fileFormatId);

    // returns the densification data to adjust the Civil Surface created from input files; read/write enabled;
    // the returned object is directly connected to this BrxCvDbTinSurfaceDefinitionAddFromFiles object;
    BrxCvSurfaceDensifyPtr densify();

    // returns the simplification data to adjust the Civil Surface created from input files; read/write enabled;
    // the returned object is directly connected to this BrxCvDbTinSurfaceDefinitionAddFromFiles object;
    BrxCvSurfaceSimplifyPtr simplify();
};

// SurfaceDefinition "AddFromPointClouds"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddFromPointClouds : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddFromPointClouds);

    BrxCvDbTinSurfaceDefinitionAddFromPointClouds();
    BrxCvDbTinSurfaceDefinitionAddFromPointClouds(const AcDbObjectIdArray& pcObjectIds);

    BrxCvDbTinSurfaceDefinitionAddFromPointClouds(const BrxCvDbTinSurfaceDefinitionAddFromPointClouds& other);
    BrxCvDbTinSurfaceDefinitionAddFromPointClouds& operator=(const BrxCvDbTinSurfaceDefinitionAddFromPointClouds& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddFromPointClouds();

    // get and set the input PointCloud object(s)
    AcDbObjectIdArray pcObjectIds() const;
    bool setPcObjectIds(const AcDbObjectIdArray& pcObjectIds);

    // returns the densification data to adjust the Civil Surface created from input files; read/write enabled;
    // the returned object is directly connected to this BrxCvDbTinSurfaceDefinitionAddFromPointClouds object;
    BrxCvSurfaceDensifyPtr densify();

    // returns the simplification data to adjust the Civil Surface created from input files; read/write enabled;
    // the returned object is directly connected to this BrxCvDbTinSurfaceDefinitionAddFromPointClouds object;
    BrxCvSurfaceSimplifyPtr simplify();
};

// SurfaceDefinition "AddPointGroups"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionAddPointGroups : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionAddPointGroups);

    BrxCvDbTinSurfaceDefinitionAddPointGroups();
    BrxCvDbTinSurfaceDefinitionAddPointGroups(const AcDbObjectIdArray& pointGroupsIds);

    BrxCvDbTinSurfaceDefinitionAddPointGroups(const BrxCvDbTinSurfaceDefinitionAddPointGroups& other);
    BrxCvDbTinSurfaceDefinitionAddPointGroups& operator=(const BrxCvDbTinSurfaceDefinitionAddPointGroups& other);
    virtual ~BrxCvDbTinSurfaceDefinitionAddPointGroups();

    // get and set the input PointCloud object(s)
    AcDbObjectIdArray pointGroupsIds() const;
    bool setPointGroupsIds(const AcDbObjectIdArray& pointGroupsIds);
};

// SurfaceDefinition "CreateFromC3D"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionCreateFromC3D : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionCreateFromC3D);

    BrxCvDbTinSurfaceDefinitionCreateFromC3D();
    BrxCvDbTinSurfaceDefinitionCreateFromC3D(const ACHAR* filePath, const ACHAR* surfaceName);

    BrxCvDbTinSurfaceDefinitionCreateFromC3D(const BrxCvDbTinSurfaceDefinitionCreateFromC3D& other);
    BrxCvDbTinSurfaceDefinitionCreateFromC3D& operator=(const BrxCvDbTinSurfaceDefinitionCreateFromC3D& other);
    virtual ~BrxCvDbTinSurfaceDefinitionCreateFromC3D();

    const ACHAR* filePath() const;
    bool setFilePath(const ACHAR* filePath);

    const ACHAR* surfaceName() const;
    bool setSurfaceName(const ACHAR* surfaceName);
};

// SurfaceDefinition "RemoveOuterEdges"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionRemoveOuterEdges : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionRemoveOuterEdges);

    BrxCvDbTinSurfaceDefinitionRemoveOuterEdges();
    BrxCvDbTinSurfaceDefinitionRemoveOuterEdges(const bool useMinLength, const double minLength,
                                                const bool useMaxLength, const double maxLength,
                                                const bool useMaxAdjAngle, const double maxAdjAngle);

    BrxCvDbTinSurfaceDefinitionRemoveOuterEdges(const BrxCvDbTinSurfaceDefinitionRemoveOuterEdges& other);
    BrxCvDbTinSurfaceDefinitionRemoveOuterEdges& operator=(const BrxCvDbTinSurfaceDefinitionRemoveOuterEdges& other);
    virtual ~BrxCvDbTinSurfaceDefinitionRemoveOuterEdges();

    bool useMaxEdgeLength() const;
    bool setUseMaxEdgeLength(const bool useMaxEdgeLength);

    double maxEdgeLength() const;
    bool  setMaxEdgeLength(const double maxEdgeLength);

    bool useMinEdgeLength() const;
    bool setUseMinEdgeLength(const bool useMinEdgeLength);

    double minEdgeLength() const;
    bool   setMinEdgeLength(const double minEdgeLength);

    bool useMaxAdjAngle() const;
    bool setUseMaxAdjAngle(const bool useMaxAdjAngle);

    double maxAdjAngle() const;
    bool   setMaxAdjAngle(const double maxAdjAngle);
};

// SurfaceDefinition "TrianglesVisibility"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionTrianglesVisibility : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionTrianglesVisibility);

    BrxCvDbTinSurfaceDefinitionTrianglesVisibility();
    BrxCvDbTinSurfaceDefinitionTrianglesVisibility(const AcGePoint2dArray& positions, const bool visible);

    BrxCvDbTinSurfaceDefinitionTrianglesVisibility(const BrxCvDbTinSurfaceDefinitionTrianglesVisibility& other);
    BrxCvDbTinSurfaceDefinitionTrianglesVisibility& operator=(const BrxCvDbTinSurfaceDefinitionTrianglesVisibility& other);
    virtual ~BrxCvDbTinSurfaceDefinitionTrianglesVisibility();

    AcGePoint2dArray positions() const;
    bool setPositions(const AcGePoint2dArray& positions);

    bool visible() const;
    bool setVisible(const bool visible);
};

// SurfaceDefinition "RemoveElevations"
class BRX_EXPORT BrxCvDbTinSurfaceDefinitionRemoveElevations : public BrxCvDbTinSurfaceDefinition
{
public :
    ACRX_DECLARE_MEMBERS(BrxCvDbTinSurfaceDefinitionRemoveElevations);

    BrxCvDbTinSurfaceDefinitionRemoveElevations();
    BrxCvDbTinSurfaceDefinitionRemoveElevations(const bool removeBelow, const double removeBelowElevation,
                                                const bool removeAbove, const double removeAboveElevation);

    BrxCvDbTinSurfaceDefinitionRemoveElevations(const BrxCvDbTinSurfaceDefinitionRemoveElevations& other);
    BrxCvDbTinSurfaceDefinitionRemoveElevations& operator=(const BrxCvDbTinSurfaceDefinitionRemoveElevations& other);
    virtual ~BrxCvDbTinSurfaceDefinitionRemoveElevations();

    bool removeBelow() const;
    bool setRemoveBelow(const bool removeBelow);

    double removeBelowElevation() const;
    bool setRemoveBelowElevation(const double removeBelowElevation);

    bool removeAbove() const;
    bool setRemoveAbove(const bool removeAbove);

    double removeAboveElevation() const;
    bool setRemoveAboveElevation(const double removeAboveElevation);

    Adesk::UInt32 removedPointsCount() const;
};
