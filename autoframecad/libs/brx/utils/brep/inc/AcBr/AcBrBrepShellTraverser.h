// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
