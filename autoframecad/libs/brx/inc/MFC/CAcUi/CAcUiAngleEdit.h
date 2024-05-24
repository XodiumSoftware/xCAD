// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
