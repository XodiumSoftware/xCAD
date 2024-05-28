// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcTransactionReactor: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcTransactionReactor);

    virtual void endCalledOnOutermostTransaction(int&,AcDbTransactionManager*);
    virtual void objectIdSwapped(const AcDbObject*,const AcDbObject*,AcDbTransactionManager*);
    virtual void transactionAborted(int&,AcDbTransactionManager*);
    virtual void transactionAboutToAbort(int&,AcDbTransactionManager*);
    virtual void transactionAboutToEnd(int&,AcDbTransactionManager*);
    virtual void transactionAboutToStart(int&,AcDbTransactionManager*);
    virtual void transactionEnded(int&,AcDbTransactionManager*);
    virtual void transactionStarted(int&,AcDbTransactionManager*);
};
