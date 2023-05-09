// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbIndex: public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbIndex);

    AcDbIndex();
    virtual ~AcDbIndex();

    virtual Acad::ErrorStatus rebuildFull(AcDbIndexUpdateData*);
protected:
    virtual Acad::ErrorStatus rebuildModified(AcDbBlockChangeIterator*);
public:
    virtual AcDbFilteredBlockIterator* newIterator(const AcDbFilter*) const;
    virtual AcDbObjectId objectBeingIndexedId() const;

    AcDbDate lastUpdatedAt() const;
    AcDbDate lastUpdatedAtU() const;
    Adesk::Boolean isUptoDate() const;
    void setLastUpdatedAt(const AcDbDate&);
    void setLastUpdatedAtU(const AcDbDate&);
};
