// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Misc/AcPane.h"
#include "Misc/AcTrayItem.h"
#include "Misc/MiscGlobal.h"

/** _ */
class AcApStatusBar
{
public:
    virtual AcPane* GetDefaultPane(AcDefaultPane) = 0; //deprecated
    virtual AcPane* GetPane(int) = 0;
    virtual AcTrayItem* GetTrayItem(int) = 0;
    virtual BOOL ClientToScreen(LPPOINT) = 0; //deprecated
    virtual BOOL ClientToScreen(LPRECT) = 0; //deprecated
    virtual BOOL CloseAllBubbleWindows(AcTrayItem*) = 0;
    virtual BOOL GetTraySettingsShowIcons() const = 0; //deprecated
    virtual BOOL GetTraySettingsShowNotifications() const = 0; //deprecated
    virtual BOOL Insert(int,AcPane*,BOOL = TRUE) = 0;
    virtual BOOL Insert(int,AcTrayItem*,BOOL = TRUE) = 0;
    virtual BOOL Remove(AcPane*,BOOL = TRUE) = 0;
    virtual BOOL Remove(AcTrayItem*,BOOL = TRUE) = 0;
    virtual BOOL Remove(int,BOOL = FALSE,BOOL = TRUE) = 0;
    virtual BOOL RemoveAllPanes(BOOL = TRUE) = 0;
    virtual BOOL RemoveAllTrayIcons(BOOL = TRUE) = 0;
    virtual BOOL RemoveCleanScreenIcon() = 0; //deprecated
    virtual BOOL RemoveDefaultPane(AcDefaultPane,BOOL = TRUE) = 0; //deprecated
    virtual BOOL ScreenToClient(LPPOINT) = 0; //deprecated
    virtual BOOL ScreenToClient(LPRECT) = 0; //deprecated
    virtual BOOL SetStatusBarMenuItem(AcPane*) = 0; //deprecated
    virtual BOOL ShowTraySettingsDialog() = 0; //deprecated
    virtual int Add(AcPane*,BOOL = TRUE) = 0;
    virtual int Add(AcTrayItem*,BOOL = TRUE) = 0;
    virtual int GetID(AcPane*) const = 0; //deprecated
    virtual int GetID(AcTrayItem*) const = 0; //deprecated
    virtual int GetID(int,BOOL = FALSE) const = 0; //deprecated
    virtual int GetIndex(AcPane*) const = 0;
    virtual int GetIndex(AcTrayItem*) const = 0;
    virtual int GetIndex(int,BOOL = FALSE) const = 0;
    virtual int GetPaneCount() const = 0;
    virtual int GetTextWidth(const CString&) const = 0; //deprecated
    virtual int GetTrayItemCount() const = 0;
#ifdef _WIN32
    virtual UINT DisplayContextMenu(CMenu&,CPoint) = 0;
    virtual UINT DisplayPopupPaneMenu(AcPane*,CMenu&) = 0;
#endif
    virtual void ShowCleanScreenIcon(BOOL) = 0; //deprecated
    virtual void ShowStatusBarMenuIcon(BOOL) = 0; //deprecated
    virtual void Update() = 0; //deprecated
};
