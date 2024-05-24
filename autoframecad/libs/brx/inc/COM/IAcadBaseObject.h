// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

DEFINE_GUID(IID_IAcadBaseObject, 
            0xc9e0781d, 0xba3d, 0x4224, 0x9f, 0xa4, 0x58, 0xec, 0xea, 0x2b, 0xc5, 0x59);
/** _ */
interface DECLSPEC_UUID("C9E0781D-BA3D-4224-9FA4-58ECEA2BC559")
IAcadBaseObject : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetObjectId(AcDbObjectId&, 
        AcDbObjectId = AcDbObjectId::kNull, TCHAR* = 0) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetObjectId(AcDbObjectId*) = 0;
    virtual HRESULT STDMETHODCALLTYPE Clone(AcDbObjectId, LPUNKNOWN* ) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetClassID(CLSID&) = 0;
    virtual HRESULT STDMETHODCALLTYPE NullObjectId() = 0;
    virtual HRESULT STDMETHODCALLTYPE OnModified() = 0;
};

typedef IAcadBaseObject* LPACADBASEOBJECT;
