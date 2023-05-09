// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbFilteredBlockIterator.h"
#include "AcDb/AcDbLayerIndex.h"

/** _ */
class AcDbLayerIndexIterator: public AcDbFilteredBlockIterator
{
public:
    AcDbLayerIndexIterator(const AcDbLayerIndex*,const AcDbLayerFilter*);
    virtual ~AcDbLayerIndexIterator();

    virtual Acad::ErrorStatus accepts(AcDbObjectId,Adesk::Boolean&) const;
    virtual Acad::ErrorStatus seek(AcDbObjectId);
    virtual Acad::ErrorStatus start();
    virtual AcDbObjectId id() const;
    virtual AcDbObjectId next();
    virtual double estimatedHitFraction() const;
};
