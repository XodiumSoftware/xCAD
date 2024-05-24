// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxIterator.h"

/** _ */
class AcRxDictionaryIterator: public AcRxIterator
{
public:
    ACRX_DECLARE_MEMBERS(AcRxDictionaryIterator);

    virtual AcRxObject* object() const = 0;
    virtual Adesk::UInt32 id() const = 0;
    virtual const ACHAR* key() const = 0;
};
