// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcRx/AcRxGlobal.h"

#ifdef __cplusplus

#if !defined(BRX_API) && !defined(BRXMGD_MODULE)
#ifndef _ODRXOBJECT_INCLUDED_
//if Teigha RxObject.h isn't included, define an alias OdPseudoConstructorType
class OdRxObject {};
class OdRxObjectPtr
{
private:
    OdRxObject* m_pObject;
public:
    OdRxObjectPtr() : m_pObject(NULL) {};
    ~OdRxObjectPtr() { m_pObject = NULL; };

    OdRxObjectPtr& operator= (const OdRxObjectPtr& source)
    {
        m_pObject = source.m_pObject;
        return *this;
    };
    OdRxObjectPtr& operator= (const OdRxObject* source)
    {
        m_pObject = (OdRxObject*)source;
        return *this;
    };
};
typedef OdRxObjectPtr(*OdPseudoConstructorType)();
#endif
#endif

//BRX-specific version of newAcRxClass() that takes both Ac and Od constructor functions
AcRxClass* newBrxClass(const ACHAR*, const ACHAR*, int, int, int = 0, AcRxObject* (*pc)() = NULL, OdPseudoConstructorType = NULL, const ACHAR* = NULL, const ACHAR* = NULL, AppNameChangeFuncPtr = NULL, int = 0);

#define __BRX_STRINGIFY(CLASSNAME)  ACRX_T(#CLASSNAME)

template <typename CLASS> static AcRxObject* acrxInstantiateClass() { return new CLASS(); }

#define ACRX_DECLARE_MEMBERS_EXPIMP(CLASS, EXPIMP) \
    static AcRxClass* gpDesc; \
    EXPIMP static AcRxClass* desc(); \
    static CLASS* cast(const AcRxObject* pObject) \
    { \
        return (pObject && pObject->isKindOf(CLASS::desc())) ? (CLASS*)pObject : NULL; \
    } \
    static void rxInit(); \
    static void rxInit(AppNameChangeFuncPtr); \
    EXPIMP AcRxClass* isA() const override; \
    static OdRxObjectPtr createOdObjectImp(const ACHAR* dwgClassName);

#define ACRX_EMPTY

#define ACRX_DECLARE_MEMBERS(CLASS) \
    ACRX_DECLARE_MEMBERS_EXPIMP(CLASS, ACRX_EMPTY)

#define ACRX_DEFINE_MEMBERS(CLASS) \
    AcRxClass* CLASS::gpDesc = NULL; \
    AcRxClass* CLASS::desc() \
    { \
        if (NULL == CLASS::gpDesc) \
        { \
            const AcRxDictionary* pClassDict = (AcRxDictionary*) acrxSysRegistry()->at(ACRX_CLASS_DICTIONARY); \
            CLASS::gpDesc = (AcRxClass*) pClassDict->at(__BRX_STRINGIFY(CLASS)); \
        } \
        return CLASS::gpDesc; \
    } \
    AcRxClass* CLASS::isA() const \
    { \
        return CLASS::desc(); \
    }

#define ACRX_STATIC_CHECK(CLASS) \
    if (NULL != CLASS::gpDesc) \
    { \
        const AcRxDictionary* pSysReg = acrxSysRegistry(); \
        if (NULL != pSysReg) \
        { \
            const AcRxDictionary* pClassDict = (AcRxDictionary*) pSysReg->at(ACRX_CLASS_DICTIONARY); \
            if (NULL != pClassDict) \
            { \
                const AcRxClass* pClass = (AcRxClass*) pClassDict->at(__BRX_STRINGIFY(CLASS)); \
                if (NULL != pClass) \
                { \
                    if (CLASS::gpDesc == pClass) return; \
                    acrx_abort(ACRX_T("Class mismatch")); \
                } \
            } \
        } \
    }

#define ACRX_NO_CONS_DEFINE_MEMBERS(CLASS,PARENTCLASS) \
    ACRX_DEFINE_MEMBERS(CLASS); \
    void CLASS::rxInit() \
    { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),0,0); \
    } \
    OdRxObjectPtr CLASS::createOdObjectImp(const ACHAR* dwgClassName) \
    { \
        return PARENTCLASS::createOdObjectImp(dwgClassName); \
    }

#define ACRX_NO_CONS_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS,PARENTCLASS,PROPS) \
    ACRX_DEFINE_MEMBERS(CLASS); \
    void CLASS::rxInit() \
    { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),0,0); \
    } \
    OdRxObjectPtr CLASS::createOdObjectImp(const ACHAR* dwgClassName) \
    { \
        return PARENTCLASS::createOdObjectImp(dwgClassName); \
    }

#define ACRX_CONS_DEFINE_MEMBERS(CLASS,PARENTCLASS,PROXYFLAGS) \
    ACRX_DEFINE_MEMBERS(CLASS); \
    static AcRxObject* make##CLASS() { return new CLASS(); } \
    static OdRxObjectPtr makeOdObjectFor##CLASS() { return PARENTCLASS::createOdObjectImp(__BRX_STRINGIFY(CLASS)); } \
    void CLASS::rxInit() \
    { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),AcDb::kDHL_CURRENT,AcDb::kMReleaseCurrent, \
            PROXYFLAGS,&make##CLASS,&makeOdObjectFor##CLASS,NULL,NULL,NULL,0 /*PROPS not supported yet*/); \
    } \
    OdRxObjectPtr CLASS::createOdObjectImp(const ACHAR* dwgClassName) \
    { \
        return PARENTCLASS::createOdObjectImp(dwgClassName); \
    }

#define ACRX_DXF_DEFINE_MEMBERS(CLASS,PARENTCLASS,MAJORVERSION,MINORVERSION,PROXYFLAGS,DXFNAME,APPNAME) \
    ACRX_DEFINE_MEMBERS(CLASS); \
    static AcRxObject* make##CLASS() { return new CLASS(); } \
    static OdRxObjectPtr makeOdObjectFor##CLASS() { return PARENTCLASS::createOdObjectImp(__BRX_STRINGIFY(CLASS)); } \
    void CLASS::rxInit() \
    { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),MAJORVERSION,MINORVERSION,PROXYFLAGS, \
            &make##CLASS,&makeOdObjectFor##CLASS,ACRX_T(#DXFNAME),ACRX_T(#APPNAME),NULL,0 /*PROPS not supported yet*/); \
    } \
    void CLASS::rxInit(AppNameChangeFuncPtr pFunc) { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),MAJORVERSION,MINORVERSION,PROXYFLAGS, \
            &make##CLASS,&makeOdObjectFor##CLASS,ACRX_T(#DXFNAME),ACRX_T(#APPNAME),pFunc,0 /*PROPS not supported yet*/); \
    } \
    OdRxObjectPtr CLASS::createOdObjectImp(const ACHAR* dwgClassName) \
    { \
        return PARENTCLASS::createOdObjectImp(dwgClassName); \
    }

#define ACRX_DXF_DEFINE_MEMBERS_WITH_PROPERTIES(CLASS,PARENTCLASS,MAJORVERSION,MINORVERSION,PROXYFLAGS,DXFNAME,APPNAME,PROPS) \
    ACRX_DEFINE_MEMBERS(CLASS); \
    static AcRxObject* make##CLASS() { return new CLASS(); } \
    static OdRxObjectPtr makeOdObjectFor##CLASS() { return PARENTCLASS::createOdObjectImp(__BRX_STRINGIFY(CLASS)); } \
    void CLASS::rxInit() \
    { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),MAJORVERSION,MINORVERSION,PROXYFLAGS, \
            &make##CLASS,&makeOdObjectFor##CLASS,ACRX_T(#DXFNAME),ACRX_T(#APPNAME),NULL,0 /*,PROPS not supported yet*/); \
    } \
    void CLASS::rxInit(AppNameChangeFuncPtr pFunc) { \
        ACRX_STATIC_CHECK(CLASS); \
        CLASS::gpDesc = newBrxClass(__BRX_STRINGIFY(CLASS),__BRX_STRINGIFY(PARENTCLASS),MAJORVERSION,MINORVERSION,PROXYFLAGS, \
            &make##CLASS,&makeOdObjectFor##CLASS,ACRX_T(#DXFNAME),ACRX_T(#APPNAME),pFunc,0 /*,PROPS not supported yet*/); \
    } \
    OdRxObjectPtr CLASS::createOdObjectImp(const ACHAR* dwgClassName) \
    { \
        return PARENTCLASS::createOdObjectImp(dwgClassName); \
    }

#endif //__cplusplus
