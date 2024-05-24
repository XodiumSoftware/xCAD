// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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