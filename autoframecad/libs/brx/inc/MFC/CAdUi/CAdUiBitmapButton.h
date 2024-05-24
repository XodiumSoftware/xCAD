// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAdUi/CAdUiOwnerDrawButton.h"

/** _ */
class BRX_IMPORTEXPORT CAdUiBitmapButton: public CAdUiOwnerDrawButton
{
    DECLARE_DYNAMIC(CAdUiBitmapButton)
public:
    BOOL GetAutoSizeToBitmap();
    CAdUiBitmapButton();
    virtual ~CAdUiBitmapButton();
    void SetAutoSizeToBitmap(BOOL);
    bool SetBitmapOffsets(int,int);
    void SizeToBitmap();
    BOOL LoadBitmap(LPCTSTR);
protected:
    BOOL LoadBitmapResource(LPCTSTR,CBitmap&,HINSTANCE);
    BOOL m_bAutoSizeToBitmap;
    CBitmap m_bmp;
    CString m_bmpResId;
    int m_bmpHeight;
    int m_bmpWidth;
    int m_bmpX;
    int m_bmpY;
    int m_focusRectOffset;
    virtual BOOL OnAutoLoad();
    virtual BOOL OnLoadBitmap(LPCTSTR);
    virtual BOOL OnReload(LPCTSTR);
    virtual void DrawButton(CDC&,int,int,BOOL,BOOL,BOOL,BOOL);
    void CalcBitmapSize();

    DECLARE_MESSAGE_MAP()
private:
    virtual void PreSubclassWindow();
    
};
