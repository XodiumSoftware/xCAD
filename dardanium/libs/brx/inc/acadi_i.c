// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_importexport.h"  // BRX_IMPORTEXPORT
#include "brx_platform_3264.h" // 32/64 bit platform detection

#ifndef BRX_COM_C_FILES_INCLUDED
#define BRX_COM_C_FILES_INCLUDED

  #ifdef _WIN32 // only on 32/64 bit Windows
    #include "ax_bricscaddb_i.c"
    #include "ax_bricscadapp_i.c"
  #endif // _WIN32

#endif