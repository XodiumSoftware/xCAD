// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/Size.h"
#include "Atil/Offset.h"


namespace Atil
{;

class Point2d;


class ATIL_IMPORTEXPORT BoundingBox
{
public:
    BoundingBox() {}
    BoundingBox(Offset org, Size sz) : m_origin(org), m_extent(SizeOps::getHighOffset(org, sz)) {}
    BoundingBox(Offset org, Offset ext) : m_origin(org), m_extent(ext) {}
    BoundingBox(int pts, const Offset* rofs) { set(pts, rofs); }
    ~BoundingBox() {}
    Offset clipToBounds(const Offset& ofs) const;
    bool contains(const BoundingBox& rh) const { return (inBounds(rh.m_origin) && inBounds(rh.m_extent)); }
    void expandToInclude(Offset ofs)
    {
        if (ofs.x < m_origin.x) { m_origin.x = ofs.x; } else if (ofs.x > m_extent.x) { m_extent.x = ofs.x; }
        if (ofs.y < m_origin.y) { m_origin.y = ofs.y; } else if (ofs.y > m_extent.y) { m_extent.y = ofs.y; }
    }
    void expandToInclude(int pts, const Offset* rofs) { for (int ip = 0; ip < pts; ++ip) expandToInclude(rofs[ip]); }
    void getExtents(Offset& org, Offset& ext) const { org = m_origin; ext = m_extent; }
    bool getIntersection(const BoundingBox& rh, BoundingBox& lh) const;
    bool getIntersection(int pts, const Point2d* rpoly, BoundingBox& lh) const;
    void getUnion(const BoundingBox& rh, BoundingBox& lh) const;
    bool inBounds(const Offset& ofs) const { return inBounds(ofs.x, ofs.y); }
    bool inBounds(int x, int y) const { return (x >= m_origin.x && y >= m_origin.y && x <= m_extent.x && y <= m_extent.y); }
    bool intersects(const BoundingBox& rh) const;
    Offset origin() const { return m_origin; }
    void set(Offset org, Size sz) { m_origin = org; m_extent = SizeOps::getHighOffset(org, sz); }
    void set(Offset org, Offset ext) { m_origin = org; m_extent = ext; }
    void set(int pts, const Offset* rofs)
    {
        if (pts <= 0) { m_origin.set(0, 0); m_extent.set(0, 0); return; }
        m_origin = *rofs; m_extent = *rofs;
        for (int ip = 1; ip < pts; ++ip) expandToInclude(rofs[ip]);
    }
    Size size() const { return SizeOps::getSizeOf(m_extent, m_origin); }

private:
    Offset m_origin;
    Offset m_extent;
};


} //namespace Atil
