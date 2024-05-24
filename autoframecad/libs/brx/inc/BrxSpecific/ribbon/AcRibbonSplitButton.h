// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonListButton.h"

class AcRibbonItemImp;

class BRX_EXPORT AcRibbonSplitButton : public AcRibbonListButton
{
    friend class AcRibbonInternal;

public:
    AcRibbonSplitButton();
    virtual ~AcRibbonSplitButton();

    void setButtonBehavior(AcRibbonUtils::RibbonSplitButtonBehavior behavior);
    AcRibbonUtils::RibbonSplitButtonBehavior buttonBehavior() const;

private:
    AcRibbonSplitButton(AcRibbonItemImp*);
};

