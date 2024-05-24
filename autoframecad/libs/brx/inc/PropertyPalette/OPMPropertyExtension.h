// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
