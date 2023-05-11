// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrEntity.h"

class AcGeCurve3d;
class AcGePoint3d;

class AcBrVertex: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrVertex);

    AcBrVertex();
    AcBrVertex(const AcBrVertex&);
    ~AcBrVertex();

    AcBr::ErrorStatus getCurveRelationToVertex(const AcGeCurve3d&,AcBr::Relation&) const;
    AcBr::ErrorStatus getPoint(AcGePoint3d&) const;
    AcBr::ErrorStatus getPoint(AcGePoint3d*&) const;
    AcBr::ErrorStatus getPointRelationToVertex(const AcGePoint3d&,AcBr::Relation&) const;

    AcBrVertex& operator=(const AcBrVertex&);
};
