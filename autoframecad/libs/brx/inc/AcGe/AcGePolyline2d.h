// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSplineEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePolyline2d: public AcGeSplineEnt2d
{
public:
    AcGePolyline2d();
    AcGePolyline2d(const AcGePoint2dArray&);
    AcGePolyline2d(const AcGeCurve2d&,double);
    AcGePolyline2d(const AcGeKnotVector&,const AcGePoint2dArray&);
    AcGePolyline2d(const AcGePolyline2d&);

    AcGePoint2d fitPointAt(int) const;
    AcGeSplineEnt2d& setFitPointAt(int,const AcGePoint2d&);
    int numFitPoints() const;

    AcGePolyline2d& operator=(const AcGePolyline2d&);
};