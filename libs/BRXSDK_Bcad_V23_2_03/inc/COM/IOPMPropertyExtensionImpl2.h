// Copyright (C) Menhirs NV. All rights reserved.
#pragma once
#include "PropertyPalette/PropertyPaletteGlobal.h"

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl2
    : public IPerPropertyBrowsing
    , public IOPMPropertyExtension
{
public:
    IOPMPropertyExtensionImpl2()
    {
    }

    virtual ~IOPMPropertyExtensionImpl2()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    HRESULT STDMETHODCALLTYPE GetDisplayString(DISPID id, BSTR *pStr)
    {
        return AcOpmGetDisplayString(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, pStr);
    }

    HRESULT STDMETHODCALLTYPE MapPropertyToPage(DISPID id, CLSID *pClsId)
    {
        return AcOpmMapPropertyToPage(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, pClsId);
    }

    HRESULT STDMETHODCALLTYPE GetPredefinedStrings(DISPID id, CALPOLESTR *pStrings, CADWORD *pCookies)
    {
        return AcOpmGetPredefinedStrings(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), id, pStrings, pCookies);
    }

    HRESULT STDMETHODCALLTYPE GetPredefinedValue(DISPID id, DWORD dw, VARIANT *pVal)
    {
        return AcOpmGetPredefinedValue(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, dw, pVal);
    }

    HRESULT STDMETHODCALLTYPE GetDisplayName(DISPID id, BSTR *pName)
    {
        return AcOpmGetDisplayName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), id, pName);
    }

    HRESULT STDMETHODCALLTYPE Editable(DISPID id, BOOL *pEditable)
    {
        return AcOpmEditable(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, pEditable);
    }

    HRESULT STDMETHODCALLTYPE ShowProperty(DISPID id, BOOL *pShow)
    {
        return AcOpmShowProperty(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, pShow);
    }
};
