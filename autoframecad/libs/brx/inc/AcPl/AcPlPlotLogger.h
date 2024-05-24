// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcPlPlotLogger
{
public:
    AcPlPlotLogger() {}
    virtual ~AcPlPlotLogger() {}

    virtual Acad::ErrorStatus endJob() = 0;
    virtual Acad::ErrorStatus endSheet() = 0;
    virtual Acad::ErrorStatus logARIError(const ACHAR*) = 0;
    virtual Acad::ErrorStatus logError(const ACHAR*) = 0;
    virtual Acad::ErrorStatus logInformation(const ACHAR*) = 0;
    virtual Acad::ErrorStatus logMessage(const ACHAR*) = 0;
    virtual Acad::ErrorStatus logSevereError(const ACHAR*) = 0;
    virtual Acad::ErrorStatus logTerminalError(const ACHAR*) = 0;
    virtual Acad::ErrorStatus logWarning(const ACHAR*) = 0;
    virtual Acad::ErrorStatus startJob() = 0;
    virtual Acad::ErrorStatus startSheet() = 0;
    virtual bool errorHasHappenedInJob() const = 0;
    virtual bool errorHasHappenedInSheet() const = 0;
    virtual bool warningHasHappenedInJob() const = 0;
    virtual bool warningHasHappenedInSheet() const = 0;
};
