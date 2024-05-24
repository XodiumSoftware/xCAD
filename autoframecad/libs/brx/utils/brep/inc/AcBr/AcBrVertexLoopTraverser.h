// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
