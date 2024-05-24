// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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

