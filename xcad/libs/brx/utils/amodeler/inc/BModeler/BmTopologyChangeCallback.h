// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT TopologyChangeCallback
{
public:
    virtual ~TopologyChangeCallback();

    virtual void entityCreated(Entity*) = 0;
    virtual void entityDeleted(Entity*) = 0;
    virtual void entityMerged(Entity*,Entity*) = 0;
    virtual void entitySplit(Entity*,Entity*) = 0;
};

}