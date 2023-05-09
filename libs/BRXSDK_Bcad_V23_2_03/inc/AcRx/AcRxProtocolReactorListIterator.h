// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class AcRxProtocolReactorListIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorListIterator);

    virtual AcRxProtocolReactorList* object() const = 0;
    virtual bool done() const = 0;
    virtual bool next() = 0;
    virtual void start() = 0;
};