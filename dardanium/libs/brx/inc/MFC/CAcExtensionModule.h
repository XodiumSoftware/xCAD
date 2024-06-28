// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

/** _ */
class CAcExtensionModule
{
protected:
    AFX_EXTENSION_MODULE m_module;
    BOOL m_bAttached;
    HINSTANCE m_hDefaultResource;
    HINSTANCE m_hModuleResource;

public:
    CAcExtensionModule();
    ~CAcExtensionModule() {}

    BOOL Attached() { return m_bAttached; }
    BOOL AttachInstance(HINSTANCE);
    HINSTANCE DefaultResourceInstance() { return m_hDefaultResource; }
    HINSTANCE ModuleResourceInstance() { return m_hModuleResource; }
    void DetachInstance();
};

inline CAcExtensionModule::CAcExtensionModule()
{
    m_module.bInitialized = FALSE;
    m_module.hModule = NULL;
    m_module.hResource = NULL;
    m_module.pFirstSharedClass = NULL;
    m_module.pFirstSharedFactory = NULL;
    m_bAttached = FALSE;
    m_hDefaultResource = NULL;
    m_hModuleResource = NULL;
}

inline BOOL CAcExtensionModule::AttachInstance(HINSTANCE hInstance)
{
    BOOL success = FALSE;
    if(!m_bAttached)
    {
        m_bAttached = AfxInitExtensionModule(m_module,hInstance);
        if(m_bAttached)
        {
            m_hDefaultResource = AfxGetResourceHandle();
            m_hModuleResource = hInstance;
            new CDynLinkLibrary(m_module);
            success = TRUE;
        }
    }
    return success;
}

inline void CAcExtensionModule::DetachInstance()
{
    if(m_bAttached)
    {
        AfxTermExtensionModule(m_module);
        m_bAttached = FALSE;
    }
}

#define AC_DECLARE_EXTENSION_MODULE(Module) extern CAcExtensionModule Module;