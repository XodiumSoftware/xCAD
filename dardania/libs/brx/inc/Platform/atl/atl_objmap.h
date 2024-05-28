// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// ATL types and functions

#ifndef _BS_ATL_OBJMAP_H_INCLUDED_
#define _BS_ATL_OBJMAP_H_INCLUDED_


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32 // on Linux/Mac

  typedef GUID     CATID;
  typedef REFGUID  REFCATID;

  #define IsEqualCATID(cat1, cat2) IsEqualGUID(cat1, cat2)

  // #define IID_IEnumCLSID           IID_IEnumGUID
  // #define IEnumCLSID               IEnumGUID
  // #define LPENUMCLSID              LPENUMGUID
  // #define CATID_NULL               GUID_NULL
  // #define IID_IEnumCATID           IID_IEnumGUID
  // #define IEnumCATID               IEnumGUID

  namespace ATL
  {

    #define  _ATL_CATMAP_ENTRY_END          0
    #define  _ATL_CATMAP_ENTRY_IMPLEMENTED  1
    #define  _ATL_CATMAP_ENTRY_REQUIRED     2

    typedef HRESULT  (_ATL_CREATORFUNC)(void* pv, REFIID riid, LPVOID* ppv);
    typedef HRESULT  (_ATL_CREATORARGFUNC)(void* pv, REFIID riid, LPVOID* ppv, DWORD_PTR dw);
    typedef HRESULT  (_ATL_MODULEFUNC)(DWORD_PTR dw);
    typedef LPCTSTR  (_ATL_DESCRIPTIONFUNC)();
    typedef const struct _ATL_CATMAP_ENTRY* (_ATL_CATMAPFUNC)();
    typedef void  (_ATL_TERMFUNC)(DWORD_PTR dw);

    struct _ATL_CATMAP_ENTRY
    {
        int  iType;
        const CATID * pcatid;
    };

    struct _ATL_REGMAP_ENTRY
    {
        LPCOLESTR  szKey;
        LPCOLESTR  szData;
    };

    struct _AtlCreateWndData
    {
        void* m_pThis;
        DWORD m_dwThreadID;
        _AtlCreateWndData* m_pNext;
    };

    struct _ATL_OBJMAP_ENTRY30
    {
        HRESULT (*pfnUpdateRegistry)(BOOL bRegister);

        const CLSID* pclsid;
        IUnknown*  pCF;
        DWORD      dwRegister;

        _ATL_CREATORFUNC*  pfnGetClassObject;
        _ATL_CREATORFUNC*  pfnCreateInstance;
        _ATL_DESCRIPTIONFUNC*  pfnGetObjectDescription;
        _ATL_CATMAPFUNC*       pfnGetCategoryMap;

        HRESULT RevokeClassObject()
        {
            // if (dwRegister == 0)
            //     return S_OK;
            // return ::CoRevokeClassObject(dwRegister);
            return E_FAIL;
        }

        HRESULT RegisterClassObject(DWORD dwClsContext, DWORD dwFlags)
        {
            // IUnknown* p = NULL;
            // if (pfnGetClassObject == NULL) return S_OK;
            // HRESULT hr = pfnGetClassObject(pfnCreateInstance, __uuidof(IUnknown), (LPVOID*) &p);
            // if (SUCCEEDED(hr))
            //     hr = ::CoRegisterClassObject(*pclsid, p, dwClsContext, dwFlags, &dwRegister);
            // if (p != NULL) p->Release();
            // return hr;
            return E_FAIL;
        }
        void (*pfnObjectMain)(bool starting);
    };
    typedef _ATL_OBJMAP_ENTRY30 _ATL_OBJMAP_ENTRY;



    // extern "C" _ATL_OBJMAP_ENTRY* __pobjMapEntryFirst; // = NULL;
    // extern "C" _ATL_OBJMAP_ENTRY* __pobjMapEntryLast; // = NULL;


    struct _ATL_TERMFUNC_ELEM
    {
        _ATL_TERMFUNC * pFunc;
        DWORD_PTR dw;
        _ATL_TERMFUNC_ELEM *  pNext;
    };


  }; // namespace ATL


#endif // !_WIN32

#endif // _BS_ATL_OBJMAP_H_INCLUDED_
