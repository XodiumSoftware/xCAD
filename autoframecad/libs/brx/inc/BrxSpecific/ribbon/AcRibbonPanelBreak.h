// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
