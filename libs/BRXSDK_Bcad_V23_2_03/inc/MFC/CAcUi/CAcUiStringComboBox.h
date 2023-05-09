// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiStringComboBox: public CAcUiComboBox
{
    DECLARE_DYNAMIC(CAcUiStringComboBox);
public:
    CAcUiStringComboBox();
    virtual ~CAcUiStringComboBox();
protected:
    DECLARE_MESSAGE_MAP()
};
