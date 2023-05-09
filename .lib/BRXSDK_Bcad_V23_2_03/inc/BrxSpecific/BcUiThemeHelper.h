#pragma once

#include "brx_importexport.h"


class BRX_IMPORTEXPORT BcUiThemeHelper
{
public:
    virtual bool IsThemingEnabled() const { return true; } //override in derived class to disable theming

protected:
    virtual void OnThemingChanged() {} // COLORTHEME change notification
};
