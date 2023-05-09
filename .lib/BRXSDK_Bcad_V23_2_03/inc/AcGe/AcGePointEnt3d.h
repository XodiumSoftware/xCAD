// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeEntity3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePointEnt3d: public AcGeEntity3d
{
protected:
    AcGePointEnt3d();
    AcGePointEnt3d(const AcGePointEnt3d&);
public:

    AcGePoint3d point3d() const;

    AcGePointEnt3d& operator=(const AcGePointEnt3d&);
    operator AcGePoint3d() const;
};
