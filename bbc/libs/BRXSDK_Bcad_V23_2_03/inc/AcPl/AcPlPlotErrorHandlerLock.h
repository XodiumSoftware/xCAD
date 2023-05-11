// Copyright (C) Menhirs NV. All rights reserved.
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
