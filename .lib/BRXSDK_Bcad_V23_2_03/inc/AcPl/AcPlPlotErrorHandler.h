// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcPl/AcPlObject.h"

/** _ */
class AcPlPlotErrorHandler: public AcPlObject
{
public:
    enum ErrorResult
    {
        kAbort = 0,
        kRetry,
        kIgnore
    };

    enum Handler
    {
        kInfo = 0,
        kWarning,
        kError,
        kARI,
        kSevere,
        kTerminal,
        kNone
    };

    ACRX_DECLARE_MEMBERS(AcPlPlotErrorHandler);

    AcPlPlotErrorHandler();
    ~AcPlPlotErrorHandler();

    virtual bool logMode() const;
    virtual bool quietMode() const;
    virtual bool setLogHandle(const ACHAR*);
    virtual bool takeResponsibility(Handler);
    virtual const ACHAR* ariTitle() const;
    virtual const ACHAR* errorTitle() const;
    virtual const ACHAR* infoTitle() const;
    virtual const ACHAR* severeTitle() const;
    virtual const ACHAR* terminalTitle() const;
    virtual const ACHAR* warningTitle() const;
    virtual ErrorResult ariError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual ErrorResult error(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual ErrorResult warning(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual int messageBox(const ACHAR*,const ACHAR*,unsigned int,int);
    virtual void info(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual void infoMessage(const ACHAR*);
    virtual void logMessage(const ACHAR*,const ACHAR*);
    virtual void setLogMode(bool);
    virtual void setQuietMode(bool);
    virtual void severeError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    virtual void terminalError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);

protected:
    bool appSetLogHandle(const ACHAR*);
    ErrorResult appARIError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    ErrorResult appError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    ErrorResult appWarning(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    int appMessageBox(const ACHAR*,const ACHAR*,unsigned int,int);
    void appInfo(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    void appInfoMessage(const ACHAR*);
    void appLogMessage(const ACHAR*,const ACHAR*);
    void appSevereError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);
    void appTerminalError(ULONG_PTR,const unsigned int,const ACHAR*,const ACHAR*,const ACHAR*);

public:
    void getCompanyString(ACHAR*&) const;
    void getProductString(ACHAR*&) const;
    void getProgramString(ACHAR*&) const;
};
