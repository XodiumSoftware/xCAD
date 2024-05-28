// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbUnderlayReference.h"

/** _ */
class BRX_EXPORT AcDbDgnReference: public AcDbUnderlayReference
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDgnReference);

    AcDbDgnReference();
    virtual ~AcDbDgnReference();
};
