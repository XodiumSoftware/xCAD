// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiMRUComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiPlotStyleTablesComboBox: public CAcUiMRUComboBox
{
public:
    bool IsMissing(int);
    CAcUiPlotStyleTablesComboBox();
    CAcUiPlotStyleTablesComboBox(BOOL);
    int AddItemToList(LPCTSTR,INT_PTR);
    int AddMissingStyleTable(LPCTSTR);
    virtual int ImageWidth();
    virtual ~CAcUiPlotStyleTablesComboBox();
    void GetLBText(int,CString&) const;
    void SetFileType(bool,bool);
protected:
    afx_msg BOOL OnDropDown();
    virtual int CalcItemHeight();
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();
    virtual void OnComboBoxInit();

    DECLARE_MESSAGE_MAP()
};
