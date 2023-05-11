// Copyright (T1) 2006-2014 Menhirs NV. All rights reserved.
#pragma once
#include "COM/IAcadBaseObject2Impl.h"
#include "COM/IRetrieveApplicationImpl.h"

template <  class T1, 
            const CLSID* pClsId, 
            class T2, 
            const IID* pIid, 
            const GUID* pGuid,
            WORD major = 1, 
            WORD minor = 0, 
            class typeInfoClass = CComTypeInfoHolder>
class ATL_NO_VTABLE IAcadObjectDispatchImpl 
    : public IDispatchImpl<T2, pIid, pGuid, major, minor, typeInfoClass>
    , public IAcadBaseObject2Impl<T1, pClsId>
    , public IRetrieveApplicationImpl
{
public:
    IAcadObjectDispatchImpl()
    {
    }

    virtual ~IAcadObjectDispatchImpl()
    {
    }

    virtual HRESULT STDMETHODCALLTYPE Delete()
    {
        return AcAxErase(this->m_objRef);
    }

    virtual HRESULT STDMETHODCALLTYPE Erase()
    {
        return AcAxErase(this->m_objRef);
    }

    virtual HRESULT STDMETHODCALLTYPE get_Application(LPDISPATCH* pApplicationObject)
    {
        return IRetrieveApplicationImpl::GetApplicationObject(pApplicationObject);
    }

    virtual HRESULT STDMETHODCALLTYPE get_Database(IAcadDatabase** pDb)
    {
        CComPtr<IDispatch> pDp;
        HRESULT hr = AcAxGetDatabase(this->m_objRef.objectId().database(), m_App, &pDp);
        if(SUCCEEDED(hr))
            hr = pDp->QueryInterface(IID_IAcadDatabase, reinterpret_cast<LPVOID*>(pDb));
        return hr;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Document(LPDISPATCH* pDoc)
    {
        *pDoc = NULL;
        AcAxOleLinkManager* pOleLinkManager = AcAxGetOleLinkManager();
        if(pOleLinkManager)
            *pDoc = pOleLinkManager->GetDocIDispatch(this->m_objRef.objectId().database());
        if(*pDoc)
            (*pDoc)->AddRef();
        return *pDoc ? S_OK : S_FALSE;
    }

    virtual HRESULT STDMETHODCALLTYPE get_Handle(BSTR* pHandle)
    {
        return AcAxGetHandle(this->m_objRef, pHandle);
    }

    virtual HRESULT STDMETHODCALLTYPE get_HasExtensionDictionary(VARIANT_BOOL* pBoolHas)
    {
        return AcAxHasExtensionDictionary(this->m_objRef, pBoolHas);
    }

    virtual HRESULT STDMETHODCALLTYPE get_ObjectID(LONG_PTR* pI)
    {
        *pI = (LONG_PTR)(this->m_objRef.objectId().asOldId());
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE get_ObjectID32(long* pI)
    {
        *pI = (long)(this->m_objRef.objectId().asOldId());
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE get_ObjectName(BSTR* pClassName)
    {
        return AcAxGetObjectName(this->m_objRef, pClassName);
    }

    virtual HRESULT STDMETHODCALLTYPE get_OwnerID(LONG_PTR* pLongOwnerObjectId)
    {
        return AcAxGetOwnerId(this->m_objRef, pLongOwnerObjectId);
    }

    virtual HRESULT STDMETHODCALLTYPE get_OwnerID32(long* pLongOwnerObjectId)
    {
        LONG_PTR id;
        HRESULT hr = AcAxGetOwnerId(this->m_objRef, &id);
        if(SUCCEEDED(hr))
            *pLongOwnerObjectId = (long)id;
        return hr;
    }

    virtual HRESULT STDMETHODCALLTYPE GetExtensionDictionary(IAcadDictionary** pD)
    {
        return AcAxGetExtensionDictionary(this->m_objRef, IRetrieveApplicationImpl::m_App, pD);
    }

    virtual HRESULT STDMETHODCALLTYPE GetXData(BSTR pAppName, VARIANT* pDs, VARIANT* pVs)
    {
        return AcAxGetXData(this->m_objRef, pAppName, pDs, pVs);
    }

    virtual HRESULT STDMETHODCALLTYPE SetXData(VARIANT dxfGroupCodes, VARIANT values)
    {
        return AcAxSetXData(this->m_objRef, dxfGroupCodes, values);
    }
};


