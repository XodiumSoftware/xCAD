// Copyright (C) Menhirs NV. All rights reserved.
#pragma once
#include "AcGe/AcGeGlobal.h"
#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxObject.h"

// BRX START
class OdGiPolyline;
// BRX END

/** _ */
class BRX_IMPORTEXPORT AcGiPolyline: public AcRxObject
{
private:
    // BRX START
    OdGiPolyline* m_pBrxImp;
public:
    OdGiPolyline* getOdEntity() const { return m_pBrxImp; };
    // BRX END

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

private:
    Adesk::UInt32      m_numVertices;
    const AcGePoint3d* m_vertices;
    const AcGeVector3d* m_normal;
    LinetypeGeneration  m_ltypeGeneration;
    Adesk::LongPtr  m_numSubentMarkers;
    const Adesk::LongPtr* m_subentMarkere;
    const bool* m_arcSegmentFlags;
};
