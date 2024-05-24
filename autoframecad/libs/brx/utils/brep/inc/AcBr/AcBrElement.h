// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrMeshEntity.h"

class AcBrElement: public AcBrMeshEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrElement);

protected:
    friend class BrxBrMeshEntityImp;

    AcBrElement();
    AcBrElement(const AcBrElement&);
public:
    virtual ~AcBrElement();

protected:
    AcBrElement& operator=(const AcBrElement&);
};
