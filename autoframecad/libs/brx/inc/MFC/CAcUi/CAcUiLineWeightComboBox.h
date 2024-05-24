// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiMRUComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiLineWeightComboBox: public CAcUiMRUComboBox
{
public:
    CAcUiLineWeightComboBox();
    double GetLineWeightScale();
    int FindItemByLineWeight(int);
    int GetCurrentItemLineWeight();
    int GetCurrentLayerLineWeight();
    int GetItemLineWeight(int);
    virtual int ImageWidth();
    virtual ~CAcUiLineWeightComboBox();
    void SetLineWeightScale(double);
    void SetUseDefault(BOOL);
protected:
    double m_lineWeightScale;
    virtual void DrawItemImage(CDC&,CRect&,INT_PTR);
    virtual void OnAddItems();

    DECLARE_MESSAGE_MAP()
private:
    bool m_showDefault;
};
