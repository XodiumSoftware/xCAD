// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxService.h"

/** _ */
class BRX_IMPORTEXPORT AcRxProtocolReactorManagerFactory : public AcRxService
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorManagerFactory);

    virtual AcRxProtocolReactorManager* createReactorManager(AcRxClass*) const = 0;
};
