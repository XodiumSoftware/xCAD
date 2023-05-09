// Copyright (C) Menhirs NV. All rights reserved.
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
