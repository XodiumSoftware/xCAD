#include "StdAfx.h"
#include "resource.h"
#include <mgdinterop.h>
#include "CustomEntity.h"

//uncomment to register for demand loading
//#define DoRegisterDbxApp

static AcMgObjectFactoryBase** pp_ObjFct = NULL;

class CMyManagedEntityApp : public AcRxDbxApp {

public:
    CMyManagedEntityApp () : AcRxDbxApp () {}

    virtual AcRx::AppRetCode On_kInitAppMsg (void *pAppData) 
    {
        AcRx::AppRetCode retMsg =AcRxDbxApp::On_kInitAppMsg (pAppData) ;
        RegisterDbxApp();
        RegisterManagedWrapperLink();
        return (retMsg) ;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pAppData) 
    {
        UnregisterManagedWrapperLink();
        AcRx::AppRetCode retMsg =AcRxDbxApp::On_kUnloadAppMsg (pAppData) ;
        return (retMsg) ;
    }

private:
    void RegisterManagedWrapperLink()
    {
        static AcMgObjectFactoryBase* p_ObjFctArr[] = 
        {
            new AcMgObjectFactory<CustomManagedEntity::CMyManagedEntity,CMyEntity>(),
            new AcMgObjectFactory<CustomManagedEntity::CMyManagedEntityDerived,CMyEntityDerived>(),
            NULL
        };
        pp_ObjFct = p_ObjFctArr;
    }
    void UnregisterManagedWrapperLink()
    {
        if (!pp_ObjFct)
            return;
        int i=0;
        while (pp_ObjFct[i]!=NULL)
        {
            AcMgObjectFactoryBase*& pFactory = pp_ObjFct[i++];
            delete pFactory;
            pFactory = NULL;
        }
        pp_ObjFct = NULL;
    }

    void RegisterDbxApp()
    {
#ifdef  DoRegisterDbxApp
        AcadAppInfo info;
        info.setAppName(_T("CMyEntity"));
        HMODULE hModule=GetModuleHandle(_T("CMyManagedEntity.dll"));
        TCHAR modulePath[MAX_PATH];
        DWORD pathLength = GetModuleFileName(hModule, modulePath, MAX_PATH);
        if (pathLength)
            info.setModuleName(modulePath);
        info.setManaged(AcadAppInfo::kManaged);
        info.setLoadReason(
            AcadApp::LoadReasons(
            AcadApp::kOnProxyDetection |
            AcadApp::kOnAutoCADStartup |
            AcadApp::kOnLoadRequest));
        info.writeToRegistry(true,true);
#endif
    }

    virtual void RegisterServerComponents () 
    {
    }
} ;

IMPLEMENT_ARX_ENTRYPOINT(CMyManagedEntityApp)
