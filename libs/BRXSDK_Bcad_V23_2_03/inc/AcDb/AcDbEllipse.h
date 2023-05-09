// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbEllipse: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbEllipse);

    AcDbEllipse();
    AcDbEllipse(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double = 0.0,double = (BRX_PI*2.0));
    virtual ~AcDbEllipse();

    DBCURVE_METHODS
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void setCastShadows(bool);
    virtual void setReceiveShadows(bool);

    Acad::ErrorStatus get(AcGePoint3d&,AcGeVector3d&,AcGeVector3d&,double&,double&,double&) const;
    Acad::ErrorStatus set(const AcGePoint3d&,const AcGeVector3d&,const AcGeVector3d&,double,double = 0.0,double = (BRX_PI*2.0));
    Acad::ErrorStatus setCenter(const AcGePoint3d&);
    Acad::ErrorStatus setEndAngle(double);
    Acad::ErrorStatus setEndParam(double);
    Acad::ErrorStatus setRadiusRatio(double);
    Acad::ErrorStatus setStartAngle(double);
    Acad::ErrorStatus setStartParam(double);
    AcGePoint3d center() const;
    AcGeVector3d majorAxis() const;
    AcGeVector3d minorAxis() const;
    AcGeVector3d normal() const;
    Adesk::Boolean isNull() const;
    double angleAtParam(double) const;
    double endAngle() const;
    double paramAtAngle(double) const;
    double radiusRatio() const;
    double startAngle() const;

    double majorRadius() const;
    double minorRadius() const;

    Acad::ErrorStatus setMajorRadius(double);
    Acad::ErrorStatus setMinorRadius(double);

protected:
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual void subGripStatus(const AcDb::GripStat);
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity*,AcDb::Intersect,const AcGePlane&,AcGePoint3dArray&,Adesk::GsMarker = 0,Adesk::GsMarker = 0) const;
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray&,const AcGeVector3d&);
    virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray&,const AcGeVector3d&,const int);
};
