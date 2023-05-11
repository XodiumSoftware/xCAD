// Copyright (C) Menhirs NV. All rights reserved.
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
