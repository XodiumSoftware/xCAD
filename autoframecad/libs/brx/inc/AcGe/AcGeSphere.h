// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeSphere: public AcGeSurface
{
public:
    AcGeSphere();
    AcGeSphere(const AcGeSphere&);
    AcGeSphere(double,const AcGePoint3d&);
    AcGeSphere(double,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double,double);

    AcGePoint3d center() const;
    AcGePoint3d northPole() const;
    AcGePoint3d southPole() const;
    AcGeSphere& set(double,const AcGePoint3d&);
    AcGeSphere& set(double,const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double,double,double);
    AcGeSphere& setAnglesInU(double,double);
    AcGeSphere& setAnglesInV(double,double);
    AcGeSphere& setRadius(double);
    AcGeVector3d northAxis() const;
    AcGeVector3d refAxis() const;
    Adesk::Boolean intersectWith(const AcGeLinearEnt3d&,int&,AcGePoint3d&,AcGePoint3d&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isClosed(const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean isOuterNormal() const;
    double radius() const;
    void getAnglesInU(double&,double&) const;
    void getAnglesInV(double&,double&) const;

    AcGeSphere& operator=(const AcGeSphere&);
};