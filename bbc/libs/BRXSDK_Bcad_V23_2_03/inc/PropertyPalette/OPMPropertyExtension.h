// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

interface IPropertyManager;

/** _ */
class BRX_IMPORTEXPORT OPMPropertyExtension: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(OPMPropertyExtension);

    virtual ~OPMPropertyExtension() {}

    virtual IPropertyManager* GetPropertyManager() = 0;
    virtual void SetPropertyManager(IPropertyManager*) = 0;
};
