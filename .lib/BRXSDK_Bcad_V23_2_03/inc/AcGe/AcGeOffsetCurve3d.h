// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeOffsetCurve3d: public AcGeCurve3d
{
public:
    AcGeOffsetCurve3d(const AcGeCurve3d&,const AcGeVector3d&,double);
    AcGeOffsetCurve3d(const AcGeOffsetCurve3d&);

    AcGeMatrix3d transformation() const;
    AcGeOffsetCurve3d& setCurve(const AcGeCurve3d&);
    AcGeOffsetCurve3d& setNormal(const AcGeVector3d&);
    AcGeOffsetCurve3d& setOffsetDistance(double);
    AcGeVector3d normal() const;
    Adesk::Boolean paramDirection() const;
    const AcGeCurve3d* curve() const;
    double offsetDistance() const;

    AcGeOffsetCurve3d& operator=(const AcGeOffsetCurve3d&);
};