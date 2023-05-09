// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiHeaderCtrl.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiListCtrl: public CListCtrl
{
    DECLARE_DYNAMIC(CAdUiListCtrl);
public:
    BOOL GetItemAtPoint(CPoint&,int&,int&);
    BOOL GetSubItemRect(int,int,CRect&);
    BOOL IsOwnerDraw();
    CAdUiHeaderCtrl m_headerCtrl;
    CAdUiListCtrl();
    CWnd* GetAdUiParent();
    int ColumnCount();
    virtual void GetContentExtent(int,int,LPCTSTR,int&,int&);
    virtual ~CAdUiListCtrl();
    void GetTextExtent(LPCTSTR,int&,int&);
    void SetAdUiParent(CWnd*);
protected:
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg void OnMouseMove(UINT,CPoint);
    CPoint m_lastMousePoint;
    CRect m_tipRect;
    CWnd* m_aduiParent;
    int m_tipIndex;
    int m_tipItem;
    virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY,UINT,LPARAM);
    virtual ADUI_REPLY OnGetTipSupport(CPoint&);
    virtual BOOL OnDrawTipText(CAdUiDrawTipText&);
    virtual BOOL OnGetTipRect(CRect&);
    virtual BOOL OnGetTipText(CString&);
    virtual BOOL OnHitTipRect(CPoint&);
    virtual void OnDrawTip(CDC&);
    virtual void PreSubclassWindow();

    DECLARE_MESSAGE_MAP()
};
