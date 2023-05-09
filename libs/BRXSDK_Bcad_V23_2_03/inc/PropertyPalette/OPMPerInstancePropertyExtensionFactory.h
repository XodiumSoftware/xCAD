// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

class OPMPerInstancePropertyExtension;

/** _ */
class BRX_IMPORTEXPORT OPMPerInstancePropertyExtensionFactory: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(OPMPerInstancePropertyExtensionFactory);

    virtual ~OPMPerInstancePropertyExtensionFactory() {}

    virtual OPMPerInstancePropertyExtension* CreateOPMPerInstancePropertyExtension(AcRxClass*) = 0;
};