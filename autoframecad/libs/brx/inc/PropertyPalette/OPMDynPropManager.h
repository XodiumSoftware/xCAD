// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

using namespace ATL;

#ifdef _WIN32 
struct _OPM_DYNPROP_ENTRY 
{
public:
    _ATL_CREATORFUNC* pfnCreateInstance;
    const ACHAR*      strCmd;
    AcRxClass*        pClass;
    IDynamicProperty* pProp;
    const CLSID*      pclsid;
    IPropertySource*  pPropSrc;
};



#pragma section("dynprops$__a", read, shared)
#pragma section("dynprops$__m", read, shared)
#pragma section("dynprops$__z", read, shared)

extern "C" __declspec(selectany) __declspec(allocate("dynprops$__a")) 
    _OPM_DYNPROP_ENTRY* __pDynPropsEntryFirst = NULL;
    
extern "C" __declspec(selectany) __declspec(allocate("dynprops$__z")) 
    _OPM_DYNPROP_ENTRY* __pDynPropsEntryLast = NULL;

#ifdef __SYS_64_BIT__ // 64 bit
  #define OPM_DYNPROP_OBJECT_ENTRY_MAKE(dynPropCls, rxCls, clsId) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY __DynProps_##rxCls##dynPropCls = { \
        dynPropCls::_CreatorClass::CreateInstance, NULL, rxCls::desc(), NULL, &clsId, NULL \
    }; \
    extern "C" __declspec(selectany) __declspec(allocate("dynprops$__m")) \
        _OPM_DYNPROP_ENTRY* const __pDynProps_##rxCls##dynPropCls = \
        &__DynProps_##rxCls##dynPropCls; \
    __pragma(comment(linker, "/include:__pDynProps_" #rxCls #dynPropCls));
#else // 32 bit
  #define OPM_DYNPROP_OBJECT_ENTRY_MAKE(dynPropCls, rxCls, clsId) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY __DynProps_##rxCls##dynPropCls = { \
        dynPropCls::_CreatorClass::CreateInstance, NULL, rxCls::desc(), NULL, &clsId, NULL \
    }; \
    extern "C" __declspec(selectany) __declspec(allocate("dynprops$__m")) \
        _OPM_DYNPROP_ENTRY* const __pDynProps_##rxCls##dynPropCls = \
        &__DynProps_##rxCls##dynPropCls; \
    __pragma(comment(linker, "/include:___pDynProps_" #rxCls #dynPropCls));
#endif // __SYS_64_BIT__

#define OPM_DYNPROP_OBJECT_ENTRY_AUTO(dynPropCls, rxCls) \
    OPM_DYNPROP_OBJECT_ENTRY_MAKE(dynPropCls, rxCls, __uuidof (IDynamicProperty2))

#define OPM_DYNPROP_OBJECT_LEGACY1ENTRY_AUTO(dynPropCls, rxCls) \
    OPM_DYNPROP_OBJECT_ENTRY_MAKE(dynPropCls, rxCls, __uuidof(IDynamicProperty))

#ifdef __SYS_64_BIT__ // 64 bit
  #define OPM_DYNPROP_COMMAND_ENTRY_MAKE(dynPropCls, cmdName, clsId) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY __DynProps_##cmdName##dynPropCls = { \
        dynPropCls::_CreatorClass::CreateInstance, _RXST(#cmdName), NULL, NULL, &clsId \
    }; \
    extern "C" __declspec(allocate("dynprops$__m")) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY* const \
    __pDynProps_##cmdName##dynPropCls = &__DynProps_##cmdName##dynPropCls; \
    __pragma(comment(linker, "/include:__pDynProps_" #cmdName #dynPropCls));
#else // 32 bit
  #define OPM_DYNPROP_COMMAND_ENTRY_MAKE(dynPropCls, cmdName, clsId) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY __DynProps_##cmdName##dynPropCls = { \
        dynPropCls::_CreatorClass::CreateInstance, _RXST(#cmdName), NULL, NULL, &clsId \
    }; \
    extern "C" __declspec(allocate("dynprops$__m")) \
    __declspec(selectany) _OPM_DYNPROP_ENTRY* const \
    __pDynProps_##cmdName##dynPropCls = &__DynProps_##cmdName##dynPropCls; \
    __pragma(comment(linker, "/include:___pDynProps_" #cmdName #dynPropCls));
#endif

#define OPM_DYNPROP_COMMAND_ENTRY_AUTO(dynPropCls, cmdName) \
    OPM_DYNPROP_COMMAND_ENTRY_MAKE(dynPropCls, cmdName, __uuidof (IDynamicProperty2))

#define OPM_DYNPROP_COMMAND_LEGACY1ENTRY_AUTO(dynPropCls, cmdName) \
    OPM_DYNPROP_COMMAND_ENTRY_MAKE(dynPropCls, cmdName, __uuidof(IDynamicProperty))

#define OPM_DYNPROP_PERINSTANCE_ENTRY_AUTO(dynPropCls, rxCls) \
    OPM_DYNPROP_OBJECT_ENTRY_MAKE(dynPropCls, rxCls, __uuidof(IPropertySource))

#endif // _WIN32                      


class AcRxDynPropManager 
{
public:
    AcRxDynPropManager();
    virtual ~AcRxDynPropManager();
};

inline AcRxDynPropManager::AcRxDynPropManager() 
{
#ifdef _WIN32
    _OPM_DYNPROP_ENTRY** ppFirst = &__pDynPropsEntryFirst + 1;
    _OPM_DYNPROP_ENTRY** ppLast  = &__pDynPropsEntryLast;
    HRESULT hr = S_FALSE;
    for(_OPM_DYNPROP_ENTRY **ppRun = ppFirst; ppRun < ppLast; ppRun++) {
        _OPM_DYNPROP_ENTRY *pRun = *ppRun;
        if(NULL == *ppRun) {
            continue;
        }
        if((*(pRun->pclsid) == __uuidof(IDynamicProperty)) || (*(pRun->pclsid) == __uuidof(IDynamicProperty2))) {
            CComPtr<IPropertyManager> propManager;
            if(NULL != pRun->pClass) {
                if(AcDbDatabase::desc() == pRun->pClass) {
                    OPMPropertyExtension* pExt = GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(NULL, 2);
                    if (pExt != NULL)
                        propManager = pExt->GetPropertyManager();
                } else {
                    propManager = GET_OPMPROPERTY_MANAGER(pRun->pClass);
                }
                if(NULL != propManager.p) {
                    propManager.p->Release();
                }
            } else {
                BOOL ok = GET_OPMEXTENSION_CREATE_PROTOCOL()->GetOPMManager(pRun->strCmd, &propManager);
                if(FALSE == ok) {
                    propManager = GET_OPM_COMMAND_PROPERTY_MANAGER(pRun->strCmd);
                }
                OPMPropertyExtension *pOPMExt = GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMCommandProtocol(pRun->strCmd);
                pOPMExt->SetPropertyManager(propManager);
            }
            if(NULL == propManager) {
                _com_issue_error(E_FAIL);
            }
            hr = pRun->pfnCreateInstance(NULL, *(pRun->pclsid),(void **)&(pRun->pProp));
            _com_util::CheckError(hr);
           hr = propManager->AddProperty(pRun->pProp);
           _com_util::CheckError(hr);
        } else if(*(pRun->pclsid) == __uuidof(IPropertySource)) {
            bool ok = false;
            if(NULL != pRun->pClass) {
                hr = pRun->pfnCreateInstance(NULL, *(pRun->pclsid),(void **)&(pRun->pPropSrc));
                _com_util::CheckError(hr);
                // SetPropertySourceAt will do the AddRef
                CComBSTR name ;
                pRun->pPropSrc->get_Name(&name);
                IPropertySource *pPropSrc = GET_OPM_PERINSTANCE_PROPERTY_SOURCES()->GetPropertySourceAt(&name);
                if(NULL == pPropSrc) {
                    ok = GET_OPM_PERINSTANCE_PROPERTY_SOURCES()->SetPropertySourceAt(&name, pRun->pPropSrc);
                } else {
                    pRun->pPropSrc->Release();
                    pRun->pPropSrc = pPropSrc ;
                    pPropSrc = NULL;
                    ok = true;
                }
                ok = ok && GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(pRun->pClass)->AddObjectPropertySourceName(&name);
            }
            if(!ok) {
                _com_issue_error(E_FAIL);
            }
        } 
    }
#endif // _WIN32
}

inline AcRxDynPropManager::~AcRxDynPropManager() 
{
#ifdef _WIN32
    _OPM_DYNPROP_ENTRY** ppFirst = &__pDynPropsEntryFirst + 1;
    _OPM_DYNPROP_ENTRY** ppLast = &__pDynPropsEntryLast;
    HRESULT hr = S_FALSE;
    for(_OPM_DYNPROP_ENTRY** ppRun = ppFirst; ppRun < ppLast; ppRun++) {
        _OPM_DYNPROP_ENTRY *pRun = *ppRun;
        if(NULL == *ppRun) {
            continue;
        }
        if((*(pRun->pclsid) == __uuidof(IDynamicProperty)) || (*(pRun->pclsid) == __uuidof(IDynamicProperty2))) {
            OPMPropertyExtension* pExt = NULL;
            CComPtr<IPropertyManager> propManager;
            if(NULL != pRun->pClass) {
                if(AcDbDatabase::desc() == pRun->pClass) {
                    pExt = GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(NULL, 2);
                } else {
                    pExt = GET_OPMEXTENSION_CREATE_PROTOCOL()->CreateOPMObjectProtocol(pRun->pClass);
                }
                propManager = pExt->GetPropertyManager();
                if(NULL != propManager.p) {
                    propManager.p->Release();
                }
            } else {
                BOOL ok = GET_OPMEXTENSION_CREATE_PROTOCOL()->GetOPMManager(pRun->strCmd, &propManager);
                if(FALSE == ok) {
                    propManager = GET_OPM_COMMAND_PROPERTY_MANAGER(pRun->strCmd);
                }
            }
            if(NULL != pRun->pProp) {
                if(NULL == propManager) {
                    _com_issue_error(E_FAIL);
                }
                hr = propManager->RemoveProperty(pRun->pProp);
                _com_util::CheckError(hr);
               pRun->pProp->Release();
            }
            delete pExt, pExt=NULL;
        } else if(*(pRun->pclsid) == __uuidof(IPropertySource)) {
            bool ok = false;
            if(NULL != pRun->pPropSrc) {
                CComBSTR name ;
                pRun->pPropSrc->get_Name(&name);
                ok = GET_OPM_PERINSTANCE_EXTENSION_PROTOCOL(pRun->pClass)->RemoveObjectPropertySourceName(&name);
                if(pRun->pPropSrc->Release() <= 1) {
                    ok = ok && GET_OPM_PERINSTANCE_PROPERTY_SOURCES()->RemovePropertySourceAt(&name);
                }
            }
            if(!ok) {
                _com_issue_error(E_FAIL);
            }
        }
    }
#endif // _WIN32
}

