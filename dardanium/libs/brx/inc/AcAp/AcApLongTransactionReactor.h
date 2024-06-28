// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcApLongTransactionReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcApLongTransactionReactor);

    virtual void abortLongTransaction(AcDbLongTransaction&);
    virtual void beginCheckIn(AcDbLongTransaction&);
    virtual void beginCheckOut(AcDbLongTransaction&,AcDbObjectIdArray&);
    virtual void endCheckIn(AcDbLongTransaction&);
    virtual void endCheckOut(AcDbLongTransaction&);

protected:
    Acad::ErrorStatus veto();
};
