// Copyright (C) 2006-2014 Menhirs NV. All rights reserved.
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