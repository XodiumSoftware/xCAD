// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiBitmapStatic.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiToolButton: public CAdUiBitmapButton
{
    DECLARE_DYNAMIC(CAdUiToolButton)
public:
    CAdUiToolButton();
    virtual ~CAdUiToolButton();
protected:
    DECLARE_MESSAGE_MAP()
};
