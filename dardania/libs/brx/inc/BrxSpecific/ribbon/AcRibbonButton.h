// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonCommandItem.h"

class AcRibbonItemImp;
class AcRibbonInternal;
class AcRibbonToggleButton;
class AcRibbonListButton;

class BRX_EXPORT AcRibbonButton : public AcRibbonCommandItem
{
    friend class AcRibbonInternal;
    friend class AcRibbonToggleButton;
    friend class AcRibbonListButton;

public:
    AcRibbonButton();
    virtual ~AcRibbonButton();

    void setMacroId(const ACHAR*);
    void macroId(AcString&) const;

private:
    AcRibbonButton(AcRibbonItemImp*);
};

