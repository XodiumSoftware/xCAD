// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxService: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxService);

    AcRxService();
    virtual ~AcRxService();

    Adesk::Boolean unloadable() const;
    void addDependency();
    void removeDependency();
};
