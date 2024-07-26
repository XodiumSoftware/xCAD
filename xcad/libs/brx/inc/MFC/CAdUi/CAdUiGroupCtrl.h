// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

#include <vector>

typedef void(*AdUiBmpBtnFcnPtr)(CWnd*);

typedef struct AdUiGroupCtrlData
{
    CString title;
    CWnd* pWnd;
    DWORD dwBtnCookie;
    int nWndIndex;

    AdUiGroupCtrlData()
    {
        title.Empty();
        pWnd = NULL;
        dwBtnCookie = 0;
        nWndIndex = 0;
    }
} groupData;

typedef AcArray<groupData> ADUIGROUPCTRLDATALIST;

typedef struct AdUiBmpBtnData
{
    AdUiBmpBtnFcnPtr fcnPtr;
    CBitmap* pBmp;
    CString tooltip;
    DWORD dwCookie;

    AdUiBmpBtnData()
    {
        fcnPtr = NULL;
        pBmp = NULL;
        tooltip.Empty();
        dwCookie = 0;
    }
} bmpBtnData;

typedef AcArray<bmpBtnData> ADUIHEADERBTNLIST;

#define ADUI_GROUP_BORDER_SIZE 1
#define ADUI_GROUP_BUTTONS_RIGHT 25
#define ADUI_GROUP_BUTTON_BOTTOMPADDING 2
#define ADUI_GROUP_BUTTON_SIZE 14
#define ADUI_GROUP_BUTTON_SPACE 3
#define ADUI_GROUP_BUTTON_TOPPADDING 2
#define ADUI_GROUP_CHEVRON_RIGHT 6
#define ADUI_GROUP_CHILD_VERT_SPACE 12
#define ADUI_GROUP_STYLE_CHEVRON 1
#define ADUI_GROUP_STYLE_NONACTIVE 4
#define ADUI_GROUP_STYLE_SHOWBTNFORCE 2
#define ADUI_GROUP_TITLE_BEVELSIZE 5
#define ADUI_GROUP_TITLE_HEIGHT 18
#define ADUI_GROUP_TITLE_TEXTLEFT 10
#define ADUI_GROUP_TITLE_TEXTTOP 1

#define ADUI_NCHT_BASE 221
#define ADUI_NCHT_TITLE 221
#define ADUI_NCHT_CHEVRON 222
#define ADUI_NCHT_BUTTON 223

const DWORD WM_ADUI_VISIBILITY_CHANGING = 2960;

class CAdUiTheme;

/** _ */
class BRX_IMPORTEXPORT CAdUiGroupCtrl: public CStatic
{
    DECLARE_DYNAMIC(CAdUiGroupCtrl);
public:
    bool GetHideGroupHeader();
    bool GetMinimized() const;
    CAdUiGroupCtrl();
    DWORD GetStyle();
    int GetHeaderHeight();
    int GetSelIndex();
    virtual bool AddBmpBtnToHeader(CBitmap*,AdUiBmpBtnFcnPtr,DWORD&,LPCTSTR);
    virtual bool AddBmpBtnToHeader(LPCTSTR,AdUiBmpBtnFcnPtr,DWORD&,LPCTSTR);
    virtual bool AddWnd(CWnd*,LPCTSTR,CBitmap* = NULL);
    virtual bool AddWnd(CWnd*,LPCTSTR,LPCTSTR);
    virtual bool RemoveBmpBtnFromHeader(DWORD);
    virtual bool ShowWnd(CWnd*);
    virtual void ModGroupStyle(DWORD,DWORD);
    virtual void SetFont(CFont*);
    virtual void SetFont(CFont*,BOOL);
    virtual void SetMinimized(bool);
    virtual ~CAdUiGroupCtrl();
    void SetHeaderHeight(int);
    void SetHideGroupHeader(bool);
    void SetSelIndex(int);
    void SetStyle(DWORD);
    void SetTitle(LPCTSTR);
protected:
    ADUIGROUPCTRLDATALIST m_groupList;
    ADUIHEADERBTNLIST m_bmpBtnList;
    bool m_bActive;
    bool m_bHideGroupHeader;
    bool m_bMinimized;
    CBrush m_bgBrush;
    COLORREF m_crButtonBorderNormal;
    COLORREF m_crButtonBorderSelected1;
    COLORREF m_crButtonBorderSelected2;
    COLORREF m_crButtonFillNormal;
    COLORREF m_crButtonFillSelected;
    COLORREF m_crGroupBorder;
    COLORREF m_crHeaderActive;
    COLORREF m_crHeaderInactive;
    COLORREF m_crNCBackground;
    COLORREF m_crTitleText;
    CString m_csTitle;
    CToolTipCtrl m_ToolTip;
    DWORD m_dwBtnId;
    DWORD m_nStyle;
    int m_nHeaderHeight;
    int m_nRestoreHeight;
    int m_nSelIndex;
    static LOGFONT m_lf;

    DECLARE_MESSAGE_MAP()

    //V10
public:
    virtual void SetTheme(CAdUiTheme*);
};
