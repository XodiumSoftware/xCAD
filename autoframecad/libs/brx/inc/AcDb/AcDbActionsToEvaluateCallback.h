// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbDatabase.h"

class AcDbActionsToEvaluateCallback
{
public:
    AcDbActionsToEvaluateCallback() {}
    virtual ~AcDbActionsToEvaluateCallback() noexcept = default;
    virtual void needsToEvaluate(const AcDbObjectId, AcDbAssocStatus, bool = true) = 0;
};
