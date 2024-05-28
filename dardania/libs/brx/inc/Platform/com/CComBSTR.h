// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// CComBSTR class and related functionality

#ifndef _BS_COM_CComBSTR_INCLUDED_
#define _BS_COM_CComBSTR_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


// ========== Platform independent ==========
struct IStream;

#ifdef _WIN32
namespace Mfc
{
#endif

class BRXEXPORT CComBSTR
{
public:
    CComBSTR() noexcept(false);
    CComBSTR(int len);
    CComBSTR(int len, LPCOLESTR source);
    CComBSTR(LPCOLESTR source);
    CComBSTR(const CComBSTR& source);
    CComBSTR(LPCSTR source);
    CComBSTR(int len, LPCSTR source);
    CComBSTR(REFGUID guid);
    ~CComBSTR() noexcept(false);

    CComBSTR& operator=(const CComBSTR& source);
    CComBSTR& operator=(LPCOLESTR source);
    CComBSTR& operator=(LPCSTR source);

    unsigned int Length() const noexcept(false);
    unsigned int ByteLength() const noexcept(false);

    BSTR Copy() const noexcept(false);
    HRESULT CopyTo(BSTR* dest) const noexcept(false);
    HRESULT CopyTo(VARIANT* pDest) const noexcept(false);

    void Attach(BSTR source) noexcept(false);
    BSTR Detach() noexcept(false);
    void Empty() noexcept(false);

    HRESULT Append(const CComBSTR& source) noexcept(false);
    HRESULT Append(LPCOLESTR source) noexcept(false);
    HRESULT AppendBSTR(BSTR source) noexcept(false);
    HRESULT Append(LPCOLESTR source, uintptr_t len) noexcept(false);
    HRESULT Append(LPCSTR source) noexcept(false);
    HRESULT Append(char chr) noexcept(false);
    HRESULT Append(wchar_t chr) noexcept(false);

    HRESULT AppendBytes(const char* source, uintptr_t len) noexcept(false);
    HRESULT AssignBSTR(const BSTR source) noexcept(false);

    HRESULT ToLower() noexcept(false);
    HRESULT ToUpper() noexcept(false);

    bool LoadString(HINSTANCE hInstance, UINT id) noexcept(false);
    bool LoadString(UINT id) noexcept(false);
    static bool LoadStringResource(HINSTANCE hInstance, UINT id, BSTR& strText) noexcept(false);
    static bool LoadStringResource(UINT id, BSTR& strText) noexcept(false);

    operator BSTR() const noexcept(false) { return m_str; };
    BSTR* operator&() noexcept(false);
    bool operator!() const noexcept(false);

    CComBSTR& operator+=(const CComBSTR& source);
    CComBSTR& operator+=(LPCOLESTR source);

    bool operator<(const CComBSTR& other) const noexcept(false);
    bool operator<(LPCOLESTR other) const;
    bool operator<(LPOLESTR other) const;
    bool operator<(LPCSTR other) const;

    bool operator>(const CComBSTR& other) const noexcept(false);
    bool operator>(LPCOLESTR other) const;
    bool operator>(LPOLESTR other) const;
    bool operator>(LPCSTR other) const;

    bool operator!=(const CComBSTR& other) const noexcept(false);
    bool operator!=(LPCOLESTR other) const;
    bool operator!=(LPOLESTR other) const;
    bool operator!=(int len) const noexcept(false);
    bool operator!=(LPCSTR other) const;

    bool operator==(const CComBSTR& other) const noexcept(false);
    bool operator==(LPCOLESTR other) const;
    bool operator==(LPOLESTR other) const;
    bool operator==(int len) const noexcept(false);
    bool operator==(LPCSTR other) const;

    HRESULT WriteToStream(IStream* stream) noexcept(false);
    HRESULT ReadFromStream(IStream* stream) noexcept(false);

    HRESULT BSTRToArray(LPSAFEARRAY *array) noexcept(false);
    HRESULT ArrayToBSTR(const SAFEARRAY *array) noexcept(false);

    static ULONG GetStreamSize(BSTR source);

public:
    BSTR m_str;
};

#ifdef _WIN32
}; // namespace Mfc
#endif

// ========== Platform specific ==========

#ifdef _WIN32
  typedef Mfc::CComBSTR CWinComBSTR;
#else  // Linux,Mac
  typedef      CComBSTR CWinComBSTR;
#endif

#endif // _BS_COM_CComBSTR_INCLUDED_
