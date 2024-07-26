// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrElement2d;
class AcBrNode;
class AcGePoint2d;
class AcGeVector3d;
class AcBrElement2d;
class AcBrMesh2dElement2dTraverser;

class AcBrElement2dNodeTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrElement2dNodeTraverser);

    AcBrElement2dNodeTraverser();
    AcBrElement2dNodeTraverser(const AcBrElement2dNodeTraverser&);
    ~AcBrElement2dNodeTraverser();

    AcBr::ErrorStatus getElement(AcBrElement2d&) const;
    AcBr::ErrorStatus getNode(AcBrNode&) const;
    AcBr::ErrorStatus getParamPoint(AcGePoint2d&) const;
    AcBr::ErrorStatus getSurfaceNormal(AcGeVector3d&) const;
    AcBr::ErrorStatus setElement(const AcBrElement2d&);
    AcBr::ErrorStatus setElement(const AcBrMesh2dElement2dTraverser&);
    AcBr::ErrorStatus setNode(const AcBrNode&);

    AcBrElement2dNodeTraverser& operator=(const AcBrElement2dNodeTraverser&);
};
