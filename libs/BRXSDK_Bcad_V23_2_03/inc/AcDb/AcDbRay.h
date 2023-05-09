// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbRay: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRay);

    AcDbRay();
    ~AcDbRay();

    DBCURVE_METHODS

    Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d&,double,AcDbVoidPtrArray&) const;
    AcGePoint3d basePoint() const;
    AcGeVector3d unitDir() const;
    void setBasePoint(const AcGePoint3d&);
    void setUnitDir(const AcGeVector3d&);

    // V22
    AcGePoint3d secondPoint() const;
    Acad::ErrorStatus setSecondPoint(const AcGePoint3d&);
};
