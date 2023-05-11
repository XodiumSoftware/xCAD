// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmEntityColor.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"

/** _ */
struct AcDbMTextFragment
{
    AcCmEntityColor color;
    AcGePoint2d extents;
    AcGePoint3d location;
    AcGePoint3d overPoints[2];
    AcGePoint3d underPoints[2];
    AcGePoint3d strikePoints[2];
    AcGeVector3d direction;
    AcGeVector3d normal;
    ACHAR* bigfont;
    ACHAR* font;
    ACHAR* fontname;
    ACHAR* text;
    bool bold;
    bool italic;
    double capsHeight;
    double obliqueAngle;
    double trackingFactor;
    double widthFactor;
    unsigned int overlined;
    unsigned int stackBottom;
    unsigned int stackTop;
    unsigned int underlined;
    unsigned int strikethrough:1;
};

typedef int (*AcDbMTextEnum)(AcDbMTextFragment*,void*);
