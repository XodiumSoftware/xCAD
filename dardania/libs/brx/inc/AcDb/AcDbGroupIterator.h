// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
