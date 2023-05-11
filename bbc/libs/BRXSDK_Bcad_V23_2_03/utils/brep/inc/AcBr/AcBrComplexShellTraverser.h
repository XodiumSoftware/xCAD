// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrComplex;
class AcBrShell;
class AcBrBrepComplexTraverser;

class AcBrComplexShellTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrComplexShellTraverser);

    AcBrComplexShellTraverser();
    AcBrComplexShellTraverser(const AcBrComplexShellTraverser&);
    ~AcBrComplexShellTraverser();

    AcBr::ErrorStatus getComplex(AcBrComplex&) const;
    AcBr::ErrorStatus getShell(AcBrShell&) const;
    AcBr::ErrorStatus setComplex(const AcBrBrepComplexTraverser&);
    AcBr::ErrorStatus setComplex(const AcBrComplex&);
    AcBr::ErrorStatus setComplexAndShell(const AcBrShell&);
    AcBr::ErrorStatus setShell(const AcBrShell&);

    AcBrComplexShellTraverser& operator=(const AcBrComplexShellTraverser&);
};
