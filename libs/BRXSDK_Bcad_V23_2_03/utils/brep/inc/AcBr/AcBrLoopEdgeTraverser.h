// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcGeCurve2d;
class AcGeCurve3d;
class AcGeNurbCurve2d;
class AcGeNurbCurve3d;
class AcBrLoop;
class AcBrEdge;
class AcBrFaceLoopTraverser;
class AcBrEdgeLoopTraverser;

class AcBrLoopEdgeTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrLoopEdgeTraverser);

    AcBrLoopEdgeTraverser();
    AcBrLoopEdgeTraverser(const AcBrLoopEdgeTraverser&);
    ~AcBrLoopEdgeTraverser();

    AcBr::ErrorStatus getEdge(AcBrEdge&) const;
    AcBr::ErrorStatus getEdgeOrientToLoop(Adesk::Boolean&) const;
    AcBr::ErrorStatus getLoop(AcBrLoop&) const;
    AcBr::ErrorStatus getOrientedCurve(AcGeCurve3d*&) const;
    AcBr::ErrorStatus getOrientedCurveAsNurb(AcGeNurbCurve3d&,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getParamCurve(AcGeCurve2d*&) const;
    AcBr::ErrorStatus getParamCurveAsNurb(AcGeNurbCurve2d&,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus setEdge(AcBrEdge&);
    AcBr::ErrorStatus setEdge(const AcBrEdge&);
    AcBr::ErrorStatus setLoop(AcBrFaceLoopTraverser&);
    AcBr::ErrorStatus setLoop(const AcBrFaceLoopTraverser&);
    AcBr::ErrorStatus setLoop(const AcBrLoop&);
    AcBr::ErrorStatus setLoopAndEdge(AcBrEdgeLoopTraverser&);
    AcBr::ErrorStatus setLoopAndEdge(const AcBrEdgeLoopTraverser&);

    AcBrLoopEdgeTraverser& operator=(const AcBrLoopEdgeTraverser&);
};