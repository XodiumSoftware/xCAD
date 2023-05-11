// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiMRUComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiArrowHeadComboBox: public CAcUiMRUComboBox
{
public:
    CAcUiArrowHeadComboBox();
    virtual ~CAcUiArrowHeadComboBox();

    BOOL GetUseOrigin2();
    int AddArrowHeadToMRU(LPCTSTR);
    void SetUseOrigin2(BOOL);
protected:
    virtual BOOL GetOtherName(BOOL,CString&);
    virtual int CalcItemHeight();
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();
    virtual void OnComboBoxInit();

    DECLARE_MESSAGE_MAP()
};
