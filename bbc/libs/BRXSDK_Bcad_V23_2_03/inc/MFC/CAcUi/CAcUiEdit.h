// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiEdit.h"

#define AC_ES_STRING 1
#define AC_ES_SYMBOL 2
#define AC_ES_NUMERIC 4
#define AC_ES_ANGLE 8
#define AC_ES_VAL_ONKILLFOCUS 16
#define AC_ES_CONV_ONKILLFOCUS 32
#define AC_ES_SHOW_ERRMSG 64
#define AC_ES_ERRMSG_ALLOWIGNORE 128
#define AC_ES_NOZERO 256
#define AC_ES_NOBLANK 512
#define AC_ES_NONEGATIVE 1024
#define AC_ES_INRANGE 2048

enum ACUI_ERROR_CODE
{
    kAcUiError_None = 0,
    kAcUiError_Blank,
    kAcUiError_Symbol,
    kAcUiError_Numeric,
    kAcUiError_Angle,
    kAcUiError_Zero,
    kAcUiError_Negative,
    kAcUiError_Range
};

/** _ */
class BRX_IMPORTEXPORT CAcUiEdit: public CAdUiEdit
{
    DECLARE_DYNAMIC(CAcUiEdit)
public:
    ACUI_ERROR_CODE ValidateData(CString&);
    BOOL ConvertData(CString&);
    BOOL HasChanged();
    BOOL m_bChanged;
    BOOL m_bTouch;
    BOOL Validate();
    CAcUiEdit();
    CString m_csMsg;
    double m_dMaxValue;
    double m_dMinValue;
    virtual void SetStyleMask(DWORD);
    virtual ~CAcUiEdit();
    void Convert();
    void SetDirty();
    void SetRange(double,double);
protected:
    afx_msg void OnErrSpace();
    afx_msg void OnKillFocus(CWnd*);
    virtual ADUI_REPLY DoAdUiMessage(ADUI_NOTIFY,UINT,LPARAM);
    afx_msg BOOL OnChange();

    DECLARE_MESSAGE_MAP()

//BRX START
private:
    void* m_pBrxImp;
//BRX END
};
