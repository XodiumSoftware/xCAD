// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiTipWindow: public CWnd
{
    DECLARE_DYNAMIC(CAdUiTipWindow)
public:
    BOOL GetUseText();
    CAdUiTipWindow();
    CWnd* GetControl();
    CWnd* Owner();
    virtual BOOL Create(CWnd*);
    virtual void Hide();
    virtual void Show();
    virtual ~CAdUiTipWindow();
    void GetTextExtent(LPCTSTR,int&,int&);
    void SetControl(CWnd*);
    void SetUseText(BOOL);
protected:
    afx_msg void OnActivateApp(BOOL,DWORD);
    afx_msg void OnLButtonDblClk(UINT,CPoint);
    afx_msg void OnLButtonDown(UINT,CPoint);
    afx_msg void OnMButtonDblClk(UINT,CPoint);
    afx_msg void OnMButtonDown(UINT,CPoint);
    afx_msg void OnNcDestroy();
    afx_msg void OnPaint();
    afx_msg void OnRButtonDblClk(UINT,CPoint);
    afx_msg void OnRButtonDown(UINT,CPoint);
    afx_msg void OnTimer(UINT_PTR);
    BOOL m_bUseText;
    CWnd* m_control;
    CWnd* m_owner;
    static const UINT_PTR m_timerEvent;
    static LPCTSTR m_className;
    UINT_PTR m_timerId;
    virtual void DrawBorder(CDC&,CRect&,CRect&);
    virtual void DrawContent(CDC&,CRect&);
    void StartTimer(DWORD = 50);
    void StopTimer();

    DECLARE_MESSAGE_MAP()
};
