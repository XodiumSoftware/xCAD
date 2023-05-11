// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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