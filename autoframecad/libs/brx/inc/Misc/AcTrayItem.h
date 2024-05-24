// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcStatusBarItem.h"
#include "Misc/AcTrayItemBubbleWindowControl.h"

/** _ */
class BRX_IMPORTEXPORT AcTrayItem: public AcStatusBarItem
{
public:
    AcTrayItem();
    virtual ~AcTrayItem();

    virtual AcTrayItemBubbleWindowControl* GetBubbleWindowControl() const;
    virtual BOOL CloseAllBubbleWindows();
    virtual BOOL SetIcon(HICON);
    virtual BOOL ShowBubbleWindow(AcTrayItemBubbleWindowControl*);
    virtual HICON GetIcon() const;
};
