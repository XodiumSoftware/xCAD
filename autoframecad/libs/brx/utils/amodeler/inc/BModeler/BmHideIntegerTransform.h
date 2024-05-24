// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmGlobal.h"

namespace AModeler
{

class BM_IMPORTEXPORT HideIntegerTransform
{
public:
    double mRx;
    double mRy;
    double mRz;
    double mSx;
    double mSy;
    double mSz;

    Point3d projectedIntToProjectedDouble(IntPoint3d) const;
};

}