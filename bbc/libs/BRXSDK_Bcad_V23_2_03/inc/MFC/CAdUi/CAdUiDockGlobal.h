// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#if defined(_AFXEXT) && defined(__cplusplus)
  #if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
    #undef _DEBUG
    #include <afxpriv.h>
    #define _DEBUG
  #else
    #include <afxpriv.h>
  #endif
#endif

#include "MFC/CAdUi/CAdUiGlobal.h"
#include "Misc/MiscGlobal.h"

typedef HRESULT ADUI_LOADFN(IUnknown**);
typedef HRESULT ADUI_SAVEFN(IUnknown*);

#define ADUI_DOCK_CS_DESTROY_ON_CLOSE 1
#define ADUI_DOCK_CS_STDMOUSECLICKS 2
#define ADUI_DOCK_NF_FRAMECHANGED 2
#define ADUI_DOCK_NF_SIZECHANGED 1
#define ADUI_DOCK_NF_STATECHANGED 2
#define ADUI_DOCK_POSITION_TOOL_KEY ADUI_XML_DOCK_TOOL_INFO
#define ADUI_DOCK_STARTUP_TOOL_KEY ADUI_XML_DOCK_STARTUP_INFO
#define ADUI_XML_DOCK_STARTUP_CMD_NAME ACRX_T("Command")
#define ADUI_XML_DOCK_STARTUP_INFO ACRX_T("StartupInfo")
#define ADUI_XML_DOCK_STARTUP_TOOL_NAME ACRX_T("ToolName")
#define ADUI_XML_DOCK_TOOL ACRX_T("Tool")
#define ADUI_XML_DOCK_TOOL_CLSID ACRX_T("CLSID")
#define ADUI_XML_DOCK_TOOL_INFO ACRX_T("ToolsInfo")
#define ADUI_XML_ROOT ACRX_T("AdUiTools")
#define ID_ADUI_ALLOWDOCK 4097
#define ID_ADUI_HIDEBAR 4098

bool AdUiRegisterDockingTool(LPCTSTR,LPCTSTR,UINT); //internal use only!
bool AdUiRegisterTool(LPCTSTR,LPCTSTR,CLSID*);
bool CanStealFocusFromDockedWindow(); //internal use only!
CRuntimeClass* AdUiGetRegisteredPaletteSetFloatingFrameClass();
CRuntimeClass* AdUiSetFloatingFrameClass(CRuntimeClass*);
void AdUiEnableDockControlBars(BOOL,CStringArray* = NULL); //internal use only!
void AdUiEnableDocking(CFrameWnd*,DWORD,ADUI_LOADFN*,ADUI_SAVEFN*); //internal use only!
void AdUiRegisterFloatingFrameClassAddress(CRuntimeClass**); //internal use only!
void AdUiRegisterPaletteSetFloatingFrameClass(CRuntimeClass*); //internal use only!
void AdUiSaveDockingToolPositions(); //internal use only!
void AdUiShowDockControlBars(bool); //internal use only!
void GetSystemVirtualScreen(RECT&); //internal use only!
