// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbShape: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbShape);

    AcDbShape();
    AcDbShape(const AcGePoint3d&,double,double = 0.0,double = 0.0);
    ~AcDbShape();

    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Adesk::Boolean isPlanar() const;

    Acad::ErrorStatus setName(const ACHAR*);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setOblique(double);
    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    Acad::ErrorStatus setRotation(double);
    Acad::ErrorStatus setShapeIndex(AcDbObjectId);
    Acad::ErrorStatus setShapeNumber(Adesk::Int16);
    Acad::ErrorStatus setSize(double);
    Acad::ErrorStatus setStyleId(AcDbObjectId);
    Acad::ErrorStatus setThickness(double);
    Acad::ErrorStatus setWidthFactor(double);
    AcDbObjectId shapeIndex() const;
    AcDbObjectId styleId() const;
    AcGePoint3d position() const;
    AcGeVector3d normal() const;
    ACHAR* name() const;
    Adesk::Int16 shapeNumber() const;
    double oblique() const;
    double rotation() const;
    double size() const;
    double thickness() const;
    double widthFactor() const;
};
