// Copyright (C) Menhirs NV. All rights reserved.
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
