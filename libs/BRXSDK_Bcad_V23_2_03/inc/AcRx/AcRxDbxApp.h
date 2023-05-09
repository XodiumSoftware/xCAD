// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_platform_3264.h"
#include "AcRx/AcRxDictionary.h"
#include "AcRx/AcRxDynamicLinker.h"
#include "Misc/AcArray.h"

#ifdef _WIN32
  #ifdef __SYS_64_BIT__
    #pragma comment(linker,"/export:acrxGetApiVersion,PRIVATE")
  #else
    #pragma comment(linker,"/export:_acrxGetApiVersion,PRIVATE")
  #endif  
#endif

//BRX START

#ifdef _WIN32 // hide Linux/Mac GCC specifics
  #ifdef  __attribute__
  #undef  __attribute__
  #endif
  #define __attribute__(x)   /* emptry define under Windows */
#endif


// DBX class registration

class _DbxRegisteredObject;

#ifdef _WIN32  // Windows

  // Array of registration helper class instances
  __declspec(selectany) AcArray<_DbxRegisteredObject*> __dbxRegisteredObjects;
  inline AcArray<_DbxRegisteredObject*> * __getDbxRegisteredObjects()
  {
      return &__dbxRegisteredObjects;
  };
  inline AcArray<_DbxRegisteredObject*> * __getMyDbxRegisteredObjects(void * /*pAppData*/)
  {
      return &__dbxRegisteredObjects;
  };

  #ifdef __SYS_64_BIT__
    #define ACDB_REGISTER_OBJECT_ENTRY_AUTO(T_CLASS) \
    extern "C" __declspec(selectany) _DbxRegisteredObject __dbxRegisteredObject_##T_CLASS(T_CLASS::desc,T_CLASS::rxInit); \
    __pragma( comment(linker, "/include:__dbxRegisteredObject_" #T_CLASS) );
  #else
    #define ACDB_REGISTER_OBJECT_ENTRY_AUTO(T_CLASS) \
    extern "C" __declspec(selectany) _DbxRegisteredObject __dbxRegisteredObject_##T_CLASS(T_CLASS::desc,T_CLASS::rxInit); \
    __pragma( comment(linker, "/include:___dbxRegisteredObject_" #T_CLASS) );
  #endif

#else   // !_WIN32

  // Array of registration helper class instances, provided by BRX core at runtime
  AcArray<_DbxRegisteredObject*> * __getDbxRegisteredObjects();
  AcArray<_DbxRegisteredObject*> * __getMyDbxRegisteredObjects(void * pAppData);

  #define ACDB_REGISTER_OBJECT_ENTRY_AUTO(T_CLASS) \
  __attribute__((weak, init_priority(50100), visibility("hidden"))) /* initialise after __dbxRegisteredObjects array */ \
  _DbxRegisteredObject __dbxRegisteredObject_##T_CLASS(T_CLASS::desc,T_CLASS::rxInit);

#endif  // Linux,Mac

// DBX class registration helper

class _DbxRegisteredObject
{
private:
    AcRxClass* (*m_fpDesc)();
    void (*m_fpRxInit)();

public:
    _DbxRegisteredObject()
    {
        m_fpDesc = NULL;
        m_fpRxInit = NULL;
    }

    _DbxRegisteredObject(AcRxClass* (*fpDesc)(),void (*fpRxInit)())
    {
        m_fpDesc = fpDesc;
        m_fpRxInit = fpRxInit;

        AcArray<_DbxRegisteredObject*> * dbxRegisteredObjects = __getDbxRegisteredObjects();
        if (dbxRegisteredObjects)
            dbxRegisteredObjects->append(this);
    }

    void rxInit() { m_fpRxInit(); }
    AcRxClass* getClass() { return m_fpDesc(); }
};


class AcRxDbxApp
{
protected:
    bool m_bMDIAware;
    bool m_bUnlocked;
    HINSTANCE m_hdllInstance;

public:
    AcRxDbxApp();

    virtual AcRx::AppRetCode On_kCfgMsg(void*);
    virtual AcRx::AppRetCode On_kDependencyMsg(void*);
    virtual AcRx::AppRetCode On_kEndDialogMsg(void*);
    virtual AcRx::AppRetCode On_kEndMsg(void*);
    virtual AcRx::AppRetCode On_kInitAppMsg(void*);
    virtual AcRx::AppRetCode On_kInitDialogMsg(void*);
    virtual AcRx::AppRetCode On_kInvkSubrMsg(void*);
    virtual AcRx::AppRetCode On_kLoadDwgMsg(void*);
    virtual AcRx::AppRetCode On_kNoDependencyMsg(void*);
    virtual AcRx::AppRetCode On_kNullMsg(void*);
    virtual AcRx::AppRetCode On_kOleUnloadAppMsg(void*);
    virtual AcRx::AppRetCode On_kPreQuitMsg(void*);
    virtual AcRx::AppRetCode On_kQuitMsg(void*);
    virtual AcRx::AppRetCode On_kSaveMsg(void*);
    virtual AcRx::AppRetCode On_kUnloadAppMsg(void*);
    virtual AcRx::AppRetCode On_kUnloadDwgMsg(void*);
    virtual AcRx::AppRetCode On_kSuspendMsg(void*);
    virtual void RegisterServerComponents() = 0;

    AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode,void*);
    HINSTANCE& GetModuleInstance();
};

inline AcRxDbxApp::AcRxDbxApp()
{
    m_bMDIAware = true;
    m_bUnlocked = true;
    m_hdllInstance = NULL;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kInitAppMsg(void* pAppData)
{
    if (m_bUnlocked)
        acrxDynamicLinker->unlockApplication(pAppData);
    if (m_bMDIAware)
        acrxDynamicLinker->registerAppMDIAware(pAppData);

    RegisterServerComponents();

    const AcArray<_DbxRegisteredObject*> * dbxRegisteredObjects = __getMyDbxRegisteredObjects(pAppData);
    if (dbxRegisteredObjects == NULL)
        return AcRx::kRetOK;

    if (dbxRegisteredObjects->length() > 0)
    {
        _DbxRegisteredObject * pDbxCommandStorage = NULL;
        for (int i = 0, n = dbxRegisteredObjects->length(); i < n; ++i)
        {
            pDbxCommandStorage = dbxRegisteredObjects->at(i);
            if (pDbxCommandStorage != NULL)
                pDbxCommandStorage->rxInit();
        }
        acrxBuildClassHierarchy();
    }
    return AcRx::kRetOK;
}

extern void deleteAcRxClassBranch(AcRxClass*);
inline AcRx::AppRetCode AcRxDbxApp::On_kUnloadAppMsg(void* pAppData)
{
    const AcArray<_DbxRegisteredObject*> * dbxRegisteredObjects = __getMyDbxRegisteredObjects(pAppData);
    if (dbxRegisteredObjects == NULL)
        return AcRx::kRetOK;

    _DbxRegisteredObject * pDbxCommandStorage = NULL;
    for (int i = 0, n = dbxRegisteredObjects->length(); i < n; ++i)
    {
        pDbxCommandStorage = dbxRegisteredObjects->at(i);
        if (pDbxCommandStorage != NULL)
            deleteAcRxClassBranch(pDbxCommandStorage->getClass());
    }
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kCfgMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kDependencyMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kEndDialogMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kEndMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kInitDialogMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kInvkSubrMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kLoadDwgMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kNoDependencyMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kNullMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kOleUnloadAppMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kPreQuitMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kQuitMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kSaveMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kUnloadDwgMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::On_kSuspendMsg(void*)
{
    return AcRx::kRetOK;
}

inline AcRx::AppRetCode AcRxDbxApp::acrxEntryPoint(AcRx::AppMsgCode eCode,void* pAppData)
{
    switch (eCode)
    {
        case AcRx::kCfgMsg: return On_kCfgMsg(pAppData);
        case AcRx::kDependencyMsg: return On_kDependencyMsg(pAppData);
        case AcRx::kEndDialogMsg: return On_kEndDialogMsg(pAppData);
        case AcRx::kEndMsg: return On_kEndMsg(pAppData);
        case AcRx::kInitAppMsg: return On_kInitAppMsg(pAppData);
        case AcRx::kInitDialogMsg: return On_kInitDialogMsg(pAppData);
        case AcRx::kInvkSubrMsg: return On_kInvkSubrMsg(pAppData);
        case AcRx::kLoadDwgMsg: return On_kLoadDwgMsg(pAppData);
        case AcRx::kNoDependencyMsg: return On_kNoDependencyMsg(pAppData);
        case AcRx::kNullMsg: return On_kNullMsg(pAppData);
        case AcRx::kOleUnloadAppMsg: return On_kOleUnloadAppMsg(pAppData);
        case AcRx::kPreQuitMsg: return On_kPreQuitMsg(pAppData);
        case AcRx::kQuitMsg: return On_kQuitMsg(pAppData);
        case AcRx::kSaveMsg: return On_kSaveMsg(pAppData);
        case AcRx::kUnloadAppMsg: return On_kUnloadAppMsg(pAppData);
        case AcRx::kUnloadDwgMsg: return On_kUnloadDwgMsg(pAppData);
        case AcRx::kSuspendMsg: return On_kSuspendMsg(pAppData);
    }
    return AcRx::kRetOK;
}

inline HINSTANCE& AcRxDbxApp::GetModuleInstance()
{
    return m_hdllInstance;
}

AcRxDbxApp* acrxGetApp();
#define _hdllInstance acrxGetApp()->GetModuleInstance()

#ifdef _WIN32
  #define IMPLEMENT_ARX_ENTRYPOINT(T_OBJECT) \
  T_OBJECT singleInstanceEpObject; \
  AcRxDbxApp* acrxGetApp() \
  { \
      return &singleInstanceEpObject; \
  } \
  extern "C" AcRx::AppRetCode __declspec(dllexport) acrxEntryPoint(AcRx::AppMsgCode eCode,void* pAppData) \
  { \
      return acrxGetApp()->acrxEntryPoint(eCode, pAppData); \
  }
#elif __APPLE__
  #define IMPLEMENT_ARX_ENTRYPOINT(T_OBJECT) \
  __attribute__((visibility("hidden"))) \
  AcRxDbxApp* acrxGetApp() \
  { \
      static T_OBJECT singleInstanceEpObject; \
      return &singleInstanceEpObject; \
  } \
  extern "C" AcRx::AppRetCode __attribute__((visibility("default"))) acrxEntryPoint(AcRx::AppMsgCode eCode,void* pAppData) \
  { \
      return acrxGetApp()->acrxEntryPoint(eCode, pAppData); \
  }
#else  // Linux,Mac
  #define IMPLEMENT_ARX_ENTRYPOINT(T_OBJECT) \
  __attribute__((externally_visible, visibility("hidden"))) \
  AcRxDbxApp* acrxGetApp() \
  { \
      static T_OBJECT singleInstanceEpObject; \
      return &singleInstanceEpObject; \
  } \
  extern "C" AcRx::AppRetCode __attribute__((visibility("default"))) acrxEntryPoint(AcRx::AppMsgCode eCode,void* pAppData) \
  { \
      return acrxGetApp()->acrxEntryPoint(eCode, pAppData); \
  }
#endif // !_WIN32

//BRX END
