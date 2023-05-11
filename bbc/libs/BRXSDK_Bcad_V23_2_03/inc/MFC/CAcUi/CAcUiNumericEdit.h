// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiEdit.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiNumericEdit: public CAcUiEdit
{
    DECLARE_DYNAMIC(CAcUiNumericEdit)
public:
    CAcUiNumericEdit();
    virtual void SetStyleMask(DWORD);
    virtual ~CAcUiNumericEdit();
protected:
    DECLARE_MESSAGE_MAP()
};