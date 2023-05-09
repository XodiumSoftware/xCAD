// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve2d.h"
#include "AcGe/AcGeKnotVector.h"

/** _ */
class BRX_IMPORTEXPORT AcGeSplineEnt2d: public AcGeCurve2d
{
protected:
    AcGeSplineEnt2d();
    AcGeSplineEnt2d(const AcGeSplineEnt2d&);

public:
    AcGePoint2d controlPointAt(int) const;
    AcGePoint2d endPoint() const;
    AcGePoint2d startPoint() const;
    AcGeSplineEnt2d& setControlPointAt(int,const AcGePoint2d&);
    AcGeSplineEnt2d& setKnotAt(int,double);
    Adesk::Boolean hasFitData() const;
    Adesk::Boolean isRational() const;
    const AcGeKnotVector& knots() const;
    double endParam() const;
    double knotAt(int) const;
    double startParam() const;
    int continuityAtKnot(int,const AcGeTol& = AcGeContext::gTol) const;
    int degree() const;
    int numControlPoints() const;
    int numKnots() const;
    int order() const;

    AcGeSplineEnt2d& operator=(const AcGeSplineEnt2d&);
};