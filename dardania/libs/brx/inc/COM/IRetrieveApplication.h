// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

DEFINE_GUID(IID_IRetrieveApplication, 
            0x765b4640, 0x664a, 0x11cf, 0x93, 0xf3, 0x08, 0x00, 0x09, 0x9e, 0xb3, 0xb7);
/** _ */
interface DECLSPEC_UUID("765B4640-664A-11cf-93F3-0800099EB3B7")
IRetrieveApplication : public IUnknown
{
  virtual HRESULT STDMETHODCALLTYPE SetApplicationObject(LPDISPATCH) = 0;
  virtual HRESULT STDMETHODCALLTYPE GetApplicationObject(LPDISPATCH*) = 0;
};

typedef IRetrieveApplication* LPRETRIEVEAPPLICATION;
