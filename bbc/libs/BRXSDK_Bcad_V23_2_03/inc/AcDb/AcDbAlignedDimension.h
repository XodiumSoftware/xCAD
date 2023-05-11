// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDbAlignedDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAlignedDimension);

    AcDbAlignedDimension();
    AcDbAlignedDimension(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbAlignedDimension();

    AcGePoint3d dimLinePoint() const;
    AcGePoint3d xLine1Point() const;
    AcGePoint3d xLine2Point() const;
    Acad::ErrorStatus setDimLinePoint(const AcGePoint3d&);
    Acad::ErrorStatus setOblique(double);
    Acad::ErrorStatus setXLine1Point(const AcGePoint3d&);
    Acad::ErrorStatus setXLine2Point(const AcGePoint3d&);
    double oblique() const;
};
