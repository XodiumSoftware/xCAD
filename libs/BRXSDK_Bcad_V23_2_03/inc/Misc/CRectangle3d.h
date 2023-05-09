// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePoint3d.h"

/** _ */
class BRX_IMPORTEXPORT CRectangle3d
{
public:
    AcGePoint3d lowLeft;
    AcGePoint3d lowRight;
    AcGePoint3d upLeft;
    AcGePoint3d upRight;
};