// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeInterval.h"
#include "AcGe/AcGePointOnCurve3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCurve3d: public AcGeEntity3d
{
protected:
    AcGeCurve3d();
    AcGeCurve3d(const AcGeCurve3d&);

public:
    AcGeBoundBlock3d boundBlock() const;
    AcGeBoundBlock3d boundBlock(const AcGeInterval&) const;
    AcGeBoundBlock3d orthoBoundBlock() const;
    AcGeBoundBlock3d orthoBoundBlock(const AcGeInterval&) const;
    AcGeCurve3d& reverseParam();
    AcGeCurve3d& setInterval();
    AcGeEntity3d* orthoProject(const AcGePlane&,const AcGeTol& = AcGeContext::gTol) const;
    AcGeEntity3d* project(const AcGePlane&,const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d closestPointTo(const AcGeCurve3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d closestPointTo(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d evalPoint(double) const;
    AcGePoint3d evalPoint(double,int,AcGeVector3dArray&) const;
    AcGePoint3d projClosestPointTo(const AcGeCurve3d&,const AcGeVector3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    AcGePoint3d projClosestPointTo(const AcGePoint3d&,const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean area(double,double,double&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean explode(AcGeVoidPointerArray&,AcGeIntArray&,const AcGeInterval* = NULL) const;
    Adesk::Boolean getNormalPoint(const AcGePoint3d&,AcGePointOnCurve3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean hasEndPoint(AcGePoint3d&) const;
    Adesk::Boolean hasStartPoint(AcGePoint3d&) const;
    Adesk::Boolean isClosed(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isCoplanarWith(const AcGeCurve3d&,AcGePlane&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isDegenerate(AcGe::EntityId&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isDegenerate(AcGeEntity3d*&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isLinear(AcGeLine3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(const AcGePoint3d&,double&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOn(double,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isPeriodic(double&) const;
    Adesk::Boolean isPlanar(AcGePlane&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean setInterval(const AcGeInterval&);
    double distanceTo(const AcGeCurve3d&,const AcGeTol& = AcGeContext::gTol) const;
    double distanceTo(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    double length(double,double,double = AcGeContext::gTol.equalPoint()) const;
    double paramAtLength(double,double,Adesk::Boolean = Adesk::kTrue,double = AcGeContext::gTol.equalPoint()) const;
    double paramOf(const AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getClosestPointTo(const AcGeCurve3d&,AcGePointOnCurve3d&,AcGePointOnCurve3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getClosestPointTo(const AcGePoint3d&,AcGePointOnCurve3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getInterval(AcGeInterval&) const;
    void getInterval(AcGeInterval&,AcGePoint3d&,AcGePoint3d&) const;
    void getLocalClosestPoints(const AcGeCurve3d&,AcGePointOnCurve3d&,AcGePointOnCurve3d&,const AcGeInterval* = NULL,const AcGeInterval* = NULL,const AcGeTol& = AcGeContext::gTol) const;
    void getLocalClosestPoints(const AcGePoint3d&,AcGePointOnCurve3d&,const AcGeInterval* = NULL,const AcGeTol& = AcGeContext::gTol) const;
    void getProjClosestPointTo(const AcGeCurve3d&,const AcGeVector3d&,AcGePointOnCurve3d&,AcGePointOnCurve3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getProjClosestPointTo(const AcGePoint3d&,const AcGeVector3d&,AcGePointOnCurve3d&,const AcGeTol& = AcGeContext::gTol) const;
    void getSamplePoints(double,double,double,AcGePoint3dArray&,AcGeDoubleArray&) const;
    void getSamplePoints(int,AcGePoint3dArray&) const;
    void getSplitCurves(double,AcGeCurve3d*&,AcGeCurve3d*&) const;
    void getTrimmedOffset(double,const AcGeVector3d&,AcGeVoidPointerArray&,AcGe::OffsetCrvExtType = AcGe::kFillet,const AcGeTol& = AcGeContext::gTol) const;

    AcGeCurve3d& operator=(const AcGeCurve3d&);
};
