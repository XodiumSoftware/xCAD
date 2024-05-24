// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
