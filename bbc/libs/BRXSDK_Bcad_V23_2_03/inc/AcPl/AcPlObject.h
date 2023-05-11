// Copyright (C) Menhirs NV. All rights reserved.
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
