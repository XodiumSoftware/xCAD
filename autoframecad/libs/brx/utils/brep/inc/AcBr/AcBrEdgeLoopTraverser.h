// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrLoop;
class AcBrEdge;
class AcBrLoopEdgeTraverser;
class AcBrVertexEdgeTraverser;

class AcBrEdgeLoopTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrEdgeLoopTraverser);

    AcBrEdgeLoopTraverser();
    AcBrEdgeLoopTraverser(const AcBrEdgeLoopTraverser&);
    ~AcBrEdgeLoopTraverser();

    AcBr::ErrorStatus getEdge(AcBrEdge&) const;
    AcBr::ErrorStatus getLoop(AcBrLoop&) const;
    AcBr::ErrorStatus setEdge(AcBrEdge&);
    AcBr::ErrorStatus setEdge(const AcBrEdge&);
    AcBr::ErrorStatus setEdge(const AcBrVertexEdgeTraverser&);
    AcBr::ErrorStatus setEdgeAndLoop(AcBrLoopEdgeTraverser&);
    AcBr::ErrorStatus setEdgeAndLoop(const AcBrLoopEdgeTraverser&);
    AcBr::ErrorStatus setLoop(const AcBrLoop&);

    AcBrEdgeLoopTraverser& operator=(const AcBrEdgeLoopTraverser&);
};