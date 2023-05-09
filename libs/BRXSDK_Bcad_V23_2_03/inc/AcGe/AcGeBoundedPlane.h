// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePlane.h"

/** _ */
class BRX_IMPORTEXPORT AcGeBoundedPlane: public AcGePlanarEnt
{
public:
    AcGeBoundedPlane();
    AcGeBoundedPlane(const AcGeBoundedPlane&);
    AcGeBoundedPlane(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcGeBoundedPlane(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);

    AcGeBoundedPlane& set(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcGeBoundedPlane& set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&);
    Adesk::Boolean intersectWith(const AcGeBoundedPlane&,AcGeLineSeg3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGePlane&,AcGeLineSeg3d&,const AcGeTol& = AcGeContext::gTol) const;

    AcGeBoundedPlane& operator=(const AcGeBoundedPlane&);
};