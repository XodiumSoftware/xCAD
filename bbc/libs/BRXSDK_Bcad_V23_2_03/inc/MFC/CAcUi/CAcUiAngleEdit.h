// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiEdit.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiAngleEdit: public CAcUiEdit
{
    DECLARE_DYNAMIC(CAcUiAngleEdit)
public:
    CAcUiAngleEdit();
    virtual ~CAcUiAngleEdit();

    virtual void SetStyleMask(DWORD);
protected:
    DECLARE_MESSAGE_MAP()
};
