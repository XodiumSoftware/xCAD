// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxService.h"

/** _ */
class BRX_IMPORTEXPORT AcRxProtocolReactorManagerFactory : public AcRxService
{
public:
    ACRX_DECLARE_MEMBERS(AcRxProtocolReactorManagerFactory);

    virtual AcRxProtocolReactorManager* createReactorManager(AcRxClass*) const = 0;
};
