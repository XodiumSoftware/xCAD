// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_importexport.h"
#include "BrxSpecific/BcUiThemeHelper.h"


class BRX_IMPORTEXPORT BcUiThemeHelperWinBase
{
public:
    virtual COLORREF GetThemeBackgroundColor();
    virtual COLORREF GetThemeForegroundColor();

protected:
    static const UINT WM_COLORTHEMECHANGED;
};

class BcUiThemeHelperWin : public BcUiThemeHelper, public BcUiThemeHelperWinBase
{
};
