// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "MFC/CAcUi/CAcUiGlobal.h"
#include "MFC/CAdUi/CAdUiGlobal.h"
#include "Misc/MiscGlobal.h"

/** _ */
class BRX_IMPORTEXPORT CAcUiString: public CString
{
public:
    BOOL IsAlphabetic(int) const;
    BOOL IsAlphanumeric(int) const;
    BOOL IsBlank(int) const;
    BOOL IsHexNumeric(int) const;
    BOOL IsLowercase(int) const;
    BOOL IsNumeric(int) const;
    BOOL IsPunctuation(int) const;
    BOOL IsTab(int) const;
    BOOL IsUppercase(int) const;
    BOOL IsWhiteSpace(int) const;
    CAcUiString();
    CAcUiString(ACHAR,int = 1);
    CAcUiString(const CString&);
    CAcUiString(LPCTSTR);
    CAcUiString(LPCTSTR,int);
    CAcUiString(UINT);
    CString CreateEllipsedString(CDC*,CString,UINT);
    void ConvertFromMenuExecString();
    void ConvertMenuExecString();
    void ExpandTabs(int = 8);
    void FixFileName();
    void GetCurrentWorkingDirectory();
    void MakeCharLower(int);
    void MakeCharUpper(int);
    void ReplaceCharWithChar(ACHAR,ACHAR);
    void ShortenString(CDC*,CString,UINT);
    void StripDiesel();
    void StripMnemonic();
    void StripPrecedingBlanks();
    void StripPrecedingCharacters(ACHAR);
    void StripTrailingBlanks();
    void StripTrailingCharacters(ACHAR);
    void WrapLine(CAcUiString&,int);
    void WrapLine(CStringList&,int);
};
