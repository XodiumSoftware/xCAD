// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class wxMessageDialogBase;
class wxRadioBox;

class TestMessageBoxDialog : public wxDialog
{
public:
    TestMessageBoxDialog(wxWindow *parent);

    bool Create();

protected:
    wxString GetBoxTitle() { return m_textTitle->GetValue(); }
    wxString GetMessage() { return m_textMsg->GetValue(); }
    long GetStyle();

    void PrepareMessageDialog(wxMessageDialogBase &dlg);

    virtual void AddAdditionalTextOptions(wxSizer *WXUNUSED(sizer)) { }
    virtual void AddAdditionalFlags(wxSizer *WXUNUSED(sizer)) { }

    void OnApply(wxCommandEvent& event);
    void OnClose(wxCommandEvent& event);
    void OnUpdateLabelUI(wxUpdateUIEvent& event);
    void OnUpdateNoDefaultUI(wxUpdateUIEvent& event);

private:
    enum
    {
        Btn_Yes,
        Btn_No,
        Btn_Ok,
        Btn_Cancel,
        Btn_Help,
        Btn_Max
    };

    struct BtnInfo
    {
        int flag;
        const char *name;
    };

    static const BtnInfo ms_btnInfo[Btn_Max];

    enum
    {
        MsgDlgIcon_No,
        MsgDlgIcon_None,
        MsgDlgIcon_Info,
        MsgDlgIcon_Question,
        MsgDlgIcon_Warning,
        MsgDlgIcon_Error,
        MsgDlgIcon_AuthNeeded,
        MsgDlgIcon_Max
    };

    wxTextCtrl *m_textTitle,
               *m_textMsg,
               *m_textExtMsg;

    wxCheckBox *m_buttons[Btn_Max];
    wxTextCtrl *m_labels[Btn_Max];

    wxRadioBox *m_icons;

    wxCheckBox *m_chkNoDefault,
               *m_chkCentre;

    DECLARE_EVENT_TABLE()
    wxDECLARE_NO_COPY_CLASS(TestMessageBoxDialog);
};
