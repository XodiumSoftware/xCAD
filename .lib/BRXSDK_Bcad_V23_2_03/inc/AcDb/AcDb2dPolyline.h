// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDb2dPolyline: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDb2dPolyline);
    AcDb2dPolyline();
    AcDb2dPolyline (AcDb::Poly2dType,AcGePoint3dArray&,double = 0.0,Adesk::Boolean = Adesk::kFalse,double = 0.0,double = 0.0,AcGeDoubleArray* = NULL);
    ~AcDb2dPolyline();

    DBCURVE_METHODS

    Acad::ErrorStatus appendVertex(AcDb2dVertex*);
    Acad::ErrorStatus appendVertex(AcDbObjectId&,AcDb2dVertex*);
    Acad::ErrorStatus convertToPolyType(AcDb::Poly2dType);
    Acad::ErrorStatus curveFit();
    Acad::ErrorStatus insertVertexAt(AcDbObjectId&,const AcDbObjectId&,AcDb2dVertex*);
    Acad::ErrorStatus insertVertexAt(const AcDb2dVertex*,AcDb2dVertex*);
    Acad::ErrorStatus makeClosed();
    Acad::ErrorStatus makeOpen();
    Acad::ErrorStatus openSequenceEnd(AcDbSequenceEnd*&,AcDb::OpenMode);
    Acad::ErrorStatus openVertex(AcDb2dVertex*&,AcDbObjectId,AcDb::OpenMode,bool = false) const;
    Acad::ErrorStatus setDefaultEndWidth(double);
    Acad::ErrorStatus setDefaultStartWidth(double);
    Acad::ErrorStatus setElevation(double);
    Acad::ErrorStatus setLinetypeGenerationOff();
    Acad::ErrorStatus setLinetypeGenerationOn();
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setPolyType(AcDb::Poly2dType);
    Acad::ErrorStatus setThickness(double);
    Acad::ErrorStatus splineFit();
    Acad::ErrorStatus splineFit(AcDb::Poly2dType,Adesk::Int16);
    Acad::ErrorStatus straighten();
    AcDb::Poly2dType polyType() const;
    AcDbObjectIterator* vertexIterator() const;
    AcGePoint3d vertexPosition(const AcDb2dVertex&) const;
    AcGeVector3d normal() const;
    Adesk::Boolean isLinetypeGenerationOn() const;
    double defaultEndWidth() const;
    double defaultStartWidth() const;
    double elevation() const;
    double thickness() const;
    Acad::ErrorStatus setClosed(Adesk::Boolean);
    Acad::ErrorStatus length(double &) const;
    Acad::ErrorStatus constantWidth(double&) const;
    Acad::ErrorStatus setConstantWidth(double);

protected:
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
