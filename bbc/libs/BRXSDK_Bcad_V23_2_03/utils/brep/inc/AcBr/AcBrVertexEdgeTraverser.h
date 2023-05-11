// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrEdge;
class AcBrVertex;

class AcBrVertexEdgeTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrVertexEdgeTraverser);

    AcBrVertexEdgeTraverser();
    AcBrVertexEdgeTraverser(const AcBrVertexEdgeTraverser&);
    ~AcBrVertexEdgeTraverser();

    AcBr::ErrorStatus getEdge(AcBrEdge&) const;
    AcBr::ErrorStatus getVertex(AcBrVertex&) const;
    AcBr::ErrorStatus setEdge(const AcBrEdge&);
    AcBr::ErrorStatus setVertex(const AcBrVertex&);

    AcBrVertexEdgeTraverser& operator=(const AcBrVertexEdgeTraverser&);
};