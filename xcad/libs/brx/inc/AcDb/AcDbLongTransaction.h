// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbLongTransWorkSetIterator.h"
#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbLongTransaction: public AcDbObject
{
public:
    enum
    {
        kSameDb = 0,
        kXrefDb,
        kUnrelatedDb
    };

    ACDB_DECLARE_MEMBERS(AcDbLongTransaction);

    AcDbLongTransaction();
    ~AcDbLongTransaction();

    Acad::ErrorStatus addToWorkSet(AcDbObjectId);
    Acad::ErrorStatus getLongTransactionName(ACHAR*&) const;
    Acad::ErrorStatus newWorkSetIterator(AcDbLongTransWorkSetIterator*&,bool = false,bool = false) const;
    Acad::ErrorStatus removeFromWorkSet(AcDbObjectId);
    Acad::ErrorStatus syncWorkSet();
    AcDbIdMapping* activeIdMap();
    AcDbObjectId destinationBlock() const;
    AcDbObjectId originBlock() const;
    AcDbObjectId originObject(AcDbObjectId) const;
    bool disallowDrawOrder();
    bool workSetHas(AcDbObjectId,bool = false) const;
    int type() const;
    void regenWorkSetWithDrawOrder();
};
