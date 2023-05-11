// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

class OPMPropertyExtension;
interface IDynamicProperty;
interface IPropertyManager;

/** _ */
class BRX_IMPORTEXPORT OPMPropertyExtensionFactory: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(OPMPropertyExtensionFactory);

    virtual ~OPMPropertyExtensionFactory() {}

    virtual BOOL GetOPMManager(const ACHAR*,IPropertyManager**) = 0;
    virtual BOOL GetPropertyCount(AcRxClass*,LONG*) = 0;
    virtual BOOL GetPropertyCountEx(AcRxClass*,LONG*) = 0;
    virtual LONG GetPropertyClassArray(AcRxClass*,IDynamicProperty**) = 0;
    virtual LONG GetPropertyClassArray(AcRxClass*,IUnknown**) = 0;
    virtual OPMPropertyExtension* CreateOPMCommandProtocol(const ACHAR*,LONG = 0) = 0;
    virtual OPMPropertyExtension* CreateOPMObjectProtocol(AcRxClass*,LONG = 0) = 0;
};