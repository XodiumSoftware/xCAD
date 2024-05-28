// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeSurface.h"

/** _ */
class BRX_IMPORTEXPORT AcGeExternalSurface: public AcGeSurface
{
public:
    AcGeExternalSurface();
    AcGeExternalSurface(const AcGeExternalSurface&);
    AcGeExternalSurface(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);

    AcGe::ExternalEntityKind externalSurfaceKind() const;
    AcGeExternalSurface& set(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);
    AcGeExternalSurface& setToOwnSurface();
    Adesk::Boolean isCone() const;
    Adesk::Boolean isCylinder() const;
    Adesk::Boolean isDefined() const;
    Adesk::Boolean isNativeSurface(AcGeSurface*&) const;
    Adesk::Boolean isNurbSurface() const;
    Adesk::Boolean isOwnerOfSurface() const;
    Adesk::Boolean isPlane() const;
    Adesk::Boolean isSphere() const;
    Adesk::Boolean isTorus() const;
    void getExternalSurface(void*&) const;

    AcGeExternalSurface& operator=(const AcGeExternalSurface&);
};