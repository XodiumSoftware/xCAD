// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrElement.h"

class AcGeVector3d;

class AcBrElement2d: public AcBrElement
{
public:
    ACRX_DECLARE_MEMBERS(AcBrElement2d);

    AcBrElement2d();
    AcBrElement2d(const AcBrElement2d&);
    ~AcBrElement2d();    

    AcBr::ErrorStatus getNormal(AcGeVector3d&) const;

    AcBrElement2d& operator=(const AcBrElement2d&);
};
