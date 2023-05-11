// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#pragma pack (push, 8)

#ifdef _BCAD
#include <tchar.h>
#include <vcclr.h>
#include "dbxHeaders.h"


#using <brxmgd.dll>
#using <td_mgd.dll>
#pragma comment(lib ,"BrxMgd.lib")

#else
#include <windows.h>
#include <tchar.h>
#include <vcclr.h>
#using <System.Core.dll>
#using <acdbmgd.dll>
#include "dbxHeaders.h"
#endif

#pragma pack (pop)
