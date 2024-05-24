// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcLy/AcLyRelExpr.h"
#include "Misc/AcArray.h"

/** _ */
class AcLyAndExpr
{
public:
    virtual ~AcLyAndExpr() {}

    virtual const AcArray<AcLyRelExpr*>& getRelExprs() const = 0;
};
