// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrEntity.h"

class AcBrComplex;

class AcBrShell: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrShell);

    AcBrShell();
    AcBrShell(const AcBrShell&);
    ~AcBrShell();

    AcBr::ErrorStatus getComplex(AcBrComplex&) const;
    AcBr::ErrorStatus getType(AcBr::ShellType&) const;

    AcBrShell& operator=(const AcBrShell&);
};
