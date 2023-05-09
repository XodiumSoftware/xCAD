// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrEntity.h"

class AcGeCurve3d;
class AcGePoint3d;
class AcBrShell;
class AcGeSurface;
class AcGeNurbSurface;
class AcGeExternalBoundedSurface;

class AcBrFace: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrFace);

    AcBrFace();
    AcBrFace(const AcBrFace&);
    ~AcBrFace();

    AcBr::ErrorStatus getArea(double&,const double&	= 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getCurveRelationToFace(const AcGeCurve3d&,AcBr::Relation&) const;
    AcBr::ErrorStatus getOrientToSurface(Adesk::Boolean&) const;
    AcBr::ErrorStatus getPointRelationToFace(const AcGePoint3d&,AcBr::Relation&) const;
    AcBr::ErrorStatus getShell(AcBrShell&) const;
    AcBr::ErrorStatus getSurface(AcGeSurface*&) const;
    AcBr::ErrorStatus getSurfaceAsNurb(AcGeNurbSurface&,const double& = 0.0,double& = defaultDoubleNull) const;
    AcBr::ErrorStatus getSurfaceAsTrimmedNurbs(Adesk::UInt32&,AcGeExternalBoundedSurface**&) const;
    AcBr::ErrorStatus getSurfaceType(AcGe::EntityId&) const;

    AcBrFace& operator=(const AcBrFace&);
};

