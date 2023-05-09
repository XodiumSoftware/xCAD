// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcEd/AcEdCommandStack.h"
#include "AcRx/AcRxDbxApp.h"
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

//BRX START

#ifdef _WIN32 // hide Linux/Mac GCC specifics
  #ifdef  __attribute__
  #undef  __attribute__
  #endif
  #define __attribute__(x)   /* emptry define under Windows */
#endif


// BRX command registration

class _ArxRegisteredCommand;

#ifdef _WIN32  // Windows

  // Array of registration helper class instances
  __declspec(selectany) AcArray<class _ArxRegisteredCommand*> __arxRegisteredCommands;
  inline AcArray<_ArxRegisteredCommand*> * __getArxRegisteredObjects()
  {
      return &__arxRegisteredCommands;
  };
  inline AcArray<_ArxRegisteredCommand*> * __getMyArxRegisteredObjects(void * /*pAppData*/)
  {
      return &__arxRegisteredCommands;
  };

  #ifdef __SYS_64_BIT__
    #define ACED_ARXCOMMAND_ENTRY_AUTO(T_CLASS,T_GROUPNAME,T_GLOBALNAME,T_LOCALNAME,T_FLAGS,T_CONTEXT) \
    extern "C" __declspec(selectany) _ArxRegisteredCommand __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME (T_CLASS::T_GROUPNAME##T_GLOBALNAME,ACRX_T(#T_LOCALNAME),ACRX_T(#T_GLOBALNAME),ACRX_T(#T_GROUPNAME),T_FLAGS,T_CONTEXT); \
    __pragma( comment(linker, "/include:__arxRegisteredCommand_" #T_GLOBALNAME #T_GROUPNAME) ); \
    const int __arxRegisteredFlags_##T_GLOBALNAME##T_GROUPNAME = __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME.getFlags();

    #define ACED_ARXCOMMAND_ENTRYBYID_AUTO(T_CLASS,T_GROUPNAME,T_GLOBALNAME,T_LOCALID,T_FLAGS,T_CONTEXT) \
    extern "C" __declspec(selectany) _ArxRegisteredCommand __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME (T_CLASS::T_GROUPNAME##T_GLOBALNAME,NULL,ACRX_T(#T_GLOBALNAME),ACRX_T(#T_GROUPNAME),T_FLAGS,T_CONTEXT,T_LOCALID); \
    __pragma( comment(linker, "/include:__arxRegisteredCommand_" #T_GLOBALNAME #T_GROUPNAME) ); \
    const int __arxRegisteredFlags_##T_GLOBALNAME##T_GROUPNAME = __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME.getFlags();
  #else
    #define ACED_ARXCOMMAND_ENTRY_AUTO(T_CLASS,T_GROUPNAME,T_GLOBALNAME,T_LOCALNAME,T_FLAGS,T_CONTEXT) \
    extern "C" __declspec(selectany) _ArxRegisteredCommand __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME (T_CLASS::T_GROUPNAME##T_GLOBALNAME,ACRX_T(#T_LOCALNAME),ACRX_T(#T_GLOBALNAME),ACRX_T(#T_GROUPNAME),T_FLAGS,T_CONTEXT); \
    __pragma( comment(linker, "/include:___arxRegisteredCommand_" #T_GLOBALNAME #T_GROUPNAME) ); \
    const int __arxRegisteredFlags_##T_GLOBALNAME##T_GROUPNAME = __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME.getFlags();

    #define ACED_ARXCOMMAND_ENTRYBYID_AUTO(T_CLASS,T_GROUPNAME,T_GLOBALNAME,T_LOCALID,T_FLAGS,T_CONTEXT) \
    extern "C" __declspec(selectany) _ArxRegisteredCommand __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME (T_CLASS::T_GROUPNAME##T_GLOBALNAME,NULL,ACRX_T(#T_GLOBALNAME),ACRX_T(#T_GROUPNAME),T_FLAGS,T_CONTEXT,T_LOCALID); \
    __pragma( comment(linker, "/include:___arxRegisteredCommand_" #T_GLOBALNAME #T_GROUPNAME) ); \
    const int __arxRegisteredFlags_##T_GLOBALNAME##T_GROUPNAME = __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME.getFlags();
  #endif

#else   // !_WIN32

  // Array of registration helper class instances
  AcArray<_ArxRegisteredCommand*> * __getArxRegisteredObjects();
  AcArray<_ArxRegisteredCommand*> * __getMyArxRegisteredObjects(void * pAppData);

  #define ACED_ARXCOMMAND_ENTRY_AUTO(T_CLASS,T_GROUPNAME,T_GLOBALNAME,T_LOCALNAME,T_FLAGS,T_CONTEXT) \
  __attribute__((weak, init_priority(50200), visibility("hidden"))) /* initialise at very late moment */ \
  _ArxRegisteredCommand __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME(T_CLASS::T_GROUPNAME##T_GLOBALNAME,ACRX_T(#T_LOCALNAME),ACRX_T(#T_GLOBALNAME),ACRX_T(#T_GROUPNAME),T_FLAGS,T_CONTEXT); \
  const int __arxRegisteredFlags_##T_GLOBALNAME##T_GROUPNAME = T_FLAGS;

  #define ACED_ARXCOMMAND_ENTRYBYID_AUTO(T_CLASS,T_GROUPNAME,T_GLOBALNAME,T_LOCALID,T_FLAGS,T_CONTEXT) \
  __attribute__((weak, init_priority(50200), visibility("hidden"))) /* initialise at very late moment */ \
  _ArxRegisteredCommand __arxRegisteredCommand_##T_GLOBALNAME##T_GROUPNAME(T_CLASS::T_GROUPNAME##T_GLOBALNAME,NULL,ACRX_T(#T_GLOBALNAME),ACRX_T(#T_GROUPNAME),T_FLAGS,T_CONTEXT,T_LOCALID); \
  const int __arxRegisteredFlags_##T_GLOBALNAME##T_GROUPNAME = T_FLAGS;

#endif  // Linux,Mac

// BRX command registration helper

class _ArxRegisteredCommand
{
private:
    AcRxFunctionPtr m_fpCmdFunction;
    const ACHAR* m_pLocalName;
    const ACHAR* m_pGlobalName;
    const ACHAR* m_pGroupName;
    ACHAR m_localName[133];
    Adesk::Int32 m_flags;
    AcEdUIContext* m_pContext;
    UINT m_localNameResourceID;
public:
    _ArxRegisteredCommand()
    {
        m_fpCmdFunction = NULL;
        m_pLocalName = NULL;
        m_pGlobalName = NULL;
        m_pGroupName = NULL;
        m_localName[0] = 0;
        m_flags = 0;
        m_pContext = NULL;
        m_localNameResourceID = 0;
    }

    _ArxRegisteredCommand(const AcRxFunctionPtr fpCmdFunction,const ACHAR* pLocalName,const ACHAR* pGlobalName,const ACHAR* pGroupName,
                          const Adesk::Int32 flags,AcEdUIContext* pContext,const UINT localNameResourceID = -1)
    {
        m_fpCmdFunction = fpCmdFunction;
        m_pLocalName = pLocalName;
        m_pGlobalName = pGlobalName;
        m_pGroupName = pGroupName;
        m_localName[0] = 0;
        m_flags = flags;
        m_pContext = pContext;
        m_localNameResourceID = localNameResourceID;

        AcArray<_ArxRegisteredCommand*> * arxRegisteredCommands = __getArxRegisteredObjects();
        if (arxRegisteredCommands)
            arxRegisteredCommands->append(this);
    }

    AcRxFunctionPtr getCmdFunction() const { return m_fpCmdFunction; }
    const ACHAR* getLocalName() const { return m_pLocalName; }
    const ACHAR* getGlobalName() const { return m_pGlobalName; }
    const ACHAR* getGroupName() const { return m_pGroupName; }
    Adesk::Int32 getFlags() const { return m_flags; }
    AcEdUIContext* getContext() const { return m_pContext; }

    void loadLocalName(const HINSTANCE hInstance)
    {
        if (NULL != m_pLocalName)
            return;
#ifdef _WIN32
        ::LoadString(hInstance,m_localNameResourceID,m_localName,132);
#else
        _tcscpy(m_localName, getGlobalName());
#endif
        m_pLocalName = m_localName;
    }
};


// SDS command registration

class _AdsRegisteredSymbol;

#ifdef _WIN32  // Windows

  // Array of registration helper class instances
  __declspec(selectany) AcArray<_AdsRegisteredSymbol*> __adsRegisteredSymbols;
  inline AcArray<_AdsRegisteredSymbol*> * __getAdsRegisteredObjects()
  {
      return &__adsRegisteredSymbols;
  };
  inline AcArray<_AdsRegisteredSymbol*> * __getMyAdsRegisteredObjects(void * /*pAppData*/)
  {
      return &__adsRegisteredSymbols;
  };

  #ifdef __SYS_64_BIT__
    #define ACED_ADSSYMBOL_ENTRY_AUTO(T_CLASS,T_NAME,T_REGISTERFUNCTION) \
    extern "C" __declspec(selectany) _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,ACRX_T(#T_NAME),T_REGISTERFUNCTION); \
    __pragma( comment(linker, "/include:__adsRegisteredSymbol_" #T_NAME) ); \
    const bool __adsRegisteredFunction_##T_CLASS##T_NAME = __adsRegisteredSymbol_##T_NAME.registerFunction();

    #define ACED_ADSSYMBOL_ENTRYBYID_AUTO(T_CLASS,T_NAME,T_NAMEID,T_REGISTERFUNCTION) \
    extern "C" __declspec(selectany) _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,NULL,T_REGISTERFUNCTION,T_NAMEID); \
    __pragma( comment(linker, "/include:__adsRegisteredSymbol_" #T_NAME) ); \
    const bool __adsRegisteredFunction_##T_CLASS##T_NAME = __adsRegisteredSymbol_##T_NAME.registerFunction();

    #define ACED_ADSCOMMAND_ENTRY_AUTO(T_CLASS,T_NAME,T_REGISTERFUNCTION) \
    extern "C" __declspec(selectany) _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,ACRX_T("C:") ACRX_T(#T_NAME),T_REGISTERFUNCTION); \
    __pragma( comment(linker, "/include:__adsRegisteredSymbol_" #T_NAME) ); \
    const bool __adsRegisteredFunction_##T_CLASS##T_NAME = __adsRegisteredSymbol_##T_NAME.registerFunction();
  #else
    #define ACED_ADSSYMBOL_ENTRY_AUTO(T_CLASS,T_NAME,T_REGISTERFUNCTION) \
    extern "C" __declspec(selectany) _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,ACRX_T(#T_NAME),T_REGISTERFUNCTION); \
    __pragma( comment(linker, "/include:___adsRegisteredSymbol_" #T_NAME) ); \
    const bool __adsRegisteredFunction_##T_CLASS##T_NAME = __adsRegisteredSymbol_##T_NAME.registerFunction();

    #define ACED_ADSSYMBOL_ENTRYBYID_AUTO(T_CLASS,T_NAME,T_NAMEID,T_REGISTERFUNCTION) \
    extern "C" __declspec(selectany) _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,NULL,T_REGISTERFUNCTION,T_NAMEID); \
    __pragma( comment(linker, "/include:___adsRegisteredSymbol_" #T_NAME) ); \
    const bool __adsRegisteredFunction_##T_CLASS##T_NAME = __adsRegisteredSymbol_##T_NAME.registerFunction();

    #define ACED_ADSCOMMAND_ENTRY_AUTO(T_CLASS,T_NAME,T_REGISTERFUNCTION) \
    extern "C" __declspec(selectany) _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,ACRX_T("C:") ACRX_T(#T_NAME),T_REGISTERFUNCTION); \
    __pragma( comment(linker, "/include:___adsRegisteredSymbol_" #T_NAME) ); \
    const bool __adsRegisteredFunction_##T_CLASS##T_NAME = __adsRegisteredSymbol_##T_NAME.registerFunction();
  #endif

#else   // !_WIN32

  // Array of registration helper class instances
  AcArray<_AdsRegisteredSymbol*> * __getAdsRegisteredObjects();
  AcArray<_AdsRegisteredSymbol*> * __getMyAdsRegisteredObjects(void * pAppData);

  #define ACED_ADSSYMBOL_ENTRY_AUTO(T_CLASS,T_NAME,T_REGISTERFUNCTION) \
  __attribute__((weak, init_priority(50300), visibility("hidden"))) /* initialise at very late moment */ \
  _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,ACRX_T(#T_NAME),T_REGISTERFUNCTION);

  #define ACED_ADSSYMBOL_ENTRYBYID_AUTO(T_CLASS,T_NAME,T_NAMEID,T_REGISTERFUNCTION) \
  __attribute__((weak, init_priority(50300), visibility("hidden"))) /* initialise at very late moment */ \
  _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,NULL,T_REGISTERFUNCTION,T_NAMEID);

  #define ACED_ADSCOMMAND_ENTRY_AUTO(T_CLASS,T_NAME,T_REGISTERFUNCTION) \
  __attribute__((weak, init_priority(50300), visibility("hidden"))) /* initialise at very late moment */ \
  _AdsRegisteredSymbol __adsRegisteredSymbol_##T_NAME(T_CLASS::ads_ ##T_NAME,ACRX_T("C:") ACRX_T(#T_NAME),T_REGISTERFUNCTION);

#endif  // Linux,Mac

// SDS command registration helper

typedef int (*_AdsFuncPtr)();

class _AdsRegisteredSymbol
{
private:
    _AdsFuncPtr m_fpFunction;
    const ACHAR* m_pName;
    ACHAR m_name[133];
    bool m_registerFunction;
    UINT m_nameResourceID;
public:
    _AdsRegisteredSymbol()
    {
        m_fpFunction = NULL;
        m_pName = NULL;
        m_name[0] = 0;
        m_registerFunction = false;
        m_nameResourceID = 0;
    }

    _AdsRegisteredSymbol(const _AdsFuncPtr fpFunction,const ACHAR* pName,const bool registerFunction,const UINT nameResourceID = (UINT)-1)
    {
        m_fpFunction = fpFunction;
        m_pName = pName;
        m_name[0] = 0;
        m_registerFunction = registerFunction;
        m_nameResourceID = nameResourceID;

        AcArray<_AdsRegisteredSymbol*> * adsRegisteredSymbols = __getAdsRegisteredObjects();
        if (adsRegisteredSymbols)
            adsRegisteredSymbols->append(this);
    }

    _AdsFuncPtr getFunction() const { return m_fpFunction; }
    const ACHAR* getName() const { return m_pName; }
    const bool registerFunction() const { return m_registerFunction; }

    void loadName(const HINSTANCE hInstance)
    {
        if (NULL != m_pName)
            return;
#ifdef _WIN32
        ::LoadString(hInstance,m_nameResourceID,m_name,132);
#else
        _tcscpy(m_name, m_pName);
#endif
        m_pName = m_name;
    }
};


#define ACED_ADSCOMMAND_ENTRYBYID_AUTO(T_CLASS,T_NAME,T_NAMEID,T_REGISTERFUNCTION) \
ACED_ADSSYMBOL_ENTRYBYID_AUTO(T_CLASS,T_NAME,T_NAMEID,T_REGISTERFUNCTION)

/** _ */
class AcRxArxApp: public AcRxDbxApp
{
public:
    AcRxArxApp();

    virtual AcRx::AppRetCode On_kInitAppMsg(void*);
    virtual AcRx::AppRetCode On_kInvkSubrMsg(void*);
    virtual AcRx::AppRetCode On_kLoadDwgMsg(void*);
    virtual AcRx::AppRetCode On_kUnloadAppMsg(void*);
    virtual AcRx::AppRetCode On_kUnloadDwgMsg(void*);
#ifdef __ATLCOM_H__
protected:
    AcRxDynPropManager *m_pDynPropManager ;
#endif
};

inline AcRxArxApp::AcRxArxApp()
    : AcRxDbxApp()
#ifdef __ATLCOM_H__
    , m_pDynPropManager(NULL)
#endif
{
}

inline AcRx::AppRetCode AcRxArxApp::On_kInitAppMsg(void* pAppData)
{
    AcRx::AppRetCode result = AcRxDbxApp::On_kInitAppMsg(pAppData);

    AcArray<_ArxRegisteredCommand*> * arxRegisteredCommands = __getMyArxRegisteredObjects(pAppData);
    if (!arxRegisteredCommands)
        return result;

    _ArxRegisteredCommand * pArxCommandStorage = NULL;
    for (int i = 0; i < arxRegisteredCommands->length(); i++)
    {
        pArxCommandStorage = arxRegisteredCommands->at(i);
        if (!pArxCommandStorage)
            continue;

        pArxCommandStorage->loadLocalName(m_hdllInstance);

        HINSTANCE hInstance = this->GetModuleInstance();

        acedRegCmds->addCommand(pArxCommandStorage->getGroupName(),
                                pArxCommandStorage->getGlobalName(),
                                pArxCommandStorage->getLocalName(),
                                pArxCommandStorage->getFlags(),
                                pArxCommandStorage->getCmdFunction(),
                                pArxCommandStorage->getContext(),
                                -1,
                                hInstance);
    }

#ifdef __ATLCOM_H__
    m_pDynPropManager = new AcRxDynPropManager();
#endif
    return result;
}

inline AcRx::AppRetCode AcRxArxApp::On_kUnloadAppMsg(void* pAppData)
{
    AcRx::AppRetCode result = AcRxDbxApp::On_kUnloadAppMsg(pAppData);

    AcArray<_ArxRegisteredCommand*> * arxRegisteredCommands = __getMyArxRegisteredObjects(pAppData);
    if (!arxRegisteredCommands)
        return result;

    _ArxRegisteredCommand * pArxCommandStorage = NULL;
    for (int i = 0; i < arxRegisteredCommands->length(); i++)
    {
        pArxCommandStorage = arxRegisteredCommands->at(i);
        if (!pArxCommandStorage)
            continue;
        acedRegCmds->removeCmd(pArxCommandStorage->getGroupName(),
                               pArxCommandStorage->getGlobalName());
    }
#ifdef __ATLCOM_H__
    if(NULL != m_pDynPropManager) 
    {
        delete m_pDynPropManager, m_pDynPropManager = NULL;
    }
#endif
    return result;
}

inline AcRx::AppRetCode AcRxArxApp::On_kLoadDwgMsg(void* pAppData)
{
    AcRx::AppRetCode result = AcRxDbxApp::On_kLoadDwgMsg(pAppData);

    AcArray<_AdsRegisteredSymbol*> * adsRegisteredSymbols = __getMyAdsRegisteredObjects(NULL);
    if (!adsRegisteredSymbols)
        return result;

    _AdsRegisteredSymbol * pAdsCommandStorage = NULL;
    for (short i = 0; i < adsRegisteredSymbols->length(); i++)
    {
        pAdsCommandStorage = adsRegisteredSymbols->at(i);
        if (!pAdsCommandStorage)
            continue;

        pAdsCommandStorage->loadName(m_hdllInstance);

        acedDefun(pAdsCommandStorage->getName(),i);
        if (pAdsCommandStorage->registerFunction())
            acedRegFunc(pAdsCommandStorage->getFunction(),i);
    }

    return result;
}

inline AcRx::AppRetCode AcRxArxApp::On_kUnloadDwgMsg(void* pAppData)
{
    AcRx::AppRetCode result = AcRxDbxApp::On_kUnloadDwgMsg(pAppData);

    AcArray<_AdsRegisteredSymbol*> * adsRegisteredSymbols = __getMyAdsRegisteredObjects(NULL);
    if (!adsRegisteredSymbols)
        return result;

    _AdsRegisteredSymbol * pAdsCommandStorage = NULL;
    for (short i = 0; i < adsRegisteredSymbols->length(); i++)
    {
        pAdsCommandStorage = adsRegisteredSymbols->at(i);
        if (!pAdsCommandStorage)
            continue;

        pAdsCommandStorage->loadName(m_hdllInstance);

        acedUndef(pAdsCommandStorage->getName(),i);
    }

    return result;
}

inline AcRx::AppRetCode AcRxArxApp::On_kInvkSubrMsg(void* pAppData)
{
    AcRx::AppRetCode result = AcRxDbxApp::On_kInvkSubrMsg(pAppData);

    AcArray<_AdsRegisteredSymbol*> * adsRegisteredSymbols = __getMyAdsRegisteredObjects(NULL);
    if (!adsRegisteredSymbols)
        return result;

    int funCode = acedGetFunCode();
    if (funCode < 0 || funCode >= adsRegisteredSymbols->length())
        return result;

    _AdsRegisteredSymbol * pAdsCommandStorage = adsRegisteredSymbols->at(funCode);

    _AdsFuncPtr fp = pAdsCommandStorage->getFunction();
    fp();

    return result;
}

//BRX END
