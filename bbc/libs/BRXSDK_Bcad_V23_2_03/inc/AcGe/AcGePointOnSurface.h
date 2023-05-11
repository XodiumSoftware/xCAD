// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePointEnt3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGePointOnSurface: public AcGePointEnt3d
{
public:
    AcGePointOnSurface();
    AcGePointOnSurface(const AcGePointOnSurface&);
    AcGePointOnSurface(const AcGeSurface&);
    AcGePointOnSurface(const AcGeSurface&,const AcGePoint2d&);

    AcGePoint2d parameter() const;
    AcGePoint3d point() const;
    AcGePoint3d point(const AcGePoint2d&);
    AcGePoint3d point(const AcGeSurface&,const AcGePoint2d&);
    AcGePointOnSurface& setParameter(const AcGePoint2d&);
    AcGePointOnSurface& setSurface(const AcGeSurface&);
    AcGeVector2d inverseTangentVector(const AcGeVector3d&) const;
    AcGeVector2d inverseTangentVector(const AcGeVector3d&,const AcGePoint2d&);
    AcGeVector2d inverseTangentVector(const AcGeVector3d&,const AcGeSurface&,const AcGePoint2d&);
    AcGeVector3d mixedPartial() const;
    AcGeVector3d mixedPartial(const AcGePoint2d&);
    AcGeVector3d mixedPartial(const AcGeSurface&,const AcGePoint2d&);
    AcGeVector3d normal() const;
    AcGeVector3d normal(const AcGePoint2d&);
    AcGeVector3d normal(const AcGeSurface&,const AcGePoint2d&);
    AcGeVector3d tangentVector(const AcGeVector2d&) const;
    AcGeVector3d tangentVector(const AcGeVector2d&,const AcGePoint2d&);
    AcGeVector3d tangentVector(const AcGeVector2d&,const AcGeSurface&,const AcGePoint2d&);
    AcGeVector3d uDeriv(int) const;
    AcGeVector3d uDeriv(int,const AcGePoint2d&);
    AcGeVector3d uDeriv(int,const AcGeSurface&,const AcGePoint2d&);
    AcGeVector3d vDeriv(int) const;
    AcGeVector3d vDeriv(int,const AcGePoint2d&);
    AcGeVector3d vDeriv(int,const AcGeSurface&,const AcGePoint2d&);
    const AcGeSurface* surface() const;

    AcGePointOnSurface& operator=(const AcGePointOnSurface&);
};
