// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "MyEntity.h"

ACRX_DXF_DEFINE_MEMBERS(CMyEntity, AcDbEntity, AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
                        AcDbProxyEntity::kNoOperation, CMyEntity, "BRX Sample Application")


#define _PI_ 3.1415926535897932384626433832795028841971693993751

CMyEntity::CMyEntity()
{
}

CMyEntity::CMyEntity(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3)
{
    m_point1 = point1;
    m_point2 = point2;
    m_point3 = point3;
}

Acad::ErrorStatus CMyEntity::dwgOutFields(AcDbDwgFiler* pFiler) const
{
    assertReadEnabled();

    Acad::ErrorStatus status = AcDbEntity::dwgOutFields(pFiler);
    if (Acad::eOk != status)
        return status;

    pFiler->writeItem(m_point1);
    pFiler->writeItem(m_point2);
    pFiler->writeItem(m_point3);

    return pFiler->filerStatus();
}

Acad::ErrorStatus CMyEntity::dwgInFields(AcDbDwgFiler* pFiler)
{
    assertWriteEnabled();

    Acad::ErrorStatus status = AcDbEntity::dwgInFields(pFiler);
    if (Acad::eOk != status)
        return status;

    pFiler->readItem(&m_point1);
    pFiler->readItem(&m_point2);
    pFiler->readItem(&m_point3);

    return pFiler->filerStatus();
}

Acad::ErrorStatus CMyEntity::dxfOutFields(AcDbDxfFiler* pFiler) const
{
    assertReadEnabled();

    Acad::ErrorStatus status = AcDbEntity::dxfOutFields(pFiler);
    if (Acad::eOk != status)
        return status;

    pFiler->writeItem(AcDb::kDxfSubclass,_T("CMYENTITY"));

    pFiler->writeItem(AcDb::kDxfXCoord,   m_point1);
    pFiler->writeItem(AcDb::kDxfXCoord+1, m_point2);
    pFiler->writeItem(AcDb::kDxfXCoord+2, m_point3);

    return pFiler->filerStatus();
}

Acad::ErrorStatus CMyEntity::dxfInFields(AcDbDxfFiler* pFiler)
{
    assertWriteEnabled();

    Acad::ErrorStatus status = AcDbEntity::dxfInFields(pFiler);
    if (Acad::eOk != status)
        return status;

    if (!pFiler->atSubclassData(_T("CMYENTITY")))
        return Acad::eBadDxfSequence;

    struct resbuf rb;
    while (Acad::eOk == status)
    {
        status = pFiler->readResBuf(&rb);

        if (Acad::eOk != status)
            return Acad::eBadDxfSequence;

        switch (rb.restype)
        {
            case AcDb::kDxfXCoord:
                m_point1 = asPnt3d(rb.resval.rpoint);
                continue;
            case AcDb::kDxfXCoord + 1:
                m_point2 = asPnt3d(rb.resval.rpoint);
                continue;
            case AcDb::kDxfXCoord + 2:
                m_point3 = asPnt3d(rb.resval.rpoint);
                continue;
            default:
                pFiler->pushBackItem();
                status = Acad::eEndOfFile;
                continue;
        }
    }

    return pFiler->filerStatus();
}

Adesk::Boolean CMyEntity::subWorldDraw(AcGiWorldDraw* pWd)
{
    static AcGePoint3d  s_polygon[4];

    assertReadEnabled();

    pWd->subEntityTraits().setFillType(kAcGiFillNever);
    s_polygon[0]  = m_point1;
    s_polygon[1]  = m_point2;
    s_polygon[2]  = m_point3;
    s_polygon[3]  = m_point1;
    pWd->geometry().polyline(4, s_polygon, nullptr, 10);

    pWd->subEntityTraits().setSelectionMarker(100);
    pWd->subEntityTraits().setFillType(kAcGiFillNever);
    pWd->geometry().circle(m_point1, m_point2, m_point3);

    pWd->subEntityTraits().setSelectionMarker(1);
    pWd->subEntityTraits().setFillType(kAcGiFillAlways);
    pWd->geometry().polygon(3, &m_point1);

    return Adesk::kTrue;
}

Acad::ErrorStatus CMyEntity::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& modes, AcDbIntArray& ids) const
{
    assertReadEnabled();

    gripPoints.append(m_point1);
    gripPoints.append(m_point2);
    gripPoints.append(m_point3);

    AcGeCircArc3d geCircle(m_point1, m_point2, m_point3);
    gripPoints.append(geCircle.center());

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::subMoveGripPointsAt(const AcDbIntArray& gripIds, const AcGeVector3d& translation)
{
    assertWriteEnabled();

    for (int i=0; i<gripIds.length(); ++i)
    {
        int gripId = gripIds.at(i);

        switch(gripId)
        {
            case 0:
                m_point1 = m_point1 + translation;
                break;
            case 1:
                m_point2 = m_point2 + translation;
                break;
            case 2:
                m_point3 = m_point3 + translation;
                break;
            case 3:  // center point
                m_point1 = m_point1 + translation;
                m_point2 = m_point2 + translation;
                m_point3 = m_point3 + translation;
                break;
        }
    }

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::subGetOsnapPoints(AcDb::OsnapMode osnapMode, Adesk::GsMarker gsSelectionMark,
                                               const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
                                               const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
                                               AcDbIntArray& geomIds) const
{
    AcGeMatrix3d matrix; matrix.setToIdentity();
    return subGetOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform,
                             snapPoints, geomIds, matrix);
}

Acad::ErrorStatus CMyEntity::subGetOsnapPoints(AcDb::OsnapMode osnapMode, Adesk::GsMarker gsSelectionMark,
                                               const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint,
                                               const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints,
                                               AcDbIntArray& geomIds, const AcGeMatrix3d& matrix) const
{
    if (gsSelectionMark == 100) // the circle
    {
        AcGeCircArc3d geCircle(m_point1, m_point2, m_point3);
        switch (osnapMode)
        {
            case AcDb::kOsModeCen :
            case AcDb::kOsModeIns :
            {
                snapPoints.append(geCircle.center());
                return Acad::eOk;
            }
            case AcDb::kOsModeNear :
            {
                geCircle.setAngles(0.0, 2.0 * _PI_);
                AcGePointOnCurve3d pntOnCurve;
                geCircle.getClosestPointTo(pickPoint, pntOnCurve);
                snapPoints.append(pntOnCurve.point());
                return Acad::eOk;
            }
        }

        AcDbCircle circle(geCircle.center(), geCircle.normal(), geCircle.radius());
        return circle.getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint,
                                     viewXform, snapPoints, geomIds);
    }

    if ((gsSelectionMark >= 10) && (gsSelectionMark <= 12)) // the polygon
    {
        switch (osnapMode)
        {
            case AcDb::kOsModeEnd :
            {
                if (gsSelectionMark == 10)
                {
                    snapPoints.append(m_point1);
                    snapPoints.append(m_point2);
                }
                else
                if (gsSelectionMark == 11)
                {
                    snapPoints.append(m_point2);
                    snapPoints.append(m_point3);
                }
                else
                if (gsSelectionMark == 12)
                {
                    snapPoints.append(m_point3);
                    snapPoints.append(m_point1);
                }
                return Acad::eOk;
            }
            case AcDb::kOsModeMid :
            {
                if (gsSelectionMark == 10)
                {
                    snapPoints.append(m_point1 + (0.5 * (m_point2 - m_point1)));
                }
                else
                if (gsSelectionMark == 11)
                {
                    snapPoints.append(m_point2 + (0.5 * (m_point3 - m_point2)));
                }
                else
                if (gsSelectionMark == 12)
                {
                    snapPoints.append(m_point3 + (0.5 * (m_point1 - m_point3)));
                }
                return Acad::eOk;
            }
            case AcDb::kOsModeNear :
            {
                AcGeLine3d line;
                AcGePointOnCurve3d pntOnCurve;
                if (gsSelectionMark == 10)
                {
                    line.set(m_point1, m_point2);
                    line.getClosestPointTo(pickPoint, pntOnCurve);
                    snapPoints.append(pntOnCurve.point());
                }
                else
                if (gsSelectionMark == 11)
                {
                    line.set(m_point2, m_point3);
                    line.getClosestPointTo(pickPoint, pntOnCurve);
                    snapPoints.append(pntOnCurve.point());
                }
                else
                if (gsSelectionMark == 12)
                {
                    line.set(m_point3, m_point1);
                    line.getClosestPointTo(pickPoint, pntOnCurve);
                    snapPoints.append(pntOnCurve.point());
                }
                return Acad::eOk;
            }
        }

        AcGePoint3dArray vertices(3);
        vertices.append(m_point1);
        vertices.append(m_point2);
        vertices.append(m_point3);
        AcDb3dPolyline polygon(AcDb::k3dSimplePoly, vertices, Adesk::kTrue);
        
        return polygon.getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint,
                                      viewXform, snapPoints, geomIds);
    }

    if (gsSelectionMark == 1)
    {
        AcGePoint3dArray vertices(3);
        vertices.append(m_point1);
        vertices.append(m_point2);
        vertices.append(m_point3);
        AcDb3dPolyline polygon(AcDb::k3dSimplePoly, vertices, Adesk::kTrue);
        
        return polygon.getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint,
                                      viewXform, snapPoints, geomIds);
    }

    return Acad::eNotImplementedYet;
}

Acad::ErrorStatus CMyEntity::subGetSubentPathsAtGsMarker(AcDb::SubentType type, Adesk::GsMarker gsMark,
                                                         const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform,
                                                         int& numPaths, AcDbFullSubentPath*& subentPaths,
                                                         int numInserts, AcDbObjectId* entAndInsertStack) const
{
    assertReadEnabled();

    numPaths = 0;
    subentPaths = NULL;

    switch (type)
    {
        case AcDb::kVertexSubentType :
            numPaths = 1;
            subentPaths = new AcDbFullSubentPath[1];
            subentPaths[0] = AcDbFullSubentPath(objectId(), AcDb::kVertexSubentType, gsMark);
            return Acad::eOk;
        case AcDb::kEdgeSubentType :
            numPaths = 1;
            subentPaths = new AcDbFullSubentPath[1];
            subentPaths[0] = AcDbFullSubentPath(objectId(), AcDb::kEdgeSubentType, gsMark);
            return Acad::eOk;
        case AcDb::kFaceSubentType :
        case AcDb::kNullSubentType :
        default :
            assert(false);
            break;
    }

    return Acad::eInvalidInput;
}

Acad::ErrorStatus CMyEntity::subGetGsMarkersAtSubentPath(const AcDbFullSubentPath& path, AcDbIntPtrArray& gsMarkers) const
{
    return Acad::eNotImplementedYet;
}

AcDbEntity* CMyEntity::subSubentPtr(const AcDbFullSubentPath& acSubentPath) const
{
    assertReadEnabled();

    // GsMarker 10,11,12 - triangle edges  100 - circle
    const AcDbSubentId subEntId = acSubentPath.subentId();
    switch (subEntId.type())
    {
        case AcDb::kVertexSubentType :
        {
            AcDbPoint* pt = new AcDbPoint();
            if (subEntId.index() == 10)
            {
                pt->setPosition(m_point1);
            }
            else
            if (subEntId.index() == 11)
            {
                pt->setPosition(m_point2);
            }
            else
            if (subEntId.index() == 12)
            {
                pt->setPosition(m_point3);
            }
            else
            if (subEntId.index() == 100) // circle
            {
                AcGeCircArc3d geCircle(m_point1, m_point2, m_point3);
                pt->setPosition(geCircle.center());
            }
            pt->setPropertiesFrom(this);
            return pt;
        }
        case AcDb::kEdgeSubentType :
        {
            if (subEntId.index() == 1) // outer polygon
            {
                AcGePoint3dArray vertices(3);
                vertices.append(m_point1);
                vertices.append(m_point2);
                vertices.append(m_point3);
                AcDb3dPolyline* polyline = new AcDb3dPolyline(AcDb::k3dSimplePoly, vertices, Adesk::kTrue);
                return polyline;
            }

            if (subEntId.index() == 100) // circle
            {
                AcGeCircArc3d geCircle(m_point1, m_point2, m_point3);
                AcDbCircle* circle = new AcDbCircle(geCircle.center(), geCircle.normal(), geCircle.radius());
                circle->setPropertiesFrom(this);
                return circle;
            }

            AcDbLine* line = new AcDbLine();
            if (subEntId.index() == 10)
            {
                line->setStartPoint(m_point1);
                line->setEndPoint(m_point2);
            }
            else
            if (subEntId.index() == 11)
            {
                line->setStartPoint(m_point2);
                line->setEndPoint(m_point3);
            }
            else
            if (subEntId.index() == 12)
            {
                line->setStartPoint(m_point3);
                line->setEndPoint(m_point1);
            }
            line->setPropertiesFrom(this);
            return line;
        }
        case AcDb::kFaceSubentType :
        case AcDb::kNullSubentType :
        default :
            assert(false);
            break;
    }

    return nullptr;
}

Acad::ErrorStatus CMyEntity::subTransformBy(const AcGeMatrix3d& matrix)
{
    assertWriteEnabled();

    m_point1.transformBy(matrix);
    m_point2.transformBy(matrix);
    m_point3.transformBy(matrix);

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::getPlane(AcGePlane& plane, AcDb::Planarity& planarity) const
{
    assertReadEnabled();

    const AcGePoint3d& origin(m_point1);

    AcGeVector3d uAxis(m_point3 - m_point1);
    AcGeVector3d vAxis(m_point2 - m_point1);

    const AcGeVector3d normVec = uAxis.crossProduct(vAxis);
    vAxis = normVec.crossProduct(uAxis);

    plane.set(origin, uAxis.normalize(), vAxis.normalize());
    planarity = AcDb::kPlanar;

    return Acad::eOk;
}
