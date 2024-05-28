
// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// Windows platform emulation for Linux + Mac

// this header contains some generic utilities to keep BRX source code
// platform-independent;
// this header can be included for both Windows + Linux builds, to ensure
// single source code across platforms;

#pragma once

#ifndef _BS_BRX_PLATFORM_UTILS_INCLUDED_
#define _BS_BRX_PLATFORM_UTILS_INCLUDED_

#ifndef _WIN32
  #include <wordexp.h>
#endif

// Export declaration macro (Windows + Linux,Mac; for BRX + client build)
#ifndef BRXEXPORT
  #ifdef _WIN32  // Windows
    #ifdef BRX_API      // BRX build
      #define BRXEXPORT __declspec(dllexport)
    #else               // client build
      #define BRXEXPORT
    #endif
  #else   // !_WIN32
    #ifdef BRX_API      // BRX build
      #define BRXEXPORT   __attribute__((visibility("default")))
    #else               // client build
      #define BRXEXPORT
    #endif
  #endif  // Linux,Mac
#endif // !BRXEXPORT

#ifndef EXPORT
  #ifdef _WIN32  // Windows
    #define EXPORT  __declspec(dllexport)
  #else   // !_WIN32
    #define EXPORT  __attribute__((visibility("default")))
  #endif  // Linux,Mac
#endif


// ======== Platform independent =========

// ----- generic utilities for all platforms -----

// adjust path delimiter to OS version (Windows <-> Linux/Mac)
inline wchar_t * adjustSlashes (wchar_t * pathname)
{
  #ifdef _WIN32  // Windows accepts both \\ and '/', but we enforce '\\'
    wchar_t * pos = wcschr(pathname, L'/');
    while (pos)
    {
       *pos = L'\\';
        pos = wcschr(pos, L'/');
    }
    return pathname;
  #else  // Linux,Mac : // accepts only' /', so we enforce '/'
    wchar_t * pos = wcschr(pathname, L'\\');
    while (pos)
    {
       *pos = L'/';
        pos = wcschr(pos, L'\\');
    }
    return pathname;
  #endif // !_WIN32
}

// adjust path delimiter to OS version (Windows <-> Linux/Mac)
inline char * adjustSlashes (char * pathname)
{
  #ifdef _WIN32  // Windows accepts both \\ and '/', but we enforce '\\'
    char * pos = strchr(pathname, '/');
    while (pos)
    {
       *pos = '\\';
        pos = strchr(pos, '/');
    }
    return pathname;
  #else  // Linux,Mac : // accepts only' /', so we enforce '/'
    char * pos = strchr(pathname, '\\');
    while (pos)
    {
       *pos = '/';
        pos = strchr(pos, '\\');
    }
    return pathname;
  #endif // !_WIN32
}



// ========== Platform specific ==========

#ifdef _WIN32 // on Windows

  // ANSI <-> UNICODE (char*/wchar_t*) string conversion
  #include "AtlBase.h"
  #define  ANSI2T(str)  (CA2CT(str))
  #define  T2ANSI(str)  (CT2CA(str))

#endif // _WIN32

#ifndef _WIN32 // on Linux/Mac

  class CWideString;
  class CAnsiString;
  #define  ANSI2T(ansistr)  CWideString(ansistr)  // ANSI -> UNICODE
  #define  T2ANSI(widestr)  CAnsiString(widestr)  // UNICODE -> ANSI

  // ANSI -> Unicode conversion string class
  class BRXEXPORT CWideString
  {
  public:
      CWideString() { m_wideString = NULL; };
      CWideString(const char* ansi) { ansi2wide(ansi); };
      CWideString(const wchar_t* wide) { m_wideString = wide ? wcsdup(wide) : NULL; };
     ~CWideString() { if (m_wideString) free(m_wideString); };

      operator const wchar_t*() const { return (const wchar_t*)m_wideString; };
      operator wchar_t*() { return m_wideString; };

  private:
      void ansi2wide (const char* ansi)
      {
          m_wideString = NULL;
          if (!ansi) return;  // allow NULL pointer
          size_t len = strlen(ansi);

          size_t byteLen = ((len+2)*sizeof(wchar_t));
          m_wideString = (wchar_t*)malloc(byteLen + (2*sizeof(wchar_t))); // some safety
          memset(m_wideString, 0, byteLen + (2*sizeof(wchar_t)));

          size_t converted = mbstowcs(m_wideString, ansi, len);

          if (converted == (size_t)(-1)) // on error, convert by character !
          {
              int st = mbtowc(NULL, NULL, 0); // reset state
              memset(m_wideString, 0, byteLen + (2*sizeof(wchar_t)));

              char    * szSrc = (char*)ansi;
              wchar_t * szDst = m_wideString;
              char    * szEnd = szSrc + len;
              int       processed = 0;
              while (szSrc < szEnd)
              {
                  processed = mbtowc(szDst, szSrc, MB_LEN_MAX);
                  if (processed <= 0)
                  {
                      *szDst = (unsigned short)(*szSrc);
                      st = mbtowc(NULL, NULL, 0); // reset state
                      processed = 1;
                  }
                  szSrc += processed;
                  szDst++;
              }
          }
      };

  public:
      wchar_t* m_wideString;
  };

  // Unicode -> ANSI conversion string class
  class BRXEXPORT CAnsiString
  {
  public:
      CAnsiString() { m_ansiString = NULL; };
      CAnsiString(const char* ansi) { m_ansiString = ansi ? strdup(ansi) : NULL; };
      CAnsiString(const wchar_t* wide) { wide2ansi2(wide); };
     ~CAnsiString() { if (m_ansiString) free(m_ansiString); };

      operator const char*() const { return (const char*)m_ansiString; };
      operator char*() { return m_ansiString; };

      char* expand() { return fsexpand(); };

  private:
      void wide2ansi2 (const wchar_t* wide)
      {
          m_ansiString = NULL;
          if (!wide) return;  // allow NULL pointer
          size_t len = wcstombs(NULL, wide, 0);
          m_ansiString = (char*)malloc(len + 2); // some safety
          memset(m_ansiString, 0, len + 2);
          wcstombs(m_ansiString, wide, len);
      };
      char* fsexpand()
      {
          if ((m_ansiString == NULL) || (*m_ansiString != '~') || (*(m_ansiString+1) != '/'))
              return m_ansiString;

          wordexp_t result;
          if (wordexp(m_ansiString, &result, 0) != 0) // error case
              return m_ansiString;

          free(m_ansiString);
          m_ansiString = strdup(result.we_wordv[0]);
          wordfree(&result);
          return m_ansiString;
      };

  public:
      char* m_ansiString;
  };

#endif // !_WIN32 // Linux/Mac



#endif // _BS_BRX_PLATFORM_UTILS_INCLUDED_
