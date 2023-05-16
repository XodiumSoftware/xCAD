// sds_platform.h : platform-specific definitions for Windows+Linux+Max

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#ifndef _SDS_PLATFORM_H_
#define _SDS_PLATFORM_H_

#ifndef _UT_PLATFORM_H_
#ifndef _BS_WIN_DEFS_INCLUDED_

#ifdef _WIN32

  #define SDS_DLL_EXPORT __declspec(dllexport)
  #define SDS_DLL_IMPORT __declspec(dllimport)

#endif // _WIN32


// ========== for Windows, Linux, Mac =========
#undef __SYS_64_BIT__
#undef __SYS_32_BIT__
#if defined ( _WIN64 ) || defined(__LP64__) || defined(_LP64) || defined(__64BITS__) || defined(__x86_64__)
  #define __SYS_64_BIT__
#else
  #define __SYS_32_BIT__
#endif


#ifndef _WIN32  // Linux + Mac

  #define SDS_DLL_EXPORT __attribute__((visibility("default")))
  #define SDS_DLL_IMPORT

  #define  WINAPI     _stdcall
  #define  APIENTRY              // in Win32 : _stdcall

  #define UNREFERENCED_PARAMETER(par)
  #define DBG_UNREFERENCED_PARAMETER(par)
  #define DBG_UNREFERENCED_LOCAL_VARIABLE(var)

  // predefined data values
  #if !defined( TRUE )
    #define TRUE  true
  #endif
  #if !defined( FALSE )
    #define FALSE false
  #endif

  #define  DLL_PROCESS_ATTACH    1
  #define  DLL_THREAD_ATTACH     2
  #define  DLL_THREAD_DETACH     3
  #define  DLL_PROCESS_DETACH    0
  #define  DLL_PROCESS_VERIFIER  4

  #define _MAX_DRIVE      3
  #define _MAX_PATH       4096
  #define _MAX_FNAME      4096
  #define _MAX_DIR        _MAX_FNAME
  #define _MAX_EXT        _MAX_FNAME

  #define  O_BINARY       0x0  // no analogon on Linux
  #define _FILE_OFFSET_BITS 64

  #define CP_ACP 0

  // function redirections
  #define _TEOF           WEOF
  #define _fgettc         fgetwc
  #define _fputtc         fputwc
  #define _fgetts         fgetws
  #define _fputts         fputws
  #define _ftprintf       fwprintf
  #define _istalpha       iswalpha
  #define _istalnum       iswalnum
  #define _istdigit       iswdigit
  #define _istspace       iswspace
  #define _istcntrl       iswcntrl
  #define _istupper       iswupper
  #define _stscanf        swscanf
  #define _tcscat         wcscat
  #define _tcschr         wcschr
  #define _tcsclen        wcslen
  #define _tcscmp         wcscmp
  #define _tcscpy         wcscpy
  #define _tcsdup         wcsdup
  #define _tcsicmp        wcscasecmp
  #define _tcsicoll       wcscasecmp
  #define _tcscoll        wcscoll
  #define _tcslen         wcslen
  #define _tcsncat        wcsncat
  #define _tcsncmp        wcsncmp
  #define _tcsncpy        wcsncpy
  #define _tcsnicmp       wcsncasecmp
  #define _tcsrchr        wcsrchr
  #define _tcsspn         wcsspn
  #define _tcsstr         wcsstr
  #define _tcstok_s       wcstok
  #define _tcstod         wcstod
  #define _tcstol         wcstol
  #define _tcstoul        wcstoul
  #define _tcspbrk        wcspbrk
  #define _totupper       towupper
  #define _tsetlocale     wsetlocale
  #define _vsntprintf     vswprintf
  #define _tcscspn        wcscspn
  #define _istupper       iswupper
  #define _istlower       iswlower
  #define _istcntrl       iswcntrl
  #define _stnprintf      swprintf

  #define BSTR2TSTR(x)    (x)  // no string conversion in UNICODE nessecary

  #if !defined( CONST )
    #define CONST const
  #endif

  #ifndef _T
    #define _T(x) L##x
  #endif

  // data types
  #include <inttypes.h>

  typedef uint8_t   BYTE;
  typedef int32_t   INT;
  typedef int32_t   BOOL;
  typedef uint32_t  UINT;

  typedef short           SHORT;
  typedef unsigned short  USHORT;
  typedef unsigned short  WORD;
  typedef long            LONG;
  typedef unsigned long   ULONG;
  typedef unsigned long   DWORD;
  typedef long long       LONGLONG;
  typedef unsigned long long  ULONGLONG;
  typedef float           FLOAT;
  typedef double          DOUBLE;
  typedef unsigned int    size_type;
  typedef ULONGLONG       DWORDLONG;

  typedef uint32_t        DWORD32;
  typedef uint64_t        DWORD64;
  typedef int16_t         INT16;
  typedef int32_t         INT32;
  typedef int64_t         INT64;
  typedef int32_t         LONG32;
  typedef int64_t         LONG64;
  typedef uint16_t        UINT16;
  typedef uint32_t        UINT32;
  typedef uint64_t        UINT64;
  typedef uint32_t        ULONG32;
  typedef uint64_t        ULONG64;

  // Linux,Mac : minimum portable data types
  #ifdef __SYS_32_BIT__   // 32 bit
    typedef INT32         INT_PTR;
    typedef INT32*        PINT_PTR;
    typedef UINT32        UINT_PTR;
    typedef UINT32*       PUINT_PTR;
    typedef LONG32        LONG_PTR;
    typedef LONG32*       PLONG_PTR;
    typedef ULONG32       ULONG_PTR;
    typedef ULONG32*      PULONG_PTR;
    typedef INT32         intptr_t;
    typedef UINT32        uintptr_t;
    typedef int32_t       __int3264;
  #else                   // 64 bit
    typedef INT64         INT_PTR;
    typedef INT64*        PINT_PTR;
    typedef UINT64        UINT_PTR;
    typedef UINT64*       PUINT_PTR;
    typedef LONG64        LONG_PTR;
    typedef LONG64*       PLONG_PTR;
    typedef ULONG64       ULONG_PTR;
    typedef ULONG64*      PULONG_PTR;
    typedef INT64         intptr_t;
    typedef UINT64        uintptr_t;
    typedef int64_t       __int3264;
  #endif

  typedef ULONG_PTR       DWORD_PTR;
  typedef ULONG_PTR*      PDWORD_PTR;

  typedef char            __int8;
  typedef short           __int16;
  typedef int32_t         __int32;
  typedef int64_t         __int64;

  typedef BYTE*           PBYTE;
  typedef char            CHAR;
  typedef char*           LPSTR;
  typedef const char*     LPCSTR;
  typedef wchar_t         WCHAR;
  typedef wchar_t         TCHAR;
  typedef wchar_t        _TCHAR;
  typedef TCHAR*          LPTSTR;
  typedef const TCHAR*    LPCTSTR;
  typedef void            VOID;
  typedef void*           PVOID;
  typedef void*           LPVOID;

  typedef void*           HANDLE;
  typedef HANDLE          HINSTANCE;
  typedef HANDLE          HMODULE;
  typedef int32_t         HRESULT;
  typedef HANDLE          HBITMAP;
  typedef HANDLE          HMETAFILE;
  typedef HANDLE          HWND;
  typedef HANDLE          HMENU;
  typedef unsigned long   LCID;



#endif // !_WIN32


// common for all platforms - ODA stuff must be included first

// minimum ODA includes
#ifndef _TOOLKIT_IN_DLL_
  #define _TOOLKIT_IN_DLL_
#endif
#include "OdaCommon.h"
#include "StringArray.h"
#include "RxDynamicModule.h"

// common SDS includes
#include "sds.h"


// implementations for missing C runtime functions
#ifndef _WIN32  // Linux + Mac

  // replacement code for the non-implemented "getumask()" function
  inline mode_t _getumask()
  {
     mode_t mask = umask(0);
     umask(mask);
     return mask;
  }

  // we assume, that the target string is >= 24 characters; 22 is enough for 64bit int + sign
  inline wchar_t* _ltot (long number, wchar_t *wstr, int radix)
  {
     // radix is ignored, used as '10' always
     int len = swprintf(wstr, 24, L"%d", number);
     if (len >= 0) wstr[len] = _T('\0');
     return wstr;
  }

  inline int _ttoi (const wchar_t* str)
  {
     if (!str || !(*str)) return 0;
     std::wistringstream in(str);
     int result;
     in >> result;
     return result;
  }

  inline long _ttol (const wchar_t* str)
  {
     if (!str || !(*str)) return 0;
     std::wistringstream in(str);
     long result;
     in >> result;
     return result;
  }

  inline wchar_t* _tcsinc (const wchar_t* str)
  {
     return (str == NULL) ? NULL : const_cast<wchar_t*>(++str);
  }

  inline wchar_t* _tcsninc (const wchar_t* str, size_t count)
  {
     return (str == NULL) ? NULL : const_cast<wchar_t*>(str + (count * sizeof(wchar_t*)));
  }

  inline wchar_t* _tcslwr (wchar_t* str)
  {
     if (str == NULL)
         return NULL;

     wchar_t* orgstr = str;
     while (*str)
     {
       *str = towlower(*str);
        str++;
     }
     return orgstr;
  }

  inline wchar_t* _tcsupr (wchar_t* str)
  {
     if (str == NULL)
         return NULL;

     wchar_t* orgstr = str;
     while (*str)
     {
       *str = towupper(*str);
        str++;
     }
     return orgstr;
  }

  inline wchar_t* _tcsspnp (const wchar_t* string1, const wchar_t* string2)
  {
     if (!string1 || !string2)
        return (wchar_t*)string1;

     wchar_t* str = (wchar_t*)string1;
     while (*str)
     {
        if (!wcschr(string2, *str))
           return str;
        ++str;
     }
     return NULL;
  }

  inline char* strupr (char* str)
  {
     if (str == NULL)
         return NULL;

     char* orgstr = str;
     while (*str)
     {
        *str = toupper(*str);
         str++;
     }
     return orgstr;
  }

  static int _tstat (const wchar_t *path, struct stat *buffer)
  {
     OdString filePath = OdString(path);
     return stat(static_cast<const char*>(filePath), buffer);
  }

  static int _taccess(const wchar_t* path, int mode)
  {
     OdString filePath = OdString(path);
     return access(static_cast<const char*>(filePath), mode);
  }

  static FILE* _tfopen (const wchar_t* path, const wchar_t* mode)
  {
     OdString filePath = OdString(path);
     OdString fileMode = OdString(mode);
     return fopen(static_cast<const char*>(filePath), static_cast<const char*>(fileMode));
  }

  static int _topen (const wchar_t *path, int oflag, int pmode = _getumask())
  {
     OdString filePath = OdString(path);
     return open(static_cast<const char*>(filePath), oflag, pmode);
  }

  static int _trename (const wchar_t *oldname, const wchar_t *newname)
  {
     OdString oldFile = OdString(oldname);
     OdString newFile = OdString(newname);
     return rename(static_cast<const char*>(oldFile), static_cast<const char*>(newFile));
  }

  static int _tremove (const wchar_t *path)
  {
     OdString filePath = OdString(path);
     return remove(static_cast<const char*>(filePath));
  }

  static int _trmdir (const wchar_t *path)
  {
     OdString filePath = OdString(path);
     return rmdir(static_cast<const char*>(filePath));
  }

  static int _tmkdir (const wchar_t *path)
  {
     OdString filePath = OdString(path);
     return mkdir(static_cast<const char*>(filePath), _getumask()); // S_IRWXU|S_IRWXG|S_IRWXO
  }

  static wchar_t* _tgetcwd (wchar_t *buffer, int maxlen)
  {
     char  mbpath[_MAX_FNAME];
     if (!getcwd(mbpath, _MAX_FNAME))
        return NULL;

     if (!buffer)
     {
        buffer = (wchar_t*)malloc( (maxlen+1) * sizeof(wchar_t) );
     }

     OdString filePath = OdString(mbpath);
     return _tcscpy(buffer, filePath.c_str());
  }

  static int _tchdir (const wchar_t* path)
  {
     OdString filePath = OdString(path);
     return chdir(static_cast<const char*>(filePath));
  }

  static wchar_t* _tgetenv (const wchar_t* var)
  {
     OdString envVar = OdString(var);
     char* result = getenv(static_cast<const char*>(envVar));
     if (!result)
        return NULL;

     OdString envVal = OdString(result);
     return LPTSTR(LPCTSTR(envVal));
  }

  static void _tsearchenv (const wchar_t *infile, const wchar_t *varname, wchar_t *retfile)
  {
     if (_taccess(infile, 0) == 0)
     {
        _tcscpy(retfile, infile);
        return;
     }

     _tcscpy(retfile, _T(""));

     wchar_t  filename[_MAX_FNAME];
     wchar_t  varvalue[8192];
     wchar_t* szPos;

     wchar_t* pvalue = varvalue;
     _tcscpy(varvalue, _tgetenv(varname));

     while (*pvalue != _T('\0'))
     {
        szPos = _tcschr(pvalue, _T(':'));
        if (szPos)
           *szPos = _T('\0');
        _stnprintf(filename, _MAX_FNAME, _T("%ls/%ls"), pvalue, infile);

        if (_taccess(filename, 0) == 0)
        {
           _tcscpy(retfile, filename);
           return;
        }

        if (!szPos) // no further : delimiter, done
           return;

        pvalue = ++szPos;
     }
  }

  static void _tsplitpath (const wchar_t * _FullPath, wchar_t * _Drive, wchar_t * _Dir, wchar_t * _Filename, wchar_t * _Ext)
  {
     if (_Drive)
        *_Drive = L'\0';
     if (_Dir)
        *_Dir = L'\0';
     if (_Filename)
        *_Filename = L'\0';
     if (_Ext)
        *_Ext = L'\0';

     if (!_FullPath)
        return;

     const wchar_t *dirEnd = 0;
     if (_Dir || _Filename)
     {
        dirEnd = wcsrchr(_FullPath, L'/');
        if (dirEnd) dirEnd++;
     }
     if (_Dir && dirEnd)
     {
        const size_t len = dirEnd - _FullPath;
        if(len)
            wcsncpy(_Dir, _FullPath, len);
        _Dir[len] = L'\0';
     }

     const wchar_t *filenameEnd = 0;
     if(_Filename || _Ext)
        filenameEnd = wcsrchr(dirEnd ? dirEnd : _FullPath, L'.');

     if (_Filename)
     {
        _tcscpy(_Filename, dirEnd ? dirEnd : _FullPath);
        if (filenameEnd)
        {
           const size_t len = filenameEnd - (dirEnd ? dirEnd : _FullPath);
           if (len)
               wcsncpy(_Filename, (dirEnd ? dirEnd : _FullPath), len);
           _Filename[len] = L'\0';
        }
     }
     if (_Ext && filenameEnd && *filenameEnd)
     {
        wcscpy(_Ext, filenameEnd);
     }
  }

#endif // !_WIN32

#endif //_UT_PLATFORM_H_
#endif //_BS_WIN_DEFS_INCLUDED_

#endif //_SDS_PLATFORM_H_
