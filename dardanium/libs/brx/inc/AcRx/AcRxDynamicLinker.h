// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "AcRx/AcRxDictionary.h"

/** _ */
class AcRxDynamicLinker: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxDynamicLinker);

    virtual AcRxObject* registerService(const ACHAR*,AcRxService*) = 0;
    virtual Adesk::UInt32 ProductLcid() const = 0;
    virtual bool initListedModules(const ACHAR*) = 0;
    virtual bool isApplicationLocked(const ACHAR*) const = 0;
    virtual bool isAppMDIAware(const ACHAR*) const = 0;
    virtual bool loadApp(const ACHAR*,AcadApp::LoadReasons,bool,bool=false) = 0;
    virtual bool loadModule(const ACHAR*,bool,bool=false) = 0;
    virtual bool lockApplication(void*) const = 0;
    virtual bool registerAppMDIAware(void*) const = 0;
    virtual bool registerAppNotMDIAware(void*) const = 0;
    virtual bool unloadApp(const ACHAR*,bool=false) = 0;
    virtual bool unloadModule(const ACHAR*,bool=false) = 0;
    virtual bool unlockApplication(void*) const = 0;
    virtual const ACHAR* ProductKey() const = 0;
    virtual void addReactor(AcRxDLinkerReactor*) = 0;
    virtual void removeReactor(AcRxDLinkerReactor*) = 0;
    virtual void* getSymbolAddress(const ACHAR*,const ACHAR*) const = 0;
    virtual void* getSymbolAddress(const ACHAR*,const char*) const = 0;

    bool isAppBusy(const ACHAR*) const;
    void setAppBusy(const ACHAR*,bool) const;
};

#define acrxDynamicLinker AcRxDynamicLinker::cast(acrxSysRegistry()->at(ACRX_DYNAMIC_LINKER))
