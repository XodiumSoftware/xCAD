// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#if defined(_AFXEXT) && defined(__cplusplus)
  #if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
    #undef _DEBUG
    #include <afxcoll.h>
    #include <afxtempl.h>
    #define _DEBUG
  #else
    #include <afxcoll.h>
    #include <afxtempl.h>
  #endif
#endif

/** _ */
template<class Type> class CNavArray: public CTypedPtrArray<CObArray,Type*>
{
public:
    BOOL IsIndexValid(INT_PTR);
    CNavArray();
    int GetCount();
    Type* AddData();
    Type* GetData(INT_PTR);
    virtual ~CNavArray();
    void RemoveData(INT_PTR);
    void RemoveAllData();
protected:
    virtual Type* NewData();
};

template<class Type> BOOL CNavArray<Type>::IsIndexValid(INT_PTR i)
{
    return ((i < 0) || (i > this->GetUpperBound())) ? FALSE : TRUE;
}

template<class Type> CNavArray<Type>::CNavArray() :
CTypedPtrArray<CObArray,Type*>()
{
}

template<class Type> int CNavArray<Type>::GetCount()
{
    return (int)(this->GetUpperBound() + 1);
}

template<class Type> Type* CNavArray<Type>::AddData()
{
    Type* pData = this->NewData();
    if(!pData)
        return NULL;
    this->Add(pData);
    return pData;
}

template<class Type> Type* CNavArray<Type>::GetData(INT_PTR i)
{
    if (!this->IsIndexValid(i))
        return NULL;

    Type* pData = this->GetAt(i);
    return pData;
}

template<class Type> CNavArray<Type>::~CNavArray()
{
    this->RemoveAllData();
}

template<class Type> void CNavArray<Type>::RemoveData(INT_PTR i)
{
    if (!IsIndexValid(i))
        return;

    Type* pData = this->GetAt(i);
    this->RemoveAt(i);
    delete pData;
}

template<class Type> void CNavArray<Type>::RemoveAllData()
{
    Type* pData = NULL;
    INT_PTR count = (INT_PTR)this->GetCount();
    for(INT_PTR i = 0; i < count; ++i)
    {
        pData = this->GetAt(i);
        delete pData;
    }
    this->RemoveAll();
    this->FreeExtra();
}

template<class Type> Type* CNavArray<Type>::NewData()
{
    return new Type;
}