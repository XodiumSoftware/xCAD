// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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