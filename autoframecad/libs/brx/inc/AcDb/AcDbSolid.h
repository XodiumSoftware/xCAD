// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbSolid: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSolid);

    AcDbSolid();
    AcDbSolid(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcDbSolid(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    ~AcDbSolid();

    Acad::ErrorStatus getPointAt(Adesk::UInt16,AcGePoint3d&) const;
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setPointAt(Adesk::UInt16,const AcGePoint3d&);
    Acad::ErrorStatus setThickness(double);
    AcGeVector3d normal() const;
    double thickness() const;

protected:
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
