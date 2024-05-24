// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

interface IPropertySource;

/** _ */
class BRX_IMPORTEXPORT OPMPerInstancePropertySources: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(OPMPerInstancePropertySources);

    virtual ~OPMPerInstancePropertySources() {}

    virtual bool GetPropertySourceNames(VARIANT*) = 0;
    virtual bool RemovePropertySourceAt(const BSTR*) = 0;
    virtual bool SetPropertySourceAt(const BSTR*,IPropertySource*) = 0;
    virtual IPropertySource* GetPropertySourceAt(const BSTR*) = 0;
};