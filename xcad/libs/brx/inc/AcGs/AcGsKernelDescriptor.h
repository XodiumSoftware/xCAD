// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGi/AcGiKernelDescriptor.h"

class AcUniqueString;

/** _ */
class BRX_IMPORTEXPORT AcGsKernelDescriptor : public AcGiKernelDescriptor
{
public:
    void addSupport(const AcUniqueString*);
    bool hasRequirement(const AcUniqueString*) const;
#ifndef __cpp_concepts
    bool requires(const AcUniqueString* req) const { return hasRequirement(req); } //deprecated
#endif

public:
    static const AcUniqueString* k2DDrawing;
    static const AcUniqueString* k3DDrawing;
    static const AcUniqueString* k3DSelection;
    static const AcUniqueString* k3DRapidRTRendering;
};
