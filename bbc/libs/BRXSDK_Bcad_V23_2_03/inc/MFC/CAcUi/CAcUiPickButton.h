// Copyright (C) Menhirs NV. All rights reserved.
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
