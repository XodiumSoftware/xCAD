// Copyright (C) Menhirs NV. All rights reserved.
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