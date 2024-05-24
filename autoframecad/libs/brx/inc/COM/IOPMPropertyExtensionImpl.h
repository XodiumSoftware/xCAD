// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "PropertyPalette/PropertyPaletteGlobal.h"

template<class T>
class ATL_NO_VTABLE IOPMPropertyExtensionImpl
    : public ICategorizeProperties
    , public IPerPropertyBrowsing
    , public IOPMPropertyExtension
{
public:
    IOPMPropertyExtensionImpl()
    {
    }

    virtual ~IOPMPropertyExtensionImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    HRESULT STDMETHODCALLTYPE MapPropertyToCategory(DISPID id, PROPCAT* pCat)
    {
        return AcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, pCat);
    }

    HRESULT STDMETHODCALLTYPE GetCategoryName(PROPCAT propcat, LCID lcid, BSTR* pName)
    {
        return AcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), propcat, lcid, pName);
    }

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
