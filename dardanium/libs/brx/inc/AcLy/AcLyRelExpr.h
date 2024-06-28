// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/MiscGlobal.h"

/** _ */
class AcLyRelExpr
{
public:
    virtual const ACHAR* getConstant() const = 0;
    virtual const ACHAR* getVariable() const = 0;
};