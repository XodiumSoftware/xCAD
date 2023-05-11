// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxObject.h"

class AcDbDatabase;
class AcDbViewport;
class AcDbAnnotationScale;

/** _ */
class BRX_EXPORT AcDbAnnotationScaleReactor : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAnnotationScaleReactor);

public:
    virtual void annotationScaleChanged(const AcDbDatabase*, const AcDbViewport*, const AcDbAnnotationScale*, const bool bInitializing);
};

BRX_EXPORT bool acdbAddAnnotationScaleReactor(AcDbAnnotationScaleReactor*);
BRX_EXPORT bool acdbRemoveAnnotationScaleReactor(AcDbAnnotationScaleReactor*);
