// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
