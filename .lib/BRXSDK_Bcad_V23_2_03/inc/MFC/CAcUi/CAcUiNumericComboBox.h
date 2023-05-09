// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiNumericComboBox: public CAcUiComboBox
{
    DECLARE_DYNAMIC(CAcUiNumericComboBox);
public:
    CAcUiNumericComboBox();
    virtual ~CAcUiNumericComboBox();
protected:
    DECLARE_MESSAGE_MAP()
};
