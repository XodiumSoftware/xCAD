// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeEntity3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCurveSurfInt: public AcGeEntity3d
{
public:
    AcGeCurveSurfInt();
    AcGeCurveSurfInt(const AcGeCurveSurfInt&);
    AcGeCurveSurfInt(const AcGeCurve3d&,const AcGeSurface&,const AcGeTol& = AcGeContext::gTol);

    AcGeCurveSurfInt& set(const AcGeCurve3d&,const AcGeSurface&,const AcGeTol& = AcGeContext::gTol);
    AcGePoint3d intPoint(int,AcGeIntersectError&) const;
    AcGeTol tolerance() const;
    const AcGeCurve3d* curve() const;
    const AcGeSurface* surface() const;
    int numIntPoints(AcGeIntersectError&) const;
    void getIntConfigs(int,AcGe::csiConfig&,AcGe::csiConfig&,Adesk::Boolean&,AcGeIntersectError&) const;
    void getIntParams(int,double&,AcGePoint2d&,AcGeIntersectError&) const;
    void getPointOnCurve(int,AcGePointOnCurve3d&,AcGeIntersectError&) const;
    void getPointOnSurface(int,AcGePointOnSurface&,AcGeIntersectError&) const;

    AcGeCurveSurfInt& operator=(const AcGeCurveSurfInt&);
};
