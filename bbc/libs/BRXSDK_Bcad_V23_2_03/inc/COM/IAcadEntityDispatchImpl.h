// Copyright (T1) 2006-2014 Menhirs NV. All rights reserved.
#pragma once
#include "COM/IAcadObjectDispatchImpl.h"

template <  class T1, 
            const CLSID* pClsId, 
            class T2, 
            const IID* pIid, 
            const GUID* pGuid,
            WORD major = 1, 
            WORD minor = 0, 
            class typeInfo = CComTypeInfoHolder>
class ATL_NO_VTABLE IAcadEntityDispatchImpl 
    : public IAcadObjectDispatchImpl<T1, pClsId, T2, pIid, pGuid, major, minor, typeInfo>
{
public:
    HRESULT STDMETHODCALLTYPE ArrayPolar(int n, double a, VARIANT pt, VARIANT * pObjs)
    {
        return AcAxArrayPolar(this->m_objRef, this->m_App, n, a, pt, pObjs);
    }

    HRESULT STDMETHODCALLTYPE ArrayRectangular(int cntR, int cntC, int cntL, double dR, double dC, double dL, VARIANT * pObjs)
    {
        return AcAxArrayRectangular(this->m_objRef, this->m_App, cntR, cntC, cntL, dR, dC, dL, pObjs);
    }

    HRESULT STDMETHODCALLTYPE Copy(LPDISPATCH* pObj)
    {
        return AcAxCopy(this->m_objRef, this->m_App, pObj);
    }

    HRESULT STDMETHODCALLTYPE GetBoundingBox(VARIANT* min, VARIANT* max)
    {
        return AcAxGetBoundingBox(this->m_objRef, min, max);
    }

    HRESULT STDMETHODCALLTYPE get_color(AcColor* pColor)
    {
        return AcAxGetColor(this->m_objRef, pColor);
    }

    virtual HRESULT STDMETHODCALLTYPE get_EntityName(BSTR *pClassName)
    {
        return AcAxGetObjectName(this->m_objRef, pClassName);
    }

    virtual HRESULT STDMETHODCALLTYPE get_EntityTransparency(BSTR *transparency)
    {
        return AcAxGetTransparency(this->m_objRef, transparency);
    }

    virtual HRESULT STDMETHODCALLTYPE get_EntityType(long*)
    {
        return E_NOTIMPL;
    }

    HRESULT STDMETHODCALLTYPE get_Hyperlinks(IAcadHyperlinks** pHyperlinks)
    {
        return AcAxGetHyperlinks(this->m_objRef, this->m_App, pHyperlinks);
    }

    HRESULT STDMETHODCALLTYPE get_Layer(BSTR* pLayer)
    {
        return AcAxGetLayer(this->m_objRef, pLayer);
    }

    HRESULT STDMETHODCALLTYPE get_Linetype(BSTR * pLinetype)
    {
        return AcAxGetLinetype(this->m_objRef, pLinetype);
    }

    HRESULT STDMETHODCALLTYPE get_LinetypeScale(double * pLtScale)
    {
        return AcAxGetLinetypeScale(this->m_objRef, pLtScale);
    }

    HRESULT STDMETHODCALLTYPE get_Lineweight(ACAD_LWEIGHT* pLw)
    {
        return AcAxGetLineWeight(this->m_objRef, pLw);
    }

    HRESULT STDMETHODCALLTYPE get_Material(BSTR * pMaterial)
    {
        return AcAxGetMaterial(this->m_objRef, pMaterial);
    }

    HRESULT STDMETHODCALLTYPE get_PlotStyleName(BSTR* pName)
    {
        return AcAxGetPlotStyleName(this->m_objRef, pName);
    }

    HRESULT STDMETHODCALLTYPE get_TrueColor(IAcadAcCmColor** pTrueColor)
    {
        return AcAxGetTrueColor(this->m_objRef, pTrueColor);
    }

    HRESULT STDMETHODCALLTYPE get_Visible(VARIANT_BOOL * pVisible)
    {
        return AcAxGetVisible(this->m_objRef, pVisible);
    }

    HRESULT STDMETHODCALLTYPE Highlight(VARIANT_BOOL highlight)
    {
        return AcAxHighlight(this->m_objRef, highlight);
    }

    HRESULT STDMETHODCALLTYPE IntersectWith(LPDISPATCH pEnt, AcExtendOption o, VARIANT* pts)
    {
        return AcAxIntersectWith(this->m_objRef, pEnt, o, pts);
    }

    HRESULT STDMETHODCALLTYPE Mirror(VARIANT p1, VARIANT p2, LPDISPATCH* pObj)
    {
        return AcAxMirror(this->m_objRef, this->m_App, p1, p2, pObj);
    }

    HRESULT STDMETHODCALLTYPE Mirror3D(VARIANT p1, VARIANT p2, VARIANT point3, LPDISPATCH* pObj)
    {
        return AcAxMirror3D(this->m_objRef, this->m_App, p1, p2, point3, pObj);
    }

    HRESULT STDMETHODCALLTYPE Move(VARIANT from, VARIANT to)
    {
        return AcAxMove(this->m_objRef, from, to);
    }

    HRESULT STDMETHODCALLTYPE put_color(AcColor color)
    {
        return AcAxPutColor(this->m_objRef, color);
    }

    HRESULT STDMETHODCALLTYPE put_EntityTransparency(BSTR transparency)
    {
        return AcAxPutTransparency(this->m_objRef, transparency);
    }

    HRESULT STDMETHODCALLTYPE put_Layer(BSTR layer)
    {
        return AcAxPutLayer(this->m_objRef, layer);
    }

    HRESULT STDMETHODCALLTYPE put_Linetype(BSTR linetype)
    {
        return AcAxPutLinetype(this->m_objRef, linetype);
    }

    HRESULT STDMETHODCALLTYPE put_LinetypeScale(double ltScale)
    {
        return AcAxPutLinetypeScale(this->m_objRef, ltScale);
    }

    HRESULT STDMETHODCALLTYPE put_Lineweight(ACAD_LWEIGHT lw)
    {
        return AcAxPutLineWeight(this->m_objRef, lw);
    }

    HRESULT STDMETHODCALLTYPE put_Material(BSTR material)
    {
        return AcAxPutMaterial(this->m_objRef, material);
    }

    HRESULT STDMETHODCALLTYPE put_PlotStyleName(BSTR name)
    {
        return AcAxPutPlotStyleName(this->m_objRef, name);
    }

    HRESULT STDMETHODCALLTYPE put_TrueColor(IAcadAcCmColor* pTrueColor)
    {
        return AcAxPutTrueColor(this->m_objRef, pTrueColor);
    }

    HRESULT STDMETHODCALLTYPE put_Visible(VARIANT_BOOL visible)
    {
        return AcAxPutVisible(this->m_objRef, visible);
    }

    HRESULT STDMETHODCALLTYPE Rotate(VARIANT pt, double angle)
    {
        return AcAxRotate(this->m_objRef, pt, angle);
    }

    HRESULT STDMETHODCALLTYPE Rotate3D(VARIANT p1, VARIANT p2, double angle)
    {
        return AcAxRotate3D(this->m_objRef, p1, p2, angle);
    }

    HRESULT STDMETHODCALLTYPE ScaleEntity(VARIANT pt, double scale)
    {
        return AcAxScaleEntity(this->m_objRef, pt, scale);
    }

    HRESULT STDMETHODCALLTYPE TransformBy(VARIANT m)
    {
        return AcAxTransformBy(this->m_objRef, m);
    }

    HRESULT STDMETHODCALLTYPE Update()
    {
        return AcAxUpdate(this->m_objRef);
    }
};
