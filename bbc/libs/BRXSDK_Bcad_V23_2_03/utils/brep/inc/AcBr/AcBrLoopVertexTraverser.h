// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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