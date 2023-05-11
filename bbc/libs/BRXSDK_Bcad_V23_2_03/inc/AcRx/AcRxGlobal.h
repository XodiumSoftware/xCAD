// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"

//common forward declarations
#ifdef __cplusplus
class AcRxClass;
class AcRxDictionary;
class AcRxDictionaryIterator;
class AcRxDLinkerReactor;
class AcRxDynamicLinker;
class AcRxEvent;
class AcRxEventReactor;
class AcRxIterator;
class AcRxObject;
class AcRxProtocolReactor;
class AcRxProtocolReactorIterator;
class AcRxProtocolReactorList;
class AcRxProtocolReactorListIterator;
class AcRxProtocolReactorManager;
class AcRxProtocolReactorManagerFactory;
class AcRxService;
#endif //__cplusplus

#define ACRX_CLASS_DICTIONARY ACRX_T("ClassDictionary")
#define ACRX_DYNAMIC_LINKER ACRX_T("DynamicLinker")
#define ACRX_KERNEL_SERVICES ACRX_T("KernelServices")
#define ACRX_PROTOCOL_REACTOR_MANAGER ACRX_T("ProtocolReactorManager")
#define ACRX_SERVICE_DICTIONARY ACRX_T("ServiceDictionary")

#define ACRX_MAX_CMDNAME_LEN 64

#define ACRX_CMD_MODAL 0
#define ACRX_CMD_TRANSPARENT 1
#define ACRX_CMD_USEPICKSET 2
#define ACRX_CMD_REDRAW 4
#define ACRX_CMD_NOPERSPECTIVE 8
#define ACRX_CMD_NOMULTIPLE 16
#define ACRX_CMD_NOTILEMODE 32
#define ACRX_CMD_NOPAPERSPACE 64
#define ACRX_CMD_PLOTONLY 128
#define ACRX_CMD_NOOEM 256
#define ACRX_CMD_UNDEFINED 512
#define ACRX_CMD_INPROGRESS 1024
#define ACRX_CMD_DEFUN 2048
#define ACRX_CMD_NONEWSTACK 65536
#define ACRX_CMD_NOINTERNALLOCK 131072
#define ACRX_CMD_DOCREADLOCK 524288
#define ACRX_CMD_DOCEXCLUSIVELOCK 1048576
#define ACRX_CMD_SESSION 2097152
#define ACRX_CMD_INTERRUPTIBLE 4194304
#define ACRX_CMD_NOHISTORY 8388608
#define ACRX_CMD_NO_UNDO_MARKER 16777216
#define ACRX_CMD_NOBEDIT 33554432

#define ACRX_COMMAND_DOCK ACRX_T("ACAD_REGISTERED_COMMANDS")

#define ACRX_ASCII_MAX 255
#define ACRX_EOS 0
#define ACRX_ULONG_MAX 0xFFFFFFFF

#define acrxProtocolReactors AcRxProtocolReactorManagerFactory::cast(acrxServiceDictionary->at(ACRX_PROTOCOL_REACTOR_MANAGER))
#define ACRX_PROTOCOL_REACTOR_MANAGER_AT(Class) acrxProtocolReactors->createReactorManager(Class)
#define ACRX_PROTOCOL_REACTOR_LIST_AT(Class,Reactor) ACRX_PROTOCOL_REACTOR_MANAGER_AT(Class)->createReactorList(Reactor)

#ifndef kLoadADSMsg
#define kLoadADSMsg kLoadDwgMsg
#define kUnloadADSMsg kUnloadDwgMsg
#endif

#define _RXST(Str) _T(Str)

#ifdef __cplusplus

struct AcRx
{
    typedef void (*FcnPtr)();

    enum AppMsgCode
    {
        kNullMsg = 0,
        kInitAppMsg,
        kUnloadAppMsg,
        kLoadDwgMsg,
        kUnloadDwgMsg,
        kInvkSubrMsg,
        kCfgMsg,
        kEndMsg,
        kQuitMsg,
        kSaveMsg,
        kDependencyMsg,
        kNoDependencyMsg,
        kOleUnloadAppMsg,
        kPreQuitMsg,
        kInitDialogMsg,
        kEndDialogMsg,
        kSuspendMsg
    };

    enum AppRetCode
    {
        kRetOK = 0,
        kRetError = 3
    };

    enum DictIterType
    {
        kDictSorted = 0,
        kDictCollated
    };

    enum Ordering
    {
        kLessThan = -1,
        kEqual,
        kGreaterThan,
        kNotOrderable
    };

    // BRX specific
    // MTSupport flags advertise the capabilities of objects to participate in multi-threaded
    // operations. These capabilities are queried per object, but default implementation uses
    // the class flags. Flags are queried by calling the following functions:
    //     Adesk::UInt32 AcRxClass::customFlags() const;
    //     Adesk::UInt32 AcGiDrawable::regenSupportFlags() const;

    enum MTSupport
    {
        kMTNone           = 0x00, // process in single-threaded mode only (ARX style)

        // MT display support
        kMTRender         = 0x01, // worldDraw() or viewportDraw() calls from different threads are allowed
                                  // for highest level (MS or PS) drawables, otherwise they should be processed
                                  // in one dedicated thread only
        kMTRenderInBlock  = 0x02, // calls to worldDraw() or viewportDraw() methods from different threads are allowed,
                                  // if the drawable is located inside a block (compound object)
        kMTRenderNested   = 0x04, // worldDraw() or viewportDraw() from different threads are allowed for
                                  // nested drawables of a compound object
        // all render modes combined
        kMTRenderMask     = kMTRender | kMTRenderInBlock | kMTRenderNested,

        // MT loading support
        kMTLoading        = 0x80, // multithreaded loading is supported for this object
        // all loading modes combined
        kMTLoadingMask    = kMTLoading,

        // complete MT loading + rendering support
        kMTFullSupport    = kMTRenderMask | kMTLoadingMask,
    };
};

#endif //__cplusplus

typedef void (*AcRxFunctionPtr)();

#ifdef __cplusplus

typedef void (*AppNameChangeFuncPtr)(const AcRxClass*,ACHAR*&,int);

AcadApp::ErrorStatus acrxRegisterApp(AcadApp::LoadReasons,const ACHAR*,bool=false);
AcadApp::ErrorStatus acrxUnregisterApp(const ACHAR*,bool=false);
AcRxClass* newAcRxClass(const ACHAR*,const ACHAR*,int = 0,AcRxObject* (*pc)() = NULL,const ACHAR* = NULL,const ACHAR* = NULL,int = 0);
AcRxClass* newAcRxClass(const ACHAR*,const ACHAR*,int,int,int = 0,AcRxObject* (*pc)() = NULL,const ACHAR* = NULL,const ACHAR* = NULL,AppNameChangeFuncPtr = NULL,int = 0);
bool acrxApplicationIsLocked(const ACHAR*);
bool acrxIsAppMDIAware(const ACHAR*);
bool acrxLoadApp(const ACHAR*,bool=false);
bool acrxLoadModule(const ACHAR*,bool,bool=false);
bool acrxLockApplication(void*);
bool acrxRegisterAppMDIAware(void*);
bool acrxRegisterAppNotMDIAware(void*);
bool acrxServiceIsRegistered(const ACHAR*);
bool acrxUnloadApp(const ACHAR*,bool=false);
bool acrxUnloadModule(const ACHAR*,bool=false);
bool acrxUnlockApplication(void*);
bool __stdcall acrxAppIsLoaded(const ACHAR*);
void deleteAcRxClass(AcRxClass*);

#endif //__cplusplus

const ACHAR* acrxObjectDBXRegistryKey();
const ACHAR* acrxProductKey();
unsigned long acrxProductLCID();
void acrxBuildClassHierarchy();
void* acrxGetServiceSymbolAddr(const ACHAR*,const ACHAR*);
void* acrxLoadedApps();
void* acrxRegisterService(const ACHAR*);

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
    void acrx_abort(const ACHAR*,...);
#ifdef __cplusplus
}
#endif //__cplusplus