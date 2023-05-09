// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class AcDbEvalContext: public AcRxObject, public AcHeapOperators
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEvalContext);

    AcDbEvalContext();
    virtual ~AcDbEvalContext();

    virtual Acad::ErrorStatus getAt(AcDbEvalContextPair&) const;
    virtual AcDbEvalContextIterator* newIterator() const;
    virtual void insertAt(const AcDbEvalContextPair&);
    virtual void removeAt(const ACHAR*);
};
