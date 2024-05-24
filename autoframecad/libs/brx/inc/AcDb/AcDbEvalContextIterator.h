// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
