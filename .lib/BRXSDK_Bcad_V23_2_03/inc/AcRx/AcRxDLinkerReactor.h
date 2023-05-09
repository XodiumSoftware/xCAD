// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxDLinkerReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxDLinkerReactor);

    virtual void rxAppLoadAborted(const ACHAR*);
    virtual void rxAppLoaded(const ACHAR*);
    virtual void rxAppUnloadAborted(const ACHAR*);
    virtual void rxAppUnloaded(const ACHAR*);
    virtual void rxAppWillBeLoaded(const ACHAR*);
    virtual void rxAppWillBeUnloaded(const ACHAR*);
};
