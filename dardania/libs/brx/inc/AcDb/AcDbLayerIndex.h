// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbIndex.h"

/** _ */
class BRX_EXPORT AcDbLayerIndex: public AcDbIndex
{
public:
    ACDB_DECLARE_MEMBERS(AcDbLayerIndex);

    AcDbLayerIndex();
    virtual ~AcDbLayerIndex();

    virtual Acad::ErrorStatus rebuildFull(AcDbIndexUpdateData*);
protected:
    virtual Acad::ErrorStatus rebuildModified(AcDbBlockChangeIterator*);
public:
    virtual AcDbFilteredBlockIterator* newIterator(const AcDbFilter*) const;

    Acad::ErrorStatus compute(AcDbLayerTable*,AcDbBlockTableRecord*);
};
