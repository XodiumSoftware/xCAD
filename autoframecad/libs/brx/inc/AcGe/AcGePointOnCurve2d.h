// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePointEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePointOnCurve2d: public AcGePointEnt2d
{
public:
    AcGePointOnCurve2d();
    AcGePointOnCurve2d(const AcGeCurve2d&);
    AcGePointOnCurve2d(const AcGeCurve2d&,double);
    AcGePointOnCurve2d(const AcGePointOnCurve2d&);

    AcGePoint2d point() const;
    AcGePoint2d point(const AcGeCurve2d&,double);
    AcGePoint2d point(double);
    AcGePointOnCurve2d& setCurve(const AcGeCurve2d&);
    AcGePointOnCurve2d& setParameter(double);
    AcGeVector2d deriv(int) const;
    AcGeVector2d deriv(int,const AcGeCurve2d&,double);
    AcGeVector2d deriv(int,double);
    Adesk::Boolean curvature(double&);
    Adesk::Boolean curvature(double,double&);
    Adesk::Boolean isSingular(const AcGeTol& = AcGeContext::gTol) const;
    const AcGeCurve2d* curve() const;
    double parameter() const;

    AcGePointOnCurve2d& operator=(const AcGePointOnCurve2d&);
};
