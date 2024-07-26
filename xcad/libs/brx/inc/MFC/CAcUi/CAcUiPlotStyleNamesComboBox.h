// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiMRUComboBox.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiPlotStyleNamesComboBox: public CAcUiMRUComboBox
{
public:
    CAcUiPlotStyleNamesComboBox();
    virtual int ImageWidth();
    virtual ~CAcUiPlotStyleNamesComboBox();
    void OtherRunsCurrentPlotStyle();
    void OtherRunsDefault();
    void OtherRunsSelectPlotStyle();
    void SetAllowByLayerByBlock(BOOL);
    void SetColorDependentMode();
    void SetNamedMode();
protected:
    virtual BOOL OnSelectOther(BOOL,int,int&);
    virtual void OnAddItems();
    virtual void OnComboBoxInit();

    DECLARE_MESSAGE_MAP()
};
