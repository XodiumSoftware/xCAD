// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcRibbonBase.h"

class AcRibbonPanelImp;
class AcRibbonPanelSource;
class AcRibbonItem;

class BRX_EXPORT AcRibbonPanel : public AcRibbonBase
{
    friend class AcRibbonInternal;

public:
    AcRibbonPanel();
    virtual ~AcRibbonPanel();

    bool setSource(AcRibbonPanelSource*);
    AcRibbonPanelSource* source() const;

    bool isEnabled() const;
    bool enable(bool isEnabled);

    bool isVisible() const;
    bool setVisible(bool isVisible);

    AcRibbonTab* tab() const;

    AcRibbonItem* findItem(const ACHAR* id);
    AcRibbonItem* findItem(const ACHAR* id, bool searchSubItems);

private:
    AcRibbonPanel(AcRibbonPanelImp*);

private:
    AcRibbonPanelImp* m_pBrxImp;
};

