// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeExternalBoundedSurface: public AcGeSurface
{
public:
    AcGeExternalBoundedSurface();
    AcGeExternalBoundedSurface(const AcGeExternalBoundedSurface&);
    AcGeExternalBoundedSurface(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);

    AcGe::ExternalEntityKind externalSurfaceKind() const;
    AcGeExternalBoundedSurface& set(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);
    AcGeExternalBoundedSurface& setToOwnSurface();
    Adesk::Boolean isCone() const;
    Adesk::Boolean isCylinder() const;
    Adesk::Boolean isDefined() const;
    Adesk::Boolean isExternalSurface() const;
    Adesk::Boolean isNurbs() const;
    Adesk::Boolean isOwnerOfSurface() const;
    Adesk::Boolean isPlane() const;
    Adesk::Boolean isSphere() const;
    Adesk::Boolean isTorus() const;
    int numContours() const;
    void getBaseSurface(AcGeExternalSurface&) const;
    void getBaseSurface(AcGeSurface*&) const;
    void getContours(int&,AcGeCurveBoundary*&) const;
    void getExternalSurface(void*&) const;

    AcGeExternalBoundedSurface& operator=(const AcGeExternalBoundedSurface&);
};