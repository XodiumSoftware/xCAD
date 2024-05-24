// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT SaveToSatCallback
{
public:
    virtual ~SaveToSatCallback();

    virtual void saveDouble(double) = 0;
    virtual void saveIdent(const char*) = 0;
    virtual void saveIndex(int) = 0;
    virtual void saveInt(int) = 0;
};

}