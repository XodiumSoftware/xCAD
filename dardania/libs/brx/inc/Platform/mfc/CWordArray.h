// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef _BS_MFC_CWORDARRAY_INCLUDED_
#define _BS_MFC_CWORDARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcWordArray : public CObject
{
    //DECLARE_SERIAL(CMfcWordArray)

public:
    CMfcWordArray();
    ~CMfcWordArray();

    INT_PTR GetSize() const;
    INT_PTR GetCount() const;
    BOOL IsEmpty() const;
    INT_PTR GetUpperBound() const;
    void SetSize(INT_PTR nNewSize, INT_PTR nGrowBy = -1);

    // Clean up
    void FreeExtra();
    void RemoveAll();

    // Accessing elements
    WORD GetAt(INT_PTR nIndex) const;
    void SetAt(INT_PTR nIndex, WORD newElement);

    WORD& ElementAt(INT_PTR nIndex);

    // Direct Access to the element data (may return NULL)
    const WORD* GetData() const;
    WORD* GetData();

    // Potentially growing the array
    void SetAtGrow(INT_PTR nIndex, WORD newElement);

    INT_PTR Add(WORD newElement);

    INT_PTR Append(const CMfcWordArray& src);
    void Copy(const CMfcWordArray& src);

    // overloaded operator helpers
    WORD operator[](INT_PTR nIndex) const;
    WORD& operator[](INT_PTR nIndex);

    // Operations that move elements around
    void InsertAt(INT_PTR nIndex, WORD newElement, INT_PTR nCount = 1);

    void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);
    void InsertAt(INT_PTR nStartIndex, CMfcWordArray* pNewArray);

protected:
    WORD* m_pArrayData;
    INT_PTR m_arraySize;
    INT_PTR m_arrayMaxSize;
    INT_PTR m_sizeGrowBy;

public:
    //void Serialize(CArchive&);
    //void Dump(CDumpContext&) const;
    void AssertValid() const;

protected:
    // local typedefs for class templates
    typedef WORD BASE_TYPE;
    typedef WORD BASE_ARG_TYPE;
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CWordArray : public CMfcWordArray
{
public:
    CWordArray( ) noexcept(false) : CMfcWordArray() {};
};

#endif // !_WIN32

#endif // _BS_MFC_CWORDARRAY_INCLUDED_
