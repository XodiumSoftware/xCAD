// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "COM/IAcadBaseObject.h"
#include "COM/CProxy_AcadObjectEvents.h"
#include "COM/CProxy_PropertyNotifySink.h"

/** _ */
template <class T, const CLSID* pClsId>
class ATL_NO_VTABLE IAcadBaseObjectImpl 
    : public IAcadBaseObject
    , public IConnectionPointContainerImpl<T>
    , public CProxy_AcadObjectEvents<T>
    , public CProxy_PropertyNotifySink<T>
{
public:
    BEGIN_CONNECTION_POINT_MAP(T)
        CONNECTION_POINT_ENTRY(IID_IAcadObjectEvents)
        CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    END_CONNECTION_POINT_MAP()

public:
    IAcadBaseObjectImpl()
    {
    }

    virtual ~IAcadBaseObjectImpl()
    {
        if(!m_objId.isNull()) 
        {
            AcDbObjectPointer<AcDbObject> object(m_objId, AcDb::kForNotify, Adesk::kTrue);
            if((object.openStatus()) == Acad::eOk && (object.object()))
            {
                AcAxOleLinkManager* pLinkMan = AcAxGetOleLinkManager();
                if(pLinkMan) 
                {
                    pLinkMan->SetIUnknown(object.object(), NULL);
                }
            }
        }
    }


    virtual HRESULT STDMETHODCALLTYPE Clone(AcDbObjectId /*owner*/, LPUNKNOWN* /*clone*/)
    {
        return E_NOTIMPL;
    }

    virtual HRESULT CreateNewObject(AcDbObjectId& /*new object id OUT*/,
        AcDbObjectId& /*owner object id IN*/, TCHAR* /*name IN*/ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetClassID(CLSID& clsId)
    {
        clsId = *pClsId;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE GetObjectId(AcDbObjectId* objectId)
    {
        *objectId = m_objId;
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE NullObjectId()
    {
        bool wasNull = m_objId.isNull();
        m_objId = AcDbObjectId::kNull;
        if(!wasNull)
            ObjectIdModified();
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE OnModified()
    {
        this->Fire_Modified();
        this->Fire_OnChanged();
        return S_OK;
    }

    virtual HRESULT STDMETHODCALLTYPE SetObjectId(AcDbObjectId& objectId,
        AcDbObjectId ownerObjectId = AcDbObjectId::kNull, TCHAR* name = NULL)
    {
        HRESULT hr = S_OK;
        if(!m_objId.isNull())
            return E_FAIL;

        if(objectId.isNull()) {
            hr = CreateNewObject(objectId, ownerObjectId, name);
            if(FAILED(hr)) 
                return hr;
        }
        if(objectId.isNull()) 
            return E_FAIL;
        m_objId = objectId;
        ObjectIdModified();
        return hr;
    }

protected:
    virtual void ObjectIdModified()
    {
    }

protected:
    AcDbObjectId m_objId;
};

