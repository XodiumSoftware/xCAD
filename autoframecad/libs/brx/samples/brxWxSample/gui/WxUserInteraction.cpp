// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "WxUserInteraction.h"
#include "MyWxApp.h"

#ifdef __WXMSW__
WxUserInteraction::WxUserInteraction()
{
    userInteraction(acDocManagerPtr()->curDocument(),true);
}

WxUserInteraction::WxUserInteraction( AcApDocument* pDocument,bool prompting )
{
    userInteraction(pDocument,prompting);
}

WxUserInteraction::~WxUserInteraction(void)
{
    undoUserInteraction();
}

void WxUserInteraction::userInteraction(AcApDocument* pDocument,bool prompting)
{
    AcApDocManager* pDocMan = acDocManagerPtr();
    if(pDocMan->curDocument() == pDocument)
    {
        pDocMan->disableDocumentActivation();
        if(!prompting)
            return;

        HWND hwMainWnd = adsw_acadMainWnd();
        if(::IsWindowEnabled(hwMainWnd) == TRUE)
            return;

        m_activeWindow = GetFocus();
        for (HWND window = ::GetActiveWindow(); window != NULL; window = ::GetWindow(window, GW_OWNER))
        {
            if (window == hwMainWnd)
                break;
            m_wnds.push_back(window);
        }
        ::EnableWindow(hwMainWnd, TRUE);
        ::SetFocus(hwMainWnd);
        for(size_t idx = 0 ; idx < m_wnds.size() ; idx++)
        {
            ::ShowWindow(m_wnds[idx],SW_HIDE);
        }
    }
}

void WxUserInteraction::undoUserInteraction()
{
  acDocManagerPtr()->enableDocumentActivation();
  if(m_wnds.size() > 0)
  {
    for (std::vector<HWND>::reverse_iterator it = m_wnds.rbegin() ; it != m_wnds.rend(); ++it)
    {
     ::ShowWindow(*it,SW_SHOW);
    }
    ::EnableWindow(adsw_acadMainWnd(), FALSE);
    ::SetFocus(m_activeWindow);
  }
}

#else

WxUserInteraction::WxUserInteraction()
{
  userInteraction(acDocManagerPtr()->curDocument(),true);
}

WxUserInteraction::WxUserInteraction( AcApDocument* pDocument,bool prompting )
{
  userInteraction(pDocument,prompting);
}

WxUserInteraction::~WxUserInteraction(void)
{
  undoUserInteraction();
}

void WxUserInteraction::userInteraction(AcApDocument* pDocument,bool prompting)
{
  AcApDocManager* pDocMan = acDocManagerPtr();
  if(pDocMan->curDocument() == pDocument)
  {
    pDocMan->disableDocumentActivation();
    if(!prompting)
      return;

    wxWindow *pMainWindow = MyWxApp::mainWindow();
    if(pMainWindow->IsEnabled())
      return;

    m_activeWindow = wxWindow::FindFocus();
    for (wxWindow *window = m_activeWindow; window != NULL; window = window->GetParent())
    {
      if (window == pMainWindow)
        break;
      m_wnds.push_back(window);
    }

    pMainWindow->Enable();
    pMainWindow->SetFocus();

    for (std::vector<wxWindow*>::iterator it = m_wnds.begin() ; it != m_wnds.end(); ++it)
    {
      wxWindow *window = *it;
      if(window)
       window->Hide();
    }
  }
}

void WxUserInteraction::undoUserInteraction()
{
  acDocManagerPtr()->enableDocumentActivation();
  if(m_wnds.size() > 0)
  {
    for (std::vector<wxWindow*>::reverse_iterator it = m_wnds.rbegin() ; it != m_wnds.rend(); ++it)
    {
      wxWindow *window = *it;
      if(window)
        window->Show(true);
    }
    if(m_activeWindow)
    {
      m_activeWindow->Enable();
      m_activeWindow->SetFocus();
    }
  }
}

#endif
