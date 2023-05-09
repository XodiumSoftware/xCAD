// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/MiscGlobal.h"

class AcDbObjectContext;

/** _ */
class BRX_EXPORT AcDbObjectContextCollectionIterator : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbObjectContextCollectionIterator);
    
public:
    virtual bool done() const = 0;
    virtual bool next() = 0;
    virtual Acad::ErrorStatus start() = 0;

    virtual Acad::ErrorStatus getContext(AcDbObjectContext*&) const = 0;
};
