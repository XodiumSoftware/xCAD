// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmCircle3d.h"

namespace AModeler
{

class BM_IMPORTEXPORT PolygonVertexData
{
public:
    enum Type
    {
        kArc3d = 0,
        kArcByRadius,
        kArcByBulge,
        kFilletByRadius,
        kUnspecifiedCurve
    };

    bool isCenterLeft;
    Circle3d circle;
    Curve* curve;
    double bulge;
    int approx;
    Surface* surface;
    Type type;

    PolygonVertexData(Type);
    PolygonVertexData(Type,double,int);
    PolygonVertexData(Type,double,bool,int);
    PolygonVertexData(Type,const Circle3d&,int);

    bool isArc() const;
};

}
