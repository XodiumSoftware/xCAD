// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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
