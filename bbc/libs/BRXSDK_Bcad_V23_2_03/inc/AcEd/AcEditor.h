// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxEvent.h"

/** _ */
class BRX_IMPORTEXPORT AcEditor: public AcRxEvent
{
public:
    ACRX_DECLARE_MEMBERS(AcEditor);

    virtual void addReactor(AcRxEventReactor*) = 0;
    virtual void removeReactor(AcRxEventReactor*) = 0;
};