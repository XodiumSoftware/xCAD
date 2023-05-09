// Copyright (C) Menhirs NV. All rights reserved.
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