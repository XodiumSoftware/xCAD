// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmComplexColor.h"
#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbDatabaseReactor.h"
#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbEntityReactor.h"
#include "AcDb/AcDbExtents.h"
#include "AcDb/AcDbExtents2d.h"
#include "AcDb/AcDbObjectIterator.h"
#include "AcGe/AcGePlane.h"

/** _ */
class BRX_IMPORTEXPORT AcDbCurve: public AcDbEntity
{
protected:
    AcDbCurve();

public:
    ACDB_DECLARE_MEMBERS(AcDbCurve);

    static Acad::ErrorStatus createFromAcGeCurve(const AcGeCurve3d&, AcDbCurve*&,
                                                 AcGeVector3d* = NULL, const AcGeTol& = AcGeContext::gTol);

    virtual ~AcDbCurve();

    virtual Acad::ErrorStatus extend(Adesk::Boolean,const AcGePoint3d&);
    virtual Acad::ErrorStatus extend(double);
    virtual Acad::ErrorStatus getArea(double&) const;
    virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,AcGePoint3d&,Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,const AcGeVector3d&,AcGePoint3d&,Adesk::Boolean = Adesk::kFalse) const;
    virtual Acad::ErrorStatus getDistAtParam(double,double&) const;
    virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d&,double&) const;
    virtual Acad::ErrorStatus getEndParam(double&) const;
    virtual Acad::ErrorStatus getEndPoint(AcGePoint3d&) const;
    virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getFirstDeriv(double,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getOffsetCurves(double,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d&,double,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane&,AcDbCurve*&) const;
    virtual Acad::ErrorStatus getParamAtDist(double,double&) const;
    virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d&,double&) const;
    virtual Acad::ErrorStatus getPointAtDist(double,AcGePoint3d&) const;
    virtual Acad::ErrorStatus getPointAtParam(double,AcGePoint3d&) const;
    virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane&,const AcGeVector3d&,AcDbCurve*&) const;
    virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d&,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getSecondDeriv(double,AcGeVector3d&) const;
    virtual Acad::ErrorStatus getSpline(AcDbSpline*&) const;
    virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray&,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray&,AcDbVoidPtrArray&) const;
    virtual Acad::ErrorStatus getStartParam(double&) const;
    virtual Acad::ErrorStatus getStartPoint(AcGePoint3d&) const;
    virtual Adesk::Boolean isClosed() const;
    virtual Adesk::Boolean isPeriodic() const;
    virtual Acad::ErrorStatus reverseCurve();
    virtual Acad::ErrorStatus getAcGeCurve(AcGeCurve3d*&, const AcGeTol& = AcGeContext::gTol) const;
    virtual Acad::ErrorStatus setFromAcGeCurve(const AcGeCurve3d&, AcGeVector3d* = NULL,
                                               const AcGeTol& = AcGeContext::gTol);
};

#define DBCURVE_METHODS \
virtual Acad::ErrorStatus extend(Adesk::Boolean,const AcGePoint3d&); \
virtual Acad::ErrorStatus extend(double); \
virtual Acad::ErrorStatus getArea(double&) const; \
virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,AcGePoint3d&,Adesk::Boolean = Adesk::kFalse) const; \
virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d&,const AcGeVector3d&,AcGePoint3d&,Adesk::Boolean = Adesk::kFalse) const; \
virtual Acad::ErrorStatus getDistAtParam(double,double&) const; \
virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d&,double&) const; \
virtual Acad::ErrorStatus getEndParam(double&) const; \
virtual Acad::ErrorStatus getEndPoint(AcGePoint3d&) const; \
virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d&,AcGeVector3d&) const; \
virtual Acad::ErrorStatus getFirstDeriv(double,AcGeVector3d&) const; \
virtual Acad::ErrorStatus getOffsetCurves(double,AcDbVoidPtrArray&) const; \
virtual Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane&,AcDbCurve*&) const; \
virtual Acad::ErrorStatus getParamAtDist(double,double&) const; \
virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d&,double&) const; \
virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const; \
virtual Acad::ErrorStatus getPointAtDist(double,AcGePoint3d&) const; \
virtual Acad::ErrorStatus getPointAtParam(double,AcGePoint3d&) const; \
virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane&,const AcGeVector3d&,AcDbCurve*&) const; \
virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d&,AcGeVector3d&) const; \
virtual Acad::ErrorStatus getSecondDeriv(double,AcGeVector3d&) const; \
virtual Acad::ErrorStatus getSpline(AcDbSpline*&) const; \
virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray&,AcDbVoidPtrArray&) const; \
virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray&,AcDbVoidPtrArray&) const; \
virtual Acad::ErrorStatus getStartParam(double&) const; \
virtual Acad::ErrorStatus getStartPoint(AcGePoint3d&) const; \
virtual Adesk::Boolean isClosed() const; \
virtual Adesk::Boolean isPeriodic() const; \
virtual Adesk::Boolean isPlanar() const; \
virtual Acad::ErrorStatus reverseCurve(); \
virtual Acad::ErrorStatus getAcGeCurve(AcGeCurve3d*&, const AcGeTol& = AcGeContext::gTol) const; \
virtual Acad::ErrorStatus setFromAcGeCurve(const AcGeCurve3d&, AcGeVector3d* = NULL, \
                                           const AcGeTol& = AcGeContext::gTol);
