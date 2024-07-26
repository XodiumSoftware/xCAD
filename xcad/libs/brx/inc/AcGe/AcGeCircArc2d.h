// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCircArc2d: public AcGeCurve2d
{
public:
    AcGeCircArc2d();
    AcGeCircArc2d(const AcGePoint2d&,double);
    AcGeCircArc2d(const AcGePoint2d&,const AcGePoint2d&,const AcGePoint2d&);
    AcGeCircArc2d(const AcGePoint2d&,const AcGePoint2d&,double,Adesk::Boolean = Adesk::kTrue);
    AcGeCircArc2d(const AcGePoint2d&,double,double,double,const AcGeVector2d& = AcGeVector2d::kXAxis,Adesk::Boolean = Adesk::kFalse);
    AcGeCircArc2d(const AcGeCircArc2d&);

    AcGeCircArc2d& set(const AcGeCurve2d&,const AcGeCurve2d&,const AcGeCurve2d&,double&,double&,double&,Adesk::Boolean&);
    AcGeCircArc2d& set(const AcGeCurve2d&,const AcGeCurve2d&,double,double&,double&,Adesk::Boolean&);
    AcGeCircArc2d& set(const AcGePoint2d&,const AcGePoint2d&,const AcGePoint2d&);
    AcGeCircArc2d& set(const AcGePoint2d&,const AcGePoint2d&,const AcGePoint2d&,AcGeError&);
    AcGeCircArc2d& set(const AcGePoint2d&,const AcGePoint2d&,double,Adesk::Boolean = Adesk::kTrue);
    AcGeCircArc2d& set(const AcGePoint2d&,double);
    AcGeCircArc2d& set(const AcGePoint2d&,double,double,double,const AcGeVector2d& = AcGeVector2d::kXAxis,Adesk::Boolean = Adesk::kFalse);
    AcGeCircArc2d& setAngles(double,double);
    AcGeCircArc2d& setCenter(const AcGePoint2d&);
    AcGeCircArc2d& setRadius(double);
    AcGeCircArc2d& setRefVec(const AcGeVector2d&);
    AcGeCircArc2d& setToComplement();
    AcGePoint2d center() const;
    AcGePoint2d endPoint() const;
    AcGePoint2d startPoint() const;
    AcGeVector2d refVec() const;
    Adesk::Boolean intersectWith(const AcGeCircArc2d&,int&,AcGePoint2d&,AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt2d&,int&,AcGePoint2d&,AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isClockWise() const;
    Adesk::Boolean isInside(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean tangent(const AcGePoint2d&,AcGeLine2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean tangent(const AcGePoint2d&,AcGeLine2d&,const AcGeTol&,AcGeError&) const;
    double endAng() const;
    double radius() const;
    double startAng() const;

    AcGeCircArc2d& operator=(const AcGeCircArc2d&);
};
