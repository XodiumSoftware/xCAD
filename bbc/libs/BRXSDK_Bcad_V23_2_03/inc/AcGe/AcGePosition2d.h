// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePointEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePosition2d: public AcGePointEnt2d
{
public:
    AcGePosition2d();
    AcGePosition2d(const AcGePosition2d&);
    AcGePosition2d(double,double);
    AcGePosition2d(const AcGePoint2d&);

    AcGePosition2d& set(const AcGePoint2d&);
    AcGePosition2d& set(double,double);

    AcGePosition2d& operator=(const AcGePosition2d&);
};