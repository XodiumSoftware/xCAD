// Copyright (C) 2006-2014 Menhirs NV. All rights reserved.

// API logging / tracing features

#pragma once

// logging mode flags; can be combined; 0 means ALL

#define LOG_NONE          0x00000000
//-----------------------------
#define LOG_ACAP          0x00000001
#define LOG_ACAX          0x00000002
#define LOG_ACCM          0x00000004
#define LOG_ACDB          0x00000008
#define LOG_ACED          0x00000010
#define LOG_ACGE          0x00000020
#define LOG_ACGI          0x00000040
#define LOG_ACGS          0x00000080
#define LOG_ACPL          0x00000100
#define LOG_ACRX          0x00000200
#define LOG_ACTR          0x00000400
#define LOG_MISC          0x00000800
#define LOG_OPM           0x00001000
#define LOG_MFC           0x00002000
#define LOG_ACBR          0x00004000
#define LOG_GLOBALFUNCS   0x00008000
#define LOG_UNDOCUMENTED  0x00010000
#define LOG_ACFD          0x00020000
#define LOG_ACLY          0x00040000
#define LOG_RIBBON        0x00080000
#define LOG_CONSTRAINTS   0x00100000
#define LOG_BIM           0x00200000
#define LOG_SM            0x00400000
#define LOG_DM            0x00800000
#define LOG_BCUI          0x01000000
#define LOG_PROMPT        0x08000000  // additionally echos log message to commandline prompt
//----- client mode flags -----
#define LOG_MODE_1        0x10000000  // client mode 1
#define LOG_MODE_2        0x20000000  // client mode 2
#define LOG_MODE_3        0x40000000  // client mode 3
#define LOG_MODE_4        0x80000000  // client mode 4
//-----------------------------
#define LOG_EVERYTHING    (0xFFFFFFFF & (~LOG_PROMPT)) // all except echo


// get / set logging mode
BRX_IMPORTEXPORT  unsigned long  brxLogMode ();
BRX_IMPORTEXPORT  void           brxLogMode (const unsigned long loggingMode);

// place a tracing message into log
BRX_IMPORTEXPORT  void           brxLogMsg  (LPCTSTR szMessage);

// switch logging on / off
BRX_IMPORTEXPORT  LPCTSTR        brxLogOn   (const unsigned long loggingMode = LOG_EVERYTHING);
BRX_IMPORTEXPORT  void           brxLogOff  ();

// simple macro to be placed in client code
// 'mode' can be any combination of LOG_xxx modes, especially LOG_MODE_1 - LOG_MODE_4
#define BRX_LOG_FUNCTION(mode)   brxLog(_T(__FUNCSIG__), mode, NULL, NULL);
