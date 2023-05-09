// Copyright (C) Menhirs NV. All rights reserved.
#pragma once
#include "brx_platform_3264.h"
#include "AcDb/AcDbObjectId.h"
#include "acadi.h"

//common forward declarations
class AcAxObjectRef;
class AcAxOleLinkManager;

AcAxOleLinkManager* AcAxGetOleLinkManager();
HRESULT AcAxArrayPolar(AcAxObjectRef&,LPDISPATCH,int,double,VARIANT,VARIANT*);
HRESULT AcAxArrayPolar(AcDbObjectId&,LPDISPATCH,int,double,VARIANT,VARIANT*);
HRESULT AcAxArrayRectangular(AcAxObjectRef&,LPDISPATCH,int,int,int,double,double,double,VARIANT*);
HRESULT AcAxArrayRectangular(AcDbObjectId&,LPDISPATCH,int,int,int,double,double,double,VARIANT*);
HRESULT AcAxCopy(AcAxObjectRef&,LPDISPATCH,LPDISPATCH*,AcDbObjectId = AcDbObjectId::kNull);
HRESULT AcAxCopy(AcDbObjectId&,LPDISPATCH,LPDISPATCH*,AcDbObjectId = AcDbObjectId::kNull);
HRESULT AcAxEnableShadowDisplay(AcAxObjectRef&,bool*);
HRESULT AcAxEnableShadowDisplay(AcDbObjectId&,bool*);
HRESULT AcAxErase(AcAxObjectRef&);
HRESULT AcAxErase(AcDbObjectId&);
HRESULT AcAxGetBoundingBox(AcAxObjectRef&,VARIANT*,VARIANT*);
HRESULT AcAxGetBoundingBox(AcDbObjectId&,VARIANT*,VARIANT*);
HRESULT AcAxGetColor(AcAxObjectRef&,AcColor*);
HRESULT AcAxGetColor(AcDbObjectId&,AcColor*);
HRESULT AcAxGetDatabase(AcDbDatabase*,LPDISPATCH,LPDISPATCH*);
HRESULT AcAxGetExtensionDictionary(AcAxObjectRef&,LPDISPATCH,IAcadDictionary**);
HRESULT AcAxGetExtensionDictionary(AcDbObjectId&,LPDISPATCH,IAcadDictionary**);
HRESULT AcAxGetHandle(AcAxObjectRef&,BSTR*);
HRESULT AcAxGetHandle(AcDbObjectId&,BSTR*);
HRESULT AcAxGetHyperlinks(AcAxObjectRef&,LPDISPATCH,IAcadHyperlinks**);
HRESULT AcAxGetHyperlinks(AcDbObjectId&,LPDISPATCH,IAcadHyperlinks**);
HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*,AcDbObject*,LPDISPATCH);
HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*,AcDbObjectId&,LPDISPATCH);
HRESULT AcAxGetLayer(AcAxObjectRef&,BSTR*);
HRESULT AcAxGetLayer(AcDbObjectId&,BSTR*);
HRESULT AcAxGetLinetype(AcAxObjectRef&,BSTR*);
HRESULT AcAxGetLinetype(AcDbObjectId&,BSTR*);
HRESULT AcAxGetLinetypeScale(AcAxObjectRef&,double*);
HRESULT AcAxGetLinetypeScale(AcDbObjectId&,double*);
HRESULT AcAxGetLineWeight(AcAxObjectRef&,ACAD_LWEIGHT*);
HRESULT AcAxGetLineWeight(AcDbObjectId&,ACAD_LWEIGHT*);
HRESULT AcAxGetMaterial(AcAxObjectRef&,BSTR*);
HRESULT AcAxGetMaterial(AcDbObjectId&,BSTR*);
HRESULT AcAxGetObjectName(AcAxObjectRef&,BSTR*);
HRESULT AcAxGetObjectName(AcDbObjectId&,BSTR*);
HRESULT AcAxGetOwnerId(AcAxObjectRef&,LONG_PTR*);
HRESULT AcAxGetOwnerId32(AcAxObjectRef&,long*);
HRESULT AcAxGetOwnerId(AcDbObjectId&,LONG_PTR*);
HRESULT AcAxGetPlotStyleName(AcAxObjectRef&,BSTR*);
HRESULT AcAxGetPlotStyleName(AcDbObjectId&,BSTR*);
HRESULT AcAxGetShadowDisplay(AcAxObjectRef&,AcShadowDisplayType*);
HRESULT AcAxGetShadowDisplay(AcDbObjectId&,AcShadowDisplayType*);
HRESULT AcAxGetTrueColor(AcAxObjectRef&,IAcadAcCmColor**);
HRESULT AcAxGetTrueColor(AcDbObjectId&,IAcadAcCmColor**);
HRESULT AcAxGetVisible(AcAxObjectRef&,VARIANT_BOOL*);
HRESULT AcAxGetVisible(AcDbObjectId&,VARIANT_BOOL*);
HRESULT AcAxGetXData(AcAxObjectRef&,BSTR,VARIANT*,VARIANT*);
HRESULT AcAxGetXData(AcDbObjectId&,BSTR,VARIANT*,VARIANT*);
HRESULT AcAxHasExtensionDictionary(AcAxObjectRef&,VARIANT_BOOL*);
HRESULT AcAxHasExtensionDictionary(AcDbObjectId&,VARIANT_BOOL*);
HRESULT AcAxHighlight(AcAxObjectRef&,VARIANT_BOOL);
HRESULT AcAxHighlight(AcDbObjectId&,VARIANT_BOOL);
HRESULT AcAxIntersectWith(AcAxObjectRef&,LPDISPATCH,AcExtendOption,VARIANT*);
HRESULT AcAxIntersectWith(AcDbObjectId&,LPDISPATCH,AcExtendOption,VARIANT*);
HRESULT AcAxMirror(AcAxObjectRef&,LPDISPATCH,VARIANT,VARIANT,LPDISPATCH*);
HRESULT AcAxMirror(AcDbObjectId&,LPDISPATCH,VARIANT,VARIANT,LPDISPATCH*);
HRESULT AcAxMirror3D(AcAxObjectRef&,LPDISPATCH,VARIANT,VARIANT,VARIANT,LPDISPATCH*);
HRESULT AcAxMirror3D(AcDbObjectId&,LPDISPATCH,VARIANT,VARIANT,VARIANT,LPDISPATCH*);
HRESULT AcAxMove(AcAxObjectRef&,VARIANT,VARIANT);
HRESULT AcAxMove(AcDbObjectId&,VARIANT,VARIANT);
HRESULT AcAxPutColor(AcAxObjectRef&,AcColor);
HRESULT AcAxPutColor(AcDbObjectId&,AcColor);
HRESULT AcAxPutLayer(AcAxObjectRef&,BSTR);
HRESULT AcAxPutLayer(AcDbObjectId&,BSTR);
HRESULT AcAxPutLinetype(AcAxObjectRef&,BSTR);
HRESULT AcAxPutLinetype(AcDbObjectId&,BSTR);
HRESULT AcAxPutLinetypeScale(AcAxObjectRef&,double);
HRESULT AcAxPutLinetypeScale(AcDbObjectId&,double);
HRESULT AcAxPutLineWeight(AcAxObjectRef&,ACAD_LWEIGHT);
HRESULT AcAxPutLineWeight(AcDbObjectId&,ACAD_LWEIGHT);
HRESULT AcAxPutMaterial(AcAxObjectRef&,BSTR);
HRESULT AcAxPutMaterial(AcDbObjectId&,BSTR);
HRESULT AcAxPutPlotStyleName(AcAxObjectRef&,BSTR);
HRESULT AcAxPutPlotStyleName(AcDbObjectId&,BSTR);
HRESULT AcAxPutShadowDisplay(AcAxObjectRef&,AcShadowDisplayType);
HRESULT AcAxPutShadowDisplay(AcDbObjectId&,AcShadowDisplayType);
HRESULT AcAxPutTrueColor(AcAxObjectRef&,IAcadAcCmColor*);
HRESULT AcAxPutTrueColor(AcDbObjectId&,IAcadAcCmColor*);
HRESULT AcAxPutVisible(AcAxObjectRef&,VARIANT_BOOL);
HRESULT AcAxPutVisible(AcDbObjectId&,VARIANT_BOOL);
HRESULT AcAxRotate(AcAxObjectRef&,VARIANT,double);
HRESULT AcAxRotate(AcDbObjectId&,VARIANT,double);
HRESULT AcAxRotate3D(AcAxObjectRef&,VARIANT,VARIANT,double);
HRESULT AcAxRotate3D(AcDbObjectId&,VARIANT,VARIANT,double);
HRESULT AcAxScaleEntity(AcAxObjectRef&,VARIANT,double);
HRESULT AcAxScaleEntity(AcDbObjectId&,VARIANT,double);
HRESULT AcAxSetXData(AcAxObjectRef&,VARIANT,VARIANT);
HRESULT AcAxSetXData(AcDbObjectId&,VARIANT,VARIANT);
HRESULT AcAxTransformBy(AcAxObjectRef&,VARIANT);
HRESULT AcAxTransformBy(AcDbObjectId&,VARIANT);
HRESULT AcAxUpdate(AcAxObjectRef&);
HRESULT AcAxUpdate(AcDbObjectId&);
HRESULT AcAxGetTransparency(AcAxObjectRef&, BSTR*);
HRESULT AcAxPutTransparency(AcAxObjectRef&, BSTR);

#ifdef __SYS_64_BIT__ // only on 64 bit systems
  Adesk::Int32 AcAxGetObjectId32(const Adesk::IntDbId& objId);
  Adesk::IntDbId AcAxGetObjectId64(const Adesk::Int32& objId);
#endif
