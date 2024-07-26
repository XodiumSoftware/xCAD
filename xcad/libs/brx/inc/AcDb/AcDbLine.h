// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbCurve.h"

/** _ */
class BRX_EXPORT AcDbLine: public AcDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLine);

    AcDbLine();
    AcDbLine(const AcGePoint3d&,const AcGePoint3d&);
    ~AcDbLine();

    DBCURVE_METHODS
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d&,double,AcDbVoidPtrArray&) const;
    Acad::ErrorStatus setEndPoint(const AcGePoint3d&);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setStartPoint(const AcGePoint3d&);
    Acad::ErrorStatus setThickness(double);
    AcGePoint3d endPoint() const;
    AcGePoint3d startPoint() const;
    AcGeVector3d normal() const;
    double thickness() const;

protected:
    virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray&,const double,const int,const AcGeVector3d&,const int) const;
    virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray&,AcDbIntArray&,AcDbIntArray&) const;
    virtual void subGripStatus(const AcDb::GripStat);
    virtual Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d&,AcDbEntity*&) const;
    virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d&);
};
