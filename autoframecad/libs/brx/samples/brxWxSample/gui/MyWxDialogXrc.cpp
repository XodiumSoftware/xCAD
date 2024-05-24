// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "MyWxDialogXrc.h"
#include "WxUserInteraction.h"


IMPLEMENT_DYNAMIC_CLASS( MyWxDialogXrc, wxDialog )

  BEGIN_EVENT_TABLE( MyWxDialogXrc, wxDialog )
  ////@begin MyWxDialogXrc event table entries
  EVT_BUTTON( XRCID("ID_BUTTON"), MyWxDialogXrc::OnButtonClick )
  ////@end MyWxDialogXrc event table entries
  END_EVENT_TABLE()


  MyWxDialogXrc::MyWxDialogXrc()
{
  Init();
}

MyWxDialogXrc::MyWxDialogXrc( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
  Init();
  Create(parent, id, caption, pos, size, style);
}

bool MyWxDialogXrc::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
  SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
  SetParent(parent);
  CreateControls();
  if (GetSizer())
  {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
  return true;
}

MyWxDialogXrc::~MyWxDialogXrc()
{
}

void MyWxDialogXrc::Init()
{
}

void MyWxDialogXrc::CreateControls()
{
  if (!wxXmlResource::Get()->LoadDialog(this, GetParent(), _T("ID_WXDLGXRC")))
    wxLogError(wxT("Missing wxXmlResource::Get()->Load() in OnInit()?"));
}

bool MyWxDialogXrc::ShowToolTips()
{
  return true;
}

wxBitmap MyWxDialogXrc::GetBitmapResource( const wxString& name )
{
  wxUnusedVar(name);
  return wxNullBitmap;
}

wxIcon MyWxDialogXrc::GetIconResource( const wxString& name )
{
  wxUnusedVar(name);
  return wxNullIcon;
}

void MyWxDialogXrc::OnButtonClick( wxCommandEvent& event )
{
  WxUserInteraction action;
  AcGePoint3d pnt;
  ads_name name = {0L, 0L};
  wxTextCtrl *pText =  (wxTextCtrl*)FindWindowById(XRCID("ID_TEXTCTRL"));
  if(pText)
  {
    wxString val = _T("ID=");
    if(acedEntSel(_T("\nSelect Entity"), name, asDblArray(pnt)) == RTNORM)
    {
      val+=wxString::Format(_T("%i"),int(name[0]));
    }
    else
    {
      val+=_T("NULL");
    }
    pText->SetValue(val);
  }
  event.Skip();
}

#ifdef __WXMSW
WXLRESULT MyWxDialogXrc::MSWWindowProc( WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam )
{
  switch(nMsg)
  {
  case WM_ACAD_KEEPFOCUS:
    return TRUE;
  }
  return wxDialog::MSWWindowProc(nMsg, wParam, lParam);
}
#endif // __WXMSW
