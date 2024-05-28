// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"
#include "Misc/AcArray.h"

/** _ */
class Ac3dDwfNavTreeNode: public AcRxObject
{
public:
    virtual bool addChild(const Ac3dDwfNavTreeNode*) = 0;
    virtual bool isBlock() const = 0;
    virtual bool isGroup() const = 0;
    virtual bool removeChild(const Ac3dDwfNavTreeNode*) = 0;
    virtual const AcArray<const Ac3dDwfNavTreeNode*>& children() const = 0;
    virtual const AcArray<long>& keys() const = 0;
    virtual const AcString& displayName() const = 0;
    virtual int nDescendants() const = 0;
};