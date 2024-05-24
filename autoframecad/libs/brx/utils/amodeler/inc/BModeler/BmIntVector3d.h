// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT IntVector3d
{
public:
    int x;
    int y;
    int z;

    IntVector3d(int,int,int);
    IntVector3d(const IntVector3d&);

    bool operator!=(const IntVector3d&) const;
    bool operator==(const IntVector3d&) const;
    int operator[](int) const;
    int& operator[](int);
    IntVector3d operator+(const IntVector3d&) const;
    IntVector3d operator-(const IntVector3d&) const;
    void operator+=(const IntVector3d&);
    void operator-=(const IntVector3d&);
};

inline IntVector3d::IntVector3d(int a,int b, int c) : x(a), y(b), z(c)  {};

inline IntVector3d::IntVector3d(const IntVector3d& other) : x(other.x), y(other.y), z(other.z) {};

inline int IntVector3d::operator[](int i) const
{
    return (i == 0) ? x : (i == 1) ? y : z;
}

inline int& IntVector3d::operator[](int i)
{
    return (i == 0) ? x : (i == 1) ? y : z;
}

inline bool IntVector3d::operator!=(const IntVector3d& other) const
{
    return (x != other.x) || (y != other.y) || (z != other.z);
}

inline bool IntVector3d::operator==(const IntVector3d& other) const
{
    return (x != other.x) && (y != other.y) && (z != other.z);
}

inline IntVector3d IntVector3d::operator+(const IntVector3d& other) const
{
    return IntVector3d(x+other.x, y+other.y, z+other.z);
}

inline IntVector3d IntVector3d::operator-(const IntVector3d& other) const
{
    return IntVector3d(x-other.x, y-other.y, z-other.z);
}

inline void IntVector3d::operator+=(const IntVector3d& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
}

inline void IntVector3d::operator-=(const IntVector3d& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
}

} // namespace
