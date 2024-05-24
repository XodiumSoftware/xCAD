// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiKernelDescriptor.h"

/** _ */
class BRX_IMPORTEXPORT AcGiGraphicsKernel
{
public:
    virtual ~AcGiGraphicsKernel();
    virtual const AcGiKernelDescriptor& getDescriptor() const;
};
