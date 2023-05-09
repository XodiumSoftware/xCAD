// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSplineEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCubicSplineCurve3d: public AcGeSplineEnt3d
{
public:
    AcGeCubicSplineCurve3d();
    AcGeCubicSplineCurve3d(const AcGeCubicSplineCurve3d&);
    AcGeCubicSplineCurve3d(const AcGeCurve3d&,double = AcGeContext::gTol.equalPoint());
    AcGeCubicSplineCurve3d(const AcGePoint3dArray&,const AcGeTol& = AcGeContext::gTol);
    AcGeCubicSplineCurve3d(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol);
    AcGeCubicSplineCurve3d(const AcGeKnotVector&,const AcGePoint3dArray&,const AcGeVector3dArray&,Adesk::Boolean = Adesk::kFalse);

    AcGeCubicSplineCurve3d& setFirstDerivAt(int,const AcGeVector3d&);
    AcGeCubicSplineCurve3d& setFitPointAt(int,const AcGePoint3d&);
    AcGePoint3d fitPointAt(int) const;
    AcGeVector3d firstDerivAt(int) const;
    int numFitPoints() const;

    AcGeCubicSplineCurve3d& operator=(const AcGeCubicSplineCurve3d&);
};