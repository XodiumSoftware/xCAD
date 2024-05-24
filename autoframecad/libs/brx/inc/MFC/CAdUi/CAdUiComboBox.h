// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiEdit.h"

class CAdUiListBox;

/** _ */
class BRX_IMPORTEXPORT CAdUiComboBox: public CComboBox
{
    DECLARE_DYNAMIC(CAdUiComboBox)
public:
    BOOL IsOwnerDraw();
    BOOL IsStatic();
    BOOL IsStyleMaskSet(DWORD);
    BOOL SetToolTipText(const CString&);
    CAdUiComboBox();
    CAdUiEdit* GetEditBox();
    CAdUiListBox* GetListBox();
    CString GetToolTipText() const;
    CWnd* GetAdUiParent();
    DWORD GetStyleMask();
    virtual void GetContentExtent(LPCTSTR,int&,int&);
    virtual ~CAdUiComboBox();
    void GetLBString(int,CString&);
    void GetTextExtent(LPCTSTR,int&,int&);
    void SetAdUiParent(CWnd*);
    void SetEditBox(CAdUiEdit*,BOOL);
    void SetListBox(CAdUiListBox*,BOOL);
    void SetStyleMask(DWORD);
protected:
    afx_msg HBRUSH OnCtlColor(CDC*,CWnd*,UINT);
    afx_msg LRESULT OnAdUiMessage(WPARAM,LPARAM);
    afx_msg LRESULT OnGetToolTipText(WPARAM,LPARAM);
    afx_msg void OnMouseMove(UINT,CPoint);
    BOOL m_bAutoDeleteEBox;
    BOOL m_bAutoDeleteLBox;
    BOOL m_bSubclassedControls;
    CAdUiEdit* m_pComboEBox;
    CAdUiListBox* m_pComboLBox;
    CPoint m_lastMousePoint;
    CRect m_tipRect;
    CString m_sToolTipText;
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
