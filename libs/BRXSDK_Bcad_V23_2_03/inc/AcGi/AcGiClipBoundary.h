// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGeMatrix3d.h"

/** _ */
struct AcGiClipBoundary
{
    AcGeMatrix3d m_xInverseBlockRefXForm;
    AcGeMatrix3d m_xToClipSpace;
    AcGePoint2dArray m_aptPoints;
    AcGePoint3d m_ptPoint;
    AcGeVector3d m_vNormal;
    Adesk::Boolean m_bClippingBack;
    Adesk::Boolean m_bClippingFront;
    Adesk::Boolean m_bDrawBoundary;
    double m_dBackClipZ;
    double m_dFrontClipZ;
};
