// Copyright (C) Menhirs NV. All rights reserved.
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
