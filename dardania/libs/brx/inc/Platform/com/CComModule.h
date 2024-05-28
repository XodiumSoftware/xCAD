// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// CComModule placebo implementation; can be extended if needed

#ifndef _BS_CCOMMODULE_INCLUDED_
#define _BS_CCOMMODULE_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif

#ifndef _WIN32  // on Linux/Mac

  #include "Platform/atl/atl_objmap.h"

  using namespace ATL;

  class BRXEXPORT CComModule
  {
  public:
      CComModule();
     ~CComModule();

      HINSTANCE SetResourceInstance(HINSTANCE hInst) noexcept(false);
      HINSTANCE GetResourceInstance() noexcept(false);

      HINSTANCE SetModuleInstance(HINSTANCE hInst) noexcept(false);
      HINSTANCE GetModuleInstance() noexcept(false);

      HINSTANCE SetTypeLibInstance(HINSTANCE hInst) noexcept(false);
      HINSTANCE GetTypeLibInstance() const noexcept(false);

      HRESULT Init(_ATL_OBJMAP_ENTRY * pMap, HINSTANCE hInstance, const GUID* pTypelibId = NULL) noexcept(false);
      void Term() noexcept(false);

      HRESULT GetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) noexcept(false);
      HRESULT RegisterClassObjects(DWORD dwClsContext, DWORD dwFlags) noexcept(false);
      HRESULT RevokeClassObjects() noexcept(false);

      HRESULT RegisterTypeLib() noexcept(false);
      HRESULT RegisterTypeLib(LPCTSTR lpszIndex) noexcept(false);

      HRESULT UnRegisterTypeLib() noexcept(false);
      HRESULT UnRegisterTypeLib(LPCTSTR lpszIndex) noexcept(false);

      HRESULT RegisterServer(BOOL bRegTypeLib = FALSE, const CLSID* pCLSID = NULL) noexcept(false);
      HRESULT UnregisterServer(BOOL bUnRegTypeLib, const CLSID* pCLSID = NULL) noexcept(false);
      HRESULT UnregisterServer(const CLSID* pCLSID = NULL) noexcept(false);

  public:
      // for backward compatibility only
      _ATL_OBJMAP_ENTRY * m_pObjMap;

  private:
      HINSTANCE  m_hInst;
      HINSTANCE  m_hInstResource;
      HINSTANCE  m_hInstTypeLib;

  };
  extern CComModule* _pModule;

#endif // !_WIN32

#endif // _BS_CCOMMODULE_INCLUDED_
