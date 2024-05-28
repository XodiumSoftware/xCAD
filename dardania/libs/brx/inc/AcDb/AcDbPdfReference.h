// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbUnderlayReference.h"

/** _ */
class BRX_EXPORT AcDbPdfReference: public AcDbUnderlayReference
{
public:
    ACDB_DECLARE_MEMBERS(AcDbPdfReference);

    AcDbPdfReference();
    virtual ~AcDbPdfReference();

    static Adesk::UInt8 contrastDefault();
    static Adesk::UInt8 fadeDefault();
};
