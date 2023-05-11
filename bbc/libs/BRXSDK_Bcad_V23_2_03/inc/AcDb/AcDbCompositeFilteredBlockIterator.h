// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"

/** _ */
class BRX_IMPORTEXPORT AcDbCompositeFilteredBlockIterator
{
protected:
    AcDbCompositeFilteredBlockIterator() {}
private:
    AcDbCompositeFilteredBlockIterator(const AcDbCompositeFilteredBlockIterator&);
public:
    virtual ~AcDbCompositeFilteredBlockIterator() {}

    virtual Acad::ErrorStatus init(AcDbFilter* const*,int,const AcDbBlockTableRecord*) = 0;
    virtual Acad::ErrorStatus seek(AcDbObjectId) = 0;
    virtual Acad::ErrorStatus start() = 0;
    virtual AcDbObjectId id() const = 0;
    virtual AcDbObjectId next() = 0;

    static AcDbCompositeFilteredBlockIterator* newIterator();
};
