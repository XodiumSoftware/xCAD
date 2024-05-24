// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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

