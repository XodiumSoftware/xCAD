// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"
#include "AcGi/AcGiRequestScanLines.h"
#include "AcGi/AcGiSentScanLines.h"

/** _ */
class BRX_IMPORTEXPORT AcDbImage: public AcDbEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcDbImage);

    virtual AcGiSentScanLines* getScanLines(const AcGiRequestScanLines&) const = 0;
    virtual Adesk::Boolean freeScanLines(AcGiSentScanLines*) const = 0;
};
