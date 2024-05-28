// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbFilter: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbFilter);

    AcDbFilter();
    virtual ~AcDbFilter();

    virtual AcRxClass* indexClass() const;
};
