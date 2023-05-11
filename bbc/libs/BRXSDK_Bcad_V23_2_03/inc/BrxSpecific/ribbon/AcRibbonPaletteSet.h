// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
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
