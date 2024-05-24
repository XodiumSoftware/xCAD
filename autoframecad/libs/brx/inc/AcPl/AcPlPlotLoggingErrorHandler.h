// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcPl/AcPlPlotErrorHandler.h"

class AcPlPlotLogger;

/** _ */
class AcPlPlotLoggingErrorHandler: public AcPlPlotErrorHandler
{
public:
    ACRX_DECLARE_MEMBERS(AcPlPlotLoggingErrorHandler);

    AcPlPlotLoggingErrorHandler();
    AcPlPlotLoggingErrorHandler(AcPlPlotLogger*);
    virtual ~AcPlPlotLoggingErrorHandler();

    virtual ErrorResult ariError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual ErrorResult error(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual ErrorResult warning(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual int messageBox(const ACHAR*,const ACHAR*,unsigned int,int);
    virtual void info(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual void infoMessage(const ACHAR*);
    virtual void logMessage(const ACHAR*,const ACHAR*);
    virtual void severeError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual void terminalError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
};
