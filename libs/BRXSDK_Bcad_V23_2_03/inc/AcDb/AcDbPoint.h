// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbPoint: public AcDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPoint);

    AcDbPoint();
    AcDbPoint(const AcGePoint3d&);
    ~AcDbPoint();

    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Adesk::Boolean isPlanar() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;

    Acad::ErrorStatus setEcsRotation(double);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setPosition(const AcGePoint3d&);
    Acad::ErrorStatus setThickness(double);
    AcGePoint3d position() const;
    AcGeVector3d normal() const;
    double ecsRotation() const;
    double thickness() const;

protected:
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
};
