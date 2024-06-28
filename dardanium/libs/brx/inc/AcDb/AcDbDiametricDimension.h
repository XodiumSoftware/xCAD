// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDbDiametricDimension: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDiametricDimension);

    AcDbDiametricDimension();
    AcDbDiametricDimension(const AcGePoint3d&,const AcGePoint3d&,double,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbDiametricDimension();

    Acad::ErrorStatus setChordPoint(const AcGePoint3d&);
    Acad::ErrorStatus setFarChordPoint(const AcGePoint3d&);
    Acad::ErrorStatus setLeaderLength(double);
    AcGePoint3d chordPoint() const;
    AcGePoint3d farChordPoint() const;
    double leaderLength() const;

    //V10
    Acad::ErrorStatus setExtArcEndAngle(double);
    Acad::ErrorStatus setExtArcStartAngle(double);
    double extArcEndAngle() const;
    double extArcStartAngle() const;
};
