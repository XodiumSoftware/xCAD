// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// BSTR string and related functionality

#pragma once

#ifndef _BS_COM_BSTR_INCLUDED_
#define _BS_COM_BSTR_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32  // on Linux/Mac

  BRXEXPORT BSTR  SysAllocString       (const OLECHAR * str);
  BRXEXPORT BSTR  SysAllocStringLen    (const OLECHAR * str, UINT len);
  BRXEXPORT BSTR  SysAllocStringByteLen(LPCSTR str, UINT len);
  BRXEXPORT INT   SysReAllocString     (BSTR * pbstr, const OLECHAR * str);
  BRXEXPORT INT   SysReAllocStringLen  (BSTR * pbstr, const OLECHAR * str, UINT len);
  BRXEXPORT UINT  SysStringLen         (BSTR str);
  BRXEXPORT UINT  SysStringByteLen     (BSTR str);
  BRXEXPORT void  SysFreeString        (BSTR str);

#endif // _WIN32

#endif // _BS_COM_BSTR_INCLUDED_
