// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiSymbolComboBox: public CAcUiComboBox
{
    DECLARE_DYNAMIC(CAcUiSymbolComboBox);
public:
    CAcUiSymbolComboBox();
    virtual ~CAcUiSymbolComboBox();
protected:
    DECLARE_MESSAGE_MAP()
};
