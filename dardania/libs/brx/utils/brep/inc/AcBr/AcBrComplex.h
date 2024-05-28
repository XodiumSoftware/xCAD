// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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

