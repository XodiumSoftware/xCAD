// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePolyline3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeAugPolyline3d: public AcGePolyline3d
{
public:
    AcGeAugPolyline3d();
    AcGeAugPolyline3d(const AcGeAugPolyline3d&);
    AcGeAugPolyline3d(const AcGePoint3dArray&,const AcGeVector3dArray&);
    AcGeAugPolyline3d(const AcGeKnotVector&,const AcGePoint3dArray&,const AcGeVector3dArray&);
    AcGeAugPolyline3d(const AcGeCurve3d&,double,double,double);

    AcGeAugPolyline3d& setApproxTol(double);
    AcGeAugPolyline3d& setD2Vector(int,AcGeVector3d);
    AcGeAugPolyline3d& setPoint(int,AcGePoint3d);
    AcGeAugPolyline3d& setVector(int,AcGeVector3d);
    AcGePoint3d getPoint(int) const;
    AcGeVector3d getD2Vector(int) const;
    AcGeVector3d getVector(int) const;
    double approxTol() const;
    void getD1Vectors(AcGeVector3dArray&) const;
    void getD2Vectors(AcGeVector3dArray&) const;
    void getPoints(AcGePoint3dArray&) const;

    AcGeAugPolyline3d& operator=(const AcGeAugPolyline3d&);
};
