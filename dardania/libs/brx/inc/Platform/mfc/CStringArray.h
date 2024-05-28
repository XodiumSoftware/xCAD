// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CStringArray type and functions

#ifndef _BS_MFC_CSTRINGARRAY_INCLUDED_
#define _BS_MFC_CSTRINGARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

#ifdef _WIN32
namespace Mfc
{
#endif

class CString;
class BRXEXPORT CStringArray : public CObject
{

    //DECLARE_SERIAL(CStringArray)
public:

// Construction
    CStringArray();

// Attributes
    INT_PTR GetSize() const;
    INT_PTR GetCount() const;
    BOOL IsEmpty() const;
    INT_PTR GetUpperBound() const;
    void SetSize(INT_PTR nNewSize, INT_PTR nGrowBy = -1);

// Operations
    // Clean up
    void FreeExtra();
    void RemoveAll();

    // Accessing elements
    const CString& GetAt(INT_PTR nIndex) const;
    void SetAt(INT_PTR nIndex, LPCTSTR newElement);

    void SetAt(INT_PTR nIndex, const CString& newElement);

    CString& ElementAt(INT_PTR nIndex);

    // Direct Access to the element data (may return NULL)
    const CString* GetData() const;
    CString* GetData();

    // Potentially growing the array
    void SetAtGrow(INT_PTR nIndex, LPCTSTR newElement);

    void SetAtGrow(INT_PTR nIndex, const CString& newElement);

    INT_PTR Add(LPCTSTR newElement);

    INT_PTR Add(const CString& newElement);

    INT_PTR Append(const CStringArray& src);
    void Copy(const CStringArray& src);

    // overloaded operator helpers
    const CString& operator[](INT_PTR nIndex) const;
    CString& operator[](INT_PTR nIndex);

    // Operations that move elements around
    void InsertAt(INT_PTR nIndex, LPCTSTR newElement, INT_PTR nCount = 1);

    void InsertAt(INT_PTR nIndex, const CString& newElement, INT_PTR nCount = 1);

    void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);
    void InsertAt(INT_PTR nStartIndex, const CStringArray* pNewArray);

// Implementation
protected:
    CString* m_pArrayData;
    INT_PTR m_nArraySize;
    INT_PTR m_nArrayMaxSize;
    INT_PTR m_nSizeGrowBy;

    void InsertEmpty(INT_PTR nIndex, INT_PTR nCount);

public:
    ~CStringArray();

    //void Serialize(CArchive&);
#ifdef _DEBUG
    //void Dump(CDumpContext&) const;
    void AssertValid() const;
#endif

protected:
    // local typedefs for class templates
    typedef CString BASE_TYPE;
    typedef LPCTSTR BASE_ARG_TYPE;
};

#ifdef _WIN32
}   // namespace Mfc
#endif

// ========== Platform specific ==========
#ifdef _WIN32
    typedef Mfc::CStringArray   CMfcStringArray;
#else
    typedef      CStringArray   CMfcStringArray;
#endif

#endif // _BS_MFC_CSTRINGARRAY_INCLUDED_
