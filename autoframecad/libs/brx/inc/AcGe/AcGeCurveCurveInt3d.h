// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeInterval.h"
#include "AcGe/AcGePointOnCurve3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCurveCurveInt3d: public AcGeEntity3d
{
public:
    AcGeCurveCurveInt3d();
    AcGeCurveCurveInt3d(const AcGeCurveCurveInt3d&);
    AcGeCurveCurveInt3d(const AcGeCurve3d&,const AcGeCurve3d&,const AcGeVector3d& = AcGeVector3d::kIdentity,const AcGeTol& = AcGeContext::gTol);
    AcGeCurveCurveInt3d(const AcGeCurve3d&,const AcGeCurve3d&,const AcGeInterval&,const AcGeInterval&,const AcGeVector3d& = AcGeVector3d::kIdentity,const AcGeTol& = AcGeContext::gTol);

    AcGeCurveCurveInt3d& orderWrt1();
    AcGeCurveCurveInt3d& orderWrt2();
    AcGeCurveCurveInt3d& set(const AcGeCurve3d&,const AcGeCurve3d&,const AcGeInterval&,const AcGeInterval&,const AcGeVector3d& = AcGeVector3d::kIdentity,const AcGeTol& = AcGeContext::gTol);
    AcGeCurveCurveInt3d& set(const AcGeCurve3d&,const AcGeCurve3d&,const AcGeVector3d& = AcGeVector3d::kIdentity,const AcGeTol& = AcGeContext::gTol);
    AcGePoint3d intPoint(int) const;
    AcGeTol tolerance() const;
    AcGeVector3d planeNormal() const;
    Adesk::Boolean isTangential(int) const;
    Adesk::Boolean isTransversal(int) const;
    Adesk::Boolean overlapDirection() const;
    const AcGeCurve3d* curve1() const;
    const AcGeCurve3d* curve2() const;
    double intPointTol(int) const;
    int numIntPoints() const;
    int overlapCount() const;
    void changeCurveOrder();
    void getIntConfigs(int,AcGe::AcGeXConfig&,AcGe::AcGeXConfig&) const;
    void getIntParams(int,double&,double&) const;
    void getIntRanges(AcGeInterval&,AcGeInterval&) const;
    void getOverlapRanges (int,AcGeInterval&,AcGeInterval&) const;
    void getPointOnCurve1(int,AcGePointOnCurve3d&) const;
    void getPointOnCurve2(int,AcGePointOnCurve3d&) const;

    AcGeCurveCurveInt3d& operator=(const AcGeCurveCurveInt3d&);
};
