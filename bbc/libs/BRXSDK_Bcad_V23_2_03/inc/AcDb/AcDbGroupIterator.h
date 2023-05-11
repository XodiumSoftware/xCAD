// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbGroupIterator: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbGroupIterator);

protected:
    AcDbGroupIterator() {}
public:
    virtual ~AcDbGroupIterator() {}

    virtual Acad::ErrorStatus getObject(AcDbObject*&,AcDb::OpenMode) = 0;
    virtual AcDbObjectId objectId() const = 0;
    virtual bool done() const = 0;
    virtual bool next() = 0;
};
