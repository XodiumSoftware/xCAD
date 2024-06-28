// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiMRUComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiColorComboBox: public CAcUiMRUComboBox
{
public:
    CAcUiColorComboBox();
    virtual ~CAcUiColorComboBox();

    int AddColorToMRU(int);
    int FindItemByColorIndex(int);
    int GetBlockColorIndex();
    int GetCurrentItemColorIndex();
    int GetItemColorIndex(int);
    virtual COLORREF GetColorFromIndex(int);
    virtual COLORREF LookupColor(int,LOGPALETTE*);
    virtual int GetColorIndex(COLORREF);
    virtual int GetCurrentLayerColorIndex();
    void SetBlockColorIndex(int);
protected:
    int m_blockColorIndex;
    virtual BOOL GetOtherColorIndex(int,int,BOOL,int&);
    virtual BOOL GetOtherName(BOOL,CString&);
    virtual BOOL GetWindowsColor(COLORREF&);
    virtual BOOL OnSelectOther(BOOL,int,int&);
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();
    void RGBFill(CDC&,CRect&);

    DECLARE_MESSAGE_MAP()
};
