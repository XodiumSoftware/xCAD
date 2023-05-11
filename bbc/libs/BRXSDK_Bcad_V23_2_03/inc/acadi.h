// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_importexport.h"  // BRX_IMPORTEXPORT
#include "brx_platform_3264.h" // 32/64 bit platform detection

#ifndef BRX_COM_H_FILES_INCLUDED
#define BRX_COM_H_FILES_INCLUDED

  #if !defined(__ax_bricscaddb_h__) || !defined(__ax_bricscaddb_h__)
    #include "PropertyPalette/COMWrapperBegin.h"
    #include "ax_bricscaddb.h"   // defines __ax_bricscaddb_h__
    #include "ax_bricscadapp.h"  // defines __ax_bricscaddb_h__
    #include "PropertyPalette/COMWrapperEnd.h"
  #endif // !__ax_bricscaddb_h__ || !__ax_bricscaddb_h__

#endif // BRX_COM_H_FILES_INCLUDED