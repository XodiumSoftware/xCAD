// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeLinearEnt3d: public AcGeCurve3d
{
protected:
    AcGeLinearEnt3d();
    AcGeLinearEnt3d(const AcGeLinearEnt3d&);

public:
    AcGePoint3d pointOnLine() const;
    AcGeVector3d direction() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGePlanarEnt&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isColinearTo(const AcGeLinearEnt3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePlane&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint3d&,double&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(double,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGeLinearEnt3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isParallelTo(const AcGePlanarEnt&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGeLinearEnt3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPerpendicularTo(const AcGePlanarEnt&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean overlap(const AcGeLinearEnt3d&,AcGeLinearEnt3d*&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean projIntersectWith(const AcGeLinearEnt3d&,const AcGeVector3d&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getLine(AcGeLine3d&) const;
    void getPerpPlane(const AcGePoint3d&,AcGePlane&) const;

    AcGeLinearEnt3d& operator=(const AcGeLinearEnt3d&);
};
