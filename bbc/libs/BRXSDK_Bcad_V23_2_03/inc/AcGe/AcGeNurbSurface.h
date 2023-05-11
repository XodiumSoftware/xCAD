// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeNurbSurface: public AcGeSurface
{
public:
    AcGeNurbSurface();
    AcGeNurbSurface(const AcGeNurbSurface&);
    AcGeNurbSurface(int,int,int,int,int,int,const AcGePoint3d[],const double[],const AcGeKnotVector&,const AcGeKnotVector&,const AcGeTol& = AcGeContext::gTol);

    AcGeNurbSurface& set(int,int,int,int,int,int,const AcGePoint3d[],const double[],const AcGeKnotVector&,const AcGeKnotVector&,const AcGeTol& = AcGeContext::gTol);
    Adesk::Boolean getWeights(AcGeDoubleArray&) const;
    Adesk::Boolean isPeriodicInU(double&) const;
    Adesk::Boolean isPeriodicInV(double&) const;
    Adesk::Boolean isRationalInU() const;
    Adesk::Boolean isRationalInV() const;
    int degreeInU() const;
    int degreeInV() const;
    int numControlPointsInU() const;
    int numControlPointsInV() const;
    int numKnotsInU() const;
    int numKnotsInV() const;
    int singularityInU() const;
    int singularityInV() const;
    void getControlPoints(AcGePoint3dArray&) const;
    void getDefinition(int&,int&,int&,int&,int&,int&,AcGePoint3dArray&,AcGeDoubleArray&,AcGeKnotVector&,AcGeKnotVector&) const;
    void getUKnots(AcGeKnotVector&) const;
    void getVKnots(AcGeKnotVector&) const;

    AcGeNurbSurface& operator=(const AcGeNurbSurface&);
};