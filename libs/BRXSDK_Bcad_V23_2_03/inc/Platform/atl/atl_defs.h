// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// ATL types and functions

#pragma once

#ifndef _BS_ATL_DEFS_INCLUDED_
#define _BS_ATL_DEFS_INCLUDED_

#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


// ========== Platform independent =======

#define OLESTR2TSTR(x)  (x)  // no conversion nessecary
#define TSTR2OLESTR(x)  (x)  // no conversion nessecary

// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  #include "Platform/win/win_defs.h"
  #include "Platform/win/c-runtime.h"  // for ANSI2T / T2ANSI
  #include "Platform/win/winsdk.h"
  #include "Platform/com/com_errors.h"
  #include "Platform/mfc/mfc_defs.h"
  #include "Platform/mfc/CException.h"


  #define CP_ACP         0      // ANSI code page
  #define CP_OEMCP       1      // OEM  code page
  #define CP_MACCP       2      // MAC  code page
  #define CP_THREAD_ACP  3      // thread's ANSI code page
  #define CP_SYMBOL      42     // SYMBOL translations
  #define CP_UTF7        65000  // UTF-7 translation
  #define CP_UTF8        65001  // UTF-8 translation

  #define USES_CONVERSION       // no operation

  // Ansi -> Unicode
  #define  CA2CT(str)  ANSI2T(str)
  #define  CA2CW(str)  ANSI2T(str)
  #define  CA2W(str)   static_cast<wchar_t*>(ANSI2T((const char*)str))
  #define   A2T(str)   CA2W(str)
  #define  CA2T(str)   CA2W(str)

  // Unicode -> Ansi
  #define  CT2CA(str)  T2ANSI(str)
  #define  CW2CA(str)  T2ANSI(str)
  #define  CW2A(str)   static_cast<char*>(T2ANSI((const wchar_t*)str))
  #define   T2A(str)   CW2A(str)
  #define  CT2A(str)   CW2A(str)

  // Unicode -> Unicode (NOOP)
  #define  CT2CW(str)  str
  #define   CT2W(str)  str
  #define  T2W(str)    str
  #define  T2CW(str)   str

  #define  CW2CT(str)  str
  #define   CW2T(str)  str
  #define  W2T(str)    str
  #define  W2CT(str)   str
  
  #define  COLE2T      CW2T


  #define  ATL_NO_VTABLE  // nothing, used by COM interface declarations

  #if defined(_ATL_DLL)
    #define ATLAPI        extern "C" HRESULT __declspec(dllimport) __stdcall
    #define ATLAPI_(x)    extern "C" __declspec(dllimport) x __stdcall
    #define ATLINLINE
    #define ATLAPIINL     extern "C" inline HRESULT __stdcall
    #define ATLAPIINL_(x) extern "C" inline x __stdcall
  #else
    #define ATLAPI        extern "C" inline HRESULT __stdcall
    #define ATLAPI_(x)    extern "C" inline x __stdcall
    #define ATLAPIINL ATLAPI
    #define ATLAPIINL_(x) ATLAPI_(x)
    #define ATLINLINE
  #endif


  template<typename TP>
  inline TP WINAPI AtlAlignUp (TP tpVar, ULONG alignmentSize) noexcept(false)
  {
      return (TP((tpVar + (alignmentSize-1)) &~ (TP(alignmentSize) - 1)));
  }

  template<typename TP>
  inline TP WINAPI AtlAlignDown (TP tpVar, ULONG alignmentSize) noexcept(false)
  {
      return (TP(tpVar &~ (TP(alignmentSize) - 1)));
  }


  // Exception Handling

  #define EXCEPTION_NONCONTINUABLE       1  // Noncontinuable exception
  #define EXCEPTION_MAXIMUM_PARAMETERS  15  // maximum number of exception parameters

  namespace ATL
  {
    class CAtlException
    {
      public:
        CAtlException() noexcept(false) : m_hr( E_FAIL ) {};
        CAtlException( HRESULT hr ) noexcept(false) : m_hr( hr ) {};
        operator HRESULT() const noexcept(false) { return( m_hr ); };
      public:
        HRESULT m_hr;
    };

    BRXEXPORT void _AtlRaiseException (DWORD dwExceptionCode,
                                       DWORD dwExceptionFlags = EXCEPTION_NONCONTINUABLE);
                                       
    void WINAPI AtlThrowImpl ( HRESULT hr );

  } // namespace ATL

  #ifndef AtlThrow
    #ifndef _ATL_CUSTOM_THROW
      #define AtlThrow ATL::AtlThrowImpl
    #endif
  #endif // AtlThrow


  #ifndef ATLASSERT
    #define ATLASSERT  _ASSERTE
  #endif // !ATLASSERT


  #define  ATLTRYALLOC(x)  try { x; } catch (CException* ex) { ex->Delete(); }
  #define _ATLTRY   try
  #define _ATLCATCH(ex) catch (CException* ex)
  #define _ATLCATCHALL() catch (...)
  #define _ATLDELETEEXCEPTION(ex) ex->Delete();
  #define _ATLRETHROW throw

  #ifndef ATLTRY
    #define ATLTRY(x) ATLTRYALLOC(x);
  #endif //ATLTRY

  #ifndef ATLVERIFY
    #ifdef _DEBUG
      #define ATLVERIFY(expr) ATLASSERT(expr);
    #else
      #define ATLVERIFY(expr) (expr);
    #endif // DEBUG
  #endif // ATLVERIFY

  #ifndef ATLASSUME
    #define ATLASSUME(expr) ATLASSERT(expr);
  #endif // ATLASSUME



#endif // !_WIN32

#endif // _BS_ATL_DEFS_INCLUDED_
