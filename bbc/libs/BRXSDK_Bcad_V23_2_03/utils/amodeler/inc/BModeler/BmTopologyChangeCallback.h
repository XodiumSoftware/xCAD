// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
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