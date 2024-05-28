// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"
#include "AcTrans/AcTransGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbTransactionManager: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbTransactionManager);

    virtual Acad::ErrorStatus abortTransaction() = 0;
    virtual Acad::ErrorStatus addNewlyCreatedDBRObject(AcDbObject*,bool = true) = 0;
    virtual Acad::ErrorStatus endTransaction() = 0;
    Acad::ErrorStatus getAllObjects(AcDbVoidPtrArray&); //deprecated
    virtual Acad::ErrorStatus getAllObjects(AcArray<AcDbObject*>&) = 0;
    virtual Acad::ErrorStatus getObject(AcDbObject*&,AcDbObjectId,AcDb::OpenMode,bool = false) = 0;
    virtual Acad::ErrorStatus markObjectPageable(AcDbObject*) = 0;
    virtual Acad::ErrorStatus queueForGraphicsFlush() = 0;
    virtual AcTransaction* startTransaction() = 0;
    virtual AcTransaction* topTransaction() = 0;
    virtual int numActiveTransactions() = 0;
    virtual void addReactor(AcTransactionReactor*) = 0;
    virtual void removeReactor(AcTransactionReactor*) = 0;
};
