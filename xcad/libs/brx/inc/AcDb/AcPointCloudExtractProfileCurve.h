// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class BRX_IMPORTEXPORT ProfileCurve2d
{
public:
    enum ProfileurveType
    {
        kLineSeg = 0,
        kArc
    };

private:
    AcGeLineSeg2d m_segment;
    AcGeCircArc2d m_arcSeg;
    ProfileurveType m_curveType;

public:
    ProfileCurve2d() : m_curveType(kLineSeg) {}
    ProfileCurve2d(const AcGeLineSeg2d& lineSeg) : m_segment(lineSeg), m_curveType(kLineSeg) {}
    ProfileCurve2d(const AcGeCircArc2d& arcSeg) : m_arcSeg(arcSeg), m_curveType(kArc) {}
    bool isSegment() const { return (m_curveType == kLineSeg); }
    bool isArc() const { return (m_curveType == kArc); }
    AcGeLineSeg2d lineSeg() const { return m_segment; }
    void setLineSeg(const AcGeLineSeg2d& lineSeg) { m_segment = lineSeg; m_curveType = kLineSeg; }
    AcGeCircArc2d arc() const { return m_arcSeg; }
    void setArc(const AcGeCircArc2d& arcSeg) { m_arcSeg = arcSeg; m_curveType = kArc; }
};

class BRX_IMPORTEXPORT AcPointCloudExtractResult
{
public:
    AcArray<ProfileCurve2d> Curves;
    AcGeMatrix3d transform;
    AcGePlane ProjectedPlane;
};
