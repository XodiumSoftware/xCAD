// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiDropTarget.h"
#include "BrxSpecific/BcUiThemeHelperWin.h"

class CAdUiPaletteSet;
class CAdUiPaletteImp;

#define PS_EDIT_NAME 1

/** _ */
class BRX_IMPORTEXPORT CAdUiPalette: public CWnd, public BcUiThemeHelperWin
{
    DECLARE_DYNAMIC(CAdUiPalette)
public:
    BOOL Create(DWORD,LPCTSTR,CAdUiPaletteSet*,DWORD = 0);
    BOOL EditNameStyle();
    CAdUiPalette();
    CAdUiPaletteSet* GetPaletteSet();
    CString GetName();
    DWORD GetPaletteStyle();
    virtual bool CanFrameworkTakeFocus();
    virtual BOOL Create(CAdUiPaletteSet*);
    virtual BOOL GetMaximumSize(CSize&);
    virtual BOOL GetMinimumSize(CSize&);
    virtual BOOL Load(IUnknown*);
    virtual BOOL NameEditValidation(CEdit*);
    virtual BOOL OnKillActive();
    virtual BOOL Save(IUnknown*);
    virtual CString GetClassName();
    virtual void EditName();
    virtual void EditName(CPoint&);
    virtual void OnSetActive();
    virtual ~CAdUiPalette();
    void SetName(CString);
    void SetPaletteSet(CAdUiPaletteSet*);
    void SetPaletteStyle(DWORD);

protected:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg LRESULT OnColorThemeChanged(WPARAM, LPARAM);
    afx_msg BOOL OnSetCursor(CWnd*,UINT,UINT);
    afx_msg void OnLButtonDown(UINT,CPoint);

    DECLARE_MESSAGE_MAP()

    //BRX START
private:
    CAdUiPaletteImp* m_pPalImp;
    //BRX END

    //V10
protected:
    afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);
};
