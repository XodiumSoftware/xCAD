#include "StdAfx.h"
#include "MyWxApp.h"


extern void InitXmlResource();

#ifdef __WXMSW__
class WinFrame : public wxFrame
{
public:
    WinFrame(HWND hwnd)
    {
        this->SetHWND(hwnd);
        this->AdoptAttributesFromHWND();
        this->m_isShown = true;
        wxTopLevelWindows.Append(this);
    }
};

static WinFrame* getMainWindow()
{
    static WinFrame* win = NULL;
    if(win == NULL)
        win = new  WinFrame(adsw_acadMainWnd());
    return win;
}
#endif // __WXMSW__

bool MyWxApp::OnInit()
{
#ifdef __WXMSW__
    wxSetInstance(acrxGetApp()->GetModuleInstance());
#endif // __WXMSW__

    return (mainWindow() != NULL);
}

bool MyWxApp::initWxApp()
{
    if(wxInitialize())
    {
        ::InitXmlResource();
        ::wxInitAllImageHandlers();
        wxXmlResource::Get()->InitAllHandlers();

#ifdef __WXMSW__
        wxApp::SetInstance(new  MyWxApp());
        if (wxTheApp && wxTheApp->CallOnInit())
#endif // __WXMSW__
            return true;
    }
    return false;
}

void MyWxApp::uninitWxApp()
{
    wxUninitialize();
}

wxWindow* MyWxApp::mainWindow()
{
#ifdef __WXMSW__
    return getMainWindow();
#else
    return wxTheApp->GetTopWindow();
#endif // __WXMSW__
}

IMPLEMENT_APP_NO_MAIN(MyWxApp);
IMPLEMENT_WX_THEME_SUPPORT;
