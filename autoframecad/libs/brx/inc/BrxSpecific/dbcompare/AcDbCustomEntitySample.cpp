// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AcDbCustomEntitySample.h"


ACRX_DXF_DEFINE_MEMBERS (
    AcDbCustomEntitySample, AcDbEntity,
    AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
    AcDbProxyEntity::kNoOperation, ACDBENTITYUSERPARENT,
    "TESTARX|Product Desc:  Parent custom entity derived from AcDbEntity|Company:       Bricsys|WEB Address:   www.bricsys.com"
)

Adesk::UInt32 AcDbCustomEntitySample::kCurrentVersionNumber = 1;

//-----------------------------------------------------------------------------

AcDbCustomEntitySample::AcDbCustomEntitySample() : AcDbEntity()
    : m_center(AcGePoint3d::kOrigin), m_radiusParent(1.0)
{
}

Acad::ErrorStatus AcDbCustomEntitySample::dwgOutFields(AcDbDwgFiler* pFiler) const
{
    assertReadEnabled();

    Acad::ErrorStatus status = AcDbEntity::dwgOutFields(pFiler);
    if (Acad::eOk != status)
        return status;

    status = pFiler->writeUInt32(AcDbCustomEntitySample::kCurrentVersionNumber);
    if (Acad::eOk != status)
        return status;

    pFiler->writeItem(m_center);
    pFiler->writeItem(m_radiusParent);

    return pFiler->filerStatus();
}

Acad::ErrorStatus AcDbCustomEntitySample::dwgInFields(AcDbDwgFiler* pFiler)
{
    AW_COUNTCALL;

    assertWriteEnabled();

    Acad::ErrorStatus status = AcDbEntity::dwgInFields(pFiler);
    if (Acad::eOk != status)
        return status;

    Adesk::UInt32 version = 0;
    status = pFiler->readUInt32(&version);
    if (Acad::eOk != status)
        return status;
    if (AcDbCustomEntitySample::kCurrentVersionNumber != version)
        return Acad::eMakeMeProxy;

    pFiler->readItem(&m_center);
    pFiler->readItem(&m_radiusParent);

    return pFiler->filerStatus();
}

Adesk::Boolean AcDbCustomEntitySample::subWorldDraw(AcGiWorldDraw* pWd)
{
    assertReadEnabled();
    pWd->geometry().circle(m_center,m_radiusParent, AcGeVector3d::kZAxis);
    return Adesk::kTrue;
}

Acad::ErrorStatus AcDbCustomEntitySample::subTransformBy(const AcGeMatrix3d& matrix)
{
    assertWriteEnabled();
    return m_center.transformBy(matrix);
}

void AcDbCustomEntitySample::setCenter(const AcGePoint3d& center)
{
    m_center = center;
}

AcGePoint3d AcDbCustomEntitySample::getCenter() const
{
    return m_center;
}

void AcDbCustomEntitySample::setRadiusParent(const double& radius)
{
    m_radiusParent = radius;
}

double AcDbCustomEntitySample::getRadiusParent() const
{
    return m_radiusParent;
}
