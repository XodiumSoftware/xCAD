// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiOwnerDrawButton.h"

class BRX_IMPORTEXPORT CAdUiTrackButtonDraw;

/** _ */
class CAdUiTrackButton: public CAdUiOwnerDrawButton
{
    DECLARE_DYNAMIC(CAdUiTrackButton)
public:
    CAdUiTrackButton();
    CAdUiTrackButton(const CAdUiTrackButtonDraw&);
    CAdUiTrackButtonDraw* SetDraw(CAdUiTrackButtonDraw*);
    static CAdUiTrackButtonDraw* SetDefaultDraw(CAdUiTrackButtonDraw*);
    virtual void DrawItem(LPDRAWITEMSTRUCT);
    virtual void SetTracking(BOOL);
    virtual ~CAdUiTrackButton();
protected:
    afx_msg void OnNcPaint();
    afx_msg void OnPaint();
    virtual ADUI_REPLY OnGetTipSupport(CPoint&);
    virtual void DrawBorder(CDC*,CRect&,COLORREF);
    virtual void DrawButton(CDC&,int,int,BOOL,BOOL,BOOL,BOOL);
    virtual void DrawHotBorder();
    virtual void DrawPushButtonBorder(CDC&,CRect&,BOOL,BOOL);
    virtual void DrawToolButtonBorder(CDC&,CRect&,BOOL,BOOL);
    virtual void releaseDraw();

    DECLARE_MESSAGE_MAP()

    //V10
public:
    virtual CAdUiTheme* GetTheme() const;
    virtual CAdUiTheme* SetTheme(CAdUiTheme*);
};
