// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeTorus: public AcGeSurface
{
public:
    AcGeTorus();
    AcGeTorus(const AcGeTorus&);
    AcGeTorus(double,double,const AcGePoint3d&,const AcGeVector3d&);
    AcGeTorus(double,double,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double,double);

    AcGePoint3d center() const;
    AcGeTorus& set(double,double,const AcGePoint3d&,const AcGeVector3d&);
    AcGeTorus& set(double,double,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double,double);
    AcGeTorus& setAnglesInU(double,double);
    AcGeTorus& setAnglesInV(double,double);
    AcGeTorus& setMajorRadius(double);
    AcGeTorus& setMinorRadius(double);
    AcGeVector3d axisOfSymmetry() const;
    AcGeVector3d refAxis() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,int&,AcGePoint3d&,AcGePoint3d&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isApple() const;
    Adesk::Boolean isDegenerate() const;
    Adesk::Boolean isDoughnut() const;
    Adesk::Boolean isHollow() const;
    Adesk::Boolean isLemon() const;
    Adesk::Boolean isOuterNormal() const;
    Adesk::Boolean isVortex() const;
    double majorRadius() const;
    double minorRadius() const;
    void getAnglesInU(double&,double&) const;
    void getAnglesInV(double&,double&) const;

    AcGeTorus& operator=(const AcGeTorus&);
};