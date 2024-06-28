// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
