// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve3d.h"
#include "AcGe/AcGePlane.h"

/** _ */
class BRX_IMPORTEXPORT AcGeEllipArc3d: public AcGeCurve3d
{
public:
    AcGeEllipArc3d();
    AcGeEllipArc3d(const AcGeCircArc3d&);
    AcGeEllipArc3d(const AcGeEllipArc3d&);
    AcGeEllipArc3d(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double);
    AcGeEllipArc3d(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double,double);

    AcGeEllipArc3d& set(const AcGeCircArc3d&);
    AcGeEllipArc3d& set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double);
    AcGeEllipArc3d& set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double,double);
    AcGeEllipArc3d& setAngles(double,double);
    AcGeEllipArc3d& setAxes(const AcGeVector3d&,const AcGeVector3d&);
    AcGeEllipArc3d& setCenter(const AcGePoint3d&);
    AcGeEllipArc3d& setMajorRadius(double);
    AcGeEllipArc3d& setMinorRadius(double);
    AcGePoint3d center() const;
    AcGePoint3d closestPointToPlane(const AcGePlanarEnt&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d endPoint() const;
    AcGePoint3d startPoint() const;
    AcGeVector3d majorAxis() const;
    AcGeVector3d minorAxis() const;
    AcGeVector3d normal() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGePlanarEnt&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isCircular(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isInside(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean projIntersectWith(const AcGeLinearEnt3d&,const AcGeVector3d&,int&,AcGePoint3d&,AcGePoint3d&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    double endAng() const;
    double majorRadius() const;
    double minorRadius() const;
    double startAng() const;
    void getPlane(AcGePlane&) const;

    AcGeEllipArc3d& operator=(const AcGeEllipArc3d&);
};