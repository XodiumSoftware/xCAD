#pragma once

////@begin control identifiers
#define ID_WXDLGXRC 10000
#define SYMBOL_WXDLGXRC_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_WXDLGXRC_TITLE _("MyWxDialogXrc")
#define SYMBOL_WXDLGXRC_IDNAME ID_WXDLGXRC
#define SYMBOL_WXDLGXRC_SIZE wxSize(400, 300)
#define SYMBOL_WXDLGXRC_POSITION wxDefaultPosition
////@end control identifiers


class MyWxDialogXrc: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( MyWxDialogXrc )
    DECLARE_EVENT_TABLE()

public:

    MyWxDialogXrc();
    MyWxDialogXrc( wxWindow* parent,
                   wxWindowID id = SYMBOL_WXDLGXRC_IDNAME,
                   const wxString& caption = SYMBOL_WXDLGXRC_TITLE,
                   const wxPoint& pos = SYMBOL_WXDLGXRC_POSITION,
                   const wxSize& size = SYMBOL_WXDLGXRC_SIZE,
                   long style = SYMBOL_WXDLGXRC_STYLE );

    bool Create( wxWindow* parent,
                 wxWindowID id = SYMBOL_WXDLGXRC_IDNAME,
                 const wxString& caption = SYMBOL_WXDLGXRC_TITLE,
                 const wxPoint& pos = SYMBOL_WXDLGXRC_POSITION,
                 const wxSize& size = SYMBOL_WXDLGXRC_SIZE,
                 long style = SYMBOL_WXDLGXRC_STYLE );

    ~MyWxDialogXrc();

    void Init();
    void CreateControls();
    void OnButtonClick( wxCommandEvent& event );
    wxBitmap GetBitmapResource( const wxString& name );
    wxIcon GetIconResource( const wxString& name );
    static bool ShowToolTips();

#ifdef __WXMSW
    virtual WXLRESULT MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam);
#endif // __WXMSW

};
