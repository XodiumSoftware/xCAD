// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiBitmapButton.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiPickButton: public CAdUiBitmapButton
{
    DECLARE_DYNAMIC(CAcUiPickButton)
public:
    CAcUiPickButton();
    virtual ~CAcUiPickButton();
protected:
    virtual BOOL OnLoadBitmap(LPCTSTR);

    DECLARE_MESSAGE_MAP()
};
