#pragma once

#include "brx_importexport.h"
#include "BrxSpecific/BcImageSource.h"
#include "BrxSpecific/BcUiThemeHelper.h"

class BcUiPanelImp;


class BRX_IMPORTEXPORT BcUiPanel : public BcUiThemeHelper
{
public:
    enum Dock
    {
        kNone = -1,
        kTop = 0,
        kBottom = 1,
        kLeft = 2,
        kRight = 3,
        kFloating = kNone,
    };

public:
    // panel name is a human readable (localized) panel title
    // configKey is a fixed (global) panel name
    BcUiPanel(const ACHAR* name, const ACHAR* configKey = nullptr);
    virtual ~BcUiPanel();

    bool CreatePanel(HWND ctrl); //create the native host panel with ctrl as child
    bool DestroyPanel(); //close and destroy the native host panel
    void RegisterRestartableTool(const ACHAR* command);

    bool IsPanelCreated() const;
    bool Show(bool show = true);
    bool IsShown() const;

    //Panel properties
    const ACHAR* GetConfigKey() const; //fixed (global) panel name
    const ACHAR* GetName() const;
    void SetName(const ACHAR* name); //human readable (localized) panel title
    BcImageSourcePtr GetIconSource() const;
    void SetIconSource(BcImageSourcePtr icon);
    //Dock GetCurrentDock() const;

    //Default (initial) state
    const ACHAR* GetDefaultStackID() const;
    void SetDefaultStackID(const ACHAR* stackId);
    Dock GetDefaultDock() const;
    void SetDefaultDock(Dock dock);

protected:
    virtual void OnShow(bool shown) {}
    virtual void OnSizeChanged(int cx, int cy) {}
    virtual bool OnClosing() { return true; }

private:
    friend BcUiPanelImp;
    BcUiPanelImp* m_pImp;
};
