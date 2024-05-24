// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC CDWordArray type and functions

#ifndef _BS_MFC_CMFCDWORDARRAY_INCLUDED_
#define _BS_MFC_CMFCDWORDARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcDWordArray : public CObject
{
    //DECLARE_SERIAL(CMfcDWordArray)

public:
    CMfcDWordArray();
    ~CMfcDWordArray();

    INT_PTR GetSize() const;
    INT_PTR GetCount() const;
    BOOL IsEmpty() const;
    INT_PTR GetUpperBound() const;
    void SetSize(INT_PTR nNewSize, INT_PTR nGrowBy = -1);

    // Clean up
    void FreeExtra();
    void RemoveAll();

    // Accessing elements
    DWORD GetAt(INT_PTR nIndex) const;
    void SetAt(INT_PTR nIndex, DWORD newElement);

    DWORD& ElementAt(INT_PTR nIndex);

    // Direct Access to the element data (may return NULL)
    const DWORD* GetData() const;
    DWORD* GetData();

    // Potentially growing the array
    void SetAtGrow(INT_PTR nIndex, DWORD newElement);

    INT_PTR Add(DWORD newElement);

    INT_PTR Append(const CMfcDWordArray& src);
    void Copy(const CMfcDWordArray& src);

    // overloaded operator helpers
    DWORD operator[](INT_PTR nIndex) const;
    DWORD& operator[](INT_PTR nIndex);

    // Operations that move elements around
    void InsertAt(INT_PTR nIndex, DWORD newElement, INT_PTR nCount = 1);

    void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);
    void InsertAt(INT_PTR nStartIndex, CMfcDWordArray* pNewArray);

protected:
    DWORD* m_pArrayData;
    INT_PTR m_arraySize;
    INT_PTR m_arrayMaxSize;
    INT_PTR m_sizeGrowBy;

public:
    //void Serialize(CArchive&);
    //void Dump(CDumpContext&) const;
    void AssertValid() const;

protected:
    // local typedefs for class templates
    typedef DWORD BASE_TYPE;
    typedef DWORD BASE_ARG_TYPE;
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CDWordArray : public CMfcDWordArray
{
public:
    CDWordArray( ) noexcept(false) : CMfcDWordArray() {};
};

#endif // !_WIN32

#endif // _BS_MFC_CDWORDARRAY_INCLUDED_
