// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrEntity.h"

class AcBrComplex: public AcBrEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcBrComplex);

    AcBrComplex();
    AcBrComplex(const AcBrComplex&);
    ~AcBrComplex();

    AcBrComplex& operator=(const AcBrComplex&);
};

