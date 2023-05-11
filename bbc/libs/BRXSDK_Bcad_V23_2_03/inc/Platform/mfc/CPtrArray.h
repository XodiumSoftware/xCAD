// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CPtrArray type and functions

#pragma once

#ifndef _BS_MFC_CPTRARRAY_INCLUDED_
#define _BS_MFC_CPTRARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent ==========

class BRXEXPORT CMfcPtrArray : public CObject
{
	//DECLARE_DYNAMIC(CMfcPtrArray)

public:
	CMfcPtrArray();
	~CMfcPtrArray();

	INT_PTR GetSize() const;
	INT_PTR GetCount() const;
	BOOL IsEmpty() const;
	INT_PTR GetUpperBound() const;
	void SetSize(INT_PTR nNewSize, INT_PTR nGrowBy = -1);

	// Clean up
	void FreeExtra();
	void RemoveAll();

	// Accessing elements
	void* GetAt(INT_PTR nIndex) const;
	void SetAt(INT_PTR nIndex, void* newElement);

	void*& ElementAt(INT_PTR nIndex);

	// Direct Access to the element data (may return NULL)
	const void** GetData() const;
	void** GetData();

	// Potentially growing the array
	void SetAtGrow(INT_PTR nIndex, void* newElement);

	INT_PTR Add(void* newElement);

	INT_PTR Append(const CMfcPtrArray& src);
	void Copy(const CMfcPtrArray& src);

	// overloaded operator helpers
	void* operator[](INT_PTR nIndex) const;
	void*& operator[](INT_PTR nIndex);

	// Operations that move elements around
	void InsertAt(INT_PTR nIndex, void* newElement, INT_PTR nCount = 1);

	void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);
	void InsertAt(INT_PTR nStartIndex, CMfcPtrArray* pNewArray);

protected:
	void** m_pArrayData;
	INT_PTR m_arraySize;
	INT_PTR m_nArrayMaxSize;
	INT_PTR m_nSizeGrowBy;

public:
	//void Dump(CDumpContext&) const;
	void AssertValid() const;

protected:
	// local typedefs for class templates
	typedef void* BASE_TYPE;
	typedef void* BASE_ARG_TYPE;
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CPtrArray : public CMfcPtrArray
{
public:
    CPtrArray( ) noexcept(false) : CMfcPtrArray() {};
};

#endif // !_WIN32

#endif // _BS_MFC_CPTRARRAY_INCLUDED_
