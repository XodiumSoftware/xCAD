// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrElement2d;
class AcBrMesh2d;

class AcBrMesh2dElement2dTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrMesh2dElement2dTraverser);

    AcBrMesh2dElement2dTraverser();
    AcBrMesh2dElement2dTraverser(const AcBrMesh2dElement2dTraverser&);
    ~AcBrMesh2dElement2dTraverser();

    AcBr::ErrorStatus getElement(AcBrElement2d&) const;
    AcBr::ErrorStatus getMesh(AcBrMesh2d&) const;
    AcBr::ErrorStatus setElement(const AcBrElement2d&);
    AcBr::ErrorStatus setMesh(const AcBrMesh2d&);
    AcBr::ErrorStatus setMeshAndElement(const AcBrElement2d&);

    AcBrMesh2dElement2dTraverser& operator=(const AcBrMesh2dElement2dTraverser&);
};