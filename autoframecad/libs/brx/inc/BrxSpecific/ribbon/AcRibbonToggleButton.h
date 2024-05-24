// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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

