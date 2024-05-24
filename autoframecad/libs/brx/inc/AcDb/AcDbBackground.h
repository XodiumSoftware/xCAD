// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbBackground: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbBackground);

    virtual ~AcDbBackground();

    virtual AcGiDrawable* drawable();
};
