#include "stdafx.h"
#include "CustomEntity.h"


ACRX_DXF_DEFINE_MEMBERS (
    CMyEntity,
    AcDbEntity,
    AcDb::kDHL_CURRENT,
    AcDb::kMReleaseCurrent, 
    AcDbProxyEntity::kAllAllowedBits,
    CMYENTITY,
    CMyEntity
    "|Product Desc:     A description for your object" 
    "|Company:          Your company name" 
    "|WEB Address:      Your company WEB site address" 
)

CMyEntity::CMyEntity()
{
}

CMyEntity::CMyEntity(const AcGePoint3d& point1,const AcGePoint3d& point2,const AcGePoint3d& point3)
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

    pFiler->writeItem(AcDb::kDxfXCoord,m_point1);
    pFiler->writeItem(AcDb::kDxfXCoord+1,m_point2);
    pFiler->writeItem(AcDb::kDxfXCoord+2,m_point3);

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
    assertReadEnabled();

    pWd->subEntityTraits().setFillType(kAcGiFillAlways);
    pWd->geometry().polygon(3,&m_point1);
    pWd->subEntityTraits().setFillType(kAcGiFillNever);
    pWd->geometry().circle(m_point1,m_point2,m_point3);

    return Adesk::kTrue;
}

Acad::ErrorStatus CMyEntity::subGetGripPoints(AcGePoint3dArray& grips,AcDbIntArray&,AcDbIntArray&) const
{
    assertReadEnabled();

    grips.append(m_point1);
    grips.append(m_point2);
    grips.append(m_point3);

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::subMoveGripPointsAt(const AcDbIntArray& gripIds,const AcGeVector3d& translation)
{
    assertWriteEnabled();

    for (int i=0; i<gripIds.length(); i++)
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
        }
    }

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::subGetOsnapPoints(AcDb::OsnapMode,Adesk::GsMarker,const AcGePoint3d&,const AcGePoint3d&,const AcGeMatrix3d&,AcGePoint3dArray&,AcDbIntArray&) const
{
    //TODO
    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::subTransformBy(const AcGeMatrix3d& matrix)
{
    assertWriteEnabled();

    m_point1.transformBy(matrix);
    m_point2.transformBy(matrix);
    m_point3.transformBy(matrix);

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::set_Point1(AcGePoint3d pnt)
{
    assertWriteEnabled () ;

    m_point1 = pnt;

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::set_Point2(AcGePoint3d pnt)
{
    assertWriteEnabled () ;

    m_point2 = pnt;

    return Acad::eOk;
}

Acad::ErrorStatus CMyEntity::set_Point3(AcGePoint3d pnt)
{
    assertWriteEnabled () ;

    m_point3 = pnt;

    return Acad::eOk;
}



//////////////////////////////////////////////////////////////////////////
ACRX_DXF_DEFINE_MEMBERS (
    CMyEntityDerived,
    CMyEntity,
    AcDb::kDHL_CURRENT,
    AcDb::kMReleaseCurrent, 
    AcDbProxyEntity::kAllAllowedBits,
    CMYENTITYDERIVED,
    CMyEntityDerived
    "|Product Desc:     A description for your object" 
    "|Company:          Your company name" 
    "|WEB Address:      Your company WEB site address" 
    )

CMyEntityDerived::CMyEntityDerived()
    : CMyEntity()
{
}

CMyEntityDerived::CMyEntityDerived(const AcGePoint3d& point1,const AcGePoint3d& point2,const AcGePoint3d& point3)
    : CMyEntity(point1,point2,point3)
{
}
