// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#if defined(_AFXEXT) && defined(__cplusplus)
  #if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
    #undef _DEBUG
    #include <afxtempl.h>
    #define _DEBUG
  #else
    #include <afxtempl.h>
  #endif
#endif

#include "MFC/CAdUi/CAdUiDockControlBar.h"

class CAdUiPalette;
class CAdUiPaletteSetImp;
class CAdUiPaletteSetDockFrame;

#define ADUI_HT_CAPTION 1
#define ADUI_HT_OPTION_BUTTON 2
#define ADUI_HT_ROLLUP_BUTTON 3
#define ADUI_HT_CLOSE_BUTTON 4
#define ADUI_HT_GRIP 5
#define ADUI_HT_TABS 6
#define ADUI_HT_PALETTE 7
#define ADUI_HT_TAB_OVERFLOW 8
#define ADUI_HT_PALETTESET 9

#define PSS_AUTO_ROLLUP 2
#define PSS_PROPERTIES_MENU 4
#define PSS_CLOSE_BUTTON 8
#define PSS_EDIT_NAME 16
#define PSS_SNAP 32
#define PSS_SINGLE_PALETTE_TAB 64
#define PSS_USE_SINGLE_PALETTE_TAB_NAME 128
#define PSS_NO_ROLLUP_BUTTON 8192
#define PSS_NO_ICON 16384
#define PSS_NO_TITLEBAR 32768


/** _ */
class BRX_IMPORTEXPORT CAdUiPaletteSet: public CAdUiDockControlBar
{
    friend CAdUiPalette;
    friend CAdUiPaletteSetDockFrame;
    friend CAdUiPaletteSetImp;
    DECLARE_DYNCREATE(CAdUiPaletteSet);

public:
    enum AdUiTitleBarLocation{kLeft=0,kRight};

    CAdUiPaletteSet(int = 0);
    virtual ~CAdUiPaletteSet();

    virtual COLORREF GetThemeForegroundColor() override;
    virtual COLORREF GetThemeCaptionColor();
    virtual COLORREF GetThemeCaptionIconColor();

    AdUiTitleBarLocation TitleBarLocation();
    BOOL AutoRollupStyle();
    BOOL CloseButtonStyle();
    BOOL Create(LPCTSTR,DWORD,const RECT&,CWnd*,DWORD = PSS_AUTO_ROLLUP|PSS_PROPERTIES_MENU|PSS_CLOSE_BUTTON|PSS_SNAP);
    BOOL EditNameStyle();
    BOOL GetAutoRollup();
    BOOL PropertiesMenuStyle();
    BOOL RemovePalette(CAdUiPalette*);
    BOOL RemovePalette(int);
    BOOL RolledUp();
    BOOL SetActivePalette(CAdUiPalette*);
    BOOL SetActivePalette(int);
    BOOL SetAutoRollup(BOOL = TRUE);
    BOOL SetName(LPCTSTR);
    BOOL SetOpacity(int);
    BOOL SinglePaletteTabStyle();
    BOOL SnapStyle();
    BOOL UseSinglePaletteTabNameStyle();
    CAdUiPalette* GetPalette(int);
    CAdUiPalette* GetActivePalette();
    CFont* GetWindowFont();
    CString GetName();
    DWORD GetPaletteSetStyle();
    int AddPalette(CAdUiPalette*);
    int GetActivePaletteTabIndex();
    int GetOpacity() const;
    int GetPaletteCount();
    int GetTabIndex(CAdUiPalette*);
    int InsertPalette(int,CAdUiPalette*);
    virtual CSize CalcDynamicLayout(int, DWORD);
    virtual BOOL Load(IUnknown*); //internal use only
    virtual BOOL NameEditValidation(CEdit*);
    virtual BOOL PreTranslateMessage(MSG*);
    virtual BOOL Save(IUnknown*); //internal use only
    virtual void TitleBarLocationUpdated(AdUiTitleBarLocation);
    void EnableDocking(DWORD);
    void GetFullRect(CRect&);
    void RollOut(bool = false);
    void RollUp();
    void SetPaletteSetStyle(DWORD);
    void SetTitleBarLocation(AdUiTitleBarLocation);
    void UpdateTabs();
    // Icon Functions
    HICON SetIcon(HICON, BOOL);
    HICON GetIcon(BOOL) const;

protected:
    DECLARE_MESSAGE_MAP()

protected:
    afx_msg BOOL OnEraseBkgnd(CDC*);
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg void OnActivate(UINT,CWnd*,BOOL);
    afx_msg void OnLButtonDblClk(UINT,CPoint);
    afx_msg void OnLButtonDown(UINT,CPoint);
    afx_msg void OnLButtonUp(UINT,CPoint);
    afx_msg void OnMouseMove(UINT,CPoint);
    afx_msg void OnNcCalcSize(BOOL, NCCALCSIZE_PARAMS FAR*);
    afx_msg void OnNcPaint();
    afx_msg void OnSetFocus(CWnd*);
    afx_msg void OnSize(UINT,int,int);
    afx_msg void OnWindowPosChanging(WINDOWPOS*);
    BOOL HitTest(CPoint,UINT&,DWORD&);
    virtual BOOL AddContextMenuItems(CMenu*,int,int = 0);
    virtual bool CanFrameworkTakeFocus();
    virtual int GetBottomReservedHeight();
    virtual int GetTopReservedHeight();
    virtual void AutoRollupChanged(BOOL);
    virtual void EditName();
    virtual void GetMaximumSize(CSize&);
    virtual void GetMinimumSize(CSize&);
    virtual void PaletteActivated(CAdUiPalette*,CAdUiPalette*);
    virtual void PaletteAdded(CAdUiPalette*);
    virtual void PaletteRemoved(CAdUiPalette*);
    void GetAdjustedClientRect(CRect&);

#if (_MSC_VER < 1400)
    afx_msg UINT OnNcHitTest(CPoint);
#else
    afx_msg LRESULT OnNcHitTest(CPoint);
#endif

    //V10
public:
    CAdUiTheme* GetTheme();
    CAdUiTheme* SetTheme(CAdUiTheme*);

    //BRX START
private:
    CAdUiPaletteSetImp* m_pPSetImp;

protected:
    virtual void OnContextMenu(CWnd*, CPoint);
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
    virtual void OnBarStyleChange(DWORD dwOldStyle, DWORD dwNewStyle);
    afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);
    afx_msg LRESULT OnSetPaletteActive(WPARAM,LPARAM);
    //BRX END
};
