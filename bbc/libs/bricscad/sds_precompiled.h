// sds_precompiled.h : precompiled header for sds project
//
// Copyright © Menhirs NV. All rights reserved.
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
#ifndef	SDS_PRECOMPILED_H_
#define	SDS_PRECOMPILED_H_


#ifndef STRICT
#define STRICT 1
#endif


#ifdef _WIN32  // for Windows
  #define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

  #pragma warning(disable : 4786)
  #pragma warning(disable : 4018) // signed/unsigned mismatch for <vector>

  #define _CRTDBG_MAP_ALLOC
  #include <crtdbg.h>
  // when '_CRTDBG_MAP_ALLOC' is defined, DD defines 'NOMINMAX', so 'min' and 'max' macros are not defined in windef.h
  #include <minmax.h>

  #include <afxwin.h>
  #include <afxole.h>
#endif // _WIN32

#include "ut_platform.h"

// 'free' identifier is often used as method or function name
#undef free

#include "wx/intl.h"

#include "OdaCommon.h"
#include "OdString.h"

#include "oa_app.h"
#include "oa_db_ex.h"
#include "oa_transform.h"
#include "oa_ge_sds.h"
#include "oa_sys_vars.h"
#include "Entities.h"
#define STL_USING_ALL
#include "OdaSTL.h"

#include "ca_def.h"
#include "ca_printf.h"
#include "ut_def.h"
#include "ut_string_ops.h"

#include "sds.h"
#include "sds_helper.h"

#endif // SDS_PRECOMPILED_H_
