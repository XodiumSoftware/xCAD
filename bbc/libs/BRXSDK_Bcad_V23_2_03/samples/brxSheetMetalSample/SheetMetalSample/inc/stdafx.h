// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

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

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:

#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>

#include <algorithm>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <tuple>

#ifndef _INC_LEAGACY_HEADERS_ 
#define _INC_LEAGACY_HEADERS_ 
#endif // !_INC_LEAGACY_HEADERS_ 
#include "arxHeaders.h"

#include "AcBrBrep.h"
#include "AcBrEdge.h"
#include "AcBrFace.h"
#include "AcBrFaceLoopTraverser.h"
#include "AcBrLoopEdgeTraverser.h"

#include "AcDb/AcDbObjectPointer.h"

#include "Misc/MiscGlobal.h"

#include "BrxSpecific/sheetmetal/SheetMetal.h"
#include "BrxSpecific/sheetmetal/SheetMetalOperations.h"

//-----------------------------------------------------------------------------
#ifdef _DEBUG_WAS_DEFINED
#undef NDEBUG
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif
//-----------------------------------------------------------------------------
