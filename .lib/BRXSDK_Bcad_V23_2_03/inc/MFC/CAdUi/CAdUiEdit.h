// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiDrawTipText.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiEdit: public CEdit
{
    DECLARE_DYNAMIC(CAdUiEdit)
public:
    BOOL IsStyleMaskSet(DWORD);
    CAdUiEdit();
    CWnd* GetAdUiParent();
    DWORD GetStyleMask();
    DWORD m_styleMask;
    virtual void GetContentExtent(LPCTSTR,int&,int&);
    virtual void SetStyleMask(DWORD);
    virtual ~CAdUiEdit();
    void GetTextExtent(LPCTSTR,int&,int&);
    void SetAdUiParent(CWnd*);
protected:
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg void OnMouseMove(UINT,CPoint);
    CPoint m_lastMousePoint;
    CRect m_tipRect;
    CWnd* m_aduiParent;
    virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY,UINT,LPARAM);
    virtual ADUI_REPLY OnGetTipSupport(CPoint&);
    virtual BOOL OnDrawTipText(CAdUiDrawTipText&);
    virtual BOOL OnGetTipRect(CRect&);
    virtual BOOL OnGetTipText(CString&);
    virtual BOOL OnHitTipRect(CPoint&);
    virtual void OnDrawTip(CDC&);

    DECLARE_MESSAGE_MAP()
};
