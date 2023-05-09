// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeOffsetSurface: public AcGeSurface
{
public:
    AcGeOffsetSurface();
    AcGeOffsetSurface(AcGeSurface*,double,Adesk::Boolean = Adesk::kTrue);
    AcGeOffsetSurface(const AcGeOffsetSurface&);

    AcGeOffsetSurface& set(AcGeSurface*,double,Adesk::Boolean = Adesk::kTrue);
    Adesk::Boolean getSurface(AcGeSurface*&) const;
    Adesk::Boolean isBoundedPlane() const;
    Adesk::Boolean isCone() const;
    Adesk::Boolean isCylinder() const;
    Adesk::Boolean isPlane() const;
    Adesk::Boolean isSphere() const;
    Adesk::Boolean isTorus() const;
    double offsetDist() const;
    void getConstructionSurface(AcGeSurface*&) const;

    AcGeOffsetSurface& operator=(const AcGeOffsetSurface&);
};