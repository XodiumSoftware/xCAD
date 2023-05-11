// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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

