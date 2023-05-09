// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

class AcTrayItemBubbleWindowControlImp;

typedef void* AcTrayItemBubbleWindowCallbackData;
typedef void (*AcTrayItemBubbleWindowCallbackFunc)(void*,int);

/** _ */
class BRX_IMPORTEXPORT AcTrayItemBubbleWindowControl
{
public:
    enum
    {
        BUBBLE_WINDOW_ERROR_NO_CREATE = 0,
        BUBBLE_WINDOW_ERROR_NO_ICONS,
        BUBBLE_WINDOW_ERROR_NO_NOTIFICATIONS,
        BUBBLE_WINDOW_CLOSE,
        BUBBLE_WINDOW_TIME_OUT,
        BUBBLE_WINDOW_HYPERLINK_CLICK,
        BUBBLE_WINDOW_DOCUMENT_DEACTIVATED
    };

    enum
    {
        BUBBLE_WINDOW_ICON_NONE = 0,
        BUBBLE_WINDOW_ICON_INFORMATION,
        BUBBLE_WINDOW_ICON_CRITICAL,
        BUBBLE_WINDOW_ICON_WARNING
    };

    AcTrayItemBubbleWindowControl();
    AcTrayItemBubbleWindowControl(const CString&,const CString&,const CString& = _T(""),const CString& = _T(""),const CString& = _T(""));
    ~AcTrayItemBubbleWindowControl();

    AcTrayItemBubbleWindowCallbackData GetCallbackData() const;
    AcTrayItemBubbleWindowCallbackFunc GetCallbackFunc() const;
    const CString& GetHyperLink() const;
    const CString& GetHyperText() const;
    const CString& GetText() const;
    const CString& GetText2() const;
    const CString& GetTitle() const;
    int GetIconType() const;
    void SetCallback(AcTrayItemBubbleWindowCallbackFunc,AcTrayItemBubbleWindowCallbackData = NULL);
    void SetHyperLink(const CString&);
    void SetHyperText(const CString&);
    void SetIconType(int);
    void SetText(const CString&);
    void SetText2(const CString&);
    void SetTitle(const CString&);
private:
// BRX START
    friend AcTrayItemBubbleWindowControlImp;
    AcTrayItemBubbleWindowControlImp* m_pBrxImp;
// BRX END
};