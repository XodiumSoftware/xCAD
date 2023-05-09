// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// WinSDK data types and functions

#pragma once

#ifndef _BS_WINSDK_INCLUDED_
#define _BS_WINSDK_INCLUDED_

// ========== Platform specific ==========

#define RenameFile  MoveFile

#ifndef _WIN32 // on Linux/Mac

// ----- definitions -----

#define  DONT_RESOLVE_DLL_REFERENCES    0x00000001
#define  LOAD_LIBRARY_AS_DATAFILE       0x00000002
#define  LOAD_WITH_ALTERED_SEARCH_PATH  0x00000008
#define  LOAD_IGNORE_CODE_AUTHZ_LEVEL   0x00000010


// ----- Mouse buttons -----

//* key masks for mouse events
#define MK_LBUTTON    0x0001
#define MK_RBUTTON    0x0002
#define MK_SHIFT      0x0004
#define MK_CONTROL    0x0008
#define MK_MBUTTON    0x0010
#define MK_XBUTTON1   0x0020
#define MK_XBUTTON2   0x0040


// ----- MessageBox(Ex) constants -----

#define IDOK        1
#define IDCANCEL    2
#define IDABORT     3
#define IDRETRY     4
#define IDIGNORE    5
#define IDYES       6
#define IDNO        7
#define IDCLOSE     8
#define IDHELP      9
#define IDTRYAGAIN  10
#define IDCONTINUE  11
#define IDTIMEOUT   32000

#define MB_OK                    0x00000000L
#define MB_OKCANCEL              0x00000001L
#define MB_ABORTRETRYIGNORE      0x00000002L
#define MB_YESNOCANCEL           0x00000003L
#define MB_YESNO                 0x00000004L
#define MB_RETRYCANCEL           0x00000005L
#define MB_CANCELTRYCONTINUE     0x00000006L

#define MB_ICONHAND              0x00000010L
#define MB_ICONQUESTION          0x00000020L
#define MB_ICONEXCLAMATION       0x00000030L
#define MB_ICONASTERISK          0x00000040L
#define MB_USERICON              0x00000080L
#define MB_ICONWARNING           MB_ICONEXCLAMATION
#define MB_ICONERROR             MB_ICONHAND

#define MB_ICONINFORMATION       MB_ICONASTERISK
#define MB_ICONSTOP              MB_ICONHAND

#define MB_DEFBUTTON1            0x00000000L
#define MB_DEFBUTTON2            0x00000100L
#define MB_DEFBUTTON3            0x00000200L
#define MB_DEFBUTTON4            0x00000300L

#define MB_APPLMODAL             0x00000000L
#define MB_SYSTEMMODAL           0x00001000L
#define MB_TASKMODAL             0x00002000L
#define MB_HELP                  0x00004000L

#define MB_NOFOCUS               0x00008000L
#define MB_SETFOREGROUND         0x00010000L
#define MB_DEFAULT_DESKTOP_ONLY  0x00020000L

#define MB_TOPMOST               0x00040000L
#define MB_RIGHT                 0x00080000L
#define MB_RTLREADING            0x00100000L
#define MB_SERVICE_NOTIFICATION  0x00200000L

#define MB_TYPEMASK              0x0000000FL
#define MB_ICONMASK              0x000000F0L
#define MB_DEFMASK               0x00000F00L
#define MB_MODEMASK              0x00003000L
#define MB_MISCMASK              0x0000C000L



// ----- function redirection -----

#define  MessageBox     MessageBoxW
#define  MessageBoxEx   MessageBoxExW

#define  GetCommandLine      GetCommandLineW
#define  CommandLineToArgv   CommandLineToArgvW



// ----- structures -----

typedef struct _SECURITY_ATTRIBUTES
{
  DWORD  nLength;
  LPVOID lpSecurityDescriptor;
  BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES;
typedef _SECURITY_ATTRIBUTES* LPSECURITY_ATTRIBUTES;

typedef struct _SYSTEMTIME
{
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
} SYSTEMTIME;
typedef SYSTEMTIME* LPSYSTEMTIME;

typedef struct _FILETIME
{
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} FILETIME;
typedef FILETIME* PFILETIME;
typedef FILETIME* LPFILETIME;


//enum tagCLSCTX
//{
#define  CLSCTX_INPROC_SERVER           0x00000001L
#define  CLSCTX_INPROC_HANDLER          0x00000002L
#define  CLSCTX_LOCAL_SERVER            0x00000004L
#define  CLSCTX_INPROC_SERVER16         0x00000008L
#define  CLSCTX_REMOTE_SERVER           0x00000010L
#define  CLSCTX_INPROC_HANDLER16        0x00000020L
#define  CLSCTX_RESERVED1               0x00000040L
#define  CLSCTX_RESERVED2               0x00000080L
#define  CLSCTX_RESERVED3               0x00000100L
#define  CLSCTX_RESERVED4               0x00000200L
#define  CLSCTX_NO_CODE_DOWNLOAD        0x00000400L
#define  CLSCTX_RESERVED5               0x00000800L
#define  CLSCTX_NO_CUSTOM_MARSHAL       0x00001000L
#define  CLSCTX_ENABLE_CODE_DOWNLOAD    0x00002000L
#define  CLSCTX_NO_FAILURE_LOG          0x00004000L
#define  CLSCTX_DISABLE_AAA             0x00008000L
#define  CLSCTX_ENABLE_AAA              0x00010000L
#define  CLSCTX_FROM_DEFAULT_CONTEXT    0x00020000L
#define  CLSCTX_ACTIVATE_32_BIT_SERVER  0x00040000L
#define  CLSCTX_ACTIVATE_64_BIT_SERVER  0x00080000L
//} CLSCTX;


// ----- data types -----

typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);


// ----- functions -----

int swprintf (wchar_t *buffer, const wchar_t *format, ...);

BRXEXPORT LPTSTR CharLowerW     (LPTSTR stringOrChar);
BRXEXPORT DWORD  CharLowerBuffW (LPTSTR szString, DWORD count);
BRXEXPORT LPTSTR CharUpperW     (LPTSTR stringOrChar);
BRXEXPORT DWORD  CharUpperBuffW (LPTSTR szString, DWORD count);


BRXEXPORT char *  GetCommandLineA ();
BRXEXPORT LPTSTR  GetCommandLineW ();


BRXEXPORT BOOL  IsDebuggerPresent  ();
BRXEXPORT void  OutputDebugStringW (LPCTSTR lpOutputString);
BRXEXPORT void  OutputDebugStringA (const char * lpOutputString);

BRXEXPORT DWORD GetLastError  ();
BRXEXPORT void  SetLastError  (DWORD dwErrCode);

BRXEXPORT VOID  ZeroMemory    (PVOID dest, size_t sizeDest);
BRXEXPORT VOID  FillMemory    (PVOID dest, size_t sizeDest, BYTE fill);

BRXEXPORT int   MessageBoxW   (HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
BRXEXPORT int   MessageBoxExW (HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, WORD wLanguageId);

BRXEXPORT BOOL  Beep          (DWORD dwFreq, DWORD dwDuration);
BRXEXPORT BOOL  MessageBeep   (UINT beepType);
BRXEXPORT VOID  Sleep         (DWORD dwMillisecs);


BRXEXPORT HINSTANCE  LoadLibrary       (LPCTSTR lpFileName);
BRXEXPORT HINSTANCE  LoadLibraryEx     (LPCTSTR lpFileName, HANDLE hFile, DWORD dwFlags);
BRXEXPORT BOOL       FreeLibrary       (HINSTANCE hModule);
BRXEXPORT HMODULE    GetModuleHandle   (LPCTSTR lpModuleName);
BRXEXPORT DWORD      GetModuleFileName (HMODULE hModule, LPTSTR lpFilename, DWORD nSize);
BRXEXPORT FARPROC    GetProcAddress    (HMODULE hModule, LPCSTR lpProcName);
BRXEXPORT BOOL       DisableThreadLibraryCalls (HMODULE hModule);


BRXEXPORT BOOL  PathFileExists (LPCTSTR lpszPath);

BRXEXPORT BOOL  RenameFile (LPCTSTR lpOldFileName, LPCTSTR lpNewFileName);
BRXEXPORT BOOL  CopyFile   (LPCTSTR lpExistingFileName, LPCTSTR lpNewFileName, BOOL bFailIfExists);
BRXEXPORT BOOL  DeleteFile (LPCTSTR lpFileName);

BRXEXPORT DWORD GetCurrentDirectory (DWORD nBufferLength, LPTSTR lpBuffer);
BRXEXPORT BOOL  SetCurrentDirectory (LPCTSTR lpPathName);
BRXEXPORT DWORD GetTempPath         (DWORD nBufferLength, LPTSTR lpBuffer);
BRXEXPORT UINT  GetTempFileName     (LPCTSTR lpPathName, LPCTSTR lpPrefixString,
                                     UINT uUnique, LPTSTR lpTempFileName);
BRXEXPORT UINT  GetSystemDirectory  (LPTSTR lpBuffer, UINT uSize);
BRXEXPORT UINT  GetWindowsDirectory (LPTSTR lpBuffer, UINT uSize);

BRXEXPORT BOOL  CreateDirectory (LPCTSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BRXEXPORT BOOL  RemoveDirectory (LPCTSTR lpPathName);

BRXEXPORT DWORD GetEnvironmentVariable (LPCTSTR lpName, LPTSTR lpBuffer, DWORD nSize);
BRXEXPORT BOOL  GetUserName     (LPTSTR lpBuffer, LPDWORD nSize);
BRXEXPORT DWORD SearchPath      (LPCTSTR lpPath, LPCTSTR lpFileName, LPCTSTR lpExtension,
                                 DWORD nBufferLength, LPTSTR lpBuffer, LPTSTR *lpFilePart);


// GetFileAttributes
// GetFileSize

// SetFileAttributes


// WIN32_FIND_DATA findData;
// HANDLE hDrawingFile = ::FindFirstFile(pFn, &findData);
// ::FindNextFile();
// ::FindClose(hDrawingFile);
// hDrawingFile = ::CreateFile(pFn, GENERIC_READ | GENERIC_WRITE,


BRXEXPORT DWORD GetTickCount  ();
BRXEXPORT void  GetLocalTime  (LPSYSTEMTIME lpLocalTime);
BRXEXPORT void  GetSystemTime (LPSYSTEMTIME lpSystemTime);

//BOOL GetFileTime   (HANDLE hFile, LPFILETIME lpCreationTime,
//                    LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime);


BRXEXPORT UINT GetACP(VOID);

BRXEXPORT BOOL IsDBCSLeadByte   (BYTE testChar);
BRXEXPORT BOOL IsDBCSLeadByteEx (UINT CodePage, BYTE testChar);

BRXEXPORT int MultiByteToWideChar (UINT CodePage,         // code page
                                   DWORD dwFlags,         // character-type options
                                   LPCSTR lpMultiByteStr, // address of string to map
                                   int cbMultiByte,       // number of bytes in string
                                   LPWSTR lpWideCharStr,  // address of wide-character buffer
                                   int cchWideChar        // size of buffer
                                  );

BRXEXPORT int WideCharToMultiByte(UINT CodePage,            // code page
                                  DWORD dwFlags,            // performance and mapping flags
                                  LPCWSTR lpWideCharStr,    // address of wide-character string
                                  int cchWideChar,          // number of characters in string
                                  LPSTR lpMultiByteStr,     // address of buffer for new string
                                  int cbMultiByte,          // size of buffer
                                  LPCSTR lpDefaultChar,     // address of default for unmappable characters
                                  LPBOOL lpUsedDefaultChar  // address of flag set when default char. used
                                 );


// ----- Locking / Unlocking ----
BRXEXPORT long _InterlockedIncrement   (long* pAddend);
BRXEXPORT long _InterlockedDecrement   (long* pAddend);
BRXEXPORT long _InterlockedExchangeAdd (long* pAddend, long incrDecrVal);
BRXEXPORT long _InterlockedExchange    (long* target, long setVvalue);

BRXEXPORT LONG  InterlockedIncrement   (volatile LONG* pAddend);
BRXEXPORT LONG  InterlockedDecrement   (volatile LONG* pAddend);
BRXEXPORT LONG  InterlockedExchangeAdd (volatile LONG* pAddend, LONG incrDecrVal);
BRXEXPORT LONG  InterlockedExchange    (volatile LONG* target,  LONG setVvalue);


// ----- Exception Handling -----

BRXEXPORT void RaiseException(DWORD exceptionCode, DWORD exceptionFlags,
                              DWORD numArguments, CONST ULONG_PTR *arrArgs);



// ----- helper functions : CRect, CSize, CPoint -----

BRXEXPORT int   MulDiv        (int nNumber, int nNumerator, int nDenominator);

BRXEXPORT BOOL  CopyRect      (LPRECT pDst, CONST RECT *pSrc);
BRXEXPORT BOOL  EqualRect     (CONST RECT *pRect1, CONST RECT *pRect2);
BRXEXPORT BOOL  InflateRect   (LPRECT pRect, int dx, int dy);
BRXEXPORT BOOL  IntersectRect (LPRECT pDst, CONST RECT *pSrc1, CONST RECT *pSrc2);
BRXEXPORT BOOL  IsRectEmpty   (CONST RECT * pRect);
BRXEXPORT BOOL  OffsetRect    (LPRECT pRect, int dx, int dy);
BRXEXPORT BOOL  PtInRect      (CONST RECT * pRect, POINT pt);
BRXEXPORT BOOL  SetRect       (LPRECT pRect, int left, int top, int right, int bottom);
BRXEXPORT BOOL  SetRectEmpty  (LPRECT pRect);
BRXEXPORT BOOL  SubtractRect  (LPRECT pRect, CONST RECT * pFrom, CONST RECT * pSub);
BRXEXPORT BOOL  UnionRect     (LPRECT pRect, CONST RECT * pSrc1, CONST RECT * pSrc2);


// ----- Timer functions -----

#ifndef WM_TIMER
#define WM_TIMER 0x00000113L
#endif

typedef VOID (CALLBACK * TIMERPROC) (HWND hWnd, UINT msg, UINT_PTR timerId, DWORD dwTime);

BRXEXPORT UINT   SetTimer  (HWND hWnd, UINT_PTR timerId, UINT nElapse, TIMERPROC timerProc);
BRXEXPORT BOOL   KillTimer (HWND hWnd, UINT_PTR timerId);

BRXEXPORT BOOL   QueryPerformanceCounter (LARGE_INTEGER *lpPerformanceCount);


#endif // !_WIN32

#endif // _BS_WINSDK_INCLUDED_
