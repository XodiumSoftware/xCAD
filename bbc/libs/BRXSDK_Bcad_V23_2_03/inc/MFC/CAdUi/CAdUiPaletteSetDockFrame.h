// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiDockGlobal.h"
#include "BrxSpecific/BcUiThemeHelperWin.h"

class CAdUiPaletteSet;
class CAdUiPaletteSetDockFrameImp;

class BRX_IMPORTEXPORT CAdUiPaletteSetDockFrame: public CMiniDockFrameWnd, public BcUiThemeHelperWin
{
    DECLARE_DYNCREATE(CAdUiPaletteSetDockFrame);

//BRX START
    friend CAdUiPaletteSet;
    friend CAdUiPaletteSetDockFrameImp;
private:
    CAdUiPaletteSetDockFrameImp* m_pPSetFrameImp;
//BRX END

public:
    enum AdUiTitleBarLocation
    {
        kLeft = 0,
        kRight
    };

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
    CAdUiPaletteSetDockFrame();
    virtual ~CAdUiPaletteSetDockFrame();

    virtual BOOL Create(CWnd*,DWORD);
    virtual void CalcWindowRect(LPRECT,UINT = adjustBorder);

    AdUiTitleBarLocation TitleBarLocation();
    ContainedBarType GetContainedBarType();
    void SetAutoRollup(BOOL);
    void SetTitleBarLocation(AdUiTitleBarLocation);

protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT&);
    virtual BOOL PreTranslateMessage(MSG*);
    virtual LRESULT OnDragEnter(WPARAM,LPARAM);
    virtual LRESULT OnDragLeave(WPARAM,LPARAM);
    virtual LRESULT OnDragOver(WPARAM,LPARAM);
    virtual LRESULT OnDragScroll(WPARAM,LPARAM);
    virtual LRESULT OnDrop(WPARAM,LPARAM);
    virtual LRESULT OnDropEx(WPARAM,LPARAM);

    afx_msg LRESULT OnColorThemeChanged(WPARAM, LPARAM);
    afx_msg BOOL OnEraseBkgnd(CDC*);
    afx_msg BOOL OnSetCursor(CWnd*,UINT,UINT);
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg int OnMouseActivate(CWnd*,UINT,UINT);
#if _MSC_VER <= 1600
    afx_msg LRESULT OnDisplayChange(WPARAM,LPARAM);
#else
    afx_msg void    OnDisplayChange(UINT nImageDepth, int cxScreen, int cyScreen);
#endif
    afx_msg LRESULT OnEnterSizeMove(WPARAM,LPARAM);
    afx_msg LRESULT OnExitSizeMove(WPARAM,LPARAM);
    afx_msg LRESULT OnNcHitTest(CPoint);
    afx_msg LRESULT OnKeepFocus(WPARAM, LPARAM);
    afx_msg void OnParentNotify(UINT, LPARAM);
    afx_msg void OnActivate(UINT,CWnd*,BOOL);
    afx_msg void OnClose();
    afx_msg void OnContextMenu(CWnd*,CPoint);
    afx_msg void OnDestroy();
    afx_msg void OnGetMinMaxInfo(MINMAXINFO*);
    afx_msg void OnLButtonDown(UINT,CPoint);
    afx_msg void OnMouseMove(UINT,CPoint);
    afx_msg void OnNcCalcSize(BOOL, NCCALCSIZE_PARAMS FAR*);
    afx_msg void OnNcLButtonDown(UINT,CPoint);
    afx_msg void OnNcLButtonUp(UINT,CPoint);
    afx_msg void OnNcMouseMove(UINT,CPoint);
    afx_msg void OnNcPaint();
    afx_msg BOOL OnNcActivate(BOOL);
    afx_msg void OnActivateApp(BOOL, DWORD);
    afx_msg void OnNcRButtonDown(UINT,CPoint);
    afx_msg void OnNcRButtonUp(UINT,CPoint);
    afx_msg void OnPaint();
    afx_msg void OnSetFocus(CWnd*);
    afx_msg void OnSettingChange(UINT,LPCTSTR);
    afx_msg void OnShowWindow(BOOL,UINT);
    afx_msg void OnSize(UINT,int,int);
    afx_msg void OnSizing(UINT,LPRECT);
    afx_msg void OnStyleChanging(int, LPSTYLESTRUCT);
    afx_msg void OnSysCommand(UINT,LPARAM);
    afx_msg void OnTimer(UINT_PTR);
    afx_msg void OnWindowPosChanging(WINDOWPOS*);
    bool CanAutoCADTakeFocus();
    bool CanFrameworkTakeFocus();
    BOOL HitTest(CPoint,UINT&,DWORD&);
    CAdUiPaletteSet* GetPaletteSet();
    void ForceChildRepaint();

    DECLARE_MESSAGE_MAP()
};
