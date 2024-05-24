// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDb3PointAngularDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDb3PointAngularDimension);

    AcDb3PointAngularDimension();
    AcDb3PointAngularDimension(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDb3PointAngularDimension();

    AcGePoint3d arcPoint() const;
    AcGePoint3d centerPoint() const;
    AcGePoint3d xLine1Point() const;
    AcGePoint3d xLine2Point() const;
    Acad::ErrorStatus setArcPoint(const AcGePoint3d&);
    Acad::ErrorStatus setCenterPoint(const AcGePoint3d&);
    Acad::ErrorStatus setXLine1Point(const AcGePoint3d&);
    Acad::ErrorStatus setXLine2Point(const AcGePoint3d&);
};
