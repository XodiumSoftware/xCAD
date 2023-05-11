// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "PropertyPalette/PropertyPaletteGlobal.h"

// {4D07FC10-F931-11ce-B001-00AA006884E5}
DEFINE_GUID(IID_ICategorizeProperties, 0x4d07fc10, 0xf931, 0x11ce, 0xb0, 0x1, 0x0, 0xaa, 0x0, 0x68, 0x84, 0xe5);

/** _ */
interface DECLSPEC_UUID("4D07FC10-F931-11ce-B001-00AA006884E5")
ICategorizeProperties : public IUnknown
{
  virtual HRESULT STDMETHODCALLTYPE MapPropertyToCategory(DISPID,PROPCAT*) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetCategoryName(PROPCAT,LCID,BSTR*) = 0;
};
typedef ICategorizeProperties FAR* LPCATEGORIZEPROPERTIES;
