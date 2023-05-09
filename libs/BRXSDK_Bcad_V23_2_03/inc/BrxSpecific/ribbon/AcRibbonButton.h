// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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

