// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COleDispatchDriver class and related functionality

#ifndef _BS_COM_COLEDISPATCHDRIVER_INCLUDED_
#define _BS_COM_COLEDISPATCHDRIVER_INCLUDED_

#include "com_defs.h"


#ifndef _WIN32  // on Linux/Mac

  // ----- VTS SYMBOLS (afxdisp.h) - for COleDispatchDriver
  // parameter types: by value
  #define VTS_I2          "\x02"     // 'short'
  #define VTS_I4          "\x03"     // 'long'
  #define VTS_R4          "\x04"     // 'float'
  #define VTS_R8          "\x05"     // 'double'
  #define VTS_CY          "\x06"     // 'CY' or 'CY*'
  #define VTS_DATE        "\x07"     // 'DATE'
  #define VTS_WBSTR       "\x08"     // 'LPCOLESTR'
  #define VTS_DISPATCH    "\x09"     // 'IDispatch*'
  #define VTS_SCODE       "\x0A"     // 'SCODE'
  #define VTS_BOOL        "\x0B"     // 'VARIANT_BOOL'
  #define VTS_VARIANT     "\x0C"     // 'const VARIANT&' or 'VARIANT*'
  #define VTS_UNKNOWN     "\x0D"     // 'IUnknown*'
  #define VTS_BSTR        VTS_WBSTR  // 'LPCOLESTR'
  #define VT_BSTRT        VT_BSTR
  #define VTS_I1          "\x10"     // 'signed char'
  #define VTS_UI1         "\x11"     // 'BYTE'
  #define VTS_UI2         "\x12"     // 'WORD'
  #define VTS_UI4         "\x13"     // 'DWORD'
  #define VTS_I8          "\x14"     // 'LONGLONG'
  #define VTS_UI8         "\x15"     // 'ULONGLONG'
  // parameter types: by reference
  #define VTS_PI2         "\x42"     // 'short*'
  #define VTS_PI4         "\x43"     // 'long*'
  #define VTS_PR4         "\x44"     // 'float*'
  #define VTS_PR8         "\x45"     // 'double*'
  #define VTS_PCY         "\x46"     // 'CY*'
  #define VTS_PDATE       "\x47"     // 'DATE*'
  #define VTS_PBSTR       "\x48"     // 'BSTR*'
  #define VTS_PDISPATCH   "\x49"     // 'IDispatch**'
  #define VTS_PSCODE      "\x4A"     // 'SCODE*'
  #define VTS_PBOOL       "\x4B"     // 'VARIANT_BOOL*'
  #define VTS_PVARIANT    "\x4C"     // 'VARIANT*'
  #define VTS_PUNKNOWN    "\x4D"     // 'IUnknown**'
  #define VTS_PI1         "\x50"     // 'signed char*'
  #define VTS_PUI1        "\x51"     // 'BYTE*'
  #define VTS_PUI2        "\x52"     // 'WORD*'
  #define VTS_PUI4        "\x53"     // 'DWORD*'
  #define VTS_PI8         "\x54"     // 'LONGLONG*'
  #define VTS_PUI8        "\x55"     // 'ULONGLONG*'
  // special VT_ and VTS_ values
  #define VTS_NONE        NULL       // used for members with 0 params
  #define VT_MFCVALUE     0xFFF      // special value for DISPID_VALUE
  #define VT_MFCBYREF     0x40       // indicates VT_BYREF type
  #define VT_MFCMARKER    0xFF       // delimits named parameters (INTERNAL USE)



#endif // !_WIN32

#endif // _BS_COM_COLEDISPATCHDRIVER_INCLUDED_
