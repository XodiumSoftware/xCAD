// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrEntity.h"

class AcDbEntity;
class AcDb3dSolid;
class AcGeCurve3d;
class AcGePoint3d;

class AcBrBrep: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrBrep);

    AcBrBrep();
    AcBrBrep(const AcBrBrep&);
    ~AcBrBrep();

    AcBr::ErrorStatus get(AcDb3dSolid*&) const;
    AcBr::ErrorStatus get(AcDbSurface*&) const;
    AcBr::ErrorStatus getCurveRelationToBrep(const AcGeCurve3d&,AcBr::Relation&) const;
    AcBr::ErrorStatus getPointRelationToBrep(const AcGePoint3d&,AcBr::Relation&) const;
    AcBr::ErrorStatus set(const AcDbEntity&);

    AcBrBrep& operator=(const AcBrBrep&);

private:
    friend class AcBrMesh2d;

    // ! for BRX internal use only !
    class OdDbEntity* getOdDbEntity() const;
};
