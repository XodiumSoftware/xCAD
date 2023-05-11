// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbIndex.h"

/** _ */
class BRX_EXPORT AcDbSpatialIndex: public AcDbIndex
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSpatialIndex);

    AcDbSpatialIndex();
    virtual ~AcDbSpatialIndex();

    virtual Acad::ErrorStatus rebuildFull(AcDbIndexUpdateData*);
protected:
    virtual Acad::ErrorStatus rebuildModified(AcDbBlockChangeIterator*);
public:
    virtual AcDbFilteredBlockIterator* newIterator(const AcDbFilter*) const;
};
