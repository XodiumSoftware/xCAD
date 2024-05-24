// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiDockControlBar.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiDockControlBar: public CAdUiDockControlBar
{
    DECLARE_DYNCREATE(CAcUiDockControlBar);
public:
    CAcUiDockControlBar() {}
protected:
    virtual bool CanFrameworkTakeFocus();
};
