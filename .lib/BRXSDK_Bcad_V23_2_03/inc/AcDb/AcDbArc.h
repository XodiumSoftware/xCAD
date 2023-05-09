// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbArc: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbArc);

    AcDbArc();
    AcDbArc(const AcGePoint3d&,double,double,double);
    AcDbArc(const AcGePoint3d&,const AcGeVector3d&,double,double,double);
    ~AcDbArc();

    DBCURVE_METHODS
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    Acad::ErrorStatus setCenter(const AcGePoint3d&);
    Acad::ErrorStatus setEndAngle(double);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setRadius(double);
    Acad::ErrorStatus setStartAngle(double);
    Acad::ErrorStatus setThickness(double);
    AcGePoint3d center() const;
    AcGeVector3d normal() const;
    double endAngle() const;
    double radius() const;
    double startAngle() const;
    double thickness() const;
    double length() const;
    double totalAngle() const;

protected:
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subGripStatus(const AcDb::GripStat);
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
};
