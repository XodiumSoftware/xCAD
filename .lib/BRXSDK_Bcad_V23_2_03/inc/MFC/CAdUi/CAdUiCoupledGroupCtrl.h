// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAdUi/CAdUiGlobal.h"

class CAdUiGroupCtrl;
class CAdUiTheme;

#define ADUI_DEFAULT_TREE_TO_DETAILS_RATIO 0.4

/** _ */
class BRX_IMPORTEXPORT CAdUiCoupledGroupCtrl: public CWnd
{
    DECLARE_DYNAMIC(CAdUiCoupledGroupCtrl);
public:
    bool GetSplitterEnabled();
    CAdUiCoupledGroupCtrl();
    double GetTopToWholeRatio() const;
    virtual void AddCouple(CAdUiGroupCtrl*,CAdUiGroupCtrl*);
    virtual void AddCouple(CAdUiGroupCtrl*,CWnd*);
    virtual void AddCouple(CWnd*,CAdUiGroupCtrl*);
    virtual void AddCouple(CWnd*,CWnd*);
    virtual void MinMaxOneChild(CWnd*,bool);
    virtual ~CAdUiCoupledGroupCtrl();
    void SetSplitterEnabled(bool);
    void SetTopToWholeRatio(double);
protected:
    bool m_bDragging;
    bool m_bSplitterEnabled;
    CAdUiGroupCtrl* m_pAdUiBottomWnd;
    CAdUiGroupCtrl* m_pAdUiTopWnd;
    CBrush m_bkBrush;
    COLORREF m_crNCBackground;
    COLORREF m_crSplitter;
    CPoint m_ptLast;
    CRect m_rtSpace;
    CWnd* m_pBottomWnd;
    CWnd* m_pTopWnd;
    double m_topToWholeRatio;

    DECLARE_MESSAGE_MAP()

    //V10
public:
    void SetTheme(CAdUiTheme*);
};
