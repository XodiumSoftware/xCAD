// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class OdApStatusBarItemImp;
class CMenu;

/** _ */
class BRX_IMPORTEXPORT AcStatusBarItem
{
protected:
    //BRX START
    friend class AcApStatusBarImp;
    OdApStatusBarItemImp* m_pBrxImp;
    //BRX END

public:
    AcStatusBarItem();
    AcStatusBarItem(const CString&, bool);
    virtual ~AcStatusBarItem();

    bool IsTrayItem() const;
    const CString& GetName() const;

    virtual BOOL ClientToScreen(LPPOINT); //deprecated
    virtual BOOL ClientToScreen(LPRECT); //deprecated
    virtual BOOL GetToolTipText(CString&) const;
    virtual BOOL IsEnabled();
    virtual BOOL IsVisible();
    virtual BOOL QueryToolTipText(CString&) const; //deprecated
    virtual BOOL ScreenToClient(LPPOINT); //deprecated
    virtual BOOL ScreenToClient(LPRECT); //deprecated
    virtual BOOL SetIcon(HICON);
    virtual BOOL SetToolTipText(const CString&);
    virtual BOOL ShowTraySettingsDialog(); //deprecated
    virtual HICON GetIcon() const;
#ifdef _WIN32
    virtual UINT DisplayContextMenu(CMenu&, CPoint);
#endif
    virtual void Enable(BOOL);
    virtual void OnDelete();
    virtual void OnLButtonDblClk(UINT, CPoint);
    virtual void OnLButtonDown(UINT, CPoint);
    virtual void OnRButtonDown(UINT, CPoint);
    virtual void SetVisible(BOOL);
};
