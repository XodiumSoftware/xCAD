// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiBitmapButton.h"
#include "MFC/CAdUi/CAdUiDockGlobal.h"
#include "BrxSpecific/BcUiThemeHelperWin.h"

class CAdUiDockFrame;
class CAdUiPaletteSetDockFrame;
class CAdUiPaletteSet;
class CAdUiPaletteSetImp;
class CAdUiDockControlBarImp;

/** _ */
class BRX_IMPORTEXPORT CAdUiDockControlBar: public CControlBar, public BcUiThemeHelperWin
{
    friend CAdUiDockFrame;
    DECLARE_DYNAMIC(CAdUiDockControlBar)

public:
    CAdUiDockControlBar(int = ADUI_DOCK_CS_STDMOUSECLICKS);
    virtual ~CAdUiDockControlBar();

    bool AdjustVertDockedBarHeight(int);
    bool AllowDockingMenuItemState();
    bool Anchored();
    BOOL Create(CWnd*,LPCTSTR,UINT,DWORD = CBRS_BOTTOM|WS_CHILD|WS_VISIBLE,const RECT& = CFrameWnd::rectDefault);
    BOOL Create(LPCTSTR,LPCTSTR,DWORD,const RECT&,CWnd*,UINT,CCreateContext* = NULL);
    BOOL IsFloating();
    LPCGUID GetToolID();
    DWORD GetDockStyle();
    virtual bool CanFrameworkTakeFocus();
    virtual CSize CalcFixedLayout(BOOL,BOOL);
    void DockControlBar(UINT,RECT*);
    void EnableDocking(DWORD);
    void GetFloatingRect(CRect*);
    void GetPersistedDockingRect(CRect*);
    void GetPersistedFloatingRect(CRect*);
    void InitFloatingPosition(CRect*);
    virtual BOOL Load(IUnknown*); //internal use only
    void RestoreControlBar(UINT = AFX_IDW_DOCKBAR_LEFT,CRect* = NULL);
    virtual BOOL Save(IUnknown*); //internal use only
    void SetAllowDockingMenuItemState(bool);
    void SetToolID(LPCGUID);
    void TileInRow();

#ifdef _DEBUG
    void AssertValid() const;
#endif

protected:
    afx_msg BOOL OnEraseBkgnd(CDC*);
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg void OnAllowDock();
    afx_msg void OnAnchor();
    afx_msg void OnAnchorLeft();
    afx_msg void OnAnchorRight();
    afx_msg void OnContextMenu(CWnd*,CPoint);
    afx_msg void OnHideBar();
    afx_msg void OnPaint();
    afx_msg void OnWindowPosChanged(WINDOWPOS*);
    enum {btnWidth=12,btnHeight=12,idCloseBtn=10001,idPinBtn=10002};
    virtual BOOL AddCustomMenuItems(LPARAM);
    virtual BOOL CreateControlBar(LPCREATESTRUCT);
    virtual bool OnClosing();
    virtual void GetFloatingMinSize(long*,long*);
    virtual void OnUserSizing(UINT,LPRECT);
    virtual void PaintControlBar(CDC*);
    virtual void SizeChanged(CRect*,BOOL,int);
    virtual BOOL OnCommand(WPARAM, LPARAM);
    void GetUsedRect(CRect&);

    DECLARE_MESSAGE_MAP()

private:
    void OnUpdateCmdUI(CFrameWnd*,BOOL); //This method is pure virtual in CControlBar

    //BRX START
protected:
    afx_msg LRESULT OnColorThemeChanged(WPARAM, LPARAM);
    afx_msg HBRUSH OnCtlColor(CDC*, CWnd*, UINT);
    afx_msg LRESULT OnKeepFocus(WPARAM, LPARAM);
    afx_msg void OnNcPaint();
    afx_msg void OnNcCalcSize(BOOL, NCCALCSIZE_PARAMS FAR*);
    afx_msg LRESULT OnNcHitTest(CPoint);
    afx_msg void OnCaptureChanged(CWnd*);
    afx_msg void OnLButtonUp(UINT, CPoint);
    afx_msg void OnMouseMove(UINT, CPoint);
    afx_msg void OnNcLButtonDown(UINT, CPoint);
    afx_msg void OnLButtonDown(UINT, CPoint);
    afx_msg void OnLButtonDblClk(UINT, CPoint);
    afx_msg void OnRButtonDown(UINT, CPoint);
    afx_msg void OnWindowPosChanging(WINDOWPOS FAR*);
    afx_msg void OnClose();
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT, int, int);
    afx_msg LRESULT OnSizeParent(WPARAM, LPARAM lParam);
    virtual void OnBarStyleChange(DWORD dwOldStyle, DWORD dwNewStyle);

private:
    virtual void AlignControlBars();

public:
    virtual CSize CalcDynamicLayout(int, DWORD);

private:
    BOOL NegotiateSpace(int, BOOL);

private:
    friend CAdUiPaletteSetDockFrame;
    friend CAdUiPaletteSet;
    friend CAdUiPaletteSetImp;
    CAdUiDockControlBarImp* m_pCBarImp;
    //BRX END
};
