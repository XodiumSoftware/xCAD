// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDoubleClickEdit: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbDoubleClickEdit);

    virtual void finishEdit() = 0;
    virtual void startEdit(AcDbEntity*,AcGePoint3d) = 0;
};
