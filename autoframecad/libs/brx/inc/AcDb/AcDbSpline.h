// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
#ifndef BRX_EXPORTS
static const unsigned int kPlineVerticesThrehold = 100000;
#endif

enum SplineType
{
    kFitPoints = 0,
    kControlPoints = 1
};

class BRX_EXPORT AcDbSpline: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSpline);

    AcDbSpline();
    AcDbSpline(const AcGePoint3dArray&,int = 4,double = 0.0);
    AcDbSpline(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,int = 4,double = 0.0);
    AcDbSpline(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double = 0.0,double = (BRX_PI*2.0));
    AcDbSpline(int,Adesk::Boolean,Adesk::Boolean,Adesk::Boolean,const AcGePoint3dArray&,const AcGeDoubleArray&,const AcGeDoubleArray&,double = 0.0,double = 0.0);
    AcDbSpline(const AcGePoint3dArray&,AcGe::KnotParameterization,int = 3,double = 0.0);
    AcDbSpline(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,AcGe::KnotParameterization,int = 3,double = 0.0);
    virtual ~AcDbSpline();

    DBCURVE_METHODS
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void setCastShadows(bool);
    virtual void setReceiveShadows(bool);

    Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    Acad::ErrorStatus elevateDegree(int);
    Acad::ErrorStatus getControlPointAt(int,AcGePoint3d&) const;
    Acad::ErrorStatus getFitData(AcGePoint3dArray&,int&,double&,Adesk::Boolean&,AcGeVector3d&,AcGeVector3d&) const;
    Acad::ErrorStatus getFitData(AcGePoint3dArray&,Adesk::Boolean&,AcGeVector3d&,AcGeVector3d&,AcGe::KnotParameterization&,int&,double&) const;
    Acad::ErrorStatus getFitPointAt(int,AcGePoint3d&) const;
    Acad::ErrorStatus getFitTangents(AcGeVector3d&,AcGeVector3d&) const;
    Acad::ErrorStatus getNurbsData(int&,Adesk::Boolean&,Adesk::Boolean&,Adesk::Boolean&,AcGePoint3dArray&,AcGeDoubleArray&,AcGeDoubleArray&,double&,double&) const;
    Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d&,double,AcDbVoidPtrArray&) const;
    Acad::ErrorStatus insertFitPointAt(int,const AcGePoint3d&);
    Acad::ErrorStatus insertKnot(double);
    Acad::ErrorStatus purgeFitData();
    Acad::ErrorStatus removeFitPointAt(int);
    Acad::ErrorStatus setControlPointAt(int,const AcGePoint3d&);
    Acad::ErrorStatus setFitData(const AcGePoint3dArray&,int,double,const AcGeVector3d&,const AcGeVector3d&);
    Acad::ErrorStatus setFitData(const AcGePoint3dArray&,bool,AcGe::KnotParameterization,int = 3,double = 0.0);
    Acad::ErrorStatus setFitData(const AcGePoint3dArray&,const AcGeVector3d&,const AcGeVector3d&,AcGe::KnotParameterization,int = 3,double = 0.0);
    Acad::ErrorStatus setFitPointAt(int,const AcGePoint3d&);
    Acad::ErrorStatus setFitTangents(const AcGeVector3d&,const AcGeVector3d&);
    Acad::ErrorStatus setFitTol(double);
    Acad::ErrorStatus setNurbsData(int,Adesk::Boolean,Adesk::Boolean,Adesk::Boolean,const AcGePoint3dArray&,const AcGeDoubleArray&,const AcGeDoubleArray&,double = 0.,double =0.);
    Acad::ErrorStatus setWeightAt(int,double);
    Acad::ErrorStatus updateFitData();
    Adesk::Boolean hasFitData() const;
    Adesk::Boolean isNull() const;
    Adesk::Boolean isRational() const;
    double fitTolerance() const;
    double weightAt(int) const;
    int degree() const;
    int numControlPoints() const;
    int numFitPoints() const;

    Acad::ErrorStatus toPolyline(AcDbCurve*&, int = 10, int* = NULL, unsigned int = kPlineVerticesThrehold) const;
    Acad::ErrorStatus toPolyline(AcDbCurve*&, bool, bool, int = 10, int* = NULL, unsigned int = kPlineVerticesThrehold) const;
    Acad::ErrorStatus modifyPositionAndTangent(double , const AcGePoint3d& , const AcGeVector3d* );

    SplineType type() const;
    Acad::ErrorStatus setType(SplineType);
};
