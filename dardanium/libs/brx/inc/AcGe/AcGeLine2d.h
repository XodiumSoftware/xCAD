// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeLinearEnt2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeLine2d: public AcGeLinearEnt2d
{
public:
    static const AcGeLine2d kXAxis;
    static const AcGeLine2d kYAxis;

    AcGeLine2d();
    AcGeLine2d(const AcGePoint2d&,const AcGePoint2d&);
    AcGeLine2d(const AcGePoint2d&,const AcGeVector2d&);
    AcGeLine2d(const AcGeLine2d&);

    AcGeLine2d& set(const AcGePoint2d&,const AcGePoint2d&);
    AcGeLine2d& set(const AcGePoint2d&,const AcGeVector2d&);

    AcGeLine2d& operator=(const AcGeLine2d&);
};
