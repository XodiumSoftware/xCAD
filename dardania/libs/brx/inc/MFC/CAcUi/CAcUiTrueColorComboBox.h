// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColor.h"
#include "MFC/CAcUi/CAcUiMRUComboBox.h"

#define ACUI_MAX_TRUECOLOR_COMBOBOX_MRU 16
#define ACUI_TRUECOLOR_COMBOBOX_TABLE_SIZE 25

/** _ */
class BRX_IMPORTEXPORT CAcUiTrueColorComboBox: public CAcUiMRUComboBox
{
public:
    enum ColorTableIndex
    {
        kCargoOther2 = -2,
        kCargoOther1,
        kCargoOption1,
        kCargoOption2,
        kCargoStockItem1,
        kCargoStockItem2,
        kCargoStockItem3,
        kCargoStockItem4,
        kCargoStockItem5,
        kCargoStockItem6,
        kCargoStockItem7,
        kIndexOfFirstMRUItem,
        kLastIndex = 24
    };

    CAcUiTrueColorComboBox();
    const AcCmColor& GetBlockColor();
    DWORD getColorByCargo(int);
    DWORD getColorData(AcCmColor);
    int AddColorToMRU(const AcCmColor&);
    int AddItemToList(LPCTSTR,int,INT_PTR);
    int FindItemByColor(const AcCmColor&);
    int GetColorIndex(COLORREF);
    virtual COLORREF GetColorFromIndex(int);
    virtual ~CAcUiTrueColorComboBox();
    void AddItems();
    void GetCurrentItemColor(AcCmColor&);
    void SetBlockColor(const AcCmColor&);
protected:
    AcCmColor* m_AcCmColorTable[ACUI_TRUECOLOR_COMBOBOX_TABLE_SIZE];
    AcCmColor m_blockColor;
    afx_msg void OnDrawItem(int,LPDRAWITEMSTRUCT);
    bool GetCurrentLayerColor(AcCmColor&);
    BOOL GetOtherColor(AcCmColor&,const AcCmColor&,BOOL);
    BOOL GetWindowsColor(AcCmColor&);
    virtual BOOL GetOtherName(BOOL,CString&);
    virtual BOOL OnSelectOther(BOOL,int,int&);
    virtual COLORREF LookupColor(int,LOGPALETTE*);
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();
    void initAcCmColorTable();
    void RGBFill(CDC&,CRect&);

    DECLARE_MESSAGE_MAP()
};
