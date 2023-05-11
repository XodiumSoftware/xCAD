// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "MFC/CAcUi/CAcUiEdit.h"
#include "MFC/CAdUi/CAdUiComboBox.h"
class AcCmColor;

#if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
#undef _DEBUG
#include <map>
#define _DEBUG
#else
#include <map>
#endif

typedef std::map<int, AcCmColor*> AcCmColorTable;

/** _ */
class BRX_IMPORTEXPORT CAcUiComboBox: public CAdUiComboBox
{
    DECLARE_DYNAMIC(CAcUiComboBox);
public:
    CAcUiComboBox();
    virtual ~CAcUiComboBox();

    ACUI_ERROR_CODE ValidateData(CString&);
    BOOL ConvertData(CString&);
    BOOL Validate();
    CAcUiEdit* AcUiEditBox();
    void Convert();
    void SetRange(double,double);
protected:
    DECLARE_MESSAGE_MAP()
};
