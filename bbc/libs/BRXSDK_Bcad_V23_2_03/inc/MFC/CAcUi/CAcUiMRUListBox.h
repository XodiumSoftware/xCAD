// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiListBox.h"

class CAcUiMRUComboBox;

/** _ */
class BRX_IMPORTEXPORT CAcUiMRUListBox: public CAcUiListBox
{
public:
    CAcUiMRUListBox();
    virtual void GetContentExtent(int,LPCTSTR,int&,int&);
    virtual ~CAcUiMRUListBox();
protected:
    CAcUiMRUComboBox* MRUComboBox();
    int ExtraWidth();
    virtual BOOL OnGetTipRect(CRect&);

    DECLARE_MESSAGE_MAP()
};