#pragma once
#include "AcDb/AcDbDatabase.h"

class AcDbActionsToEvaluateCallback
{
public:
    AcDbActionsToEvaluateCallback() {}
    virtual ~AcDbActionsToEvaluateCallback() noexcept = default;
    virtual void needsToEvaluate(const AcDbObjectId, AcDbAssocStatus, bool = true) = 0;
};
