// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "PropertyPalette/PropertyPaletteGlobal.h"

#define ICategorizeProperties2 IAcPiCategorizeProperties
#define IID_ICategorizeProperties2 IID_IAcPiCategorizeProperties

// {4F83F129-B3FB-4390-910E-1136FA396D61}
DEFINE_GUID(IID_IAcPiCategorizeProperties, 0x4f83f129, 0xb3fb, 0x4390, 0x91, 0xe, 0x11, 0x36, 0xfa, 0x39, 0x6d, 0x61);

/** _ */
interface DECLSPEC_UUID("4F83F129-B3FB-4390-910E-1136FA396D61")
IAcPiCategorizeProperties : public IUnknown
{
  virtual HRESULT STDMETHODCALLTYPE MapPropertyToCategory(DISPID,int*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetCategoryName(int,LCID,BSTR*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetCategoryDescription(int,LCID, BSTR*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetCategoryWeight(int,long*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetParentCategory(int,int*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetUniqueID(BSTR*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetCommandButtons(int,VARIANT*) = 0;
};
typedef IAcPiCategorizeProperties FAR* LPIACPICATEGORIZEPROPERTIES;
