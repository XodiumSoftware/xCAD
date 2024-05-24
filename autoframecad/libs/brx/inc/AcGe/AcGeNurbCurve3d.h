// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSplineEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeNurbCurve3d: public AcGeSplineEnt3d
{
public:
    AcGeNurbCurve3d();
    AcGeNurbCurve3d(const AcGeEllipArc3d&);
    AcGeNurbCurve3d(const AcGeLineSeg3d&);
    AcGeNurbCurve3d(const AcGePoint3dArray&,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve3d(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve3d(const AcGePoint3dArray&,const AcGeVector3dArray&,const AcGeTol& = AcGeContext::gTol,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve3d(int,const AcGeKnotVector&,const AcGePoint3dArray&,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve3d(int,const AcGeKnotVector&,const AcGePoint3dArray&,const AcGeDoubleArray&,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve3d(int,const AcGePolyline3d&,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve3d(const AcGeNurbCurve3d&);
    AcGeNurbCurve3d(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,Adesk::Boolean,Adesk::Boolean,AcGe::KnotParameterization,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve3d(const AcGeCurve3d&, double = AcGeContext::gTol.equalPoint());

    AcGeNurbCurve3d& addKnot(double);
    AcGeNurbCurve3d& elevateDegree(int);
    AcGeNurbCurve3d& hardTrimByParams(double,double);
    AcGeNurbCurve3d& insertKnot(double);
    AcGeNurbCurve3d& joinWith(const AcGeNurbCurve3d&);
    AcGeNurbCurve3d& makeClosed();
    AcGeNurbCurve3d& makeNonPeriodic();
    AcGeNurbCurve3d& makeOpen();
    AcGeNurbCurve3d& makePeriodic();
    AcGeNurbCurve3d& makeRational(double = 1.0);
    AcGeNurbCurve3d& setEvalMode(Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve3d& setFitData(const AcGeKnotVector&,const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve3d& setFitData(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve3d& setFitData(int,const AcGePoint3dArray&,const AcGeTol& = AcGeContext::gTol);
    AcGeSplineEnt3d& setWeightAt(int,double);

    Adesk::Boolean buildFitData();
    Adesk::Boolean buildFitData(AcGe::KnotParameterization);
    Adesk::Boolean setFitKnotParameterization(AcGe::KnotParameterization);
    AcGeNurbCurve3d& setFitData(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,AcGe::KnotParameterization,const AcGeTol& = AcGeContext::gTol);

    Adesk::Boolean addFitPointAt(int,const AcGePoint3d&);
    Adesk::Boolean deleteFitPointAt(int);
    Adesk::Boolean evalMode() const;
    Adesk::Boolean getFitData(AcGePoint3dArray&,AcGeTol&,Adesk::Boolean&,AcGeVector3d&,AcGeVector3d&) const;
    Adesk::Boolean getFitData(AcGePoint3dArray&,AcGeTol&,Adesk::Boolean&,AcGeVector3d&,AcGeVector3d&,AcGe::KnotParameterization&) const;
    Adesk::Boolean getFitKnotParameterization(AcGe::KnotParameterization&) const;

    Adesk::Boolean getFitPointAt(int,AcGePoint3d&) const;
    Adesk::Boolean getFitTangents(AcGeVector3d&,AcGeVector3d&) const;
    Adesk::Boolean getFitTangents(AcGeVector3d&,AcGeVector3d&,Adesk::Boolean&,Adesk::Boolean&) const;
    Adesk::Boolean getFitTolerance(AcGeTol&) const;
    Adesk::Boolean getParamsOfC1Discontinuity(AcGeDoubleArray&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean getParamsOfG1Discontinuity(AcGeDoubleArray&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean purgeFitData();
    Adesk::Boolean setFitPointAt(int,const AcGePoint3d&);
    Adesk::Boolean setFitTangents(const AcGeVector3d&,const AcGeVector3d&);
    Adesk::Boolean setFitTangents(const AcGeVector3d&,const AcGeVector3d&,Adesk::Boolean,Adesk::Boolean) const;
    Adesk::Boolean setFitTolerance(const AcGeTol& = AcGeContext::gTol);
    double weightAt(int) const;
    int numFitPoints() const;
    int numWeights() const;
    void getDefinitionData(int&,Adesk::Boolean&,Adesk::Boolean&,AcGeKnotVector&,AcGePoint3dArray&,AcGeDoubleArray&) const;

    AcGeNurbCurve3d& operator=(const AcGeNurbCurve3d&);
};