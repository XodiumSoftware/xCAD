// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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
