// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrLoop;
class AcGePoint2d;
class AcBrVertex;
class AcBrFaceLoopTraverser;
class AcBrVertexLoopTraverser;

class AcBrLoopVertexTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrLoopVertexTraverser);

    AcBrLoopVertexTraverser();
    AcBrLoopVertexTraverser(const AcBrLoopVertexTraverser&);
    ~AcBrLoopVertexTraverser();

    AcBr::ErrorStatus getLoop(AcBrLoop&) const;
    AcBr::ErrorStatus getParamPoint(AcGePoint2d&) const;
    AcBr::ErrorStatus getParamPoint(AcGePoint2d*&) const;
    AcBr::ErrorStatus getVertex(AcBrVertex&) const;
    AcBr::ErrorStatus setLoop(AcBrFaceLoopTraverser&);
    AcBr::ErrorStatus setLoop(const AcBrFaceLoopTraverser&);
    AcBr::ErrorStatus setLoop(const AcBrLoop&);
    AcBr::ErrorStatus setLoopAndVertex(const AcBrVertexLoopTraverser&);
    AcBr::ErrorStatus setVertex(const AcBrVertex&);

    AcBrLoopVertexTraverser& operator=(const AcBrLoopVertexTraverser&);
};