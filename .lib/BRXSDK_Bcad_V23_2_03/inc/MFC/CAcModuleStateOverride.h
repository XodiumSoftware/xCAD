// Copyright (C) 2006-2014 Menhirs NV. All rights reserved.
#pragma once

/*
  ! PLEASE DO ONLY USE THIS FILE WHEN BUILDING A REGULAR DLL TO BE USED WITH BRICSCAD !
  ! only use inside exported functions of a regular DLL !

  Similar to AFX_MANAGE_STATE macro, this helper class stores, sets, and restore the active
  module state - the current one is saved, and the module state of the regular DLL is set
  active; when the function is left, the previous module state is restored.

  For a regular DLL, MFC retrieves the related resource handle from the module state.

  Using AFX_MANAGE_STATE macro in a regular DLL with Bricscad, there might be serious
  exceptions from Windows (MFC) runtime system regarding inappropriate thread contexts.
  
  As a workaround solution, this helper class can be used instead of AFX_MANAGE_STATE.
  Please carefully test your application - no warranty is provided !

  When building an extension DLL or EXE, this class does nothing.

  Usage : simply instanciate a variable (on stack) instead of calling AFX_MANAGE_STATE()
          macro; when the scope of the function is left, the previously active module state
          is restored

  Example :
            #ifdef _BRICSCAD
              CAcModuleStateOverride  staticModuleOverride;
            #else
              AFX_MANAGE_STATE(AfxGetStaticModuleState());
            #endif

*/

/** _ */
class CAcModuleStateOverride
{
private:
    AFX_MODULE_STATE * m_previousModuleState;
public:
    CAcModuleStateOverride();
    CAcModuleStateOverride(AFX_MODULE_STATE * setModuleState);
    ~CAcModuleStateOverride();
};

inline CAcModuleStateOverride::CAcModuleStateOverride()
{
#ifdef _USRDLL
    m_previousModuleState = ::AfxSetModuleState(::AfxGetStaticModuleState());
#endif
}

inline CAcModuleStateOverride::CAcModuleStateOverride(AFX_MODULE_STATE * setModuleState)
{
#ifdef _USRDLL
    m_previousModuleState = ::AfxSetModuleState(setModuleState);
#endif
}

inline CAcModuleStateOverride::~CAcModuleStateOverride()
{
    ::AfxSetModuleState(m_previousModuleState);
}
