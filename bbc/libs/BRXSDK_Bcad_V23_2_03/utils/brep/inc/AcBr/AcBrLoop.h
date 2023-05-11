// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrEntity.h"

class AcBrFace;

class AcBrLoop: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrLoop);

    AcBrLoop();
    AcBrLoop(const AcBrLoop&);
    ~AcBrLoop();

    AcBr::ErrorStatus getFace(AcBrFace&) const;
    AcBr::ErrorStatus getType(AcBr::LoopType&) const;

    AcBrLoop& operator=(const AcBrLoop&);
};
