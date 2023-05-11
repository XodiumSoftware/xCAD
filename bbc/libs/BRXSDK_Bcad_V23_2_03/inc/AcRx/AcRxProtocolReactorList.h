// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class AcRxProtocolReactorList: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorList);

    virtual Acad::ErrorStatus addReactor(AcRxProtocolReactor*) = 0;
    virtual AcRxClass* reactorClass() const = 0;
    virtual AcRxProtocolReactorIterator* newIterator() const = 0;
    virtual void removeReactor(AcRxProtocolReactor*) = 0;
};