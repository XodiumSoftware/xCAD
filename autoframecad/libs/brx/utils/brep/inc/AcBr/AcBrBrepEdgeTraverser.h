// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrBrep;
class AcBrEdge;

class AcBrBrepEdgeTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrBrepEdgeTraverser);

    AcBrBrepEdgeTraverser();
    AcBrBrepEdgeTraverser(const AcBrBrepEdgeTraverser&);
    ~AcBrBrepEdgeTraverser();

    AcBr::ErrorStatus getBrep(AcBrBrep&) const;
    AcBr::ErrorStatus getEdge(AcBrEdge&) const;
    AcBr::ErrorStatus setBrep(const AcBrBrep&);
    AcBr::ErrorStatus setBrepAndEdge(const AcBrEdge&);
    AcBr::ErrorStatus setEdge(const AcBrEdge&);

    AcBrBrepEdgeTraverser& operator=(const AcBrBrepEdgeTraverser&);
};
