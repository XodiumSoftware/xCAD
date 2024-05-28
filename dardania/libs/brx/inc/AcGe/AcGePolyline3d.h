// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSplineEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePolyline3d: public AcGeSplineEnt3d
{
public:
    AcGePolyline3d();
    AcGePolyline3d(const AcGeCurve3d&,double);
    AcGePolyline3d(const AcGePoint3dArray&);
    AcGePolyline3d(const AcGeKnotVector&,const AcGePoint3dArray&);
    AcGePolyline3d(const AcGePolyline3d&);

    AcGePoint3d fitPointAt(int) const;
    AcGeSplineEnt3d& setFitPointAt(int,const AcGePoint3d&);
    int numFitPoints() const;

    AcGePolyline3d& operator=(const AcGePolyline3d&);
};