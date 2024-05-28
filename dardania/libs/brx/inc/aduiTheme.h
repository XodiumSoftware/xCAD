// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#if defined(_AFXEXT) && defined(__cplusplus)
  #if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
    #undef _DEBUG
    #include <afxtempl.h>
    #define _DEBUG
  #else
    #include <afxtempl.h>
  #endif
#endif

#include "brx_importexport.h"  // BRX_IMPORTEXPORT

#include "MFC/CAdUi/CAdUiTheme.h"
#include "Misc/MiscGlobal.h"
