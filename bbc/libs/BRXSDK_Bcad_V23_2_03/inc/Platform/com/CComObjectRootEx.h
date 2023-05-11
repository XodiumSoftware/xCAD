// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// CComObjectRootEx class and related functionality

#pragma once

#ifndef _BS_COM_CCOMOBJECTROOTEX_INCLUDED_
#define _BS_COM_CCOMOBJECTROOTEX_INCLUDED_

#ifndef _WIN32  // on Linux/Mac

#include "com_defs.h"
#include "CComObjectThreadModel.h"


// CComObjectRootBase

// forward, effectively unused
struct _ATL_INTMAP_ENTRY;

class CComObjectRootBase
{
public:
    CComObjectRootBase () { m_dwRef = 0L; m_pOuterUnknown = NULL; };
    ~CComObjectRootBase() {};

    HRESULT FinalConstruct() { return S_OK; };
    void FinalRelease() {};

    HRESULT _AtlFinalConstruct() { return S_OK; };
    void _AtlFinalRelease() {};

    // void _HRPass(HRESULT hr) { (hr); };
    // void _HRFail(HRESULT hr) { (hr); };

    // called during Module::Init and Module::Term
    static void WINAPI ObjectMain(bool /* isStarting */) {};

    static const struct _ATL_CATMAP_ENTRY* GetCategoryMap() { return NULL; };
    static HRESULT WINAPI InternalQueryInterface(void* pThis,
                                                 const _ATL_INTMAP_ENTRY* pEntries,
                                                 REFIID iid,
                                                 void** ppvObject)
    {
        // ASSERT(ppvObject != NULL);
        // ASSERT(pThis != NULL);
        // // First entry in the com map should be a simple map entry
        // ASSERT(pEntries->pFunc == _ATL_SIMPLEMAPENTRY);
        // return AtlInternalQueryInterface(pThis, pEntries, iid, ppvObject);
        return S_OK;
    };

    ULONG OuterAddRef()  { return m_pOuterUnknown->AddRef(); };
    ULONG OuterRelease() { return m_pOuterUnknown->Release(); };
    HRESULT OuterQueryInterface(REFIID iid, void ** ppvObject)
    {
        // return m_pOuterUnknown->QueryInterface(iid, ppvObject);
        return S_OK;
    }

    void SetVoid(void*) {};
    void InternalFinalConstructAddRef()  {};
    void InternalFinalConstructRelease() {};

    // static HRESULT WINAPI _Break(void* /* pv */, REFIID iid, void** /* ppvObject */, DWORD_PTR /* dw */)
    // {
    //     (iid);
    //     _ATLDUMPIID(iid, _T("Break due to QI for interface "), S_OK);
    //     DebugBreak();
    //     return S_FALSE;
    // }
    // static HRESULT WINAPI _NoInterface(void* /* pv */, REFIID /* iid */, void** /* ppvObject */, DWORD_PTR /* dw */)
    // {
    //     return E_NOINTERFACE;
    // }
    // static HRESULT WINAPI _Creator(void* pv, REFIID iid, void** ppvObject, DWORD_PTR dw)
    // {
    //     _ATL_CREATORDATA* pcd = (_ATL_CREATORDATA*)dw;
    //     return pcd->pFunc(pv, iid, ppvObject);
    // }
    // static HRESULT WINAPI _Delegate(void* pv, REFIID iid, void** ppvObject, DWORD_PTR dw)
    // {
    //     HRESULT hRes = E_NOINTERFACE;
    //     IUnknown* p = *(IUnknown**)((DWORD_PTR)pv + dw);
    //     if (p != NULL)
    //         hRes = p->QueryInterface(iid, ppvObject);
    //     return hRes;
    // }
    // static HRESULT WINAPI _Chain(void* pv, REFIID iid, void** ppvObject, DWORD_PTR dw)
    // {
    //     _ATL_CHAINDATA* pcd = (_ATL_CHAINDATA*)dw;
    //     void* p = (void*)((DWORD_PTR)pv + pcd->dwOffset);
    //     return InternalQueryInterface(p, pcd->pFunc(), iid, ppvObject);
    // }
    // static HRESULT WINAPI _ChainAttr(void* pv, REFIID iid, void** ppvObject, DWORD_PTR dw)
    // {
    //     const _ATL_INTMAP_ENTRY* (WINAPI *pFunc)() = (const _ATL_INTMAP_ENTRY* (WINAPI *)())dw;
    //     const _ATL_INTMAP_ENTRY *pEntries = pFunc();
    //     if (pEntries == NULL)
    //         return S_OK;
    //     return InternalQueryInterface(pv, pEntries, iid, ppvObject);
    // }
    // static HRESULT WINAPI _Cache(void* pv, REFIID iid, void** ppvObject, DWORD_PTR dw)
    // {
    //     HRESULT hRes = E_NOINTERFACE;
    //     _ATL_CACHEDATA* pcd = (_ATL_CACHEDATA*)dw;
    //     IUnknown** pp = (IUnknown**)((DWORD_PTR)pv + pcd->dwOffsetVar);
    //     if (*pp == NULL)
    //         hRes = pcd->pFunc(pv, __uuidof(IUnknown), (void**)pp);
    //     if (*pp != NULL)
    //         hRes = (*pp)->QueryInterface(iid, ppvObject);
    //     return hRes;
    // }

public:
    LONG       m_dwRef;
    IUnknown * m_pOuterUnknown;
};


// CComObjectRootEx

template <class ThreadModel>
class CComObjectRootEx : public CComObjectRootBase
{
public:
    typedef ThreadModel _ThreadModel;
    // typedef typename _ThreadModel::AutoCriticalSection _CritSec;
    // typedef typename _ThreadModel::AutoDeleteCriticalSection _AutoDelCritSec;
    // typedef CComObjectLockT<_ThreadModel> ObjectLock;

    ~CComObjectRootEx() {};

    ULONG InternalAddRef()  { return _ThreadModel::Increment(&m_dwRef); };
    ULONG InternalRelease() { return _ThreadModel::Decrement(&m_dwRef); };

    HRESULT _AtlInitialConstruct() { return S_OK; /*m_critsec.Init();*/ };
    void Lock()   { /* m_criticalSection.Lock();   */ };
    void Unlock() { /* m_criticalSection.Unlock(); */ };

private:
    // _AutoDelCritSec m_criticalSection;
};

// CComObjectRootEx<CComSingleThreadModel>

template <>
class CComObjectRootEx<CComSingleThreadModel> : public CComObjectRootBase
{
public:
    typedef CComSingleThreadModel _ThreadModel;
    // typedef _ThreadModel::AutoCriticalSection _CritSec;
    // typedef _ThreadModel::AutoDeleteCriticalSection _AutoDelCritSec;
    // typedef CComObjectLockT<_ThreadModel> ObjectLock;

    ~CComObjectRootEx() {}

    ULONG InternalAddRef()  { return _ThreadModel::Increment(&m_dwRef); }
    ULONG InternalRelease() { return _ThreadModel::Decrement(&m_dwRef); };

    HRESULT _AtlInitialConstruct() { return S_OK; };
    void Lock()   {};
    void Unlock() {};
};



#endif // !_WIN32

#endif // _BS_COM_CCOMOBJECTROOTEX_INCLUDED_
