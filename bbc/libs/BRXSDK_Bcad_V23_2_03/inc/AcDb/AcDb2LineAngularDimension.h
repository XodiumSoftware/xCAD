// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDb2LineAngularDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDb2LineAngularDimension);

    AcDb2LineAngularDimension();
    AcDb2LineAngularDimension(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDb2LineAngularDimension();

    AcGePoint3d arcPoint() const;
    AcGePoint3d xLine1End() const;
    AcGePoint3d xLine1Start() const;
    AcGePoint3d xLine2End() const;
    AcGePoint3d xLine2Start() const;
    Acad::ErrorStatus setArcPoint(const AcGePoint3d&);
    Acad::ErrorStatus setXLine1End(const AcGePoint3d&);
    Acad::ErrorStatus setXLine1Start(const AcGePoint3d&);
    Acad::ErrorStatus setXLine2End(const AcGePoint3d&);
    Acad::ErrorStatus setXLine2Start(const AcGePoint3d&);
};
