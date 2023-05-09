// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"

class AcRibbonPaletteSet;
class AcRibbonControl;
class AcRibbonTab;
class AcRibbonPanel;
class AcRibbonPanelSource;
class AcRibbonItem;
class AcRibbonCombo;
class AcRibbonToggleButton;

class BRX_EXPORT AcRibbonReactor
{
    friend class AcRibbonReactorMgr;

protected:
    AcRibbonReactor();

public:
    virtual ~AcRibbonReactor();

    virtual void ribbonPaletteSetCreated(AcRibbonPaletteSet*) {}

    virtual void ribbonPaletteSetToBeDestroyed(AcRibbonPaletteSet*) {}

    virtual void ribbonPaletteSetSizeChanged(AcRibbonPaletteSet*, int width, int height) {}

    virtual void ribbonControlLoaded(AcRibbonControl*) {}

    virtual void ribbonVisibilityChanged(AcRibbonControl*, bool) {}

    virtual void ribbonPropertyChanged(AcRibbonTab*, 
        const AcRibbonUtils::RibbonPropertyEventArgs<AcString>&) {}

    virtual void ribbonPropertyChanged(AcRibbonPanel*,
        const AcRibbonUtils::RibbonPropertyEventArgs<AcString>& args) {}

    virtual void ribbonPropertyChanged(AcRibbonPanelSource*,
        const AcRibbonUtils::RibbonPropertyEventArgs<AcString>& args) {}

    virtual void ribbonPropertyChanged(AcRibbonItem*,
        const AcRibbonUtils::RibbonPropertyEventArgs<AcString>& args) {}

    virtual void ribbonPropertyChanged(AcRibbonCombo*,
        const AcRibbonUtils::RibbonPropertyEventArgs<int>&) {}

    virtual void ribbonPropertyChanged(AcRibbonCombo*,
        const AcRibbonUtils::RibbonPropertyEventArgs<bool>&) {}

    virtual void ribbonCheckStateChanged(AcRibbonToggleButton*,
        const AcRibbonUtils::RibbonPropertyEventArgs<bool>&) {}

private:
    void* m_pBrxImp;
};

