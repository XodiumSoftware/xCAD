// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class OPMPerInstancePropertyExtension: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(OPMPerInstancePropertyExtension);

    virtual ~OPMPerInstancePropertyExtension() {}

    virtual bool AddObjectPropertySourceName(const BSTR*) = 0;
    virtual bool GetObjectPropertySourceNames(VARIANT*) = 0;
    virtual bool RemoveObjectPropertySourceName(const BSTR*) = 0;
};