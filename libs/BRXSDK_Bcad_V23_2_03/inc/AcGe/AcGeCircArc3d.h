// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve3d.h"
#include "AcGe/AcGePlane.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCircArc3d: public AcGeCurve3d
{
public:
    AcGeCircArc3d();
    AcGeCircArc3d(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcGeCircArc3d(const AcGePoint3d&,const AcGeVector3d&,double);
    AcGeCircArc3d(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double);
    AcGeCircArc3d(const AcGeCircArc3d&);

    AcGeCircArc3d& set(const AcGeCurve3d&,const AcGeCurve3d&,const AcGeCurve3d&,double&,double&,double&,Adesk::Boolean&);
    AcGeCircArc3d& set(const AcGeCurve3d&,const AcGeCurve3d&,double,double&,double&,Adesk::Boolean&);
    AcGeCircArc3d& set(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&);
    AcGeCircArc3d& set(const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,AcGeError&);
    AcGeCircArc3d& set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double);
    AcGeCircArc3d& set(const AcGePoint3d&,const AcGeVector3d&,double);
    AcGeCircArc3d& setAngles(double,double);
    AcGeCircArc3d& setAxes(const AcGeVector3d&,const AcGeVector3d&);
    AcGeCircArc3d& setCenter(const AcGePoint3d&);
    AcGeCircArc3d& setRadius(double);
    AcGePoint3d center() const;
    AcGePoint3d closestPointToPlane(const AcGePlanarEnt&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d endPoint() const;
    AcGePoint3d startPoint() const;
    AcGeVector3d normal() const;
    AcGeVector3d refVec() const;
    Adesk::Boolean intersectWith(const AcGeCircArc3d&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGePlanarEnt&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isInside(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean projIntersectWith(const AcGeLinearEnt3d&,const AcGeVector3d&,int&,AcGePoint3d&,AcGePoint3d&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean tangent(const AcGePoint3d&,AcGeLine3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean tangent(const AcGePoint3d&,AcGeLine3d&,const AcGeTol&,AcGeError&) const;
    double endAng() const;
    double radius() const;
    double startAng() const;
    void getPlane(AcGePlane&) const;

    AcGeCircArc3d& operator=(const AcGeCircArc3d&);
};
