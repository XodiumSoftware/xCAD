// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonButton.h"

class AcRibbonItemImp;

class BRX_EXPORT AcRibbonToggleButton : public AcRibbonButton
{
    friend class AcRibbonInternal;

public:
    AcRibbonToggleButton();
    virtual ~AcRibbonToggleButton();

    void setCheckState(bool state);
    bool isChecked() const;

private:
    AcRibbonToggleButton(AcRibbonItemImp*);
};

