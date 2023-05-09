// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiKernelDescriptor.h"

/** _ */
class BRX_IMPORTEXPORT AcGiGraphicsKernel
{
public:
    virtual ~AcGiGraphicsKernel();
    virtual const AcGiKernelDescriptor& getDescriptor() const;
};
