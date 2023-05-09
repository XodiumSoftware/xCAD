// Copyright (C) Menhirs NV. All rights reserved.
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