// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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