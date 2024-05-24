// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
