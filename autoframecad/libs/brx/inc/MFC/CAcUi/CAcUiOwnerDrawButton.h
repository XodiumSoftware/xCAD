// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiOwnerDrawButton.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiOwnerDrawButton: public CAdUiOwnerDrawButton
{
    DECLARE_DYNAMIC(CAcUiOwnerDrawButton)
public:
    CAcUiOwnerDrawButton();
    virtual ~CAcUiOwnerDrawButton();
protected:
    DECLARE_MESSAGE_MAP()
};