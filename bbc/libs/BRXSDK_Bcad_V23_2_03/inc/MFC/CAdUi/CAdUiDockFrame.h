// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiDockGlobal.h"
#include "BrxSpecific/BcUiThemeHelperWin.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiDockFrame: public CMiniDockFrameWnd, public BcUiThemeHelperWin
{
    DECLARE_DYNCREATE(CAdUiDockFrame);

public:
    enum ContainedBarType
    {
        Unknown = 0,
        Standard,
        AdskBar
    };

protected:
    bool m_bZOrderChanged;
    ContainedBarType m_nContainedBarType;

public:
    CAdUiDockFrame();

    bool CanFrameworkTakeFocus();
    ContainedBarType GetContainedBarType();
    void ForceChildRepaint();

protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT&);

    afx_msg LRESULT OnKeepFocus(WPARAM, LPARAM);
    afx_msg LRESULT OnColorThemeChanged(WPARAM, LPARAM);
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg BOOL OnEraseBkgnd(CDC*);
    afx_msg int OnMouseActivate(CWnd*,UINT,UINT);
    afx_msg LRESULT OnNcHitTest(CPoint);
    afx_msg void OnClose();
    afx_msg void OnGetMinMaxInfo(MINMAXINFO*);
    afx_msg void OnNcLButtonDown(UINT,CPoint);
    afx_msg void OnPaint();
    afx_msg void OnSize(UINT,int,int);
    afx_msg void OnSizing(UINT,LPRECT);
    afx_msg void OnWindowPosChanging (WINDOWPOS*);
    bool CanAutoCADTakeFocus();

    DECLARE_MESSAGE_MAP()
};
