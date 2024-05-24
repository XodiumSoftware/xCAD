// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiDrawTipText.h"

class CAdUiTheme;

/** _ */
class BRX_IMPORTEXPORT CAdUiOwnerDrawButton: public CButton
{
    DECLARE_DYNAMIC(CAdUiOwnerDrawButton)
public:
    BOOL AutoLoad();
    BOOL GetEnableDragDrop();
    BOOL GetEnableFastDraw();
    BOOL GetEnablePointedAt();
    BOOL GetIsStatic();
    BOOL GetIsToolButton();
    BOOL Reload(LPCTSTR);
    CAdUiOwnerDrawButton();
    CWnd* GetAdUiParent();
    virtual void DrawItem(LPDRAWITEMSTRUCT);
    virtual void PreSubclassWindow();
    virtual ~CAdUiOwnerDrawButton();
    void SetAdUiParent(CWnd*);
    void SetEnableDragDrop(BOOL);
    void SetEnableFastDraw(BOOL);
    void SetEnablePointedAt(BOOL);
    void SetIsStatic(BOOL);
    void SetIsToolButton(BOOL);
protected:
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg LRESULT OnThemeChanged(WPARAM,LPARAM);
    afx_msg UINT OnGetDlgCode();
    afx_msg void OnDestroy();
    afx_msg void OnDropFiles(HDROP);
    afx_msg void OnKillFocus(CWnd*);
    afx_msg void OnMouseMove(UINT,CPoint);
    afx_msg void OnNcDestroy();
    afx_msg void OnSetFocus(CWnd*);
    afx_msg void OnTimer(UINT_PTR);
    BOOL GetIsPointedAt();
    BOOL m_bEnableDragDrop;
    BOOL m_bEnableFastDraw;
    BOOL m_bEnablePointedAt;
    BOOL m_bIsPointedAt;
    BOOL m_bIsStatic;
    BOOL m_bIsToolButton;
    BOOL m_bIsTrackButton;
    BOOL m_bMouseHover;
    CPoint m_lastMousePoint;
    CRect m_tipRect;
    CWnd* m_aduiParent;
    int m_nPartId;
    int m_nStateId;
    static const UINT_PTR m_timerEvent;
    UINT_PTR m_timerId;
    UINT m_uEdge;
    virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY,UINT,LPARAM);
    virtual ADUI_REPLY OnGetTipSupport(CPoint&);
    virtual BOOL OnAutoLoad();
    virtual BOOL OnDrawTipText(CAdUiDrawTipText&);
    virtual BOOL OnGetTipRect(CRect&);
    virtual BOOL OnGetTipText(CString&);
    virtual BOOL OnHitTipRect(CPoint&);
    virtual BOOL OnReload(LPCTSTR);
    virtual void DrawButton(CDC&,int,int,BOOL,BOOL,BOOL,BOOL);
    virtual void DrawPushButtonBorder(CDC&,CRect&,BOOL,BOOL);
    virtual void DrawToolButtonBorder(CDC&,CRect&,BOOL,BOOL);
    virtual void OnDragDrop(HDROP);
    virtual void OnDrawTip(CDC&);
    virtual void OnPointedAt(BOOL);
    void DrawTransparentBitmap(CDC&,CBitmap&,int,int,int,int,BOOL);
    void SetIsPointedAt(BOOL);
    void StartTimer(DWORD = 50);
    void StopTimer();

    DECLARE_MESSAGE_MAP()

    //V10
protected:
    CAdUiTheme* m_pTheme;
public:
    virtual CAdUiTheme* SetTheme(CAdUiTheme*);
};
