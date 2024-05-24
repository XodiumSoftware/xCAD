// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeCurve3d.h"
#include "AcGe/AcGeKnotVector.h"

/** _ */
class BRX_IMPORTEXPORT AcGeSplineEnt3d: public AcGeCurve3d
{
protected:
    AcGeSplineEnt3d();
    AcGeSplineEnt3d(const AcGeSplineEnt3d&);

public:
    AcGePoint3d controlPointAt(int) const;
    AcGePoint3d endPoint() const;
    AcGePoint3d startPoint() const;
    AcGeSplineEnt3d& setControlPointAt(int,const AcGePoint3d&);
    AcGeSplineEnt3d& setKnotAt(int,double);
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

    AcGeSplineEnt3d& operator=(const AcGeSplineEnt3d&);
};