// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeEntity2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePointEnt2d: public AcGeEntity2d
{
protected:
    AcGePointEnt2d();
    AcGePointEnt2d(const AcGePointEnt2d&);

public:
    AcGePoint2d point2d() const;

    AcGePointEnt2d& operator=(const AcGePointEnt2d&);
    operator AcGePoint2d() const;
};
