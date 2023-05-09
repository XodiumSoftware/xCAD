// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// COM error definitions

#pragma once

#ifndef _BS_COM_ERRORS_INCLUDED_
#define _BS_COM_ERRORS_INCLUDED_

#include "com_defs.h"

// own error flag for all platforms
#define E_NOTSUPPORTED   ((HRESULT)0x8000FFFEL)

#ifndef _WIN32  // on Linux/Mac

  // ----- COM Error Functions and Handlers -----

  #define SUCCEEDED(hr)               ((HRESULT)(hr) == 0)
  #define FAILED(hr)                  ((HRESULT)(hr) != 0)
  #define IS_ERROR(Status)            ((unsigned long)(Status) >> 31 == SEVERITY_ERROR)
  #define HRESULT_CODE(hr)            ((hr) & 0xFFFF)
  #define SCODE_CODE(sc)              ((sc) & 0xFFFF)
  #define HRESULT_FACILITY(hr)        (((hr) >> 16) & 0x1fff)
  #define SCODE_FACILITY(sc)          (((sc) >> 16) & 0x1fff)
  #define HRESULT_SEVERITY(hr)        (((hr) >> 31) & 0x1)
  #define SCODE_SEVERITY(sc)          (((sc) >> 31) & 0x1)

  #define MAKE_HRESULT(sev,fac,code) \
                                      ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )
  #define MAKE_SCODE(sev,fac,code) \
                                      ((SCODE) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )

  // Define the facility codes
  #define FACILITY_NULL                0
  #define FACILITY_RPC                 1
  #define FACILITY_DISPATCH            2
  #define FACILITY_STORAGE             3
  #define FACILITY_ITF                 4
  #define FACILITY_WIN32               7
  #define FACILITY_WINDOWS             8
  #define FACILITY_SSPI                9
  #define FACILITY_SECURITY            9
  #define FACILITY_CONTROL            10
  #define FACILITY_CERT               11
  #define FACILITY_INTERNET           12
  #define FACILITY_MEDIASERVER        13
  #define FACILITY_MSMQ               14
  #define FACILITY_SETUPAPI           15
  #define FACILITY_SCARD              16
  #define FACILITY_COMPLUS            17
  #define FACILITY_AAF                18
  #define FACILITY_URT                19
  #define FACILITY_ACS                20
  #define FACILITY_DPLAY              21
  #define FACILITY_UMI                22
  #define FACILITY_SXS                23
  #define FACILITY_WINDOWS_CE         24
  #define FACILITY_HTTP               25
  #define FACILITY_BACKGROUNDCOPY     32
  #define FACILITY_CONFIGURATION      33
  #define FACILITY_STATE_MANAGEMENT   34
  #define FACILITY_METADIRECTORY      35
  #define FACILITY_WINDOWSUPDATE      36
  #define FACILITY_DIRECTORYSERVICE   37
  #define FACILITY_NT_BIT             0x10000000

  #define __HRESULT_FROM_WIN32(x)   ((HRESULT)(x) <= 0 ? ((HRESULT)(x)) : ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)))
  #define HRESULT_FROM_WIN32(x)     __HRESULT_FROM_WIN32(x)

  #define HRESULT_FROM_NT(x)                   ((HRESULT) ((x) | FACILITY_NT_BIT))
  #define GetScode(hr)                         ((SCODE) (hr))
  #define ResultFromScode(sc)                  ((HRESULT) (sc))
  #define PropagateResult(hrPrevious, scBase)  ((HRESULT) scBase)
  #define _HRESULT_TYPEDEF_(x)      ((HRESULT)(x))


  // ----- COM Error Codes -----

  #define SEVERITY_SUCCESS                 0
  #define SEVERITY_ERROR                   1

  #define ERROR_SUCCESS                    0L
  #define NO_ERROR                         0L
  #define NOERROR                          0
  #define S_OK                             ((HRESULT)0x00000000L)
  #define S_FALSE                          ((HRESULT)0x00000001L)
  #define SEC_E_OK                         ((HRESULT)0x00000000L)

  #define ERROR_INVALID_FUNCTION           1L
  #define ERROR_FILE_NOT_FOUND             2L
  #define ERROR_PATH_NOT_FOUND             3L
  #define ERROR_TOO_MANY_OPEN_FILES        4L
  #define ERROR_ACCESS_DENIED              5L
  #define ERROR_INVALID_HANDLE             6L
  #define ERROR_ARENA_TRASHED              7L
  #define ERROR_NOT_ENOUGH_MEMORY          8L
  #define ERROR_INVALID_BLOCK              9L
  #define ERROR_BAD_ENVIRONMENT            10L
  #define ERROR_BAD_FORMAT                 11L
  #define ERROR_INVALID_ACCESS             12L
  #define ERROR_INVALID_DATA               13L
  #define ERROR_OUTOFMEMORY                14L
  #define ERROR_INVALID_DRIVE              15L
  #define ERROR_CURRENT_DIRECTORY          16L
  #define ERROR_CURRENT_DIRECTORY          16L
  #define ERROR_NOT_SAME_DEVICE            17L
  #define ERROR_NO_MORE_FILES              18L
  #define ERROR_WRITE_PROTECT              19L
  #define ERROR_BAD_UNIT                   20L
  #define ERROR_NOT_READY                  21L
  #define ERROR_BAD_COMMAND                22L
  #define ERROR_CRC                        23L
  #define ERROR_BAD_LENGTH                 24L
  #define ERROR_SEEK                       25L
  #define ERROR_NOT_DOS_DISK               26L
  #define ERROR_SECTOR_NOT_FOUND           27L
  #define ERROR_OUT_OF_PAPER               28L
  #define ERROR_WRITE_FAULT                29L
  #define ERROR_READ_FAULT                 30L
  #define ERROR_GEN_FAILURE                31L
  #define ERROR_SHARING_VIOLATION          32L
  #define ERROR_LOCK_VIOLATION             33L
  #define ERROR_WRONG_DISK                 34L
  #define ERROR_SHARING_BUFFER_EXCEEDED    36L
  #define ERROR_HANDLE_EOF                 38L
  #define ERROR_HANDLE_DISK_FULL           39L
  #define ERROR_NOT_SUPPORTED              50L
  #define ERROR_REM_NOT_LIST               51L
  #define ERROR_DUP_NAME                   52L
  #define ERROR_BAD_NETPATH                53L
  #define ERROR_NETWORK_BUSY               54L
  #define ERROR_DEV_NOT_EXIST              55L
  #define ERROR_TOO_MANY_CMDS              56L
  #define ERROR_ADAP_HDW_ERR               57L
  #define ERROR_BAD_NET_RESP               58L
  #define ERROR_UNEXP_NET_ERR              59L
  #define ERROR_BAD_REM_ADAP               60L
  #define ERROR_PRINTQ_FULL                61L
  #define ERROR_NO_SPOOL_SPACE             62L
  #define ERROR_PRINT_CANCELLED            63L
  #define ERROR_NETNAME_DELETED            64L
  #define ERROR_NETWORK_ACCESS_DENIED      65L
  #define ERROR_BAD_DEV_TYPE               66L
  #define ERROR_BAD_NET_NAME               67L
  #define ERROR_TOO_MANY_NAMES             68L
  #define ERROR_TOO_MANY_SESS              69L
  #define ERROR_SHARING_PAUSED             70L
  #define ERROR_REQ_NOT_ACCEP              71L

  #define E_UNEXPECTED                     ((HRESULT)0x8000FFFFL)
  #define E_NOTIMPL                        ((HRESULT)0x80000001L)
  #define E_OUTOFMEMORY                    ((HRESULT)0x80000002L)
  #define E_INVALIDARG                     ((HRESULT)0x80000003L)
  #define E_NOINTERFACE                    ((HRESULT)0x80000004L)
  #define E_POINTER                        ((HRESULT)0x80000005L)
  #define E_HANDLE                         ((HRESULT)0x80000006L)
  #define E_ABORT                          ((HRESULT)0x80000007L)
  #define E_FAIL                           ((HRESULT)0x80000008L)
  #define E_ACCESSDENIED                   ((HRESULT)0x80000009L)
  #define E_PENDING                        ((HRESULT)0x8000000AL)

  #define DISP_E_UNKNOWNINTERFACE          ((HRESULT)0x80020001L)
  #define DISP_E_MEMBERNOTFOUND            ((HRESULT)0x80020003L)
  #define DISP_E_PARAMNOTFOUND             ((HRESULT)0x80020004L)
  #define DISP_E_TYPEMISMATCH              ((HRESULT)0x80020005L)
  #define DISP_E_UNKNOWNNAME               ((HRESULT)0x80020006L)
  #define DISP_E_NONAMEDARGS               ((HRESULT)0x80020007L)
  #define DISP_E_BADVARTYPE                ((HRESULT)0x80020008L)
  #define DISP_E_EXCEPTION                 ((HRESULT)0x80020009L)
  #define DISP_E_OVERFLOW                  ((HRESULT)0x8002000AL)
  #define DISP_E_BADINDEX                  ((HRESULT)0x8002000BL)
  #define DISP_E_UNKNOWNLCID               ((HRESULT)0x8002000CL)
  #define DISP_E_ARRAYISLOCKED             ((HRESULT)0x8002000DL)
  #define DISP_E_BADPARAMCOUNT             ((HRESULT)0x8002000EL)
  #define DISP_E_PARAMNOTOPTIONAL          ((HRESULT)0x8002000FL)
  #define DISP_E_BADCALLEE                 ((HRESULT)0x80020010L)
  #define DISP_E_NOTACOLLECTION            ((HRESULT)0x80020011L)
  #define DISP_E_DIVBYZERO                 ((HRESULT)0x80020012L)
  #define DISP_E_BUFFERTOOSMALL            ((HRESULT)0x80020013L)

  #define TYPE_E_BUFFERTOOSMALL            ((HRESULT)0x80028016L)
  #define TYPE_E_FIELDNOTFOUND             ((HRESULT)0x80028017L)
  #define TYPE_E_INVDATAREAD               ((HRESULT)0x80028018L)
  #define TYPE_E_UNSUPFORMAT               ((HRESULT)0x80028019L)
  #define TYPE_E_REGISTRYACCESS            ((HRESULT)0x8002801CL)
  #define TYPE_E_LIBNOTREGISTERED          ((HRESULT)0x8002801DL)
  #define TYPE_E_UNDEFINEDTYPE             ((HRESULT)0x80028027L)
  #define TYPE_E_QUALIFIEDNAMEDISALLOWED   ((HRESULT)0x80028028L)
  #define TYPE_E_INVALIDSTATE              ((HRESULT)0x80028029L)
  #define TYPE_E_WRONGTYPEKIND             ((HRESULT)0x8002802AL)
  #define TYPE_E_ELEMENTNOTFOUND           ((HRESULT)0x8002802BL)
  #define TYPE_E_AMBIGUOUSNAME             ((HRESULT)0x8002802CL)
  #define TYPE_E_NAMECONFLICT              ((HRESULT)0x8002802DL)
  #define TYPE_E_UNKNOWNLCID               ((HRESULT)0x8002802EL)
  #define TYPE_E_DLLFUNCTIONNOTFOUND       ((HRESULT)0x8002802FL)
  #define TYPE_E_BADMODULEKIND             ((HRESULT)0x800288BDL)
  #define TYPE_E_SIZETOOBIG                ((HRESULT)0x800288C5L)
  #define TYPE_E_DUPLICATEID               ((HRESULT)0x800288C6L)
  #define TYPE_E_INVALIDID                 ((HRESULT)0x800288CFL)
  #define TYPE_E_TYPEMISMATCH              ((HRESULT)0x80028CA0L)
  #define TYPE_E_OUTOFBOUNDS               ((HRESULT)0x80028CA1L)
  #define TYPE_E_IOERROR                   ((HRESULT)0x80028CA2L)
  #define TYPE_E_CANTCREATETMPFILE         ((HRESULT)0x80028CA3L)
  #define TYPE_E_CANTLOADLIBRARY           ((HRESULT)0x80029C4AL)
  #define TYPE_E_INCONSISTENTPROPFUNCS     ((HRESULT)0x80029C83L)
  #define TYPE_E_CIRCULARTYPE              ((HRESULT)0x80029C84L)


#endif // !_WIN32

#endif // _BS_COM_ERRORS_INCLUDED_
