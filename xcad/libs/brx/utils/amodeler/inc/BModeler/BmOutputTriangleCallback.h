// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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