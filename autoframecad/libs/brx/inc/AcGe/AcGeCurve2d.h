// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeInterval.h"
#include "AcGe/AcGePointOnCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCurve2d: public AcGeEntity2d
{
protected:
    AcGeCurve2d();
    AcGeCurve2d(const AcGeCurve2d&);

public:
    AcGeBoundBlock2d boundBlock() const;
    AcGeBoundBlock2d boundBlock(const AcGeInterval&) const;
    AcGeBoundBlock2d orthoBoundBlock() const;
    AcGeBoundBlock2d orthoBoundBlock(const AcGeInterval&) const;
    AcGeCurve2d& reverseParam();
    AcGeCurve2d& setInterval();
    AcGePoint2d closestPointTo(const AcGeCurve2d&,AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint2d closestPointTo(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint2d evalPoint(double) const;
    AcGePoint2d evalPoint(double,int,AcGeVector2dArray&) const;
    Adesk::Boolean area(double,double,double&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean explode(AcGeVoidPointerArray&,AcGeIntArray&,const AcGeInterval* = NULL) const;
    Adesk::Boolean getNormalPoint(const AcGePoint2d&,AcGePointOnCurve2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean hasEndPoint(AcGePoint2d&) const;
    Adesk::Boolean hasStartPoint(AcGePoint2d&) const;
    Adesk::Boolean isClosed(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isDegenerate(AcGe::EntityId&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isDegenerate(AcGeEntity2d*&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isLinear(AcGeLine2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint2d&,double&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(double,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPeriodic(double&) const;
    Adesk::Boolean setInterval(const AcGeInterval&);
    double distanceTo(const AcGeCurve2d&,const AcGeTol& = AcGeContext::gTol) const;
    double distanceTo(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    double length(double,double,double = AcGeContext::gTol.equalPoint()) const;
    double paramAtLength(double,double,Adesk::Boolean = Adesk::kTrue,double = AcGeContext::gTol.equalPoint()) const;
    double paramOf(const AcGePoint2d&,const AcGeTol& = AcGeContext::gTol) const;
    void getClosestPointTo(const AcGeCurve2d&,AcGePointOnCurve2d&,AcGePointOnCurve2d&,const AcGeTol& = AcGeContext::gTol) const;
    void getClosestPointTo(const AcGePoint2d&,AcGePointOnCurve2d&,const AcGeTol& = AcGeContext::gTol) const;
    void getInterval(AcGeInterval&) const;
    void getInterval(AcGeInterval&,AcGePoint2d&,AcGePoint2d&) const;
    void getLocalClosestPoints(const AcGeCurve2d&,AcGePointOnCurve2d&,AcGePointOnCurve2d&,const AcGeInterval* = NULL,const AcGeInterval* = NULL,const AcGeTol& = AcGeContext::gTol) const;
    void getLocalClosestPoints(const AcGePoint2d&,AcGePointOnCurve2d&,const AcGeInterval* = NULL,const AcGeTol& = AcGeContext::gTol) const;
    void getSamplePoints(double,double,double,AcGePoint2dArray&,AcGeDoubleArray&) const;
    void getSamplePoints(int,AcGePoint2dArray&) const;
    void getSplitCurves(double,AcGeCurve2d*&,AcGeCurve2d*&) const;
    void getTrimmedOffset(double,AcGeVoidPointerArray&,AcGe::OffsetCrvExtType = AcGe::kFillet,const AcGeTol& = AcGeContext::gTol) const;

    AcGeCurve2d& operator=(const AcGeCurve2d&);
};
