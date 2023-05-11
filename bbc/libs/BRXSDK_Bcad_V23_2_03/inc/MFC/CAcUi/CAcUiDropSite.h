// Copyright (C) Menhirs NV. All rights reserved.
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
