// Copyright (C) 2006-2009 Menhirs NV. All rights reserved.
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