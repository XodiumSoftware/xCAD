// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrBrep;
class AcBrShell;

class AcBrBrepShellTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrBrepShellTraverser);

    AcBrBrepShellTraverser();
    AcBrBrepShellTraverser(const AcBrBrepShellTraverser&);
    ~AcBrBrepShellTraverser();

    AcBr::ErrorStatus getBrep(AcBrBrep&) const;
    AcBr::ErrorStatus getShell(AcBrShell&) const;
    AcBr::ErrorStatus setBrep(const AcBrBrep&);
    AcBr::ErrorStatus setBrepAndShell(const AcBrShell&);
    AcBr::ErrorStatus setShell(const AcBrShell&);

    AcBrBrepShellTraverser& operator=(const AcBrBrepShellTraverser&);
};
