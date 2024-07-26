// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// Windows Registry types and functions

#ifndef _BS_WINREGISTRY_INCLUDED_
#define _BS_WINREGISTRY_INCLUDED_


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32 // on Linux/Mac

  #include "Platform/win/winsdk.h"  // FILETIME and related

  // structures + types

  typedef HANDLE  HKEY;
  typedef HKEY*   PHKEY;

  typedef DWORD        ACCESS_MASK;
  typedef ACCESS_MASK  REGSAM;

  // flags

  #define DELETE                    (0x00010000L)
  #define READ_CONTROL              (0x00020000L)
  #define SYNCHRONIZE               (0x00100000L)

  #define STANDARD_RIGHTS_READ      (READ_CONTROL)
  #define STANDARD_RIGHTS_WRITE     (READ_CONTROL)
  #define STANDARD_RIGHTS_EXECUTE   (READ_CONTROL)
  #define STANDARD_RIGHTS_REQUIRED  (0x000F0000L)
  #define STANDARD_RIGHTS_ALL       (0x001F0000L)
  #define SPECIFIC_RIGHTS_ALL       (0x0000FFFFL)

  #define KEY_QUERY_VALUE           (0x00000001L)
  #define KEY_SET_VALUE             (0x00000002L)
  #define KEY_CREATE_SUB_KEY        (0x00000004L)
  #define KEY_ENUMERATE_SUB_KEYS    (0x00000008L)
  #define KEY_NOTIFY                (0x00000010L)
  #define KEY_CREATE_LINK           (0x00000020L)
  #define KEY_WOW64_32KEY           (0x00000200L)
  #define KEY_WOW64_64KEY           (0x00000100L)
  #define KEY_WOW64_RES             (0x00000300L)

  #define KEY_READ        ( (STANDARD_RIGHTS_READ    \
                           | KEY_QUERY_VALUE         \
                           | KEY_ENUMERATE_SUB_KEYS  \
                           | KEY_NOTIFY)             \
                           & (~SYNCHRONIZE))
  #define KEY_EXECUTE     KEY_READ

  #define KEY_WRITE       ( (STANDARD_RIGHTS_WRITE   \
                           | KEY_SET_VALUE           \
                           | KEY_CREATE_SUB_KEY)     \
                           & (~SYNCHRONIZE))

  #define KEY_ALL_ACCESS  ( (STANDARD_RIGHTS_ALL     \
                           | KEY_QUERY_VALUE         \
                           | KEY_SET_VALUE           \
                           | KEY_CREATE_SUB_KEY      \
                           | KEY_ENUMERATE_SUB_KEYS  \
                           | KEY_NOTIFY              \
                           | KEY_CREATE_LINK)        \
                           & (~SYNCHRONIZE))


  #define REG_OPTION_RESERVED        (0x00000000L)
  #define REG_OPTION_NON_VOLATILE    (0x00000000L)
  #define REG_OPTION_VOLATILE        (0x00000001L)
  #define REG_OPTION_CREATE_LINK     (0x00000002L)
  #define REG_OPTION_BACKUP_RESTORE  (0x00000004L)
  #define REG_OPTION_OPEN_LINK       (0x00000008L)

  #define REG_LEGAL_OPTION  (  REG_OPTION_RESERVED       \
                             | REG_OPTION_NON_VOLATILE   \
                             | REG_OPTION_VOLATILE       \
                             | REG_OPTION_CREATE_LINK    \
                             | REG_OPTION_BACKUP_RESTORE \
                             | REG_OPTION_OPEN_LINK)


  // predefined values

  #define REG_NONE                        ( 0)
  #define REG_SZ                          ( 1)
  #define REG_EXPAND_SZ                   ( 2)
  #define REG_BINARY                      ( 3)
  #define REG_DWORD                       ( 4)
  #define REG_DWORD_LITTLE_ENDIAN         ( 4)
  #define REG_DWORD_BIG_ENDIAN            ( 5)
  #define REG_LINK                        ( 6)
  #define REG_MULTI_SZ                    ( 7)
  #define REG_RESOURCE_LIST               ( 8)
  #define REG_FULL_RESOURCE_DESCRIPTOR    ( 9)
  #define REG_RESOURCE_REQUIREMENTS_LIST  (10)
  #define REG_QWORD                       (11)
  #define REG_QWORD_LITTLE_ENDIAN         (11)

  #define REG_CREATED_NEW_KEY        (0x00000001L)
  #define REG_OPENED_EXISTING_KEY    (0x00000002L)

  #define REGDB_E_FIRST              (0x80040150L)
  #define REGDB_E_LAST               (0x8004015FL)
  #define REGDB_S_FIRST              (0x00040150L)
  #define REGDB_S_LAST               (0x0004015FL)

  // error codes
  #define REGDB_E_READREGDB          (0x80040150L)
  #define REGDB_E_WRITEREGDB         (0x80040151L)
  #define REGDB_E_KEYMISSING         (0x80040152L)
  #define REGDB_E_INVALIDVALUE       (0x80040153L)
  #define REGDB_E_CLASSNOTREG        (0x80040154L)
  #define REGDB_E_IIDNOTREG          (0x80040155L)
  #define REGDB_E_BADTHREADINGMODEL  (0x80040156L)

  // definitions

  #define HKEY_CLASSES_ROOT     ((HKEY)0x80000000L)
  #define HKEY_CURRENT_USER     ((HKEY)0x80000001L)
  #define HKEY_LOCAL_MACHINE    ((HKEY)0x80000002L)
  #define HKEY_USERS            ((HKEY)0x80000003L)
  #define HKEY_PERFORMANCE_DATA ((HKEY)0x80000004L)
  #define HKEY_CURRENT_CONFIG   ((HKEY)0x80000005L)
  #define HKEY_DYN_DATA         ((HKEY)0x80000006L)
  #define HKEY_PERFORMANCE_TEXT    ((HKEY)0x80000050L)
  #define HKEY_PERFORMANCE_NLSTEXT ((HKEY)0x80000060L)


  #define RegOpenKey       RegOpenKeyW
  #define RegOpenKeyEx     RegOpenKeyExW
  #define RegQueryInfoKey  RegQueryInfoKeyW
  #define RegQueryValue    RegQueryValueW
  #define RegQueryValueEx  RegQueryValueExW
  #define RegSetValue      RegSetValueW
  #define RegSetValueEx    RegSetValueExW
  #define RegCreateKey     RegCreateKeyW
  #define RegCreateKeyEx   RegCreateKeyExW
  #define RegDeleteValue   RegDeleteValueW
  #define RegDeleteKey     RegDeleteKeyW
  #define RegEnumKey       RegEnumKeyW
  #define RegEnumKeyEx     RegEnumKeyExW
  #define RegEnumValue     RegEnumValueW

  // functions

  BRXEXPORT LONG RegOpenKeyW      (HKEY hKey, LPCTSTR szSubKey, PHKEY pResult); //KEY_READ|KEY_WRITE

  BRXEXPORT LONG RegOpenKeyExW    (HKEY hKey, LPCTSTR szSubKey, DWORD options, REGSAM samFlags, PHKEY pResult);

  BRXEXPORT LONG RegCloseKey      (HKEY hKey);

  BRXEXPORT LONG RegQueryInfoKeyW (HKEY hKey,
                                   LPWSTR  szClass,
                                   LPDWORD pcchClass,
                                   LPDWORD pReserved,
                                   LPDWORD pcSubKeys,
                                   LPDWORD pcbMaxSubKeyLen,
                                   LPDWORD pcbMaxClassLen,
                                   LPDWORD pcValues,
                                   LPDWORD pcbMaxValueNameLen,
                                   LPDWORD pcbMaxValueLen,
                                   LPDWORD pcbSecurityDescriptor,
                                   PFILETIME lpftLastWriteTime);

  BRXEXPORT LONG RegQueryValueW   (HKEY hKey,
                                   LPCWSTR szSubKey,
                                   LPWSTR  pData,
                                   LPDWORD pcbData);

  BRXEXPORT LONG RegQueryValueExW (HKEY hKey,
                                   LPCWSTR szValueName,
                                   LPDWORD pReserved,
                                   LPDWORD pType,
                                   LPBYTE  pData,
                                   LPDWORD pcbData);

  BRXEXPORT LONG RegSetValueW     (HKEY hKey,
                                   LPCWSTR szSubKey,
                                   DWORD dwType,
                                   LPCWSTR pData,
                                   DWORD cbData);

  BRXEXPORT LONG RegSetValueExW   (HKEY hKey,
                                   LPCWSTR szValueName,
                                   DWORD reserved,
                                   DWORD dwType,
                                   CONST BYTE* pData,
                                   DWORD cbData);

  BRXEXPORT LONG RegCreateKeyW    (HKEY hKey, LPCWSTR szSubKey, PHKEY pResult);

  BRXEXPORT LONG RegCreateKeyExW  (HKEY hKey,
                                   LPCWSTR szSubKey,
                                   DWORD reserved,
                                   LPWSTR pClass,
                                   DWORD dwOptions,
                                   REGSAM samFlags,
                                   LPSECURITY_ATTRIBUTES pSecurityAttributes,
                                   PHKEY pResult,
                                   LPDWORD pDisposition);

  BRXEXPORT LONG RegDeleteValueW  (HKEY hKey, LPCWSTR szValueName);
  BRXEXPORT LONG RegDeleteKeyW    (HKEY hKey, LPCWSTR szSubKey);

  BRXEXPORT LONG RegEnumKeyW      (HKEY hKey,
                                   DWORD dwIndex,
                                   LPWSTR szName,
                                   DWORD cchName);

  BRXEXPORT LONG RegEnumKeyExW    (HKEY hKey,
                                   DWORD dwIndex,
                                   LPWSTR szName,
                                   LPDWORD pcchName,
                                   LPDWORD pReserved,
                                   LPWSTR szClass,
                                   LPDWORD pcchClass,
                                   PFILETIME pftLastWriteTime);

  BRXEXPORT LONG RegEnumValueW    (HKEY hKey,
                                   DWORD dwIndex,
                                   LPWSTR szValueName,
                                   LPDWORD pcchValueName,
                                   LPDWORD pReserved,
                                   LPDWORD pType,
                                   LPBYTE pData,
                                   LPDWORD pcbData);


#endif // !_WIN32


#endif // _BS_WINREGISTRY_INCLUDED_
