// Copyright (C) Menhirs NV. All rights reserved.
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