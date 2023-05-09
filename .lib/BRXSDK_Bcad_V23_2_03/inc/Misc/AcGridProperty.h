// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcCm/AcCmColor.h"


struct AcGridProperty
{
    AcDb::GridProperty  mnPropMask;
    AcDb::GridLineStyle mnLineStyle;
    AcDb::LineWeight    mnLineWeight;
    AcDbHardPointerId   mLinetype;
    AcCmColor           mColor;
    AcDb::Visibility    mnVisibility;
    double              mfDoubleLineSpacing;
};
