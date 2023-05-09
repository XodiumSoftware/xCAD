// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeCurve2d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeExternalCurve2d: public AcGeCurve2d
{
public:
    AcGeExternalCurve2d();
    AcGeExternalCurve2d(const AcGeExternalCurve2d&);
    AcGeExternalCurve2d(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);

    AcGe::ExternalEntityKind externalCurveKind() const;
    AcGeExternalCurve2d& set(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);
    AcGeExternalCurve2d& setToOwnCurve();
    Adesk::Boolean isDefined() const;
    Adesk::Boolean isNurbCurve() const;
    Adesk::Boolean isNurbCurve(AcGeNurbCurve2d&) const;
    Adesk::Boolean isOwnerOfCurve() const;
    void getExternalCurve(void*&) const;

    AcGeExternalCurve2d& operator=(const AcGeExternalCurve2d&);
};