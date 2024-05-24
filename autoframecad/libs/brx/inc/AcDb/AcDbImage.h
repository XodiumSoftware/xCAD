// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
