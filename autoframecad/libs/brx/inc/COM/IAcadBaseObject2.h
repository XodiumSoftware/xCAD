// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

DEFINE_GUID(IID_IAcadBaseObject2,
            0xAA0AA808, 0x4761, 0x4B5F, 0xb4, 0x75, 0x56, 0x93, 0xa5, 0xa7, 0xd8, 0x03);
/** _ */
interface DECLSPEC_UUID("AA0AA808-4761-4B5F-B475-5693A5A7D803") 
IAcadBaseObject2 : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE AddToDb(AcDbObjectId&, 
        AcDbObjectId = AcDbObjectId::kNull, TCHAR* = NULL) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateObject(AcDbObjectId = AcDbObjectId::kNull,
        ACHAR* = NULL) = 0;
    virtual HRESULT STDMETHODCALLTYPE ForceDbResident(VARIANT_BOOL*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetObject(AcDbObject*&) = 0;
    virtual HRESULT STDMETHODCALLTYPE ObjectExists(VARIANT_BOOL*) = 0;
    virtual HRESULT STDMETHODCALLTYPE OnModified(DISPID = DISPID_UNKNOWN) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetObject(AcDbObject*&) = 0;
};

typedef IAcadBaseObject2* LPACADBASEOBJECT2;
