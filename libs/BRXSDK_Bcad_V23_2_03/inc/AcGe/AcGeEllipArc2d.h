// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeEllipArc2d: public AcGeCurve2d
{
public:
    AcGeEllipArc2d();
    AcGeEllipArc2d(const AcGeCircArc2d&);
    AcGeEllipArc2d(const AcGeEllipArc2d&);
    AcGeEllipArc2d(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&,double,double);
    AcGeEllipArc2d(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&,double,double,double,double);

    AcGeEllipArc2d& set(const AcGeCircArc2d&);
    AcGeEllipArc2d& set(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&,double,double);
    AcGeEllipArc2d& set(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&,double,double,double,double);
    AcGeEllipArc2d& setAngles(double,double);
    AcGeEllipArc2d& setAxes(const AcGeVector2d&,const AcGeVector2d&);
    AcGeEllipArc2d& setCenter(const AcGePoint2d&);
    AcGeEllipArc2d& setMajorRadius(double);
    AcGeEllipArc2d& setMinorRadius(double);
    AcGePoint2d center() const;
    AcGePoint2d endPoint() const;
    AcGePoint2d startPoint() const;
    AcGeVector2d majorAxis() const;
    AcGeVector2d minorAxis() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt2d&,int&,AcGePoint2d&,AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isCircular(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isClockWise() const;
    Adesk::Boolean isInside(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    double endAng() const;
    double majorRadius() const;
    double minorRadius() const;
    double startAng() const;

    AcGeEllipArc2d& operator=(const AcGeEllipArc2d&);
};