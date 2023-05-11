// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSplineEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCubicSplineCurve2d: public AcGeSplineEnt2d
{
public:
    AcGeCubicSplineCurve2d();
    AcGeCubicSplineCurve2d(const AcGeCubicSplineCurve2d&);
    AcGeCubicSplineCurve2d(const AcGeCurve2d&,double = AcGeContext::gTol.equalPoint());
    AcGeCubicSplineCurve2d(const AcGePoint2dArray&,const AcGeTol& = AcGeContext::gTol);
    AcGeCubicSplineCurve2d(const AcGePoint2dArray&,const AcGeVector2d&,const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol);
    AcGeCubicSplineCurve2d(const AcGeKnotVector&,const AcGePoint2dArray&,const AcGeVector2dArray&,Adesk::Boolean = Adesk::kFalse);

    AcGeCubicSplineCurve2d& setFirstDerivAt(int,const AcGeVector2d&);
    AcGeCubicSplineCurve2d& setFitPointAt(int,const AcGePoint2d&);
    AcGePoint2d fitPointAt(int) const;
    AcGeVector2d firstDerivAt(int) const;
    int numFitPoints() const;

    AcGeCubicSplineCurve2d& operator=(const AcGeCubicSplineCurve2d&);
};