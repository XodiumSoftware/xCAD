// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbHardOwnershipId.h"
#include "AcDb/AcDbHardPointerId.h"
#include "AcDb/AcDbR13ObjectId.h"
#include "AcDb/AcDbSoftOwnershipId.h"
#include "AcDb/AcDbSoftPointerId.h"
#include "AcRx/AcRxClass.h"
#include "Misc/AcHeapOperators.h"

class BrxDbObjectIteratorImp;

/** _ */
class BRX_IMPORTEXPORT AcDbObjectIterator: public AcRxObject, public AcHeapOperators
{
private:
    //BRX START
    friend class BrxFriend;
    BrxDbObjectIteratorImp* m_pBrxImp;
    //BRX END

public:
    ACRX_DECLARE_MEMBERS(AcDbObjectIterator);

private:
    AcDbObjectIterator();
public:
    virtual ~AcDbObjectIterator();

    AcDbEntity* entity();
    AcDbObjectId objectId();
    bool done() const;
    void setPosition(AcDbEntity*);
    void setPosition(AcDbObjectId);
    void start(bool = false);
    void step(bool = false,bool = true);
};
