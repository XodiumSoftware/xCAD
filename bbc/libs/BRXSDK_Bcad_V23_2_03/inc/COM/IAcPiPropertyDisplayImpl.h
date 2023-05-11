// Copyright (C) 2006-2014 Menhirs NV. All rights reserved.
#pragma once
#include "PropertyPalette/PropertyPaletteGlobal.h"

#define IPerPropertyDisplayImpl IAcPiPropertyDisplayImpl

template<class T> 
class ATL_NO_VTABLE IAcPiPropertyDisplayImpl : public IAcPiPropertyDisplay
{
public:
    IAcPiPropertyDisplayImpl()
    {
        m_PropDispVector.clear();
        for(int i = 0; !IsDefaultPerPropDispEntry(T::GetPerPropDisplayArray()[i]); i++) {
            m_PropDispVector.push_back(T::GetPerPropDisplayArray()[i]);
        }
    }

    virtual ~IAcPiPropertyDisplayImpl()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;

    bool IsDefaultPerPropDispEntry(PER_PROP_DISP_ENTRY entry)
    {
        if( (-1 != entry.m_dispid) || (NULL != entry.m_ProgID)|| 
            (-1 != entry.m_nWeight) || (NULL != entry.m_lpLeftIconRes) || 
            (PICTYPE_UNINITIALIZED != entry.m_nLeftIconType) || 
            (NULL != entry.m_lpEllipsisBmpRes) || 
            (PICTYPE_UNINITIALIZED != entry.m_nEllipsisBmpType) ||
            (0x80000008 != entry.m_TextColor) || (entry.m_bFullView) || 
            (-1 != entry.m_dwIntegralHeight) 
          )
        {
            return false;
        } else {
            return true;
        }
    }

    HRESULT STDMETHODCALLTYPE GetPropertyWeight(VARIANT Id, long* pWeight)
    {
        return AcOpmGetPropertyWeight(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pWeight);
    }

    HRESULT STDMETHODCALLTYPE IsFullView(VARIANT Id, VARIANT_BOOL* pLabelHidden, DWORD* pSpannedRows)
    {
        return AcOpmIsPropFullView(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pLabelHidden, pSpannedRows);
    }

    HRESULT STDMETHODCALLTYPE GetPropTextColor(VARIANT Id, OLE_COLOR* pColor)
    {
        return AcOpmGetPropTextColor(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, pColor);
    }

    HRESULT STDMETHODCALLTYPE GetCustomPropertyCtrl(VARIANT Id, LCID lcid, BSTR* pControlId)
    {
        return AcOpmGetCustomPropertyCtrl(reinterpret_cast<IUnknown*>(this), GetPerPropDisplayVector(), Id, lcid, pControlId);
    }

    HRESULT STDMETHODCALLTYPE GetPropertyIcon(VARIANT Id, IUnknown** ppIcon)
    {
        return AcOpmGetPropertyIcon(reinterpret_cast<IUnknown*>(this), GetResourceInstance(), GetPerPropDisplayVector(), Id, ppIcon);
    }

    PROP_DISP_VECTOR& GetPerPropDisplayVector()
    {
        return m_PropDispVector;
    }
public:
    PROP_DISP_VECTOR m_PropDispVector;
};

