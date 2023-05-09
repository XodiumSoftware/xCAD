// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeLinearEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeLine3d: public AcGeLinearEnt3d
{
public:
    static const AcGeLine3d kXAxis;
    static const AcGeLine3d kYAxis;
    static const AcGeLine3d kZAxis;

    AcGeLine3d();
    AcGeLine3d(const AcGePoint3d&,const AcGePoint3d&);
    AcGeLine3d(const AcGePoint3d&,const AcGeVector3d&);
    AcGeLine3d(const AcGeLine3d&);

    AcGeLine3d& set(const AcGePoint3d&,const AcGePoint3d&);
    AcGeLine3d& set(const AcGePoint3d&,const AcGeVector3d&);

    AcGeLine3d& operator=(const AcGeLine3d&);
};
