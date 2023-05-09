// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDbRadialDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRadialDimension);

    AcDbRadialDimension();
    AcDbRadialDimension(const AcGePoint3d&,const AcGePoint3d&,double,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbRadialDimension();

    Acad::ErrorStatus setCenter(const AcGePoint3d&);
    Acad::ErrorStatus setChordPoint(const AcGePoint3d&);
    Acad::ErrorStatus setLeaderLength(double);
    AcGePoint3d center() const;
    AcGePoint3d chordPoint() const;
    double leaderLength() const;

    //V10
    Acad::ErrorStatus setExtArcEndAngle(double);
    Acad::ErrorStatus setExtArcStartAngle(double);
    double extArcEndAngle() const;
    double extArcStartAngle() const;
};
