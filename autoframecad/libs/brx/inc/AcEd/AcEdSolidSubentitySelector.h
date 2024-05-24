// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSubentId.h"

/** _ */
class BRX_IMPORTEXPORT AcEdSolidSubentitySelector
{
public:
    AcEdSolidSubentitySelector();
    ~AcEdSolidSubentitySelector();

    Acad::ErrorStatus selectFaces(AcDbObjectId&,AcArray<AcDbSubentId*>&);
};
