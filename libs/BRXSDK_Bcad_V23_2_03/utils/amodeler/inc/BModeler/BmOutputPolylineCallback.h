// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT OutputPolylineCallback
{
public:
    virtual ~OutputPolylineCallback();

    virtual void outputArc(Edge*,const Point3d&,double,double,double,bool) = 0;
    virtual void outputPolyline(Edge*[],const Point3d[],const double[],int,bool,bool) = 0;
};

}