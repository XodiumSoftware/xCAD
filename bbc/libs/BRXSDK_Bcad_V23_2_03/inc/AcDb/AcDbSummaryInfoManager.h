// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbSummaryInfoReactor.h"

/** _ */
class __declspec(novtable) AcDbSummaryInfoManager
{
public:
    virtual void addReactor(AcDbSummaryInfoReactor*) = 0;
    virtual void removeReactor(AcDbSummaryInfoReactor*) = 0;
};
