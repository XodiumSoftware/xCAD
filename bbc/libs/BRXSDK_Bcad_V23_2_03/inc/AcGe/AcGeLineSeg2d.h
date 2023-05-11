// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeLine2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeLineSeg2d: public AcGeLinearEnt2d
{
public:
    AcGeLineSeg2d();
    AcGeLineSeg2d(const AcGePoint2d&,const AcGePoint2d&);
    AcGeLineSeg2d(const AcGePoint2d&,const AcGeVector2d&);
    AcGeLineSeg2d(const AcGeLineSeg2d&);

    AcGeLineSeg2d& set(const AcGeCurve2d&,const AcGeCurve2d&,double&,double&,Adesk::Boolean&);
    AcGeLineSeg2d& set(const AcGeCurve2d&,const AcGePoint2d&,double&,Adesk::Boolean&);
    AcGeLineSeg2d& set(const AcGePoint2d&,const AcGePoint2d&);
    AcGeLineSeg2d& set(const AcGePoint2d&,const AcGeVector2d&);
    AcGePoint2d baryComb(double) const;
    AcGePoint2d endPoint() const;
    AcGePoint2d midPoint() const;
    AcGePoint2d startPoint() const;
    double length() const;
    double length(double,double,double = AcGeContext::gTol.equalPoint()) const;
    void getBisector(AcGeLine2d&) const;

    AcGeLineSeg2d& operator=(const AcGeLineSeg2d&);
};
