// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonItem.h"

class AcRibbonItemImp;

class BRX_EXPORT AcRibbonRowPanel : public AcRibbonItem
{
    friend class AcRibbonInternal;

public:
    AcRibbonRowPanel();
    virtual ~AcRibbonRowPanel();

    AcRibbonUtils::AcResult addItem(AcRibbonItem*);
    AcRibbonUtils::AcResult removeItem(AcRibbonItem*);

    AcRibbonUtils::AcResult items(AcItemCollection&);

private:
    AcRibbonRowPanel(AcRibbonItemImp*);
};

class BRX_EXPORT AcRibbonRowBreak : public AcRibbonItem
{
    friend class AcRibbonInternal;

public:
    AcRibbonRowBreak();
    virtual ~AcRibbonRowBreak();

private:
    AcRibbonRowBreak(AcRibbonItemImp*);
};
