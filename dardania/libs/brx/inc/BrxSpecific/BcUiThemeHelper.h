// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_importexport.h"


class BRX_IMPORTEXPORT BcUiThemeHelper
{
public:
    virtual bool IsThemingEnabled() const { return true; } //override in derived class to disable theming

protected:
    virtual void OnThemingChanged() {} // COLORTHEME change notification
};
