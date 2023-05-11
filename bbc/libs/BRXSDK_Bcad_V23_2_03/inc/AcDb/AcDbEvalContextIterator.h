// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class AcDbEvalContextIterator: public AcRxObject, public AcHeapOperators
{
public:
    ACRX_DECLARE_MEMBERS(AcDbEvalContextIterator);

    AcDbEvalContextIterator();
    virtual ~AcDbEvalContextIterator();

    virtual AcDbEvalContextPair contextPair() const;
    virtual bool done() const;
    virtual bool next();
    virtual void start();
};
