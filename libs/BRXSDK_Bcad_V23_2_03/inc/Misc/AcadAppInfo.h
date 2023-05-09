// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcadAppInfo: public AcRxObject
{
public:
    enum CmdStatus
    {
        kNoAction = 0,
        kRetry,
        kShowMsg,
        kNoModule
    };

    typedef CmdStatus (*LoaderFunPtr)(void*);

    ACRX_DECLARE_MEMBERS(AcadAppInfo);

    AcadAppInfo();
    virtual ~AcadAppInfo();

    AcadApp::ErrorStatus delFromRegistry(bool = false);
    AcadApp::ErrorStatus readFromRegistry();
    AcadApp::ErrorStatus status() const;
    AcadApp::ErrorStatus writeCommandNameToRegistry(const ACHAR*,const ACHAR*);
    AcadApp::ErrorStatus writeGroupNameToRegistry(const ACHAR*);
    AcadApp::ErrorStatus writeToRegistry(bool = false,bool = false);
    AcadApp::LoadReasons loadReason();
    bool appImplements(const ACHAR*) const;
    bool managed() const;
    CmdStatus runAppLoader();
    const ACHAR* appDesc() const;
    const ACHAR* appName() const;
    const ACHAR* moduleName() const;
    void setAppDesc(const ACHAR*);
    void setAppLoader(LoaderFunPtr);
    void setAppName(const ACHAR*);
    void setLoadReason(AcadApp::LoadReasons);
    void setManaged(bool);
    void setModuleName(const ACHAR*);
};
