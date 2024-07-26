// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRibbonBase.h"

class AcRibbonControl;

class BRX_EXPORT AcRibbonPaletteSet
{
    friend class AcRibbonPaletteSetImp;
    friend class AcRibbonServices;

public:
    virtual AcRibbonControl* ribbonControl()  = 0;

    virtual bool             show(bool bShow) = 0;
    virtual bool             isShown() const  = 0;

private:
    AcRibbonPaletteSet();
    AcRibbonPaletteSet(const AcRibbonPaletteSet&) = delete;
    AcRibbonPaletteSet& operator= (const AcRibbonPaletteSet&) = delete;
    virtual ~AcRibbonPaletteSet();
};
