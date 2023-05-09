// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCone: public AcGeSurface
{
public:
    AcGeCone();
    AcGeCone(const AcGeCone&);
    AcGeCone(double,double,const AcGePoint3d&,double,const AcGeVector3d&);
    AcGeCone(double,double,const AcGePoint3d&,double,const AcGeVector3d&,const AcGeVector3d&,const AcGeInterval&,double,double);

    AcGeCone& set(double,double,const AcGePoint3d&,double,const AcGeVector3d&);
    AcGeCone& set(double,double,const AcGePoint3d&,double,const AcGeVector3d&,const AcGeVector3d&,const AcGeInterval&,double,double);
    AcGeCone& setAngles(double,double);
    AcGeCone& setBaseRadius(double);
    AcGeCone& setHeight(const AcGeInterval&);
    AcGePoint3d apex() const;
    AcGePoint3d baseCenter() const;
    AcGeVector3d axisOfSymmetry() const;
    AcGeVector3d refAxis() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isClosed(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOuterNormal() const;
    double baseRadius() const;
    double halfAngle() const;
    double heightAt(double) const;
    void getAngles(double&,double&) const;
    void getHalfAngle(double&,double&) const;
    void getHeight(AcGeInterval&) const;

    AcGeCone& operator=(const AcGeCone&);
};