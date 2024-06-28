// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDimension.h"

/** _ */
class BRX_EXPORT AcDbRadialDimensionLarge: public AcDbDimension
{
public:
    ACDB_DECLARE_MEMBERS(AcDbRadialDimensionLarge);

    AcDbRadialDimensionLarge();
    AcDbRadialDimensionLarge(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,double,const ACHAR* = NULL,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbRadialDimensionLarge();

    Acad::ErrorStatus setCenter(const AcGePoint3d&);
    Acad::ErrorStatus setChordPoint(const AcGePoint3d&);
    Acad::ErrorStatus setJogAngle(double);
    Acad::ErrorStatus setJogPoint(const AcGePoint3d&);
    Acad::ErrorStatus setJogPointPP(const AcGePoint3d&);
    Acad::ErrorStatus setOverrideCenter(const AcGePoint3d&);
    Acad::ErrorStatus setOverrideCenterPP(const AcGePoint3d&);
    Acad::ErrorStatus setTextPositionPP(const AcGePoint3d&);
    AcGePoint3d center() const;
    AcGePoint3d chordPoint() const;
    AcGePoint3d jogPoint() const;
    AcGePoint3d overrideCenter() const;
    double jogAngle() const;

    //V10
    Acad::ErrorStatus setExtArcEndAngle(double);
    Acad::ErrorStatus setExtArcStartAngle(double);
    double extArcEndAngle() const;
    double extArcStartAngle() const;
};
