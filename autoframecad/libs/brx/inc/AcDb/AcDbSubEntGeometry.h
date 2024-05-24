// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once
#include "AcDb/AcDbDatabase.h"

class AcDbSubEntGeometry
{
private:
    AcDb::SubentType m_pType;
    AcGePoint3d m_position;
    AcGeCurve3d* m_pEdgeCurve;

public:
    AcDbSubEntGeometry() : m_pType(AcDb::kNullSubentType), m_pEdgeCurve(NULL) {}
    AcDbSubEntGeometry(const AcGePoint3d& point) : m_pType(AcDb::kVertexSubentType), m_position(point), m_pEdgeCurve(NULL) {}
    AcDbSubEntGeometry(AcGeCurve3d* pCurve3d) : m_pType(AcDb::kEdgeSubentType), m_pEdgeCurve(pCurve3d) {}
    AcDb::SubentType type() const { return m_pType; }
    AcGePoint3d point() const { return m_position; }
    AcGeCurve3d* curve() const { return m_pEdgeCurve; }
};
