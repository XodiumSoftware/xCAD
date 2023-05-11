// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiToolButton.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiToolButton: public CAdUiToolButton
{
    DECLARE_DYNAMIC(CAcUiToolButton)
public:
    CAcUiToolButton();
    virtual ~CAcUiToolButton();
protected:
    DECLARE_MESSAGE_MAP()
};
