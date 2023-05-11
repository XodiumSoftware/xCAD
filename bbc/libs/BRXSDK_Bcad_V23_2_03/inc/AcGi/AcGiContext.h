// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcCm/AcCmEntityColor.h"
#include "AcDb/AcDbGlobal.h"
#include "AcRx/AcRxObject.h"

class AcGiGraphicsKernel;

/** _ */
class BRX_IMPORTEXPORT AcGiContext: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcGiContext);

    virtual AcCmEntityColor effectiveColor() const;
    virtual AcDb::LineWeight byBlockLineWeight() const;
    virtual AcDbDatabase* database() const = 0;
    virtual AcDbObjectId byBlockMaterialId() const;
    virtual AcDbObjectId byBlockPlotStyleNameId() const;
    virtual Adesk::Boolean isPlotGeneration() const = 0;
    virtual Adesk::Boolean isPsOut() const = 0;
    virtual bool isBoundaryClipping() const = 0;
    virtual bool isNesting() const;
    virtual bool supportsOwnerDraw();
    virtual bool supportsTrueTypeText();
    virtual void disableFastMoveDrag() const;

    //V17
    virtual AcGiGraphicsKernel& graphicsKernel();
};
