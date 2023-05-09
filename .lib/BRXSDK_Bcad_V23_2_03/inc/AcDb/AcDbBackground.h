// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"

/** _ */
class BRX_EXPORT AcDbBackground: public AcDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbBackground);

    virtual ~AcDbBackground();

    virtual AcGiDrawable* drawable();
};
