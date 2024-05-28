// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonItem.h"

class AcRibbonItemImp;

class BRX_EXPORT AcRibbonList : public AcRibbonItem
{
    friend class AcRibbonCombo;

public:
    virtual ~AcRibbonList() = 0;

    AcRibbonUtils::AcResult addItem(AcRibbonItem*);
    AcRibbonUtils::AcResult removeItem(AcRibbonItem*);

    AcRibbonUtils::AcResult items(AcItemCollection&);

    AcRibbonUtils::AcResult setCurrentItem(AcRibbonItem*);
    AcRibbonItem* currentItem() const;

private:
    AcRibbonList(AcRibbonItemImp*);
};

class BRX_EXPORT AcRibbonCombo : public AcRibbonList
{
    friend class AcRibbonInternal;

public:
    AcRibbonCombo();
    virtual ~AcRibbonCombo();

private:
    AcRibbonCombo(AcRibbonItemImp*);
};

