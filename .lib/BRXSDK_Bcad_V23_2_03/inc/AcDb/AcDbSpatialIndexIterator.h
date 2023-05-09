// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbFilteredBlockIterator.h"
#include "AcDb/AcDbSpatialIndex.h"

/** _ */
class AcDbSpatialIndexIterator: public AcDbFilteredBlockIterator
{
public:
    AcDbSpatialIndexIterator(const AcDbSpatialIndex*,const AcDbSpatialFilter*);
    virtual ~AcDbSpatialIndexIterator();

    virtual Acad::ErrorStatus accepts(AcDbObjectId,Adesk::Boolean&) const;
    virtual Acad::ErrorStatus seek(AcDbObjectId);
    virtual Acad::ErrorStatus start();
    virtual AcDbObjectId id() const;
    virtual AcDbObjectId next();
    virtual double estimatedHitFraction() const;
};
