// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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