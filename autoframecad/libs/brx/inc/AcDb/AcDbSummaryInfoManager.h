// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSummaryInfoReactor.h"

/** _ */
class __declspec(novtable) AcDbSummaryInfoManager
{
public:
    virtual void addReactor(AcDbSummaryInfoReactor*) = 0;
    virtual void removeReactor(AcDbSummaryInfoReactor*) = 0;
};
