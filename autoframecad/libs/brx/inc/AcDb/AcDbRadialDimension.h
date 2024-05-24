// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
