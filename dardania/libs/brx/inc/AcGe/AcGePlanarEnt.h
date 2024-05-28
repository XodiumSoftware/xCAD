// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGePlanarEnt: public AcGeSurface
{
protected:
    AcGePlanarEnt();
    AcGePlanarEnt(const AcGePlanarEnt&);

public:
    AcGePoint3d closestPointToLinearEnt(const AcGeLinearEnt3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d closestPointToPlanarEnt(const AcGePlanarEnt&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d pointOnPlane() const;
    AcGeVector3d normal() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isCoplanarTo(const AcGePlanarEnt&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGeLinearEnt3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGePlanarEnt&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGeLinearEnt3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGePlanarEnt&,const AcGeTol& = AcGeContext::gTol) const;
    void get(AcGePoint3d&,AcGePoint3d&,AcGePoint3d&) const;
    void get(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&) const;
    void getCoefficients(double&,double&,double&,double&) const;
    void getCoordSystem(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&) const;

    AcGePlanarEnt& operator=(const AcGePlanarEnt&);
};
