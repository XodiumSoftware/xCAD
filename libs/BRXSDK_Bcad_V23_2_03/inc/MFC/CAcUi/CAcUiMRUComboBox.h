// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiComboBox.h"
#include "MFC/CAcUi/CAcUiListBox.h"

#define ACUI_MAX_COMBOBOX_MRU 6
#define ACUI_MAX_TRUECOLOR_COMBOBOX_MRU 16

enum ACUI_MRU_CARGO
{
    kAcUiMRUCargo_Last = -106,
    kAcUiMRUCargo_Option2,
    kAcUiMRUCargo_Option1,
    kAcUiMRUCargo_Other2,
    kAcUiMRUCargo_Other1,
    kAcUiMRUCargo_None
};

/** _ */
class BRX_IMPORTEXPORT CAcUiMRUComboBox: public CAcUiComboBox
{
public:
    BOOL GetUseByBlock();
    BOOL GetUseByLayer();
    BOOL GetUseOption1();
    BOOL GetUseOption2();
    BOOL GetUseOther();
    BOOL GetUseOther1();
    BOOL GetUseOther2();
    BOOL GetUseWindows();
    CAcUiMRUComboBox();
    HPALETTE GetPalette();
    int AddItemToList(LPCTSTR,INT_PTR);
    int AddItemToMRU(LPCTSTR,int);
    int FindItemByCargo(INT_PTR);
    int GetCargoOption1();
    int GetCargoOption2();
    INT_PTR GetCurrentItemCargo();
    INT_PTR GetItemCargo(int);
    int InsertItemInList(int,LPCTSTR,INT_PTR);
    int ItemHeight();
    LOGPALETTE* GetLogPalette();
    virtual BOOL Create(DWORD,const RECT&,CWnd*,UINT);
    virtual BOOL GetItemColors(DRAWITEMSTRUCT&,COLORREF&,COLORREF&,COLORREF&);
    virtual int ExtraWidth();
    virtual int ImageWidth();
    virtual void DrawItem(LPDRAWITEMSTRUCT);
    virtual void GetContentExtent(LPCTSTR,int&,int&);
    virtual void MeasureItem(LPMEASUREITEMSTRUCT);
    virtual ~CAcUiMRUComboBox();
    void AddItems();
    void RecalcHeight();
    void RemoveItemFromMRU(int);
    void SetCargoOption1(int);
    void SetCargoOption2(int);
    void SetLastSelection(int);
    void SetLogPalette(LOGPALETTE*);
    void SetPalette(HPALETTE);
    void SetUseByBlock(BOOL);
    void SetUseByLayer(BOOL);
    void SetUseOption1(BOOL);
    void SetUseOption2(BOOL);
    void SetUseOther(BOOL);
    void SetUseOther1(BOOL);
    void SetUseOther2(BOOL);
    void SetUseWindows(BOOL);
protected:
    afx_msg BOOL OnCloseUp();
    afx_msg BOOL OnDropDown();
    afx_msg BOOL OnSelEndOk();
    afx_msg int OnCreate(LPCREATESTRUCT);
    BOOL FindCargoInMRU(int);
    BOOL m_bIsDynamicCreation;
    BOOL m_bOther1Selected;
    BOOL m_bOther2Selected;
    BOOL m_bUseOption1;
    BOOL m_bUseOption2;
    BOOL m_bUseOther1;
    BOOL m_bUseOther2;
    CPalette* m_pOldPalette;
    CString m_mruName[ACUI_MAX_COMBOBOX_MRU];
    HPALETTE m_hPalette;
    int GenerateCargoFromMRU(int);
    int m_cargoOption1;
    int m_cargoOption2;
    int m_itemHeight;
    int m_lastSelection;
    int m_mruCargo[ACUI_MAX_COMBOBOX_MRU];
    int m_mruLen;
    LOGPALETTE* m_logPalette;
    virtual BOOL GetOptionName(BOOL,CString&);
    virtual BOOL GetOtherName(BOOL,CString&);
    virtual BOOL OnGetTipRect(CRect&);
    virtual BOOL OnSelectOther(BOOL,int,int&);
    virtual int CalcItemHeight();
    virtual LRESULT WindowProc(UINT,WPARAM,LPARAM);
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();
    virtual void OnComboBoxInit();
    virtual void PreSubclassWindow();
    void CreateAndSelectPalette(LPDRAWITEMSTRUCT,CDC*);
    void DrawItemImageFromCargo(CDC*,CRect&,int);
    void DrawTextAndFocusRect(LPDRAWITEMSTRUCT,CDC*,CRect&,int,COLORREF&,COLORREF&);
    void SelectOther(BOOL);
    void SetupForImageDraw(LPDRAWITEMSTRUCT,CDC*,CRect&,CRect&,COLORREF&,COLORREF&);

    DECLARE_MESSAGE_MAP()
};
