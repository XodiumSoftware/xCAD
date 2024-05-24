// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeCurve3d.h"

/** _ */
class BRX_IMPORTEXPORT AcGeExternalCurve3d: public AcGeCurve3d
{
public:
    AcGeExternalCurve3d();
    AcGeExternalCurve3d(const AcGeExternalCurve3d&);
    AcGeExternalCurve3d(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);

    AcGe::ExternalEntityKind externalCurveKind() const;
    AcGeExternalCurve3d& set(void*,AcGe::ExternalEntityKind,Adesk::Boolean = Adesk::kTrue);
    AcGeExternalCurve3d& setToOwnCurve();
    Adesk::Boolean isCircArc() const;
    Adesk::Boolean isDefined() const;
    Adesk::Boolean isEllipArc() const;
    Adesk::Boolean isLine() const;
    Adesk::Boolean isLineSeg() const;
    Adesk::Boolean isNativeCurve(AcGeCurve3d*&) const;
    Adesk::Boolean isNurbCurve() const;
    Adesk::Boolean isOwnerOfCurve() const;
    Adesk::Boolean isRay() const;
    void getExternalCurve(void*&) const;

    AcGeExternalCurve3d& operator=(const AcGeExternalCurve3d&);
};