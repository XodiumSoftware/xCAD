// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiDrawTipText.h"

/** _ */
class CAdUiListBox: public CListBox
{
    DECLARE_DYNAMIC(CAdUiListBox);
public:
    BOOL GetComboBoxDraw();
    BOOL IsOwnerDraw();
    CAdUiComboBox* GetComboBox();
    CAdUiListBox();
    CWnd* GetAdUiParent();
    int GetItemAtPoint(CPoint&);
    virtual int CompareItem(LPCOMPAREITEMSTRUCT);
    virtual void DeleteItem(LPDELETEITEMSTRUCT);
    virtual void DrawItem(LPDRAWITEMSTRUCT);
    virtual void GetContentExtent(int,LPCTSTR,int&,int&);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT);
    virtual ~CAdUiListBox();
    void GetTextExtent(LPCTSTR,int&,int&);
    void SetAdUiParent(CWnd*);
    void SetComboBox(CAdUiComboBox*);
    void SetComboBoxDraw(BOOL);
protected:
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg void OnDestroy();
    afx_msg void OnMouseMove(UINT,CPoint);
    BOOL m_bComboBoxDraw;
    CAdUiComboBox* m_pComboBox;
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
