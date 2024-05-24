// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcUniqueString.h"

/** _ */
class BRX_IMPORTEXPORT AcGiKernelDescriptor : public AcArray<const AcUniqueString*>
{
public:
    void addRequirement(const AcUniqueString*);
    bool supports(const AcUniqueString*) const;
    bool supports(const AcGiKernelDescriptor&) const;
};
