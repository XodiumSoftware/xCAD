// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcRxOverrule : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcRxOverrule);

    virtual bool isApplicable(const AcRxObject*) const = 0;

    static Acad::ErrorStatus addOverrule(AcRxClass*, AcRxOverrule*, bool = false);
    static bool hasOverrule(const AcRxObject*, AcRxClass*);
    static bool isOverruling(void);
    static Acad::ErrorStatus removeOverrule(AcRxClass*, AcRxOverrule*);
    static void setIsOverruling(bool);
};
