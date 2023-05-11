// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePointEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePointOnCurve3d: public AcGePointEnt3d
{
public:
    AcGePointOnCurve3d();
    AcGePointOnCurve3d(const AcGeCurve3d&);
    AcGePointOnCurve3d(const AcGeCurve3d&,double);
    AcGePointOnCurve3d(const AcGePointOnCurve3d&);

    AcGePoint3d point() const;
    AcGePoint3d point(const AcGeCurve3d&,double);
    AcGePoint3d point(double);
    AcGePointOnCurve3d& setCurve(const AcGeCurve3d&);
    AcGePointOnCurve3d& setParameter(double);
    AcGeVector3d deriv(int) const;
    AcGeVector3d deriv(int,const AcGeCurve3d&,double);
    AcGeVector3d deriv(int,double);
    Adesk::Boolean curvature(double&);
    Adesk::Boolean curvature(double,double&);
    Adesk::Boolean isSingular(const AcGeTol& = AcGeContext::gTol) const;
    const AcGeCurve3d* curve() const;
    double parameter() const;

    AcGePointOnCurve3d& operator=(const AcGePointOnCurve3d&);
};
