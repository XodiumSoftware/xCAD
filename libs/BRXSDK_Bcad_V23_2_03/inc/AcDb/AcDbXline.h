// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbXline: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbXline);

    AcDbXline();
    ~AcDbXline();

    DBCURVE_METHODS

    Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d&,double,AcDbVoidPtrArray&) const;
    AcGePoint3d basePoint() const;
    AcGeVector3d unitDir() const;
    AcGePoint3d secondPoint() const;
    void setBasePoint(const AcGePoint3d&);
    void setUnitDir(const AcGeVector3d&);
    Acad::ErrorStatus setSecondPoint(const AcGePoint3d&);
};
