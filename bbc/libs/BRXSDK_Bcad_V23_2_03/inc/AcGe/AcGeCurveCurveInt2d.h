// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeInterval.h"
#include "AcGe/AcGePointOnCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCurveCurveInt2d: public AcGeEntity2d
{
public:
    AcGeCurveCurveInt2d();
    AcGeCurveCurveInt2d(const AcGeCurveCurveInt2d&);
    AcGeCurveCurveInt2d(const AcGeCurve2d&,const AcGeCurve2d&,const AcGeTol& = AcGeContext::gTol);
    AcGeCurveCurveInt2d(const AcGeCurve2d&,const AcGeCurve2d&,const AcGeInterval&,const AcGeInterval&,const AcGeTol& = AcGeContext::gTol);

    AcGeCurveCurveInt2d& orderWrt1();
    AcGeCurveCurveInt2d& orderWrt2();
    AcGeCurveCurveInt2d& set(const AcGeCurve2d&,const AcGeCurve2d&,const AcGeInterval&,const AcGeInterval&,const AcGeTol& = AcGeContext::gTol);
    AcGeCurveCurveInt2d& set(const AcGeCurve2d&,const AcGeCurve2d&,const AcGeTol& = AcGeContext::gTol);
    AcGePoint2d intPoint(int) const;
    AcGeTol tolerance() const;
    Adesk::Boolean isTangential(int) const;
    Adesk::Boolean isTransversal(int) const;
    Adesk::Boolean overlapDirection() const;
    const AcGeCurve2d* curve1() const;
    const AcGeCurve2d* curve2() const;
    double intPointTol(int) const;
    int numIntPoints() const;
    int overlapCount() const;
    void changeCurveOrder();
    void getIntConfigs(int,AcGe::AcGeXConfig&,AcGe::AcGeXConfig&) const;
    void getIntParams(int,double&,double&) const;
    void getIntRanges(AcGeInterval&,AcGeInterval&) const;
    void getOverlapRanges(int,AcGeInterval&,AcGeInterval&) const;
    void getPointOnCurve1(int,AcGePointOnCurve2d&) const;
    void getPointOnCurve2(int,AcGePointOnCurve2d&) const;

    AcGeCurveCurveInt2d& operator=(const AcGeCurveCurveInt2d&);
};
