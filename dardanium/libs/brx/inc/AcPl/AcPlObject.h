// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class AcPlObject: public AcRxObject, public AcHeapOperators
{
public:
    ACRX_DECLARE_MEMBERS(AcPlObject);

protected:
    AcPlObject();
public:
    virtual ~AcPlObject();
};
