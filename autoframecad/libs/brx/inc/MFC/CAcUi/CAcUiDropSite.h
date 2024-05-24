// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiDropSite.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiDropSite: public CAdUiDropSite
{
    DECLARE_DYNAMIC(CAcUiDropSite)
public:
    CAcUiDropSite();
    virtual ~CAcUiDropSite();
protected:
    DECLARE_MESSAGE_MAP()
};
