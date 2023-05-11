// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbTransactionManager.h"

/** _ */
class BRX_IMPORTEXPORT AcTransactionManager: public AcDbTransactionManager
{
public:
    ACRX_DECLARE_MEMBERS(AcTransactionManager);

    virtual Acad::ErrorStatus enableGraphicsFlush(bool) = 0;
    virtual void flushGraphics() = 0;
};