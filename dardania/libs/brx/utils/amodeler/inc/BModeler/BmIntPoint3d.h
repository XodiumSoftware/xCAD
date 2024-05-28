// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"
#include "BmIntPoint2d.h"
#include "BmIntVector3d.h"

namespace AModeler
{

class BM_IMPORTEXPORT IntPoint3d
{
public:
    static const IntPoint3d kNull;

    int x;
    int y;
    int z;

    IntPoint3d();
    IntPoint3d(int,int,int);
    IntPoint3d(const IntPoint3d&);

    const IntPoint2d& toIntPoint2d() const;

    bool operator!=(const IntPoint3d&) const;
    bool operator==(const IntPoint3d&) const;
    int operator[](int) const;
    int& operator[](int);
    IntPoint3d operator+(const IntPoint3d&) const;
    IntPoint3d operator+(const IntVector3d&) const;
    IntPoint3d operator-() const;
    IntPoint3d operator-(const IntVector3d&) const;
    IntVector3d operator-(const IntPoint3d&) const;
    void operator+=(const IntPoint3d&);
    void operator+=(const IntVector3d&);
    void operator-=(const IntPoint3d&);
    void operator-=(const IntVector3d&);
};

inline IntPoint3d::IntPoint3d() :  x(0), y(0), z(0) {};

inline IntPoint3d::IntPoint3d(int a, int b, int c) : x(a), y(b), z(c) {};

inline IntPoint3d::IntPoint3d(const IntPoint3d& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

inline const IntPoint2d& IntPoint3d::toIntPoint2d() const
{
    return *(reinterpret_cast<const IntPoint2d*>(this));
}

inline bool IntPoint3d::operator!=(const IntPoint3d& other) const
{
    return (x != other.x) || (y != other.y) || (z != other.z);
}

inline bool IntPoint3d::operator==(const IntPoint3d& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z);
}

inline int IntPoint3d::operator[](int i) const
{
    return (i == 0) ? x : (i == 1) ? y : z;
}

inline int& IntPoint3d::operator[](int i)
{
    return (i == 0) ? x : (i == 1) ? y : z;
}

inline IntPoint3d IntPoint3d::operator+(const IntPoint3d& other) const
{
    return IntPoint3d(x+other.x, y+other.y, z+other.z);
}

inline IntPoint3d IntPoint3d::operator+(const IntVector3d& other) const
{
    return IntPoint3d(x+other.x, y+other.y, z+other.z);
}

inline IntPoint3d IntPoint3d::operator-() const
{
    return IntPoint3d(-x, -y, -z);
}

inline IntPoint3d IntPoint3d::operator-(const IntVector3d& other) const
{
    return IntPoint3d(x-other.x, y-other.y, z-other.z);
}

inline IntVector3d IntPoint3d::operator-(const IntPoint3d& other) const
{
    return IntVector3d(x-other.x, y-other.y, z-other.z);
}

inline void IntPoint3d::operator+=(const IntPoint3d& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
}

inline void IntPoint3d::operator+=(const IntVector3d& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
}

inline void IntPoint3d::operator-=(const IntPoint3d& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

inline void IntPoint3d::operator-=(const IntVector3d& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

} // namespace