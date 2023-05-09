// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeLinearEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeRay3d: public AcGeLinearEnt3d
{
public:
    AcGeRay3d();
    AcGeRay3d(const AcGeRay3d&);
    AcGeRay3d(const AcGePoint3d&,const AcGePoint3d&);
    AcGeRay3d(const AcGePoint3d&,const AcGeVector3d&);

    AcGeRay3d& set(const AcGePoint3d&,const AcGePoint3d&);
    AcGeRay3d& set(const AcGePoint3d&,const AcGeVector3d&);

    AcGeRay3d& operator=(const AcGeRay3d&);
};
