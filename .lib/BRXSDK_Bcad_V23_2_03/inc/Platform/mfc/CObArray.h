// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows MFC CObArray type and functions

#pragma once

#ifndef _BS_MFC_COBARRAY_INCLUDED_
#define _BS_MFC_COBARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

// ========== Platform independent =======

class BRXEXPORT CMfcObArray : public CMfcObject
{
	//DECLARE_SERIAL(CMfcObArray)

public:
	CMfcObArray();
	~CMfcObArray();

	INT_PTR GetSize() const;
	INT_PTR GetCount() const;
	BOOL IsEmpty() const;
	INT_PTR GetUpperBound() const;
	void SetSize(INT_PTR nNewSize, INT_PTR nGrowBy = -1);

	// Clean up
	void FreeExtra();
	void RemoveAll();

	// Accessing elements
	CMfcObject* GetAt(INT_PTR nIndex) const;
	void SetAt(INT_PTR nIndex, CMfcObject* newElement);

	CMfcObject*& ElementAt(INT_PTR nIndex);

	// Direct Access to the element data (may return NULL)
	const CMfcObject** GetData() const;
	CMfcObject** GetData();

	// Potentially growing the array
	void SetAtGrow(INT_PTR nIndex, CMfcObject* newElement);

	INT_PTR Add(CMfcObject* newElement);

	INT_PTR Append(const CMfcObArray& src);
	void Copy(const CMfcObArray& src);

	// overloaded operator helpers
	CMfcObject* operator[](INT_PTR nIndex) const;
	CMfcObject*& operator[](INT_PTR nIndex);

	// Operations that move elements around
	void InsertAt(INT_PTR nIndex, CMfcObject* newElement, INT_PTR nCount = 1);

	void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);
	void InsertAt(INT_PTR nStartIndex, CMfcObArray* pNewArray);

protected:
	CMfcObject** m_pArrayData;
	INT_PTR m_nArraySize;
	INT_PTR m_nArrayMaxSize;
	INT_PTR m_nSizeGrowBy;

public:
//	void Serialize(CArchive&);
	//void Dump(CDumpContext&) const;
	void AssertValid() const;

protected:
	// local typedefs for class templates
	typedef CMfcObject* BASE_TYPE;
	typedef CMfcObject* BASE_ARG_TYPE;
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

class BRXEXPORT CObArray : public CMfcObArray
{
public:
    CObArray( ) noexcept(false) : CMfcObArray() {};
};

#endif

#endif // !_WIN32#endif // _BS_MFC_COBARRAY_INCLUDED_
