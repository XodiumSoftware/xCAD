// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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
