// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePlanarEnt.h"

/** _ */
class BRX_IMPORTEXPORT AcGePlane: public AcGePlanarEnt
{
public:
    static const AcGePlane kXYPlane;
    static const AcGePlane kYZPlane;
    static const AcGePlane kZXPlane;

    AcGePlane();
    AcGePlane(double,double,double,double);
    AcGePlane(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcGePlane(const AcGePoint3d&,const AcGeVector3d&);
    AcGePlane(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    AcGePlane(const AcGePlane&);

    AcGePlane& set(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcGePlane& set(const AcGePoint3d&,const AcGeVector3d&);
    AcGePlane& set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    AcGePlane& set(double,double,double,double);
    Adesk::Boolean intersectWith(const AcGeBoundedPlane&,AcGeLineSeg3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGePlane&,AcGeLine3d&,const AcGeTol& = AcGeContext::gTol) const;
    double signedDistanceTo(const AcGePoint3d&) const;

    AcGePlane& operator=(const AcGePlane&);
};
