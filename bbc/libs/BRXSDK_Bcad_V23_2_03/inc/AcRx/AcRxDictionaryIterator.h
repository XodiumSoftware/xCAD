// Copyright (C) Menhirs NV. All rights reserved.
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
