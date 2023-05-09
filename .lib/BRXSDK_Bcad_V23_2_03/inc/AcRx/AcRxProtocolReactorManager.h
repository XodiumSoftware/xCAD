// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxProtocolReactorManager : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorManager);

    virtual AcRxProtocolReactorList* createReactorList(AcRxClass*) = 0;
    virtual AcRxProtocolReactorListIterator* newIterator() const = 0;
};
