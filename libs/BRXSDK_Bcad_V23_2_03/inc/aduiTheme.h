// Copyright (C) Menhirs NV. All rights reserved.
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
