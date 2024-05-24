// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeCylinder: public AcGeSurface
{
public:
    AcGeCylinder();
    AcGeCylinder(const AcGeCylinder&);
    AcGeCylinder(double,const AcGePoint3d&,const AcGeVector3d&);
    AcGeCylinder(double,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeInterval&,double,double);

    AcGeCylinder& set(double,const AcGePoint3d&,const AcGeVector3d&);
    AcGeCylinder& set(double,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,const AcGeInterval&,double,double);
    AcGeCylinder& setAngles(double,double);
    AcGeCylinder& setHeight(const AcGeInterval&);
    AcGeCylinder& setRadius(double);
    AcGePoint3d origin() const;
    AcGeVector3d axisOfSymmetry() const;
    AcGeVector3d refAxis() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isClosed(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOuterNormal() const;
    double heightAt(double) const;
    double radius() const;
    void getAngles(double&,double&) const;
    void getHeight(AcGeInterval&) const;

    AcGeCylinder& operator=(const AcGeCylinder&);
};