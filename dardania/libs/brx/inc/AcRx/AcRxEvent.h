// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxEvent: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxEvent);

    virtual void addReactor(AcRxEventReactor*) = 0;
    virtual void removeReactor(AcRxEventReactor*) = 0;
};

#define ACRX_EVENT_OBJ _T("AcRxEvent")
#define acrxEvent AcRxEvent::cast(acrxSysRegistry()->at(ACRX_EVENT_OBJ))
