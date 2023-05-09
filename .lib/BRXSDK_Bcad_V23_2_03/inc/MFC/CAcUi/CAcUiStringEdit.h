// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiEdit.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiStringEdit: public CAcUiEdit
{
    DECLARE_DYNAMIC(CAcUiStringEdit)
public:
    CAcUiStringEdit();
    virtual void SetStyleMask(DWORD);
    virtual ~CAcUiStringEdit();
protected:
    DECLARE_MESSAGE_MAP()
};
