// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiEdit.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiSymbolEdit: public CAcUiEdit
{
    DECLARE_DYNAMIC(CAcUiSymbolEdit)
public:
    CAcUiSymbolEdit();
    virtual void SetStyleMask(DWORD);
    virtual ~CAcUiSymbolEdit();
protected:
    DECLARE_MESSAGE_MAP()
};