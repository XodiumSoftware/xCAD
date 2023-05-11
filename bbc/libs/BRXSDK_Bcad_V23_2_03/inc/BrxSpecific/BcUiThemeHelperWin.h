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
