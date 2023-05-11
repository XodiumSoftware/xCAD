// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSplineEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeNurbCurve2d: public AcGeSplineEnt2d
{
public:
    AcGeNurbCurve2d();
    AcGeNurbCurve2d(const AcGeEllipArc2d&);
    AcGeNurbCurve2d(const AcGeLineSeg2d&);
    AcGeNurbCurve2d(const AcGePoint2dArray&,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve2d(const AcGePoint2dArray&,const AcGeVector2d&,const AcGeVector2d&,Adesk::Boolean = Adesk::kTrue,Adesk::Boolean = Adesk::kTrue,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve2d(const AcGePoint2dArray&,const AcGeVector2dArray&,const AcGeTol& = AcGeContext::gTol,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve2d(int degree,const AcGePolyline2d&,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve2d(int,const AcGeKnotVector&,const AcGePoint2dArray&,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve2d(int,const AcGeKnotVector&,const AcGePoint2dArray&,const AcGeDoubleArray&,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve2d(const AcGeNurbCurve2d&);
    AcGeNurbCurve2d(const AcGePoint2dArray&,const AcGeVector2d&,const AcGeVector2d&,Adesk::Boolean,Adesk::Boolean,AcGe::KnotParameterization,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve2d(const AcGeCurve2d&, double = AcGeContext::gTol.equalPoint());

    AcGeNurbCurve2d& addKnot(double);
    AcGeNurbCurve2d& elevateDegree(int);
    AcGeNurbCurve2d& hardTrimByParams(double,double);
    AcGeNurbCurve2d& insertKnot(double);
    AcGeNurbCurve2d& joinWith(const AcGeNurbCurve2d&);
    AcGeNurbCurve2d& makeClosed();
    AcGeNurbCurve2d& makeNonPeriodic();
    AcGeNurbCurve2d& makeOpen();
    AcGeNurbCurve2d& makePeriodic();
    AcGeNurbCurve2d& makeRational(double = 1.0);
    AcGeNurbCurve2d& setEvalMode(Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve2d& setFitData(const AcGeKnotVector&,const AcGePoint2dArray&,const AcGeVector2d&,const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol,Adesk::Boolean = Adesk::kFalse);
    AcGeNurbCurve2d& setFitData(const AcGePoint2dArray&,const AcGeVector2d&,const AcGeVector2d&,const AcGeTol& = AcGeContext::gTol);
    AcGeNurbCurve2d& setFitData(int,const AcGePoint2dArray&,const AcGeTol& = AcGeContext::gTol);
    AcGeSplineEnt2d& setWeightAt(int,double);

    Adesk::Boolean buildFitData();
    Adesk::Boolean buildFitData(AcGe::KnotParameterization);
    Adesk::Boolean setFitKnotParameterization(AcGe::KnotParameterization);
    AcGeNurbCurve2d& setFitData(const AcGePoint2dArray&,const AcGeVector2d&,const AcGeVector2d&,AcGe::KnotParameterization,const AcGeTol& = AcGeContext::gTol);

    Adesk::Boolean addFitPointAt(int,const AcGePoint2d&);
    Adesk::Boolean deleteFitPointAt(int);
    Adesk::Boolean evalMode() const;
    Adesk::Boolean getFitData(AcGePoint2dArray&,AcGeTol&,Adesk::Boolean&,AcGeVector2d&,AcGeVector2d&) const;
    Adesk::Boolean getFitData(AcGePoint2dArray&,AcGeTol&,Adesk::Boolean&,AcGeVector2d&, AcGeVector2d&,AcGe::KnotParameterization&) const;
    Adesk::Boolean getFitKnotParameterization(AcGe::KnotParameterization&) const;

    Adesk::Boolean getFitPointAt(int,AcGePoint2d&) const;
    Adesk::Boolean getFitTangents(AcGeVector2d&,AcGeVector2d&) const;
    Adesk::Boolean getFitTolerance(AcGeTol&) const;
    Adesk::Boolean getParamsOfC1Discontinuity(AcGeDoubleArray&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean getParamsOfG1Discontinuity(AcGeDoubleArray&,const AcGeTol& = AcGeContext::gTol) const;
    Adesk::Boolean purgeFitData();
    Adesk::Boolean setFitPointAt(int,const AcGePoint2d&);
    Adesk::Boolean setFitTangents(const AcGeVector2d&,const AcGeVector2d&);
    Adesk::Boolean setFitTolerance(const AcGeTol& = AcGeContext::gTol);
    double weightAt(int) const;
    int numFitPoints() const;
    int numWeights() const;
    void getDefinitionData(int&,Adesk::Boolean&,Adesk::Boolean&,AcGeKnotVector&,AcGePoint2dArray&,AcGeDoubleArray&) const;

    AcGeNurbCurve2d& operator=(const AcGeNurbCurve2d&);
};