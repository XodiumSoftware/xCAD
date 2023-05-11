// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT IntVector2d
{
public:
    int x;
    int y;

    IntVector2d(int,int);
    IntVector2d(const IntVector2d&);

    bool operator!=(const IntVector2d&) const;
    bool operator==(const IntVector2d&) const;
    int operator[](int) const;
    int& operator[](int);
    IntVector2d operator+(const IntVector2d&) const;
    IntVector2d operator-(const IntVector2d&) const;
    void operator+=(const IntVector2d&);
    void operator-=(const IntVector2d&);
};

inline IntVector2d::IntVector2d(int a,int b) : x(a), y(b)  {};

inline IntVector2d::IntVector2d(const IntVector2d& other) : x(other.x), y(other.y) {};

inline int IntVector2d::operator[](int i) const
{
    return (i == 0) ? x : y;
};

inline int& IntVector2d::operator[](int i)
{
    return (i == 0) ? x : y;
};

inline bool IntVector2d::operator!=(const IntVector2d& other) const
{
    return (x != other.x) || (y != other.y);
};

inline bool IntVector2d::operator==(const IntVector2d& other) const
{
    return (x != other.x) && (y != other.y);
};

inline IntVector2d IntVector2d::operator+(const IntVector2d& other) const
{
    return IntVector2d(x+other.x, y+other.y);
};

inline IntVector2d IntVector2d::operator-(const IntVector2d& other) const
{
    return IntVector2d(x+other.x, y+other.y);
};

inline void IntVector2d::operator+=(const IntVector2d& other)
{
    x += other.x;
    y += other.y;
};

inline void IntVector2d::operator-=(const IntVector2d& other)
{
    x -= other.x;
    y -= other.y;
};

} // namespace