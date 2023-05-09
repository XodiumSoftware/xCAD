// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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
