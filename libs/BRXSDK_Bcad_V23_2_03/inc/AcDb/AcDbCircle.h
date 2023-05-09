// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbCircle: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbCircle);

    AcDbCircle();
    AcDbCircle(const AcGePoint3d&,const AcGeVector3d&,double);
    ~AcDbCircle();

    DBCURVE_METHODS
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    Acad::ErrorStatus setCenter(const AcGePoint3d&);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setRadius(double);
    Acad::ErrorStatus setThickness(double);
    AcGePoint3d center() const;
    AcGeVector3d normal() const;
    double radius() const;
    double thickness() const;

protected:
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subGripStatus(const AcDb::GripStat);
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
};
