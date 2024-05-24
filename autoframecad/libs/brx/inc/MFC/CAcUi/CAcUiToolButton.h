// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiToolButton.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiToolButton: public CAdUiToolButton
{
    DECLARE_DYNAMIC(CAcUiToolButton)
public:
    CAcUiToolButton();
    virtual ~CAcUiToolButton();
protected:
    DECLARE_MESSAGE_MAP()
};
