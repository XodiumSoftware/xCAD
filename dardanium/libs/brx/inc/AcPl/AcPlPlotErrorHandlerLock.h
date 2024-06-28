// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlObject.h"

class AcPlPlotErrorHandler;

/** _ */
class AcPlPlotErrorHandlerLock: public AcPlObject
{
public:
    enum LockStatus
    {
        kLocked = 0,
        kUnLocked
    };

    ACRX_DECLARE_MEMBERS(AcPlPlotErrorHandlerLock);

    AcPlPlotErrorHandlerLock();
    AcPlPlotErrorHandlerLock(AcPlPlotErrorHandler*,const ACHAR*);

    bool lock(AcPlPlotErrorHandler*,const ACHAR*);
    bool unLock(AcPlPlotErrorHandler*);
    const ACHAR* appName() const;
    LockStatus status() const;
    void getErrorHandler(AcPlPlotErrorHandler*&) const;
};
