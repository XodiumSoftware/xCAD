// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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