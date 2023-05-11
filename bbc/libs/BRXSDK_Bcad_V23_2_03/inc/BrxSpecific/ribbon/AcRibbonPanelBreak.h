// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"
#include "AcRibbonItem.h"

class AcRibbonItemImp;


class BRX_EXPORT AcRibbonPanelBreak : public AcRibbonItem
{
    friend class AcRibbonInternal;

public:
    AcRibbonPanelBreak();
    virtual ~AcRibbonPanelBreak();

private:
    AcRibbonPanelBreak(AcRibbonItemImp*);
};
