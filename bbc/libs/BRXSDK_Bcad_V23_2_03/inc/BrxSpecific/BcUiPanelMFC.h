// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "BcUiPanel.h"
#include "BrxSpecific/BcUiThemeHelperWin.h"


/** _ */
class BRX_IMPORTEXPORT BcUiPanelMFCBase : public CWnd, public BcUiPanel, public BcUiThemeHelperWinBase
{
public:
    BcUiPanelMFCBase(const ACHAR* name, const ACHAR* configKey = nullptr) : BcUiPanel(name, configKey) {}
    virtual ~BcUiPanelMFCBase() {}
};

class BRX_IMPORTEXPORT BcUiPanelMFC : public BcUiPanelMFCBase
{
    DECLARE_DYNAMIC(BcUiPanelMFC)

public:
    BcUiPanelMFC(const ACHAR* name, const ACHAR* configKey = nullptr);
    virtual ~BcUiPanelMFC();

    BOOL Create(DWORD windowStyle = WS_CHILD|WS_VISIBLE, UINT nID = (UINT)-1);
    BOOL IsFloating() const;

protected:
    virtual void SizeChanged(CRect*, BOOL, int) {}
    virtual BOOL CreateControlBar(LPCREATESTRUCT) { return TRUE; }
    //virtual bool CanFrameworkTakeFocus();
    //virtual BOOL AddCustomMenuItems(LPARAM);
    //virtual void OnUserSizing(UINT,LPRECT);
    //virtual void PaintControlBar(CDC*);

protected:
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT, int, int);
    afx_msg void OnWindowPosChanged(WINDOWPOS*);
    afx_msg HBRUSH OnCtlColor(CDC*, CWnd*, UINT);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg LRESULT OnColorThemeChanged(WPARAM, LPARAM);
    //afx_msg LRESULT OnKeepFocus(WPARAM, LPARAM);

    DECLARE_MESSAGE_MAP()

private:
    CBrush m_themeBackgroundBrush;
};
