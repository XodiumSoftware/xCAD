// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class AcRxProtocolReactorIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorIterator);

    virtual AcRxClass* reactorClass() const = 0;
    virtual AcRxProtocolReactor* object() const = 0;
    virtual bool done() const = 0;
    virtual bool next() = 0;
    virtual void start() = 0;
};