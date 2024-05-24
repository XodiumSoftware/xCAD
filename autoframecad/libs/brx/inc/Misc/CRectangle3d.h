// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGePoint3d.h"

/** _ */
class BRX_IMPORTEXPORT CRectangle3d
{
public:
    AcGePoint3d lowLeft;
    AcGePoint3d lowRight;
    AcGePoint3d upLeft;
    AcGePoint3d upRight;
};