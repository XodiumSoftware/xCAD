// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePointEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePosition3d: public AcGePointEnt3d
{
public:
    AcGePosition3d();
    AcGePosition3d(const AcGePosition3d&);
    AcGePosition3d(double,double,double);
    AcGePosition3d(const AcGePoint3d&);

    AcGePosition3d& set(const AcGePoint3d&);
    AcGePosition3d& set(double,double,double);

    AcGePosition3d& operator=(const AcGePosition3d&);
};