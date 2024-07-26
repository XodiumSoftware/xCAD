// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcAp/AcApDocManager.h"
#include "MFC/CAcExtensionModule.h"


#ifdef _WIN32 // hide Linux/Mac GCC specifics
  #ifdef  __attribute__
  #undef  __attribute__
  #endif
  #define __attribute__(x)   /* emptry define under Windows */
#endif


/** _ */
class CAcModuleResourceOverride
{
private:
    static CAcExtensionModule& m_extModule;
public:
    CAcModuleResourceOverride();
    CAcModuleResourceOverride(HINSTANCE);
    ~CAcModuleResourceOverride();
};

inline CAcModuleResourceOverride::CAcModuleResourceOverride()
{
    acDocManager->pushResourceHandle(m_extModule.ModuleResourceInstance());
}

inline CAcModuleResourceOverride::CAcModuleResourceOverride(HINSTANCE hInstance)
{
    if (hInstance)
        acDocManager->pushResourceHandle(hInstance);
    else
        acDocManager->pushResourceHandle(m_extModule.ModuleResourceInstance());
}

inline CAcModuleResourceOverride::~CAcModuleResourceOverride()
{
    acDocManager->popResourceHandle();
}

#define AC_IMPLEMENT_EXTENSION_MODULE(Module) \
  __attribute__((init_priority(65000))) /* initialise very late */ \
  CAcExtensionModule Module; \
  CAcExtensionModule& CAcModuleResourceOverride::m_extModule = Module;
