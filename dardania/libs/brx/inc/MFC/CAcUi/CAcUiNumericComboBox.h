// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
