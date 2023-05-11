// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

DEFINE_GUID(IID_IAcadBaseDatabase, 
            0xcd3eb5b8, 0xf3fc, 0x48c2, 0x84, 0xee, 0x95, 0x4e, 0xfc, 0x4d, 0x42, 0x8);
/** _ */
interface DECLSPEC_UUID("CD3EB5B8-F3FC-48c2-84EE-954EFC4D4208") 
IAcadBaseDatabase : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetDatabase(AcDbDatabase*&) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDatabase(AcDbDatabase**) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetClassID(CLSID&) = 0;
};

typedef IAcadBaseDatabase* LPACADBASEDATABASE;
