// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiBitmapStatic.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiDropSite: public CAdUiBitmapStatic
{
    DECLARE_DYNAMIC(CAdUiDropSite)
public:
    CAdUiDropSite();
    virtual ~CAdUiDropSite();
protected:
    DECLARE_MESSAGE_MAP()
};
