// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"

class AcRibbonTab;
class AcRibbonControlImp;
class AcRibbonPanel;
class AcRibbonItem;

typedef AcArray <AcRibbonTab*> AcTabCollection;

class BRX_EXPORT AcRibbonControl
{
    friend class AcRibbonPaletteSetImp;
    friend class AcRibbonControlImp;

public:
    virtual AcRibbonUtils::AcResult addTab(AcRibbonTab*) = 0;
    virtual AcRibbonUtils::AcResult removeTab(AcRibbonTab*) = 0;
    virtual AcRibbonUtils::AcResult insertTabAt(AcRibbonTab*, unsigned int position) = 0;

    virtual AcRibbonUtils::AcResult tabs(AcTabCollection&) = 0;

    virtual void setActiveTab(AcRibbonTab*) = 0;
    virtual AcRibbonTab* activeTab() = 0;

    virtual void clearTabs() = 0;

    virtual AcRibbonTab* findTab(const ACHAR* id) = 0;
    virtual AcRibbonPanel* findPanel(const ACHAR* id, bool searchOnlyInActiveTab) = 0;
    virtual AcRibbonPanel* findPanel(const ACHAR* id, AcRibbonTab*& pParent) = 0;
    virtual AcRibbonItem* findItem(const ACHAR* id, bool searchOnlyInActiveTab) = 0;
    virtual AcRibbonItem* findItem(const ACHAR* id,
                                    bool searchOnlyInActiveTab,
                                    bool searchSubItems) = 0;
    virtual AcRibbonItem* findItem(const ACHAR* id,
                                    bool searchOnlyInActiveTab,
                                    AcRibbonPanel*& pParentPanel,
                                    AcRibbonTab*& pParentTab) = 0;
    virtual AcRibbonItem* findItem(const ACHAR* id,
                                    bool searchOnlyInActiveTab,
                                    AcRibbonPanel*& pParentPanel,
                                    AcRibbonTab*& pParentTab,
                                    bool searchSubItems) = 0;

private:
    AcRibbonControl();
    AcRibbonControl(const AcRibbonControl&) = default;
    AcRibbonControl& operator= (const AcRibbonControl&) = default;
    virtual ~AcRibbonControl();
};
