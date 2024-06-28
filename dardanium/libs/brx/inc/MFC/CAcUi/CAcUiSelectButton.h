// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiPickButton.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiSelectButton: public CAcUiPickButton
{
    DECLARE_DYNAMIC(CAcUiSelectButton)
public:
    CAcUiSelectButton();
    virtual ~CAcUiSelectButton();
protected:
    DECLARE_MESSAGE_MAP()
};
