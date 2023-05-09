#pragma once

#ifndef _BS_MFC_CTYPEDPTRARRAY_INCLUDED_
#define _BS_MFC_CTYPEDPTRARRAY_INCLUDED_

#include "Platform/mfc/CObject.h"

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

template<class BASE_CLASS, class TYPE>
class BRXEXPORT CMfcTypedPtrArray : public BASE_CLASS
{
public:
	// Accessing elements
	TYPE GetAt(INT_PTR nIndex) const
		{ return (TYPE)BASE_CLASS::GetAt(nIndex); }
	TYPE& ElementAt(INT_PTR nIndex)
		{ return (TYPE&)BASE_CLASS::ElementAt(nIndex); }
	void SetAt(INT_PTR nIndex, TYPE ptr)
		{ BASE_CLASS::SetAt(nIndex, ptr); }

	// Potentially growing the array
	void SetAtGrow(INT_PTR nIndex, TYPE newElement)
	   { BASE_CLASS::SetAtGrow(nIndex, newElement); }
	INT_PTR Add(TYPE newElement)
	   { return BASE_CLASS::Add(newElement); }
	INT_PTR Append(const CMfcTypedPtrArray<BASE_CLASS, TYPE>& src)
	   { return BASE_CLASS::Append(src); }
	void Copy(const CMfcTypedPtrArray<BASE_CLASS, TYPE>& src)
		{ BASE_CLASS::Copy(src); }

	// Operations that move elements around
	void InsertAt(INT_PTR nIndex, TYPE newElement, INT_PTR nCount = 1)
		{ BASE_CLASS::InsertAt(nIndex, newElement, nCount); }
	void InsertAt(INT_PTR nStartIndex, CMfcTypedPtrArray<BASE_CLASS, TYPE>* pNewArray)
	   { BASE_CLASS::InsertAt(nStartIndex, pNewArray); }

	// overloaded operator helpers
	TYPE operator[](INT_PTR nIndex) const
		{ return (TYPE)BASE_CLASS::operator[](nIndex); }
	TYPE& operator[](INT_PTR nIndex)
		{ return (TYPE&)BASE_CLASS::operator[](nIndex); }
};

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  template <class TYPE, class ARG_TYPE = const TYPE>
  class BRXEXPORT CTypedPtrArray : public CMfcTypedPtrArray<TYPE, ARG_TYPE>
  {
  public:
      CTypedPtrArray() : CMfcTypedPtrArray<TYPE, ARG_TYPE>() {};
  };

#endif // !_WIN32

#endif // _BS_MFC_CARRAY_INCLUDED_
