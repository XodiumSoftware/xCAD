// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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