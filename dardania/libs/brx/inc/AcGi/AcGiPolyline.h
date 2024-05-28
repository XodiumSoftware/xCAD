// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcGiPolyline: public AcRxObject
{
public:
    enum LinetypeGeneration
    {
      kPerSegment = 0,
      kEndToEnd = 1,
    };

    ACRX_DECLARE_MEMBERS(AcGiPolyline);

    AcGiPolyline();
    AcGiPolyline(Adesk::UInt32, AcGePoint3d*, AcGeVector3d* = NULL, Adesk::LongPtr = -1);
    ~AcGiPolyline();

    const AcGePoint3d*  vertexList() const;
    const AcGeVector3d* normal() const;
    const Adesk::LongPtr* subEntMarkerList() const;
    const bool* arcSegmentFlags() const;

    Adesk::UInt32 points() const;
    Adesk::LongPtr baseSubEntMarker() const;
    LinetypeGeneration linetypeGen() const;

    void setNormal(const AcGeVector3d*);
    void setVertexList(Adesk::UInt32, const AcGePoint3d*);
    void setArcSegmentFlags(const bool*);
    void setLinetypeGen(LinetypeGeneration);
    void setBaseSubEntMarker(Adesk::LongPtr);
    void setSubEntMarkerList(const Adesk::LongPtr*);
};
