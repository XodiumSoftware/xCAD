// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrElement.h"

class AcGeVector3d;

class AcBrElement2d: public AcBrElement
{
public:
    ACRX_DECLARE_MEMBERS(AcBrElement2d);

    AcBrElement2d();
    AcBrElement2d(const AcBrElement2d&);
    ~AcBrElement2d();    

    AcBr::ErrorStatus getNormal(AcGeVector3d&) const;

    AcBrElement2d& operator=(const AcBrElement2d&);
};
