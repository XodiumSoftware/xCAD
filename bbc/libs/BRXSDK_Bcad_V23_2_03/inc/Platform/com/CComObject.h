// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// CComObject class and related functionality

#pragma once

#ifndef _BS_COM_CCOMOBJECT_INCLUDED_
#define _BS_COM_CCOMOBJECT_INCLUDED_

#ifndef _WIN32  // on Linux/Mac

#include "com_defs.h"

#include "CComSingleThreadModel.h"
#include "CComMultiThreadModel.h"
#include "CComObjectRootEx.h"

#include "../atl/atl_defs.h"


// Base is the user's class derived from CComObjectRoot and whatever interfaces is
// needed to be supported by the object

template <class Base>
class CComObject : public Base
{
public:
    // typedef Base _BaseClass;

    CComObject(void* = NULL) noexcept(false)
    {
        //_pAtlModule->Lock();
    }
    // Set refcount to -(LONG_MAX/2) to protect destruction and catch mismatched
    // Release() calls in debug builds
    virtual ~CComObject() noexcept(false)
    {
        Base::m_dwRef = -(LONG_MAX/2);
        Base::FinalRelease();
        //_pAtlModule->Unlock();
    }

    // If InternalAddRef or InternalRelease is undefined then your class
    // doesn't derive from CComObjectRoot
    STDMETHOD_(ULONG, AddRef)()
    {
        return Base::InternalAddRef();
    }
    STDMETHOD_(ULONG, Release)()
    {
        ULONG refcnt = Base::InternalRelease();
        if (refcnt == 0)
            delete this;
        return refcnt;
    }

    // if _InternalQueryInterface is undefined then you forgot BEGIN_COM_MAP
    STDMETHOD(QueryInterface)(REFIID iid, void ** ppvObject) noexcept(false)
    {
        // return _InternalQueryInterface(iid, ppvObject);
        return Base::QueryInterface(iid, ppvObject);        
    }

    template <class QI>
    HRESULT STDMETHODCALLTYPE QueryInterface(QI** ppvInstance) noexcept(false)
    {
        // return QueryInterface(__uuidof(QI), (void**)ppvInstance);
        return E_NOINTERFACE;
    }

    static HRESULT WINAPI CreateInstance(CComObject<Base>** ppvInstance) noexcept(false);
};


template <class Base>
HRESULT WINAPI CComObject<Base>::CreateInstance(CComObject<Base>** ppvInstance) noexcept(false)
{
    ATLASSERT(ppvInstance != NULL);

    if (ppvInstance == NULL)
        return E_POINTER;
    *ppvInstance = NULL;

    HRESULT hRes = E_OUTOFMEMORY;

    CComObject<Base>* pvInstance = NULL;

    ATLTRY(pvInstance = new CComObject<Base>());
    if (pvInstance != NULL)
    {
        pvInstance->SetVoid(NULL);

        pvInstance->InternalFinalConstructAddRef();
        hRes = pvInstance->_AtlInitialConstruct();
        if (SUCCEEDED(hRes))
            hRes = pvInstance->FinalConstruct();
        if (SUCCEEDED(hRes))
            hRes = pvInstance->_AtlFinalConstruct();
        pvInstance->InternalFinalConstructRelease();

        if (hRes != S_OK)
        {
            delete pvInstance;
            pvInstance = NULL;
        }
    }

    *ppvInstance = pvInstance;
    return hRes;
}



#endif // !_WIN32

#endif // _BS_COM_CCOMOBJECT_INCLUDED_
