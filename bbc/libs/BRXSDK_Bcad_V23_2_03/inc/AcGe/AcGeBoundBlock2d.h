// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeEntity2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeBoundBlock2d: public AcGeEntity2d
{
public:
    AcGeBoundBlock2d();
    AcGeBoundBlock2d(const AcGeBoundBlock2d&);
    AcGeBoundBlock2d(const AcGePoint2d&,const AcGePoint2d&);
    AcGeBoundBlock2d(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&);

    AcGeBoundBlock2d& extend(const AcGePoint2d&);
    AcGeBoundBlock2d& set(const AcGePoint2d&,const AcGePoint2d&);
    AcGeBoundBlock2d& set(const AcGePoint2d&,const AcGeVector2d&,const AcGeVector2d&);
    AcGeBoundBlock2d& setToBox(Adesk::Boolean);
    AcGeBoundBlock2d& swell(double);
    Adesk::Boolean contains(const AcGePoint2d&) const;
    Adesk::Boolean isBox() const;
    Adesk::Boolean isDisjoint(const AcGeBoundBlock2d&) const;
    void get(AcGePoint2d&,AcGeVector2d&,AcGeVector2d&) const;
    void getMinMaxPoints(AcGePoint2d&,AcGePoint2d&) const;

    AcGeBoundBlock2d& operator=(const AcGeBoundBlock2d&);
};