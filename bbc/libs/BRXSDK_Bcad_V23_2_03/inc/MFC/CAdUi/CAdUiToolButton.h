// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiBitmapStatic.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiToolButton: public CAdUiBitmapButton
{
    DECLARE_DYNAMIC(CAdUiToolButton)
public:
    CAdUiToolButton();
    virtual ~CAdUiToolButton();
protected:
    DECLARE_MESSAGE_MAP()
};
