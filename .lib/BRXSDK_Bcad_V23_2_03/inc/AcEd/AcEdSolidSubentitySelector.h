// Copyright (C) Menhirs NV. All rights reserved.
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