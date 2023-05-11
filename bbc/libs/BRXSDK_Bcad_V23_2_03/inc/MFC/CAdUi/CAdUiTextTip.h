// Copyright (C) Menhirs NV. All rights reserved.
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
