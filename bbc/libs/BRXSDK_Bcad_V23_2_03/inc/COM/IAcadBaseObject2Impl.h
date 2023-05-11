// Copyright (C) Menhirs NV. All rights reserved.
#pragma once
#include "COM/IAcadBaseObject2.h"
#include "COM/IAcadBaseObjectImpl.h"

#define ACAX_VARIANT_TRUE  (VARIANT_BOOL)-1
#define ACAX_VARIANT_FALSE (VARIANT_BOOL)0

/** _ */
template <class T, const CLSID* pClsId>
class ATL_NO_VTABLE IAcadBaseObject2Impl
    : public IAcadBaseObject2
    , public IAcadBaseObjectImpl<T, pClsId>
{
public:
    IAcadBaseObject2Impl()
    {
    }

    virtual ~IAcadBaseObject2Impl()
    {
    }

    virtual HRESULT STDMETHODCALLTYPE AddToDb(AcDbObjectId&  /*new object id OUT*/,
        AcDbObjectId = AcDbObjectId::kNull /*owner object id IN*/,
        TCHAR* = NULL /*name IN*/)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE CreateObject(
        AcDbObjectId = AcDbObjectId::kNull  /*owner object id IN*/,
        TCHAR* = NULL /*name IN*/)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT STDMETHODCALLTYPE ForceDbResident(VARIANT_BOOL *pForce)
    {
        if(!pForce)
            return E_POINTER;
        *pForce = ACAX_VARIANT_TRUE;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetObject(AcDbObject*& pObject)
    {
        if(!m_objRef.objectId().isNull())
            return E_FAIL;
        AcDbObjectId objectId;
        m_objRef.release(objectId, pObject);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE ObjectExists(VARIANT_BOOL *pExists)
    {
        if(!pExists)
            return E_POINTER;
        if(m_objRef.isNull())
            *pExists = ACAX_VARIANT_FALSE;
        else
            *pExists = ACAX_VARIANT_TRUE;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE OnModified(DISPID dId = DISPID_UNKNOWN)
    {
        this->Fire_Modified();
        this->Fire_OnChanged(dId);
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE SetObject(AcDbObject*& pObject)
    {
        if(!pObject)
            return E_FAIL;
        AcDbObjectId id = pObject->objectId();
        if(id.isNull()) {
            this->NullObjectId();
            m_objRef.acquire(pObject);
            return S_OK;
        } else
            return this->SetObjectId(id);
    }

protected:
    void Fire_Notification(DISPID dId = DISPID_UNKNOWN)
    {
        if(m_objRef.objectId().isNull()) {
            this->Fire_Modified();
            this->Fire_OnChanged(dId);
        }
    }

    virtual void ObjectIdModified()
    {
        releaseReference();
        m_objRef.acquire(this->m_objId);
    }

    virtual HRESULT STDMETHODCALLTYPE releaseReference()
    {
        AcDbObject* pAcDbObject = NULL;
        AcDbObjectId objId;
        m_objRef.release(objId, pAcDbObject);
        if(objId.isNull())
            delete pAcDbObject, pAcDbObject = NULL;
        return S_OK;
    }

protected:
    AcAxObjectRef m_objRef;
};
