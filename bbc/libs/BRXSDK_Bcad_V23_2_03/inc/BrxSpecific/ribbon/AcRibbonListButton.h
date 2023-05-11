// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonButton.h"

class AcRibbonItem;
class AcRibbonItemImp;
class AcRibbonInternal;
class AcRibbonSplitButton;

class BRX_EXPORT AcRibbonListButton : public AcRibbonButton
{
    friend class AcRibbonInternal;
    friend class AcRibbonSplitButton;

public:
    AcRibbonListButton();
    virtual ~AcRibbonListButton();

    AcRibbonUtils::AcResult setCurrentItem(AcRibbonItem*);
    AcRibbonButton* currentItem() const;

    AcRibbonUtils::AcResult addItem(AcRibbonItem*);
    AcRibbonUtils::AcResult removeItem(AcRibbonItem*);
    
    void items(AcItemCollection&) const;

private:
    AcRibbonListButton(AcRibbonItemImp*);
};

