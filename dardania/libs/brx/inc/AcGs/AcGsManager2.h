// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcGs/AcGsManager.h"

/** _ */
class BRX_IMPORTEXPORT AcGsManager2 : public AcGsManager
{
public:
    AcGsManager2() {}
    virtual ~AcGsManager2() {}

    virtual bool activeGraphicsKernels(AcArray<AcGsGraphicsKernel*>&) const = 0;
    virtual bool activeModels(AcArray<AcGsModel*>&) const = 0;
    virtual bool activeModels(const AcDbDatabase*, AcArray<AcGsModel*>&) const = 0;
    virtual AcGsModel* gsHighlightModel(AcGsGraphicsKernel*, const AcDbDatabase*) const = 0;
    virtual void setGsHighlightModel(AcGsGraphicsKernel*, const AcDbDatabase*, AcGsModel*) = 0;
    virtual bool hasGsModel(AcGsGraphicsKernel*, const AcDbDatabase*) const = 0;
    virtual AcGsModel* gsModel(AcGsGraphicsKernel*, const AcDbDatabase*) const = 0;
    virtual void setGsModel(AcGsGraphicsKernel*, const AcDbDatabase*, AcGsModel*) = 0;
};
