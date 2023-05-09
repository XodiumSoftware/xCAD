// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiBitmapButton.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiBitmapButton: public CAdUiBitmapButton
{
    DECLARE_DYNAMIC(CAcUiBitmapButton)
public:
    CAcUiBitmapButton();
    virtual ~CAcUiBitmapButton();
protected:
    DECLARE_MESSAGE_MAP()
};