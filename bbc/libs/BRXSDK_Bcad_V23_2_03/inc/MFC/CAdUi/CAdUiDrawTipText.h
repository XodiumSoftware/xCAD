// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiDrawTipText
{
public:
    CAdUiDrawTipText(CDC&,CRect&,CString&);
    CDC& m_dc;
    CRect& m_rect;
    CString& m_text;
};
