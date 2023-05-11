// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

// Property of Bricsys NV. All rights reserved.
// This file is part of the source code of Bricsys NV. The source code
// is subject to copyright, is a trade secret of Bricsys NV, and contains
// embodiments of inventions disclosed in patent applications and patents
// of Bricsys NV.

/////////////////////////////////////////////////////////////////////////

#pragma once

//-----------------------------------------------------------------------------
//- 'DEBUG workaround' below prevents the MFC or ATL #include-s from pulling
//- in "Afx.h" that would force the debug CRT through #pragma-s.
#if defined(_WIN32) && defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#define NDEBUG
#pragma message ("     Compiling MFC / STL / ATL header files in release mode.")
#endif
//-----------------------------------------------------------------------------

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:

#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>

#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <set>

#ifndef _INC_LEAGACY_HEADERS_ 
#define _INC_LEAGACY_HEADERS_ 
#endif // !_INC_LEAGACY_HEADERS_ 
#include "arxHeaders.h"

#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbObjectPointer.h"
#include "AcDb/AcDbTable.h"
#include "acarray.h"

#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"

#include "BrxSpecific/AcComponents.h"
#include "BrxSpecific/AcComponentCustomProperties.h"
#include "BrxSpecific/AcBillOfMaterials.h"


//-----------------------------------------------------------------------------
#ifdef _DEBUG_WAS_DEFINED
#undef NDEBUG
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif
//-----------------------------------------------------------------------------

#include "brx_version.h"

#if (__BRXVER < 23)
    #error "This sample requires BricsCAD/BRX V23"
#endif
