// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// Windows common types

#pragma once

#ifndef _BS_WIN_DEFS_INCLUDED_
#define _BS_WIN_DEFS_INCLUDED_


#include "sys_version.h"
#include "Platform/sys_headers.h"


// ========== Platform independent =======


// Math macros
#undef MAX
#undef MIN
#define MAX(a,b)  (((a) > (b)) ? (a) : (b))
#define MIN(a,b)  (((a) < (b)) ? (a) : (b))


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


// ========== Platform independent ==========

#ifdef __SYS_64_BIT__
  #define  __w64
  #define   _W64
#endif

// ========== Platform specific ==========

// Incldues for Windows platform
#ifdef _WIN32

  #define  _STRUCT_STAT   struct _stat

  #define  _stnprintf  _sntprintf
  #define  wcstoll     _tcstoi64
  #ifdef _tcstoll
    #undef _tcstoll
  #endif
  #define _tcstoll     _tcstoi64

#endif // _WIN32


#ifndef _WIN32 // on Linux/Mac

  #include "Platform/win/win_errors.h"

  // Define some MSVC specific types/macros/functions for Linux
  #define __forceinline inline
  #define __inline      inline

  // calling conventions and related
  #define  __declspec(x)

  #define  __w64       // ignore, no 64bit checks
  #define   _W64       // ignore, no 64bit checks

  #define  __cdecl     __attribute__((cdecl))
  #ifdef __APPLE__
    #define  __stdcall
  #else
    #define  __stdcall   __attribute__((stdcall))
  #endif
  #define  __fastcall  __attribute__((fastcall))

  #define  WINAPI      __attribute__((visibility("default")))
  #define  APIENTRY    WINAPI
  #define  APIPRIVATE
  #define  PASCAL
  #define  CALLBACK

  #define  FAR         // we don't care at the moment
  #define  NEAR        // we don't care at the moment

  #ifdef __cplusplus
    #define  EXTERN_C  extern "C"
  #else
    #define  EXTERN_C  extern
  #endif

  #define  _C_LIB_DECL      extern "C" {
  #define  _END_C_LIB_DECL  }
  #define  _EXTERN_C        extern "C" {
  #define  _END_EXTERN_C    }


  #define  _WINDEF_   // signals 'windef.h' was included


  // functions and structures wrappers
  #define  _STRUCT_STAT   struct stat
  #define  _stat          stat   // Windows uses _stat structure, Linux uses stat
  #define  _tzset         tzset

  #undef  STRICT  // to prevent clashes with different type definitions
  #undef _STRICT

  #define _TEOF           WEOF
  #define  EOS            _T('\0')
  #define _TEOS           EOS
  #define _fgettc         fgetwc
  #define _fputtc         fputwc
  #define _fgetts         fgetws
  #define _fputts         fputws
  #define _fgettchar      fgetwc
  #define _fputtchar      fputwc
  #define _ftscanf        fwscanf
  #define _ftprintf       fwprintf
  #define _istalpha       iswalpha
  #define _istalnum       iswalnum
  #define _istdigit       iswdigit
  #define _istxdigit      iswxdigit
  #define _istspace       iswspace
  #define _istcntrl       iswcntrl
  #define _istpunct       iswpunct
  #define _istprint       iswprint
  #define _istgraph       iswgraph
  #define _istupper       iswupper
  #define _istleadbyte    isleadbyte
  #define _stscanf        swscanf
  #define _stscanf_s      swscanf
  #define _tcscat         wcscat
  #define _tcsnccat       wcsncat
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
  #define _tcsnccmp       wcsncmp
  #define _tcsncpy        wcsncpy
  #define _tcsnicmp       wcsncasecmp
  #define _tcsnicoll      wcsncasecmp
  #define _tcsrev         _wcsrev
  #define _tcsrchr        wcsrchr
  #define _tcsspn         wcsspn
  #define _tcsstr         wcsstr
  #define _tcstod         wcstod
  #define _tcstol         wcstol
  #define _tcstoll        wcstoll
  #define _tcstoul        wcstoul
  #define _tcspbrk        wcspbrk
  #define _tsetlocale     wsetlocale
  #define _stprintf       swprintf
  #define _vsntprintf     vswprintf
  #define _tcscspn        wcscspn
  #define _istupper       iswupper
  #define _istlower       iswlower
  #define _istcntrl       iswcntrl
  #define _sntprintf      swprintf
  #define _stnprintf      _sntprintf
  #define _tcsftime       wcsftime
  #define _tcserror       wcserror

  #define _isnan          isnan
  #define _finite         finite

  // same as above, for plain "_wcs..." functions
  #define _fgetwchar      fgetwc
  #define _fputwchar      fputwc
  #define _wcsicmp        wcscasecmp
  #define _wcsicoll       wcscasecmp
  #define _wcsnicmp       wcsncasecmp
  #define _wcsnicoll      wcsncasecmp
  #define _wcsdup         wcsdup
  #define _snwprintf      swprintf
  #define _wcserror       wcserror
  #define _wsetlocale     wsetlocale

  #define _totupper       towupper
  #define _totlower       towlower
  #define _tcscpy_s       wcscpy_s
  #define _tcsspnp        _wcsspnp
  #define _tcsninc        _wcsninc
  #define _tcsinc         _wcsinc
  #define _tcsndec        _wcsndec
  #define _tcsdec         _wcsdec
  #define _ttoi           _wtoi
  #define _ttoi64         _wtol  // long in Linux64 is 64 bit
  #define _tstoi64        _wtol  // long in Linux64 is 64 bit
  #define _tcstoi64       _wtol  // long in Linux64 is 64 bit
  #define _tcstoui64      _wtol  // long in Linux64 is 64 bit
  #define _tstoi          _wtoi
  #define _ttol           _wtol
  #define _tstol          _wtol
  #define _tstof          _wtof
  #define _ltot           _ltow
  #define _ltot_s         _ltow_s
  #define _itot           _itow
  #define _itot_s         _ltow_s
  #define _tcsnlen        wcsnlen
  #define _tcslwr         _wcslwr
  #define _tcsupr         _wcsupr
  #define _tcsset         _wcsset
  #define _tcsnset        _wcsnset
  #define _tstat          _wstat
  #define _taccess        _waccess
  #define _tfopen         _wfopen
  #define _topen          _wopen
  #define _tfsopen        _wfsopen
  #define _tsopen         _wsopen
  #define _trename        _wrename
  #define _tremove        _wremove
  #define _trmdir         _wrmdir
  #define _tmkdir         _wmkdir
  #define _tgetcwd        _wgetcwd
  #define _tchdir         _wchdir
  #define _tfullpath      _wfullpath
  #define _tgetenv        _wgetenv
  #define _tputenv        _wputenv
  #define _tsearchenv     _wsearchenv
  #define _tsplitpath     _wsplitpath
  #define _ttmpnam        _wtmpnam
  #define _ttempnam       _wtempnam
  #define _tchmod         _wchmod
  #define _tunlink        _wunlink
  #define _tctime         _wctime

  // same as above, for plain "_wcs..." functions
  #define _wcstoi64       _wtol  // long in Linux64 is 64 bit
  #define _wcstoui64      _wtol  // long in Linux64 is 64 bit
  #define _wtoi64         _wtol  // long in Linux64 is 64 bit

#ifdef __APPLE__
  #define _msize          malloc_size
#else
  #define _msize          malloc_usable_size
#endif //__APPLE__

  #define _wfinddata_t    _wfinddata32_t
  #define _tfinddata_t    _wfinddata_t
  #define _tfindfirst     _wfindfirst
  #define _tfindfirst64   _wfindfirst
  #define _tfindfirsti64  _wfindfirst
  #define _tfindnext      _wfindnext
  #define _tfindnext64    _wfindnext
  #define _tfindnexti64   _wfindnext

  #define _timeb          timeb
  #define _ftime          ftime


  // security enhanced functions

  #define _stprintf_s     swprintf
  #define _tcstok_s       wcstok

  #define CharLower       CharLowerW
  #define CharLowerBuff   CharLowerBuffW
  #define CharUpper       CharUpperW
  #define CharUpperBuff   CharUpperBuffW

  #define OutputDebugString  OutputDebugStringW


  // type declarators

  // number of elemets in array type
  #if !defined ( ELEMENTS )
    #define ELEMENTS(x) (sizeof(x) / sizeof(x[0]))
  #endif

  #if !defined ( CONST )
    #define CONST const
  #endif

  #ifndef __T
    #define __T(x) L ## x
  #endif
  #ifndef _T
    #define _T(x) __T(x)
  #endif

  typedef unsigned char   boolean;
  typedef boolean         BOOLEAN;

  typedef uint8_t         BYTE; // FreeImage as used by DwgDirect uses these definitions :-(
  typedef int32_t         INT;
  typedef int32_t         BOOL;
  typedef uint32_t        UINT;
  typedef uint16_t        WORD;
  typedef uint32_t        DWORD;

  typedef int16_t         SHORT;
  typedef uint16_t        USHORT;

  typedef long            LONG;
  typedef unsigned long   ULONG;

  typedef int64_t         LONGLONG;
  typedef uint64_t        ULONGLONG;

  typedef float           FLOAT;
  typedef double          DOUBLE;
  typedef unsigned int    size_type;
  typedef unsigned long long  DWORDLONG;

  typedef int16_t         INT16;
  typedef uint16_t        UINT16;

  typedef uint32_t        DWORD32;
  typedef int32_t         INT32;
  typedef int32_t         LONG32;
  typedef uint32_t        UINT32;
  typedef uint32_t        ULONG32;

  typedef uint64_t        DWORD64;
  typedef int64_t         INT64;
  typedef int64_t         LONG64;
  typedef uint64_t        UINT64;
  typedef uint64_t        ULONG64;

  typedef char            CHAR;
  typedef char*           LPSTR;
  typedef const char*     LPCSTR;
  typedef wchar_t         WCHAR;
  typedef wchar_t         TCHAR;
  typedef wchar_t        _TCHAR;
  typedef wchar_t         __wchar_t;
  typedef TCHAR*          LPTSTR;
  typedef TCHAR*          LPWSTR;
  typedef const TCHAR*    LPCTSTR;
  typedef const TCHAR*    LPCWSTR;

#if( defined( _UNICODE ) || defined( UNICODE ) )
  typedef wchar_t         XCHAR;
  typedef LPWSTR          PXSTR;
  typedef LPCWSTR         PCXSTR;
  typedef char            YCHAR;
  typedef LPSTR           PYSTR;
  typedef LPCSTR          PCYSTR;
#else
  typedef char            XCHAR;
  typedef LPSTR           PXSTR;
  typedef LPCSTR          PCXSTR;
  typedef wchar_t         YCHAR;
  typedef LPWSTR          PYSTR;
  typedef LPCWSTR         PCYSTR;
#endif // _UNICODE || UNICODE

  typedef unsigned char   byte;

  #define VOID            void   /* typedef does not work here (for GCC) */
  typedef void*           PVOID;
  typedef void*           LPVOID;
  typedef uint8_t*        PBYTE;
  typedef uint8_t*        LPBYTE;
  typedef short*          PSHORT;
  typedef short*          LPSHORT;
  typedef unsigned short* PUSHORT;
  typedef unsigned short* LPUSHORT;
  typedef int32_t*        PINT;
  typedef int32_t*        LPINT;
  typedef uint32_t*       PUINT;
  typedef uint32_t*       LPUINT;
  typedef long*           PLONG;
  typedef long*           LPLONG;
  typedef unsigned long*  PULONG;
  typedef unsigned long*  LPULONG;
  typedef uint16_t*       PWORD;
  typedef uint16_t*       LPWORD;
  typedef uint32_t*       PDWORD;
  typedef uint32_t*       LPDWORD;
  typedef int32_t*        LPBOOL;

  #ifdef __SYS_32_BIT__   // 32 bit
    typedef int32_t       INT_PTR;
    typedef int32_t*      PINT_PTR;
    typedef uint32_t      UINT_PTR;
    typedef uint32_t*     PUINT_PTR;
    typedef int32_t       LONG_PTR;
    typedef int32_t*      PLONG_PTR;
    typedef uint32_t      ULONG_PTR;
    typedef uint32_t*     PULONG_PTR;
    typedef int32_t       __int3264;
    typedef uint32_t      DWORD_PTR;
    typedef uint32_t*     PDWORD_PTR;
  #else                   // 64 bit
    typedef int64_t       INT_PTR;
    typedef int64_t*      PINT_PTR;
    typedef uint64_t      UINT_PTR;
    typedef uint64_t*     PUINT_PTR;
    typedef int64_t       LONG_PTR;
    typedef int64_t*      PLONG_PTR;
    typedef uint64_t      ULONG_PTR;
    typedef uint64_t*     PULONG_PTR;
    typedef int64_t       __int3264;
    typedef uint64_t      DWORD_PTR;
    typedef uint64_t*     PDWORD_PTR;
  #endif  // !__SYS_32_BIT__

  typedef void*           HANDLE;
  typedef HANDLE          HINSTANCE;
  typedef HANDLE          HMODULE;
  typedef int32_t         HRESULT;
  typedef HANDLE          HBITMAP;
  typedef HANDLE          HPALETTE;
  typedef HANDLE          HMETAFILE;
  typedef HANDLE          HDC;
  typedef HANDLE          HWND;
  typedef HANDLE          HMENU;
  typedef HANDLE          HICON;
  typedef unsigned long   LCID;

  typedef uint32_t        WPARAM;   // always 32 bit
  typedef long            LPARAM;   // 32/64 bit
  typedef unsigned long   LRESULT;  // 32/64 bit

  typedef char            __int8;
  typedef short           __int16;
  typedef int32_t         __int32;
  typedef int64_t         __int64;

  typedef int32_t         __time32_t;
  typedef int64_t         __time64_t;

  typedef unsigned long   _fsize_t;


  /* Error Codes not defined in Linux <errno.h> */
  typedef int  errno_t;
  #define EPERM       1
  #define E2BIG       7
  #define STRUNCATE  80

  #define ERROR_OUT_OF_STRUCTURES    84
  #define ERROR_ALREADY_ASSIGNED     85
  #define ERROR_INVALID_PASSWORD     86
  #define ERROR_INVALID_PARAMETER    87
  #define ERROR_NET_WRITE_FAULT      88
  #define ERROR_INSUFFICIENT_BUFFER  122
  #define ERROR_NO_UNICODE_TRANSLATION  1113

  #define INVALID_HANDLE_VALUE       ((HANDLE)(LONG_PTR)-1)
  #define INVALID_FILE_SIZE          ((DWORD)0xFFFFFFFF)
  #define INVALID_SET_FILE_POINTER   ((DWORD)-1)
  #define INVALID_FILE_ATTRIBUTES    ((DWORD)-1)


  typedef struct tagPOINT
  {
      LONG  x;
      LONG  y;
  } POINT;
  typedef POINT*       LPPOINT;
  typedef const POINT* LPCPOINT;

  typedef struct tagSIZE
  {
      int  cx;
      int  cy;
  } SIZE;
  typedef SIZE*       LPSIZE;
  typedef const SIZE* LPCSIZE;

  typedef struct tagRECT
  {
      long left;
      long top;
      long right;
      long bottom;
  } RECT;
  typedef       RECT* LPRECT;
  typedef const RECT* LPCRECT;

  typedef union _LARGE_INTEGER
  {
      struct
      {
          DWORD LowPart;
          LONG  HighPart;
      };
      LONGLONG QuadPart;
  } LARGE_INTEGER;


  // COLORREF functions
  typedef unsigned long COLORREF;
  #define RGB(r, g ,b)  ((DWORD) (((BYTE) (r) | \
                        ((WORD) (g) << 8)) | \
                        (((DWORD) (BYTE) (b)) << 16)))
  #define GetRValue(rgb)  ((BYTE) (rgb))
  #define GetGValue(rgb)  ((BYTE) (((WORD) (rgb)) >> 8))
  #define GetBValue(rgb)  ((BYTE) ((rgb) >> 16))

  #ifndef RGBQUAD_DEFINED
  #define RGBQUAD_DEFINED
      typedef struct tagRGBQUAD
      {
          BYTE rgbBlue;
          BYTE rgbGreen;
          BYTE rgbRed;
          BYTE rgbReserved;
      } RGBQUAD, *LPRGBQUAD;
  #endif // RGBQUAD_DEFINED

  #ifndef RGBTRIPLE_DEFINED
  #define RGBTRIPLE_DEFINED
      #pragma pack(push,1)
      typedef struct tagRGBTRIPLE {
              BYTE    rgbtBlue;
              BYTE    rgbtGreen;
              BYTE    rgbtRed;
      } RGBTRIPLE;
      #pragma pack(pop)
  #endif // RGBTRIPLE_DEFINED

  #ifndef BITMAPINFOHEADER_DEFINED
  #define BITMAPINFOHEADER_DEFINED
      typedef struct tagBITMAPINFOHEADER
      {
          DWORD  biSize;
          LONG   biWidth;
          LONG   biHeight;
          WORD   biPlanes;
          WORD   biBitCount;
          DWORD  biCompression;
          DWORD  biSizeImage;
          LONG   biXPelsPerMeter;
          LONG   biYPelsPerMeter;
          DWORD  biClrUsed;
          DWORD  biClrImportant;
      } BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;
  #endif // BITMAPINFOHEADER_DEFINED

  #ifndef BITMAPFILEHEADER_DEFINED
  #define BITMAPFILEHEADER_DEFINED
      #pragma pack(push,2)
      typedef struct tagBITMAPFILEHEADER
      {
          WORD    bfType;
          DWORD   bfSize;
          WORD    bfReserved1;
          WORD    bfReserved2;
          DWORD   bfOffBits;
      } BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
      #pragma pack(pop)
  #endif // BITMAPFILEHEADER_DEFINED

  /* Bitmap Header Definition */
  typedef struct tagBITMAP
  {
      LONG        bmType;
      LONG        bmWidth;
      LONG        bmHeight;
      LONG        bmWidthBytes;
      WORD        bmPlanes;
      WORD        bmBitsPixel;
      LPVOID      bmBits;
  } BITMAP, *PBITMAP, *NPBITMAP, *LPBITMAP;

  typedef struct tagBITMAPCOREHEADER
  {
      DWORD  bcSize;
      WORD   bcWidth;
      WORD   bcHeight;
      WORD   bcPlanes;
      WORD   bcBitCount;
  } BITMAPCOREHEADER, *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;

#ifndef BITMAPINFO_DEFINED
#define BITMAPINFO_DEFINED
  typedef struct tagBITMAPINFO
  {
      BITMAPINFOHEADER  bmiHeader;
      RGBQUAD           bmiColors[1];
  } BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;
#endif //BITMAPINFO_DEFINED

  typedef struct tagBITMAPCOREINFO
  {
      BITMAPCOREHEADER  bmciHeader;
      RGBTRIPLE         bmciColors[1];
  } BITMAPCOREINFO, *LPBITMAPCOREINFO, *PBITMAPCOREINFO;



  // predefined data values

  #if !defined( TRUE )
    #define TRUE  1
  #endif
  #if !defined( FALSE )
    #define FALSE 0
  #endif

  #define MINCHAR    0x80
  #define MAXCHAR    0x7F
  #define MINSHORT   0x8000
  #define MAXSHORT   0x7FFF
  #define MINLONG    0x80000000
  #define MAXLONG    0x7FFFFFFF
  #define MAXBYTE    0xFF
  #define MAXWORD    0xFFFF
  #define MAXDWORD   0xFFFFFFFF

  #define _FILE_OFFSET_BITS     64

  typedef int (*PROC)();
  typedef int (FAR *FARPROC)();
  typedef int (NEAR *NEARPROC)();

  #define  DLL_PROCESS_ATTACH    (DWORD)1
  #define  DLL_THREAD_ATTACH     (DWORD)2
  #define  DLL_THREAD_DETACH     (DWORD)3
  #define  DLL_PROCESS_DETACH    (DWORD)0
  #define  DLL_PROCESS_VERIFIER  4

  #define _MAX_DRIVE      (DWORD)3
  #define _MAX_PATH       (DWORD)4096
  #define _MAX_FNAME      (DWORD)4096
  #define _MAX_DIR        _MAX_FNAME
  #define _MAX_EXT        _MAX_FNAME

  #undef   MAX_DRIVE
  #undef   MAX_PATH
  #undef   MAX_FNAME
  #undef   MAX_DIR
  #undef   MAX_EXT
  #define  MAX_DRIVE      _MAX_DRIVE
  #define  MAX_PATH       _MAX_PATH
  #define  MAX_FNAME      _MAX_FNAME
  #define  MAX_DIR        _MAX_DIR
  #define  MAX_EXT        _MAX_EXT

  #define _SH_DENYRW      0x10    /* deny read/write mode */
  #define _SH_DENYWR      0x20    /* deny write mode */
  #define _SH_DENYRD      0x30    /* deny read mode */
  #define _SH_DENYNO      0x40    /* deny none mode */
  #define _SH_SECURE      0x80    /* secure mode */

  // file "open" modes
  #define _O_APPEND      O_APPEND
  #define _O_BINARY      0  // not existing under Linux
  #define  O_BINARY      0  // not existing under Linux
  #define _O_CREAT       O_CREAT
  #define _O_SHORT_LIVED 0  // not existing under Linux (cache strategy)
  #define _O_TEMPORARY   0  // not existing under Linux
  #define _O_EXCL        O_EXCL
  #define _O_RANDOM      0  // not existing under Linux (cache strategy)
  #define _O_RDONLY      O_RDONLY
  #define _O_RDWR        O_RDWR
  #define _O_SEQUENTIAL  0  // not existing under Linux (cache strategy)
  #define _O_TEXT        0  // not existing under Linux
  #define _O_TRUNC       O_TRUNC
  #define _O_WRONLY      O_WRONLY
  // file "sharing" modes
  #define _S_IREAD       (S_IRUSR|S_IRGRP|S_IROTH)
  #define _S_IWRITE      (S_IWUSR|S_IWGRP|S_IROTH)

  #define _A_NORMAL   0x00  /* normal file */
  #define _A_RDONLY   0x01  /* read-only file */
  #define _A_HIDDEN   0x02  /* hidden file */
  #define _A_SYSTEM   0x04  /* system file */
  #define _A_SUBDIR   0x10  /* directory */
  #define _A_ARCH     0x20  /* archive */


  #define UNREFERENCED_PARAMETER(par)           (par);
  #define DBG_UNREFERENCED_PARAMETER(par)       (par);
  #define DBG_UNREFERENCED_LOCAL_VARIABLE(var)  (var);


  // minimum language support
  // primary language IDs
  #define LANG_NEUTRAL       0x00
  #define LANG_INVARIANT     0x7F

  #define LANG_AFRIKAANS     0x36
  #define LANG_ALBANIAN      0x1C
  #define LANG_ARABIC        0x01
  #define LANG_ARMENIAN      0x2B
  #define LANG_ASSAMESE      0x4D
  #define LANG_AZERI         0x2C
  #define LANG_BASQUE        0x2D
  #define LANG_BELARUSIAN    0x23
  #define LANG_BENGALI       0x45
  #define LANG_BULGARIAN     0x02
  #define LANG_CATALAN       0x03
  #define LANG_CHINESE       0x04
  #define LANG_CROATIAN      0x1A
  #define LANG_CZECH         0x05
  #define LANG_DANISH        0x06
  #define LANG_DIVEHI        0x65
  #define LANG_DUTCH         0x13
  #define LANG_ENGLISH       0x09
  #define LANG_ESTONIAN      0x25
  #define LANG_FAEROESE      0x38
  #define LANG_FARSI         0x29
  #define LANG_FINNISH       0x0B
  #define LANG_FRENCH        0x0C
  #define LANG_GALICIAN      0x56
  #define LANG_GEORGIAN      0x37
  #define LANG_GERMAN        0x07
  #define LANG_GREEK         0x08
  #define LANG_GUJARATI      0x47
  #define LANG_HEBREW        0x0D
  #define LANG_HINDI         0x39
  #define LANG_HUNGARIAN     0x0E
  #define LANG_ICELANDIC     0x0F
  #define LANG_INDONESIAN    0x21
  #define LANG_ITALIAN       0x10
  #define LANG_JAPANESE      0x11
  #define LANG_KANNADA       0x4B
  #define LANG_KASHMIRI      0x60
  #define LANG_KAZAK         0x3F
  #define LANG_KONKANI       0x57
  #define LANG_KOREAN        0x12
  #define LANG_KYRGYZ        0x40
  #define LANG_LATVIAN       0x26
  #define LANG_LITHUANIAN    0x27
  #define LANG_MACEDONIAN    0x2F
  #define LANG_MALAY         0x3E
  #define LANG_MALAYALAM     0x4C
  #define LANG_MANIPURI      0x58
  #define LANG_MARATHI       0x4E
  #define LANG_MONGOLIAN     0x50
  #define LANG_NEPALI        0x61
  #define LANG_NORWEGIAN     0x14
  #define LANG_ORIYA         0x48
  #define LANG_POLISH        0x15
  #define LANG_PORTUGUESE    0x16
  #define LANG_PUNJABI       0x46
  #define LANG_ROMANIAN      0x18
  #define LANG_RUSSIAN       0x19
  #define LANG_SANSKRIT      0x4F
  #define LANG_SERBIAN       0x1A
  #define LANG_SINDHI        0x59
  #define LANG_SLOVAK        0x1B
  #define LANG_SLOVENIAN     0x24
  #define LANG_SPANISH       0x0A
  #define LANG_SWAHILI       0x41
  #define LANG_SWEDISH       0x1D
  #define LANG_SYRIAC        0x5A
  #define LANG_TAMIL         0x49
  #define LANG_TATAR         0x44
  #define LANG_TELUGU        0x4A
  #define LANG_THAI          0x1E
  #define LANG_TURKISH       0x1F
  #define LANG_UKRAINIAN     0x22
  #define LANG_URDU          0x20
  #define LANG_UZBEK         0x43
  #define LANG_VIETNAMESE    0x2A

  //  Sublanguage IDs.
  //  The name immediately following SUBLANG_ dictates which primary
  //  language ID that sublanguage ID can be combined with to form a
  //  valid language ID.
  #define SUBLANG_NEUTRAL                  0x00    // language neutral
  #define SUBLANG_DEFAULT                  0x01    // user default
  #define SUBLANG_SYS_DEFAULT              0x02    // system default

  #define SUBLANG_ARABIC_SAUDI_ARABIA      0x01    // Arabic (Saudi Arabia)
  #define SUBLANG_ARABIC_IRAQ              0x02    // Arabic (Iraq)
  #define SUBLANG_ARABIC_EGYPT             0x03    // Arabic (Egypt)
  #define SUBLANG_ARABIC_LIBYA             0x04    // Arabic (Libya)
  #define SUBLANG_ARABIC_ALGERIA           0x05    // Arabic (Algeria)
  #define SUBLANG_ARABIC_MOROCCO           0x06    // Arabic (Morocco)
  #define SUBLANG_ARABIC_TUNISIA           0x07    // Arabic (Tunisia)
  #define SUBLANG_ARABIC_OMAN              0x08    // Arabic (Oman)
  #define SUBLANG_ARABIC_YEMEN             0x09    // Arabic (Yemen)
  #define SUBLANG_ARABIC_SYRIA             0x0a    // Arabic (Syria)
  #define SUBLANG_ARABIC_JORDAN            0x0b    // Arabic (Jordan)
  #define SUBLANG_ARABIC_LEBANON           0x0c    // Arabic (Lebanon)
  #define SUBLANG_ARABIC_KUWAIT            0x0d    // Arabic (Kuwait)
  #define SUBLANG_ARABIC_UAE               0x0e    // Arabic (U.A.E)
  #define SUBLANG_ARABIC_BAHRAIN           0x0f    // Arabic (Bahrain)
  #define SUBLANG_ARABIC_QATAR             0x10    // Arabic (Qatar)
  #define SUBLANG_AZERI_LATIN              0x01    // Azeri (Latin)
  #define SUBLANG_AZERI_CYRILLIC           0x02    // Azeri (Cyrillic)
  #define SUBLANG_CHINESE_TRADITIONAL      0x01    // Chinese (Taiwan)
  #define SUBLANG_CHINESE_SIMPLIFIED       0x02    // Chinese (PR China)
  #define SUBLANG_CHINESE_HONGKONG         0x03    // Chinese (Hong Kong S.A.R., P.R.C.)
  #define SUBLANG_CHINESE_SINGAPORE        0x04    // Chinese (Singapore)
  #define SUBLANG_CHINESE_MACAU            0x05    // Chinese (Macau S.A.R.)
  #define SUBLANG_DUTCH                    0x01    // Dutch
  #define SUBLANG_DUTCH_BELGIAN            0x02    // Dutch (Belgian)
  #define SUBLANG_ENGLISH_US               0x01    // English (USA)
  #define SUBLANG_ENGLISH_UK               0x02    // English (UK)
  #define SUBLANG_ENGLISH_AUS              0x03    // English (Australian)
  #define SUBLANG_ENGLISH_CAN              0x04    // English (Canadian)
  #define SUBLANG_ENGLISH_NZ               0x05    // English (New Zealand)
  #define SUBLANG_ENGLISH_EIRE             0x06    // English (Irish)
  #define SUBLANG_ENGLISH_SOUTH_AFRICA     0x07    // English (South Africa)
  #define SUBLANG_ENGLISH_JAMAICA          0x08    // English (Jamaica)
  #define SUBLANG_ENGLISH_CARIBBEAN        0x09    // English (Caribbean)
  #define SUBLANG_ENGLISH_BELIZE           0x0a    // English (Belize)
  #define SUBLANG_ENGLISH_TRINIDAD         0x0b    // English (Trinidad)
  #define SUBLANG_ENGLISH_ZIMBABWE         0x0c    // English (Zimbabwe)
  #define SUBLANG_ENGLISH_PHILIPPINES      0x0d    // English (Philippines)
  #define SUBLANG_FRENCH                   0x01    // French
  #define SUBLANG_FRENCH_BELGIAN           0x02    // French (Belgian)
  #define SUBLANG_FRENCH_CANADIAN          0x03    // French (Canadian)
  #define SUBLANG_FRENCH_SWISS             0x04    // French (Swiss)
  #define SUBLANG_FRENCH_LUXEMBOURG        0x05    // French (Luxembourg)
  #define SUBLANG_FRENCH_MONACO            0x06    // French (Monaco)
  #define SUBLANG_GERMAN                   0x01    // German
  #define SUBLANG_GERMAN_SWISS             0x02    // German (Swiss)
  #define SUBLANG_GERMAN_AUSTRIAN          0x03    // German (Austrian)
  #define SUBLANG_GERMAN_LUXEMBOURG        0x04    // German (Luxembourg)
  #define SUBLANG_GERMAN_LIECHTENSTEIN     0x05    // German (Liechtenstein)
  #define SUBLANG_ITALIAN                  0x01    // Italian
  #define SUBLANG_ITALIAN_SWISS            0x02    // Italian (Swiss)
  #define SUBLANG_KASHMIRI_SASIA           0x02    // Kashmiri (South Asia)
  #define SUBLANG_KASHMIRI_INDIA           0x02    // For app compatibility only
  #define SUBLANG_KOREAN                   0x01    // Korean (Extended Wansung)
  #define SUBLANG_LITHUANIAN               0x01    // Lithuanian
  #define SUBLANG_MALAY_MALAYSIA           0x01    // Malay (Malaysia)
  #define SUBLANG_MALAY_BRUNEI_DARUSSALAM  0x02    // Malay (Brunei Darussalam)
  #define SUBLANG_NEPALI_INDIA             0x02    // Nepali (India)
  #define SUBLANG_NORWEGIAN_BOKMAL         0x01    // Norwegian (Bokmal)
  #define SUBLANG_NORWEGIAN_NYNORSK        0x02    // Norwegian (Nynorsk)
  #define SUBLANG_PORTUGUESE               0x02    // Portuguese
  #define SUBLANG_PORTUGUESE_BRAZILIAN     0x01    // Portuguese (Brazilian)
  #define SUBLANG_SERBIAN_LATIN            0x02    // Serbian (Latin)
  #define SUBLANG_SERBIAN_CYRILLIC         0x03    // Serbian (Cyrillic)
  #define SUBLANG_SPANISH                  0x01    // Spanish (Castilian)
  #define SUBLANG_SPANISH_MEXICAN          0x02    // Spanish (Mexican)
  #define SUBLANG_SPANISH_MODERN           0x03    // Spanish (Spain)
  #define SUBLANG_SPANISH_GUATEMALA        0x04    // Spanish (Guatemala)
  #define SUBLANG_SPANISH_COSTA_RICA       0x05    // Spanish (Costa Rica)
  #define SUBLANG_SPANISH_PANAMA           0x06    // Spanish (Panama)
  #define SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07  // Spanish (Dominican Republic)
  #define SUBLANG_SPANISH_VENEZUELA        0x08    // Spanish (Venezuela)
  #define SUBLANG_SPANISH_COLOMBIA         0x09    // Spanish (Colombia)
  #define SUBLANG_SPANISH_PERU             0x0a    // Spanish (Peru)
  #define SUBLANG_SPANISH_ARGENTINA        0x0b    // Spanish (Argentina)
  #define SUBLANG_SPANISH_ECUADOR          0x0c    // Spanish (Ecuador)
  #define SUBLANG_SPANISH_CHILE            0x0d    // Spanish (Chile)
  #define SUBLANG_SPANISH_URUGUAY          0x0e    // Spanish (Uruguay)
  #define SUBLANG_SPANISH_PARAGUAY         0x0f    // Spanish (Paraguay)
  #define SUBLANG_SPANISH_BOLIVIA          0x10    // Spanish (Bolivia)
  #define SUBLANG_SPANISH_EL_SALVADOR      0x11    // Spanish (El Salvador)
  #define SUBLANG_SPANISH_HONDURAS         0x12    // Spanish (Honduras)
  #define SUBLANG_SPANISH_NICARAGUA        0x13    // Spanish (Nicaragua)
  #define SUBLANG_SPANISH_PUERTO_RICO      0x14    // Spanish (Puerto Rico)
  #define SUBLANG_SWEDISH                  0x01    // Swedish
  #define SUBLANG_SWEDISH_FINLAND          0x02    // Swedish (Finland)
  #define SUBLANG_URDU_PAKISTAN            0x01    // Urdu (Pakistan)
  #define SUBLANG_URDU_INDIA               0x02    // Urdu (India)
  #define SUBLANG_UZBEK_LATIN              0x01    // Uzbek (Latin)
  #define SUBLANG_UZBEK_CYRILLIC           0x02    // Uzbek (Cyrillic)

  //  Sorting IDs.
  #define SORT_DEFAULT                     0x0     // sorting default

  #define MAKELANGID(p, s)       ((((WORD)(s)) << 10) | (WORD)(p))
  #define PRIMARYLANGID(lgid)    ((WORD)(lgid) & 0x3ff)
  #define SUBLANGID(lgid)        ((WORD)(lgid) >> 10)

  #define MAKELCID(lgid, srtid)  ((DWORD)((((DWORD)((WORD  )(srtid))) << 16) |  \
                                           ((DWORD)((WORD  )(lgid)))))
  #define LANGIDFROMLCID(lcid)   ((WORD)(lcid))

  //  Default System and User IDs for language and locale.
  #define LANG_SYSTEM_DEFAULT    (MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT))
  #define LANG_USER_DEFAULT      (MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
  #define LOCALE_SYSTEM_DEFAULT  (MAKELCID(LANG_SYSTEM_DEFAULT, SORT_DEFAULT))
  #define LOCALE_USER_DEFAULT    (MAKELCID(LANG_USER_DEFAULT,   SORT_DEFAULT))
  #define LOCALE_NEUTRAL         (MAKELCID(MAKELANGID(LANG_NEUTRAL,   SUBLANG_NEUTRAL), SORT_DEFAULT))
  #define LOCALE_INVARIANT       (MAKELCID(MAKELANGID(LANG_INVARIANT, SUBLANG_NEUTRAL), SORT_DEFAULT))

  // Security Params
  #define PROV_RSA_FULL        1
  #define PROV_RSA_SIG         2
  #define PROV_DSS             3
  #define PROV_FORTEZZA        4
  #define PROV_MS_EXCHANGE     5
  #define PROV_SSL             6
  #define PROV_STT_MER         7
  #define PROV_STT_ACQ         8
  #define PROV_STT_BRND        9
  #define PROV_STT_ROOT        10
  #define PROV_STT_ISS         11
  #define PROV_RSA_SCHANNEL    12
  #define PROV_DSS_DH          13
  #define PROV_EC_ECDSA_SIG    14
  #define PROV_EC_ECNRA_SIG    15
  #define PROV_EC_ECDSA_FULL   16
  #define PROV_EC_ECNRA_FULL   17
  #define PROV_DH_SCHANNEL     18
  #define PROV_SPYRUS_LYNKS    20
  #define PROV_RNG             21
  #define PROV_INTEL_SEC       22
  #define PROV_REPLACE_OWF     23
  #define PROV_RSA_AES         24

  // Provider names
  #define MS_DEF_PROV_A               "Microsoft Base Cryptographic Provider v1.0"
  #define MS_DEF_PROV_W               L"Microsoft Base Cryptographic Provider v1.0"
  #define MS_ENHANCED_PROV_A          "Microsoft Enhanced Cryptographic Provider v1.0"
  #define MS_ENHANCED_PROV_W          L"Microsoft Enhanced Cryptographic Provider v1.0"
  #define MS_STRONG_PROV_A            "Microsoft Strong Cryptographic Provider"
  #define MS_STRONG_PROV_W            L"Microsoft Strong Cryptographic Provider"
  #define MS_DEF_RSA_SIG_PROV_A       "Microsoft RSA Signature Cryptographic Provider"
  #define MS_DEF_RSA_SIG_PROV_W       L"Microsoft RSA Signature Cryptographic Provider"
  #define MS_DEF_RSA_SCHANNEL_PROV_A  "Microsoft RSA SChannel Cryptographic Provider"
  #define MS_DEF_RSA_SCHANNEL_PROV_W  L"Microsoft RSA SChannel Cryptographic Provider"
  #define MS_DEF_DSS_PROV_A           "Microsoft Base DSS Cryptographic Provider"
  #define MS_DEF_DSS_PROV_W           L"Microsoft Base DSS Cryptographic Provider"
  #define MS_DEF_DSS_DH_PROV_A        "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
  #define MS_DEF_DSS_DH_PROV_W        L"Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
  #define MS_ENH_DSS_DH_PROV_A        "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
  #define MS_ENH_DSS_DH_PROV_W        L"Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
  #define MS_DEF_DH_SCHANNEL_PROV_A   "Microsoft DH SChannel Cryptographic Provider"
  #define MS_DEF_DH_SCHANNEL_PROV_W   L"Microsoft DH SChannel Cryptographic Provider"
  #define MS_SCARD_PROV_A             "Microsoft Base Smart Card Crypto Provider"
  #define MS_SCARD_PROV_W             L"Microsoft Base Smart Card Crypto Provider"
  #define MS_ENH_RSA_AES_PROV_A       "Microsoft Enhanced RSA and AES Cryptographic Provider"
  #define MS_ENH_RSA_AES_PROV_W       L"Microsoft Enhanced RSA and AES Cryptographic Provider"
  #define MS_ENH_RSA_AES_PROV_XP_A    "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
  #define MS_ENH_RSA_AES_PROV_XP_W    L"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"

  #ifdef UNICODE
    #define MS_DEF_PROV               MS_DEF_PROV_W
    #define MS_ENHANCED_PROV          MS_ENHANCED_PROV_W
    #define MS_STRONG_PROV            MS_STRONG_PROV_W
    #define MS_DEF_RSA_SIG_PROV       MS_DEF_RSA_SIG_PROV_W
    #define MS_DEF_RSA_SCHANNEL_PROV  MS_DEF_RSA_SCHANNEL_PROV_W
    #define MS_DEF_DSS_PROV           MS_DEF_DSS_PROV_W
    #define MS_DEF_DSS_DH_PROV        MS_DEF_DSS_DH_PROV_W
    #define MS_ENH_DSS_DH_PROV        MS_ENH_DSS_DH_PROV_W
    #define MS_DEF_DH_SCHANNEL_PROV   MS_DEF_DH_SCHANNEL_PROV_W
    #define MS_SCARD_PROV             MS_SCARD_PROV_W
    #define MS_ENH_RSA_AES_PROV_XP    MS_ENH_RSA_AES_PROV_XP_W
    #define MS_ENH_RSA_AES_PROV       MS_ENH_RSA_AES_PROV_W
  #else
    #define MS_DEF_PROV               MS_DEF_PROV_A
    #define MS_ENHANCED_PROV          MS_ENHANCED_PROV_A
    #define MS_STRONG_PROV            MS_STRONG_PROV_A
    #define MS_DEF_RSA_SIG_PROV       MS_DEF_RSA_SIG_PROV_A
    #define MS_DEF_RSA_SCHANNEL_PROV  MS_DEF_RSA_SCHANNEL_PROV_A
    #define MS_DEF_DSS_PROV           MS_DEF_DSS_PROV_A
    #define MS_DEF_DSS_DH_PROV        MS_DEF_DSS_DH_PROV_A
    #define MS_ENH_DSS_DH_PROV        MS_ENH_DSS_DH_PROV_A
    #define MS_DEF_DH_SCHANNEL_PROV   MS_DEF_DH_SCHANNEL_PROV_A
    #define MS_SCARD_PROV             MS_SCARD_PROV_A
    #define MS_ENH_RSA_AES_PROV_XP    MS_ENH_RSA_AES_PROV_XP_A
    #define MS_ENH_RSA_AES_PROV       MS_ENH_RSA_AES_PROV_A
  #endif


  //  parameter macros
  #define HIBYTE(exp)  ((BYTE)((DWORD)(exp) >> 8))
  #define LOBYTE(exp)  ((BYTE)((DWORD)(exp) & 0x00FF))

  #define LOWORD(exp)  ((WORD)((DWORD)(exp) & 0x0000FFFF))
  #define HIWORD(exp)  ((WORD)((DWORD)(exp) >> 16))

  #define MAKEWORD(low, high)  ((WORD)((((WORD)(low)) & 0x00FF) | ((((WORD)(high)) & 0x00FF) << 8)))
  #define MAKELONG(low, high)  ((DWORD)((((DWORD)(low)) & 0x0000FFFF) | ((((DWORD)(high)) & 0x00FFFF) << 16)))

  #define MAKELPARAM(low, high)  ((WPARAM)(MAKELONG(low, high)))
  #define MAKEWPARAM(low, high)  ((LPARAM)(MAKELONG(low, high)))
  #define MAKELRESULT(low, high) ((LRESULT)(MAKELONG(low, high)))

  #define GET_WPARAM(wparam, lparam)  (wparam)
  #define GET_LPARAM(wparam, lparam)  (lparam)

  #define GET_X_LPARAM(lparam)  ((int)(short)LOWORD(lparam))
  #define GET_Y_LPARAM(lparam)  ((int)(short)HIWORD(lparam))



  //  MBCS and Unicode Translation Flags
  #define MB_PRECOMPOSED        0x00000001  // use precomposed chars
  #define MB_COMPOSITE          0x00000002  // use composite chars
  #define MB_USEGLYPHCHARS      0x00000004  // use glyph chars, not ctrl chars
  #define MB_ERR_INVALID_CHARS  0x00000008  // error for invalid chars

  #define WC_COMPOSITECHECK     0x00000200  // convert composite to precomposed
  #define WC_DISCARDNS          0x00000010  // discard non-spacing chars
  #define WC_SEPCHARS           0x00000020  // generate separate chars
  #define WC_DEFAULTCHAR        0x00000040  // replace w/ default char
  #define WC_NO_BEST_FIT_CHARS  0x00000400  // do not use best fit chars



  // support for ASSERT
  #ifndef ASSERT
    #if !defined(DEBUG) && !defined(_DEBUG)
      #define ASSERT(x)
    #else
      #define ASSERT(x) \
         if (!(x)) \
         { \
            CWideString wideFile(__FILE__); \
            fwprintf(stderr, _T("\nAssert <%ls> failed\n"), #x);       /* std::cout << "Assert " << #x << " failed\n";   */ \
            fwprintf(stderr, _T(" on line %d\n"), __LINE__);           /* std::cout << " on line " << __LINE__ << "\n";  */ \
            fwprintf(stderr, _T(" in file %ls\n"), (LPCTSTR)wideFile); /* std::cout << " in file " << __FILE__ << "\n";  */ \
         }
    #endif // !DEBUG !_DEBUG
  #endif // !ASSERT

  #ifndef VERIFY
    #define VERIFY(x) \
       if (!(x)) \
       { \
          CWideString wideFile(__FILE__); \
          fwprintf(stderr, _T("\nVerify <%ls> failed\n"), #x);       /* std::cout << "Verify " << #x << " failed\n";   */ \
          fwprintf(stderr, _T(" on line %d\n"), __LINE__);           /* std::cout << " on line " << __LINE__ << "\n";  */ \
          fwprintf(stderr, _T(" in file %ls\n"), (LPCTSTR)wideFile); /* std::cout << " in file " << __FILE__ << "\n";  */ \
       }
  #endif // !VERIFY

  #ifndef _ASSERT
    #define _ASSERT  ASSERT
  #endif // !_ASSERT

  #ifndef _ASSERTE
    #define _ASSERTE  ASSERT
  #endif // !_ASSERTE


  #ifndef TRACE
    #ifdef _DEBUG
      #define TRACE(exp)                     fprintf(stdout, exp);
      #define TRACE0(str)                    fprintf(stdout, str);
      #define TRACE1(fmt, arg1)              fprintf(stdout, fmt, arg1);
      #define TRACE2(fmt, arg1, arg2)        fprintf(stdout, fmt, arg1, arg2);
      #define TRACE3(fmt, arg1, arg2, arg3)  fprintf(stdout, fmt, arg1, arg2, arg3);
    #else
      #define TRACE(exp)
      #define TRACE0(str)
      #define TRACE1(fmt, arg1)
      #define TRACE2(fmt, arg1, arg2)
      #define TRACE3(fmt, arg1, arg2, arg3)
    #endif
  #endif



#endif // _WIN32

#endif // _BS_WIN_DEFS_INCLUDED_
