// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
