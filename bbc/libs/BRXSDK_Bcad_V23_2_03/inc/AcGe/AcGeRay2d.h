// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeLinearEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeRay2d: public AcGeLinearEnt2d
{
public:
    AcGeRay2d();
    AcGeRay2d(const AcGeRay2d&);
    AcGeRay2d(const AcGePoint2d&,const AcGePoint2d&);
    AcGeRay2d(const AcGePoint2d&,const AcGeVector2d&);

    AcGeRay2d& set(const AcGePoint2d&,const AcGePoint2d&);
    AcGeRay2d& set(const AcGePoint2d&,const AcGeVector2d&);

    AcGeRay2d& operator=(const AcGeRay2d&);
};
