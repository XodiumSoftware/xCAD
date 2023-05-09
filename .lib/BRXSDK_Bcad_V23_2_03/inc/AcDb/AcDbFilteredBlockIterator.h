// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"

/** _ */
class BRX_IMPORTEXPORT AcDbFilteredBlockIterator
{
public:
    AcDbFilteredBlockIterator() {}
    virtual ~AcDbFilteredBlockIterator() {}

    virtual Acad::ErrorStatus accepts(AcDbObjectId,Adesk::Boolean&) const = 0;
    virtual Acad::ErrorStatus addToBuffer(AcDbObjectId) = 0;
    virtual Acad::ErrorStatus seek(AcDbObjectId) = 0;
    virtual Acad::ErrorStatus start() = 0;
    virtual AcDbObjectId id() const = 0;
    virtual AcDbObjectId next() = 0;
    virtual Adesk::Boolean buffersForComposition() const = 0;
    virtual double estimatedHitFraction() const = 0;
};
