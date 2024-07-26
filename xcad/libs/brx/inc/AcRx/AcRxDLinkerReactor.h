// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
