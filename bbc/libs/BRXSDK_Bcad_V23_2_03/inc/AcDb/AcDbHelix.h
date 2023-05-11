// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSpline.h"

/** _ */
class BRX_EXPORT AcDbHelix: public AcDbSpline
{
public:
    enum ConstrainType
    {
        kTurnHeight = 0,
        kTurns,
        kHeight
    };

    ACDB_DECLARE_MEMBERS(AcDbHelix);

    AcDbHelix();
    virtual ~AcDbHelix();

    virtual Acad::ErrorStatus setAxisPoint(const AcGePoint3d&,const bool = true);
    virtual Acad::ErrorStatus setAxisVector(const AcGeVector3d&);
    virtual Acad::ErrorStatus setBaseRadius(double);
    virtual Acad::ErrorStatus setConstrain(ConstrainType);
    virtual Acad::ErrorStatus setHeight(double);
    virtual Acad::ErrorStatus setStartPoint(const AcGePoint3d&);
    virtual Acad::ErrorStatus setTopRadius(double);
    virtual Acad::ErrorStatus setTurnHeight(double);
    virtual Acad::ErrorStatus setTurns(double);
    virtual Acad::ErrorStatus setTwist(Adesk::Boolean);
    virtual AcGePoint3d axisPoint() const;
    virtual AcGePoint3d startPoint() const;
    virtual AcGeVector3d axisVector() const;
    virtual Adesk::Boolean twist() const;
    virtual ConstrainType constrain() const;
    virtual double baseRadius() const;
    virtual double height() const;
    virtual double topRadius() const;
    virtual double totalLength() const;
    virtual double turnHeight() const;
    virtual double turns() const;
    virtual double turnSlope() const;
    virtual Acad::ErrorStatus reverseCurve();

    Acad::ErrorStatus createHelix();

protected:
    virtual void subGripStatus(const AcDb::GripStat);
};
