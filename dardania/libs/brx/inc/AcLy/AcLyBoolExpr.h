// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcLy/AcLyAndExpr.h"

/** _ */
class AcLyBoolExpr
{
public:
    virtual ~AcLyBoolExpr() {}

    virtual const AcArray<AcLyAndExpr*>& getAndExprs() const = 0;
};