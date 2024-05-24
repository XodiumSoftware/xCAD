// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrMesh.h"

class AcBrMesh2dFilter;

class AcBrMesh2d: public AcBrMesh
{
public:
    ACRX_DECLARE_MEMBERS(AcBrMesh2d);

    AcBrMesh2d();
    AcBrMesh2d(const AcBrMesh2d&);
    ~AcBrMesh2d();

    AcBr::ErrorStatus generate(const AcBrMesh2dFilter&);

    AcBrMesh2d& operator=(const AcBrMesh2d&);
};