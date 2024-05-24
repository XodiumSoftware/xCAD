// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrFace;
class AcBrShell;
class AcBrComplexShellTraverser;

class AcBrShellFaceTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrShellFaceTraverser);

    AcBrShellFaceTraverser();
    AcBrShellFaceTraverser(const AcBrShellFaceTraverser&);
    ~AcBrShellFaceTraverser();

    AcBr::ErrorStatus getFace(AcBrFace&) const;
    AcBr::ErrorStatus getShell(AcBrShell&) const;
    AcBr::ErrorStatus setFace(const AcBrFace&);
    AcBr::ErrorStatus setShell(const AcBrComplexShellTraverser&);
    AcBr::ErrorStatus setShell(const AcBrShell&);
    AcBr::ErrorStatus setShellAndFace(const AcBrFace&);

    AcBrShellFaceTraverser& operator=(const AcBrShellFaceTraverser&);
};