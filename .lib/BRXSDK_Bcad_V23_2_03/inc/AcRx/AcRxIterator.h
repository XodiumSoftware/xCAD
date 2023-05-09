// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxIterator);

    virtual AcRxObject* object() const = 0;
    virtual Adesk::Boolean done() const = 0;
    virtual Adesk::Boolean next() = 0;
};
