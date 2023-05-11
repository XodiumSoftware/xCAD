// Copyright (C) Menhirs NV. All rights reserved.
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
