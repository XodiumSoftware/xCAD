// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT OutputTriangleCallback
{
public:
    enum
    {
        kMaxTriStripLength = 200
    };

    virtual ~OutputTriangleCallback();

    virtual void outputTriangle(Edge*[],int) = 0;
    virtual void outputTriStrip(Edge*[],int,bool) = 0;
};

}