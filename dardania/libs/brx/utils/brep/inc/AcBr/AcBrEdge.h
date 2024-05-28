// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcBr/AcBrEntity.h"

class AcGeCurve3d;
class AcGeNurbCurve3d;
class AcGePoint3d;
class AcGeVector3d;
class AcBrVertex;

class AcBrEdge: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrEdge);

    AcBrEdge();
    AcBrEdge(const AcBrEdge&);
    ~AcBrEdge();

    AcBr::ErrorStatus getCurve(AcGeCurve3d*&) const;
    AcBr::ErrorStatus getCurveAsNurb(AcGeNurbCurve3d&, const double& = 0.0, double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getCurveRelationToEdge(const AcGeCurve3d&, AcBr::Relation&) const;
    AcBr::ErrorStatus getCurveType(AcGe::EntityId&) const;
    AcBr::ErrorStatus getOrientToCurve(Adesk::Boolean&) const;
    AcBr::ErrorStatus getPointRelationToEdge(const AcGePoint3d&, AcBr::Relation&) const;
    AcBr::ErrorStatus getVertex1(AcBrVertex&) const;
    AcBr::ErrorStatus getVertex2(AcBrVertex&) const;

    AcBrEdge& operator=(const AcBrEdge&);
};
