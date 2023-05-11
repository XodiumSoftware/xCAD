// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiDrawTipText.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiHeaderCtrl: public CHeaderCtrl
{
    DECLARE_DYNAMIC(CAdUiHeaderCtrl)
public:
    BOOL GetItemRect(int,CRect&);
    BOOL GetText(int,CString&);
    BOOL IsOwnerDraw(int);
    CAdUiHeaderCtrl();
    CWnd* GetAdUiParent();
    int GetItemAtPoint(CPoint&);
    virtual void GetContentExtent(int,LPCTSTR,int&,int&);
    virtual ~CAdUiHeaderCtrl();
    void GetTextExtent(LPCTSTR,int&,int&);
    void SetAdUiParent(CWnd*);
protected:
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg void OnMouseMove(UINT,CPoint);
    CPoint m_lastMousePoint;
    CRect m_tipRect;
    CWnd* m_aduiParent;
    int m_tipItem;
    virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY,UINT,LPARAM);
    virtual ADUI_REPLY OnGetTipSupport(CPoint&);
    virtual BOOL OnDrawTipText(CAdUiDrawTipText&);
    virtual BOOL OnGetTipRect(CRect&);
    virtual BOOL OnGetTipText(CString&);
    virtual BOOL OnHitTipRect(CPoint&);
    virtual void OnDrawTip(CDC&);

    DECLARE_MESSAGE_MAP()
};
