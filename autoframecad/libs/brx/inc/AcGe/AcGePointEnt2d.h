// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
