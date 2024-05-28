// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT SaveRestoreCallback
{
public:
    virtual ~SaveRestoreCallback();

    virtual void restoreBytes(void*,int) = 0;
    virtual void saveBytes(const void*,int) = 0;
};

}