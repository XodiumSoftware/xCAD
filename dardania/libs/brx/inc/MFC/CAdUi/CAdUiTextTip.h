// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiTipWindow.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiTextTip: public CAdUiTipWindow
{
    DECLARE_DYNAMIC(CAdUiTextTip)
public:
    CAdUiTextTip();
    virtual BOOL PreCreateWindow(CREATESTRUCT&);
    virtual void Hide();
    virtual ~CAdUiTextTip();
    void Update(CWnd*,BOOL);
    void UpdateIfNecessary(CWnd*,BOOL);
protected:
    virtual void DrawBorder(CDC&,CRect&,CRect&);
    virtual void DrawContent(CDC&,CRect&);

    DECLARE_MESSAGE_MAP()
};
