// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrBrep;
class AcBrVertex;

class AcBrBrepVertexTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrBrepVertexTraverser);

    AcBrBrepVertexTraverser();
    AcBrBrepVertexTraverser(const AcBrBrepVertexTraverser&);
    ~AcBrBrepVertexTraverser();

    AcBr::ErrorStatus getBrep(AcBrBrep&) const;
    AcBr::ErrorStatus getVertex(AcBrVertex&) const;
    AcBr::ErrorStatus setBrep(const AcBrBrep&);
    AcBr::ErrorStatus setBrepAndVertex(const AcBrVertex&);
    AcBr::ErrorStatus setVertex(const AcBrVertex&);

    AcBrBrepVertexTraverser& operator=(const AcBrBrepVertexTraverser&);
};
