// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbTrace: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbTrace);

    AcDbTrace();
    AcDbTrace(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    ~AcDbTrace();

    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Adesk::Boolean isPlanar() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    Acad::ErrorStatus getPointAt(Adesk::UInt16,AcGePoint3d&) const;
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setPointAt(Adesk::UInt16,const AcGePoint3d&);
    Acad::ErrorStatus setThickness(double);
    AcGeVector3d normal() const;
    double thickness() const;
};
