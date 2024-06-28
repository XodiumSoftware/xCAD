// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeLine3d.h"
#include "AcGe/AcGePlane.h"

/** _ */
class BRX_IMPORTEXPORT AcGeLineSeg3d: public AcGeLinearEnt3d
{
public:
    AcGeLineSeg3d();
    AcGeLineSeg3d(const AcGePoint3d&,const AcGePoint3d&);
    AcGeLineSeg3d(const AcGePoint3d&,const AcGeVector3d&);
    AcGeLineSeg3d(const AcGeLineSeg3d&);

    AcGeLineSeg3d& set(const AcGeCurve3d&,const AcGeCurve3d&,double&,double&,Adesk::Boolean&);
    AcGeLineSeg3d& set(const AcGeCurve3d&,const AcGePoint3d&,double&,Adesk::Boolean&);
    AcGeLineSeg3d& set(const AcGePoint3d&,const AcGePoint3d&);
    AcGeLineSeg3d& set(const AcGePoint3d&,const AcGeVector3d&);
    AcGePoint3d baryComb(double) const;
    AcGePoint3d endPoint() const;
    AcGePoint3d midPoint() const;
    AcGePoint3d startPoint() const;
    double length() const;
    double length(double,double,double = AcGeContext::gTol.equalPoint()) const;
    void getBisector(AcGePlane&) const;

    AcGeLineSeg3d& operator=(const AcGeLineSeg3d&);
};
