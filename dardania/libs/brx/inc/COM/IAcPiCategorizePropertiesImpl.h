// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "PropertyPalette/PropertyPaletteGlobal.h"

#define ICategorizeProperties2Impl IAcPiCategorizePropertiesImpl

template<class T>
class ATL_NO_VTABLE IAcPiCategorizePropertiesImpl
    : public IAcPiCategorizeProperties
{
public:
    IAcPiCategorizePropertiesImpl()
    {
        m_CategoryVector.clear();
        m_CatCmdBtnVector.clear();

        for(int i = 0; !IsDefaultCategoryEntry(T::GetCatArray()[i]); i++) {
            m_CategoryVector.push_back(T::GetCatArray()[i]);
        }
        for(int i = 0; !IsDefaultCmdBtnEntry(T::GetCmdBtnArray()[i]); i++) {
            m_CatCmdBtnVector.push_back(T::GetCmdBtnArray()[i]);
        }
    }

    virtual ~IAcPiCategorizePropertiesImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    HRESULT STDMETHODCALLTYPE MapPropertyToCategory(DISPID id, PROPCAT* pCat)
    {
        return AcOpmMapPropertyToCategory(reinterpret_cast<IUnknown*>(this), T::GetOPMPropertyMap(), id, pCat);
    }

    HRESULT STDMETHODCALLTYPE GetCategoryName(PROPCAT cat, LCID lcid, BSTR* pName)
    {
        HRESULT hr = AcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCategoryVector(), cat, lcid, pName);
        if(FAILED(hr)) {
            hr = AcOpmGetCategoryName(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), T::GetOPMPropertyMap(), cat, lcid, pName);
        }
        return hr;
    }

    HRESULT STDMETHODCALLTYPE GetCategoryDescription(int cat, LCID lcid, BSTR* pDesc)
    {
        return AcOpmGetCategoryDescription(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCategoryVector(), cat, lcid, pDesc);
    }

    HRESULT STDMETHODCALLTYPE GetCategoryWeight(int cat, long* pWeight)
    {
        return AcOpmGetCategoryWeight(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), cat, pWeight);
    }
    
    HRESULT STDMETHODCALLTYPE GetParentCategory(int cat, int* pPCat)
    {
        return AcOpmGetParentCategory(reinterpret_cast<IUnknown*>(this), GetCategoryVector(), cat, pPCat);
    }

    HRESULT STDMETHODCALLTYPE GetCommandButtons(int cat, VARIANT* pButtons)
    {
        return AcOpmGetCategoryCommandButtons(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetCmdBtnVector(), cat, pButtons);
    }

    CATEGORY_VECTOR& GetCategoryVector()
    {
        return m_CategoryVector;
    }

    CATCMDBTN_VECTOR& GetCmdBtnVector()
    {
        return m_CatCmdBtnVector;
    }

    bool IsDefaultCategoryEntry(CATEGORY_ENTRY entry)
    {
        if(-1 != entry.m_CatID || 0 != entry.m_nNameId || 0 != entry.m_nDescId
            || -1 != entry.m_ParentCatID|| -1 != entry.m_nWeight) {
            return false;
        } else {
            return true;
        }
    }

    bool IsDefaultCmdBtnEntry(CATCMDBTN_ENTRY entry)
    {
        if(-1 != entry.m_CatID || 0 != entry.m_nBtnNameId || NULL != entry.m_lpEnBtnBmpRes
            || PICTYPE_UNINITIALIZED != entry.m_nEnBtnBmpType 
            || NULL != entry.m_lpDisBtnBmpRes 
            || PICTYPE_UNINITIALIZED != entry.m_nDisBtnBmpType || NULL != entry.m_nStyle
            || NULL != entry.m_pfnBtnProc) {
            return false;
        } else {
            return true;
        }
    }

public:
    CATEGORY_VECTOR m_CategoryVector;
    CATCMDBTN_VECTOR m_CatCmdBtnVector;
};
