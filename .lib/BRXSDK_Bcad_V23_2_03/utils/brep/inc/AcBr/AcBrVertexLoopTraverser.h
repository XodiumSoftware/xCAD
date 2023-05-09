// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrLoop;
class AcBrVertex;
class AcBrLoopVertexTraverser;

class AcBrVertexLoopTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrVertexLoopTraverser);

    AcBrVertexLoopTraverser();
    AcBrVertexLoopTraverser(const AcBrVertexLoopTraverser&);
    ~AcBrVertexLoopTraverser();

    AcBr::ErrorStatus getLoop(AcBrLoop&) const;
    AcBr::ErrorStatus getVertex(AcBrVertex&) const;
    AcBr::ErrorStatus setLoop(const AcBrLoop&);
    AcBr::ErrorStatus setVertex(const AcBrVertex&);
    AcBr::ErrorStatus setVertexAndLoop(const AcBrLoopVertexTraverser&);

    AcBrVertexLoopTraverser& operator=(const AcBrVertexLoopTraverser&);
};
