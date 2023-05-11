// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGi/AcGiKernelDescriptor.h"

class AcUniqueString;

/** _ */
class BRX_IMPORTEXPORT AcGsKernelDescriptor : public AcGiKernelDescriptor
{
public:
    void addSupport(const AcUniqueString*);
    bool requires(const AcUniqueString*) const;

public:
    static const AcUniqueString* k2DDrawing;
    static const AcUniqueString* k3DDrawing;
    static const AcUniqueString* k3DSelection;
    static const AcUniqueString* k3DRapidRTRendering;
};
