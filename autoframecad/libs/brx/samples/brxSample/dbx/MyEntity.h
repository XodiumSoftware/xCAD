// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

//This is an example of a custom entity based on AcDbEntity
//The entity represents a circle that is controlled by 3 points

class CMyEntity : public AcDbEntity
{
private:
    // stored in DWG
    AcGePoint3d m_point1;
    AcGePoint3d m_point2;
    AcGePoint3d m_point3;

public:
    ACRX_DECLARE_MEMBERS(CMyEntity);

public:
    CMyEntity();
    CMyEntity(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3);
    virtual ~CMyEntity() {};

    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);

    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);

    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& modes, AcDbIntArray& ids) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& gripIds, const AcGeVector3d& translation);

    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode, Adesk::GsMarker gsSelectionMark, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds) const;
    virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode, Adesk::GsMarker gsSelectionMark, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds, const AcGeMatrix3d& matrix) const;

    virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType type, Adesk::GsMarker gsMark,
                                                          const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform,
                                                          int& numPaths, AcDbFullSubentPath*& subentPaths,
                                                          int numInserts, AcDbObjectId* entAndInsertStack) const;

    virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath& path, AcDbIntPtrArray& gsMarkers) const;

    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& matrix);
    virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath& acSubentPath) const;

    virtual Acad::ErrorStatus getPlane(AcGePlane& plane, AcDb::Planarity& planarity) const;
};

ACDB_REGISTER_OBJECT_ENTRY_AUTO(CMyEntity)
