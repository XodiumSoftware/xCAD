// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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