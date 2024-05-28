// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows MFC types and functions

#ifndef _BS_MFC_DEFS_INCLUDED_
#define _BS_MFC_DEFS_INCLUDED_


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  typedef struct tagMSG
  {
    HWND    hwnd;
    UINT    message;
    WPARAM  wParam;
    LPARAM  lParam;
    DWORD   time;
    POINT   pt;
  } MSG;

  class CRuntimeClass;
  class COleObjectFactory;

  struct AFX_EXTENSION_MODULE
  {
    BOOL               bInitialized;
    HMODULE            hModule;
    HMODULE            hResource;
    CRuntimeClass*     pFirstSharedClass;
    COleObjectFactory* pFirstSharedFactory;
  };


  #define AFXAPI      __stdcall
  #define AFXOLEAPI   __stdcall
  #define AFX_CDECL   __cdecl

  #define AFX_EXPORT  BRXEXPORT

  #define AFX_STATIC       extern
  #define AFX_STATIC_DATA  extern

  #define AFX_DATA_EXPORT  BRXEXPORT
  #define AFX_DATA_IMPORT

  #define AFX_CLASS_EXPORT BRXEXPORT
  #define AFX_CLASS_IMPORT

  #define AFX_API_EXPORT   BRXEXPORT
  #define AFX_API_IMPORT

  #define AFX_NOVTABLE
  #define AFX_COMDAT

  #define AFX_DATA
  #define AFX_DATADEF
  #define AFX_API

  #define AFX_CORE_DATA
  #define AFX_CORE_DATADEF

  #define AFX_OLE_DATA
  #define AFX_OLE_DATADEF

  #define AFX_DB_DATA
  #define AFX_DB_DATADEF

  #define AFX_NET_DATA
  #define AFX_NET_DATADEF

  #define AFX_EXT_DATA
  #define AFX_EXT_DATADEF
  #define AFX_EXT_CLASS
  #define AFX_EXT_API

  #define AFX_INLINE inline // or __forceinline


  // AFX Extension Module
  class BRXEXPORT CDynLinkLibrary // : public CCmdTarget
  {
    // DECLARE_DYNAMIC(CDynLinkLibrary)
    public:
      // Constructor
      CDynLinkLibrary(AFX_EXTENSION_MODULE & state, BOOL bSystem = FALSE);
      CDynLinkLibrary(HINSTANCE hModule, HINSTANCE hResource);
      virtual ~CDynLinkLibrary();

      // Attributes
      HMODULE  m_hModule;
      HMODULE  m_hResource;
      // CTypedSimpleList<CRuntimeClass*> m_classList;
      // #ifndef _AFX_NO_OLE_SUPPORT
      // CTypedSimpleList<COleObjectFactory*> m_factoryList;
      // #endif
      BOOL m_bSystem; // TRUE only for MFC DLLs

    // Implementation
    public:
      CDynLinkLibrary* m_pNextDLL;  // simple linked list
  };

  BRXEXPORT BOOL AfxInitExtensionModule (AFX_EXTENSION_MODULE & state, HMODULE hModule);
  BRXEXPORT void AfxTermExtensionModule (AFX_EXTENSION_MODULE & state, BOOL bAll = FALSE);

  BRXEXPORT HINSTANCE AfxLoadLibrary   (LPCTSTR lpszModuleName);
  BRXEXPORT HINSTANCE AfxLoadLibraryEx (LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);
  BRXEXPORT BOOL      AfxFreeLibrary   (HINSTANCE hInstLib);

  #define  AfxCoreInitModule()
  #define  AfxOleInitModule()
  #define  AfxNetInitModule()
  #define  AfxDbInitModule()

  BRXEXPORT HINSTANCE AfxGetResourceHandle();
  BRXEXPORT void AfxSetResourceHandle (HINSTANCE hInstResource);

  BRXEXPORT HWND GetActiveWindow();
  BRXEXPORT HWND GetForegroundWindow();
  BRXEXPORT HWND SetActiveWindow(HWND hWnd);


  // AFX_MODULE_STATE (global data for a module)
  class CWinApp;
  class CRuntimeClass;
  class COleObjectFactory;

  class BRXEXPORT AFX_MODULE_STATE //: public CNoTrackObject
  {
  public:
       AFX_MODULE_STATE(BOOL bDLL, WNDPROC pfnAfxWndProc, DWORD dwVersion, BOOL bSystem = FALSE);
       ~AFX_MODULE_STATE();

      CWinApp *  m_pCurrentWinApp;
      HINSTANCE  m_hCurrentInstanceHandle;
      HINSTANCE  m_hCurrentResourceHandle;
      LPCTSTR    m_lpszCurrentAppName;
      BYTE       m_bDLL;    // TRUE if module is a DLL, FALSE if it is an EXE
      BYTE       m_bSystem; // TRUE if module is a "system" module, FALSE if not
      BYTE       m_bReserved[2]; // padding

      DWORD      m_fRegisteredClasses; // flags for registered window classes

      // runtime class data
      CRuntimeClass * m_pClassInit;
      //CTypedSimpleList<CRuntimeClass*> m_classList;
      void * m_classList;

      // OLE object factories
      COleObjectFactory* m_pFactoryInit;
      //CTypedSimpleList<COleObjectFactory*> m_factoryList;
      void * m_factoryList;

      // number of locked OLE objects
      long m_nObjectCount;
      BOOL m_bUserCtrl;

      //CString  m_strUnregisterList;

      // WNDPROC  m_pfnAfxWndProc;
      // DWORD    m_dwVersion;  // version that module linked against

      // variables related to a given process in a module (used to be AFX_MODULE_PROCESS_STATE)
      //void (PASCAL *m_pfnFilterToolTipMessage)(MSG*, CWnd*);

      // CDynLinkLibrary objects (for resource chain)
      //CTypedSimpleList<CDynLinkLibrary*> m_libraryList;
      void * m_libraryList;

      //Defaults to TRUE. When FALSE - MFC will not activate context in AFX_MAINTAIN_STATE2 (used by AFX_MANAGE_STATE).
      BOOL    m_bSetAmbientActCtx;
      //Handle of the module context.
      HANDLE  m_hActCtx;
      // void CreateActivationContext();
  };

  // AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState ();
  BRXEXPORT AFX_MODULE_STATE* AfxGetModuleState ();
  BRXEXPORT AFX_MODULE_STATE* AfxGetStaticModuleState();
  BRXEXPORT AFX_MODULE_STATE* AfxSetModuleState (AFX_MODULE_STATE* pNewState);
  // BRXEXPORT BOOL AfxIsModuleDll ();
  // BRXEXPORT BOOL AfxInitCurrentStateApp ();


  // Exception handling

  BRXEXPORT void AFXAPI AfxThrowMemoryException       ();
  BRXEXPORT void AFXAPI AfxThrowNotSupportedException ();
  BRXEXPORT void AFXAPI AfxThrowInvalidArgException   ();
  BRXEXPORT void AFXAPI AfxThrowArchiveException      (int reason = 0, LPCTSTR szArchivename = NULL);
  BRXEXPORT void AFXAPI AfxThrowFileException         (int reason = 0, LONG lOsError = -1, LPCTSTR szFilename = NULL);
  BRXEXPORT void AFXAPI AfxThrowOleException          (SCODE scode);
  BRXEXPORT void AFXAPI AfxThrowOleDispatchException  (WORD wCode, LPCTSTR szDescription, UINT helpID = 0);
  BRXEXPORT void AFXAPI AfxThrowOleDispatchException  (WORD wCode, UINT descriptionID, UINT helpID = 0xFFFFFFFF);

  BRXEXPORT void AFXAPI AfxCheckError (SCODE scode);


  // Low level memory checks
  BRXEXPORT BOOL AFXAPI AfxIsValidAddress  (const void* pMemory, UINT_PTR blockSize, BOOL readWrite = TRUE);
  BRXEXPORT BOOL AFXAPI AfxIsValidString   (LPCWSTR szString, int nLength = -1);
  BRXEXPORT BOOL AFXAPI AfxIsValidString   (LPCSTR  szString, int nLength = -1);

  // BOOL AfxIsValidAtom  (ATOM nAtom);
  BRXEXPORT BOOL AfxIsValidAtom     (LPCTSTR szString);

  #if defined(_DEBUG) && !defined(_AFX_NO_DEBUG_CRT)
    BRXEXPORT BOOL AFXAPI AfxIsMemoryBlock (const void* pMemory, UINT blockSize, LONG* pRequestNumber = NULL);
  #else
    #define AfxIsMemoryBlock(pMemory, blockSize)  TRUE
  #endif // _DEBUG && !_AFX_NO_DEBUG_CRT

  struct __lnxPOSITION {};
  typedef __lnxPOSITION * POSITION; 


#endif // !_WIN32

#endif // _BS_MFC_DEFS_INCLUDED_
