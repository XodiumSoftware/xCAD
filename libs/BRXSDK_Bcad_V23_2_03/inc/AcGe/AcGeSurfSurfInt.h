// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeEntity3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeSurfSurfInt: public AcGeEntity3d
{
public:
    AcGeSurfSurfInt();
    AcGeSurfSurfInt(const AcGeSurfSurfInt&);
    AcGeSurfSurfInt(const AcGeSurface&,const AcGeSurface&,const AcGeTol& = AcGeContext::gTol);

    AcGe::ssiType getType(int,AcGe::AcGeIntersectError&) const;
    AcGeCurve2d* intParamCurve(int,Adesk::Boolean,Adesk::Boolean,AcGe::AcGeIntersectError&) const;
    AcGeCurve3d* intCurve(int,Adesk::Boolean,AcGe::AcGeIntersectError&) const;
    AcGePoint3d intPoint(int,AcGe::AcGeIntersectError&) const;
    AcGeSurfSurfInt& set(const AcGeSurface&,const AcGeSurface&,const AcGeTol& = AcGeContext::gTol);
    AcGeTol tolerance() const;
    const AcGeSurface* surface1() const;
    const AcGeSurface* surface2() const;
    int getDimension(int,AcGe::AcGeIntersectError&) const;
    int numResults(AcGe::AcGeIntersectError&) const;
    void getIntConfigs(int,AcGe::ssiConfig&,AcGe::ssiConfig&,AcGe::ssiConfig&,AcGe::ssiConfig&,AcGe::ssiType&,int&,AcGe::AcGeIntersectError&) const;
    void getIntPointParams(int,AcGePoint2d&,AcGePoint2d&,AcGe::AcGeIntersectError&) const;

    AcGeSurfSurfInt& operator=(const AcGeSurfSurfInt&);
};
