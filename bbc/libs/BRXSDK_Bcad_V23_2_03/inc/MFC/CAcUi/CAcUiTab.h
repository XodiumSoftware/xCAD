// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiTab.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiTab: public CAdUiTab
{
    DECLARE_DYNAMIC(CAcUiTab);
public:
    CAcUiTab();
    virtual ~CAcUiTab();
protected:
    DECLARE_MESSAGE_MAP()
};