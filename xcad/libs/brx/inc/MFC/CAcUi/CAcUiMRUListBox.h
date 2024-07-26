// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
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