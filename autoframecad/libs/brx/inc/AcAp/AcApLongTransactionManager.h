// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcAp/AcApGlobal.h"
#include "AcAp/AcApLongTransactionReactor.h"

/** _ */
class BRX_IMPORTEXPORT AcApLongTransactionManager: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcApLongTransactionManager);

    virtual Acad::ErrorStatus abortLongTransaction(AcDbObjectId,bool = false) = 0;
    virtual Acad::ErrorStatus addClassFilter(AcRxClass*) = 0;
    virtual Acad::ErrorStatus checkIn(AcDbObjectId,AcDbIdMapping&,bool = false) = 0;
    virtual Acad::ErrorStatus checkOut(AcDbObjectId&,AcDbObjectIdArray&,AcDbObjectId,AcDbIdMapping&,AcDbObjectId = AcDbObjectId::kNull) = 0;
    virtual AcDbObjectId currentLongTransactionFor(const AcApDocument*) const = 0;
    virtual bool isFiltered (AcRxClass*) const = 0;
    virtual void addReactor(AcApLongTransactionReactor*) = 0;
    virtual void removeReactor(AcApLongTransactionReactor*) = 0;
};