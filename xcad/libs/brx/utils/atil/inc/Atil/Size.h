// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/Offset.h"


namespace Atil
{;


class ATIL_IMPORTEXPORT Size
{
public:
    Int32 width;
    Int32 height;

    Size() : width(0), height(0) {}
    Size(Int32 _width, Int32 _height) : width(_width), height(_height) {}
    Size(const Size& rh) : width(rh.width), height(rh.height) {}
    ~Size() {}

    bool operator <= (const Size& rh) const { return (width <= rh.width && height <= rh.height); }
    bool operator >= (const Size& rh) const { return (width >= rh.width && height >= rh.height); }
    bool operator == (const Size& rh) const { return (width == rh.width && height == rh.height); }
    bool operator != (const Size& rh) const { return (width != rh.width || height != rh.height); }
    const Size& operator = (const Size& rh) { width = rh.width; height = rh.height; return *this; }
    const Size& set(Int32 _width, Int32 _height) { width = _width; height = _height; return *this; }
    const Size& grow(Int32 _width, Int32 _height) { width += _width; height += _height; return *this; }
    const Size& grow(Int32 op) { width = op; height = op; return *this; }
    const Size& shrink(Int32 _width, Int32 _height) { width -= _width; height -= _height; return *this; }
    const Size& shrink(Int32 op) { width -= op; height -= op; return *this; }
};


namespace SizeOps
{

inline Size getSizeOf(const Offset& hi, const Offset& lo)
{
    return Size(hi.x - lo.x + 1, hi.y - lo.y + 1);
}

inline Offset getHighOffset(const Size& ext)
{
    return Offset(ext.width - 1, ext.height - 1);
}

inline Offset getHighOffset(const Offset& org, const Size& ext)
{
    return Offset(org.x + ext.width - 1, org.y + ext.height - 1);
}

} //namespace SizeOps


} //namespace Atil
