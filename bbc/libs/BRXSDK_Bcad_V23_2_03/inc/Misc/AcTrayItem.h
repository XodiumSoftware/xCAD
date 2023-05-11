// Copyright (C) Menhirs NV. All rights reserved.
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
