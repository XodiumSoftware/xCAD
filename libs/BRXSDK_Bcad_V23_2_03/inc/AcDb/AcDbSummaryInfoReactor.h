// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbDatabaseSummaryInfo.h"

/** _ */
class BRX_IMPORTEXPORT AcDbSummaryInfoReactor
{
public:
    virtual ~AcDbSummaryInfoReactor() {}

    virtual void summaryInfoHasChanged(const AcDbDatabase*,const AcDbDatabaseSummaryInfo*) {}
};
