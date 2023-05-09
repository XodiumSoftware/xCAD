// Copyright (C) Menhirs NV. All rights reserved.

// this header provides following features :
// it defines a number of useful macros, to manage multi-platform/version/architecture builds

#pragma once

#ifndef BRX_VERSION_INCLUDED
#define BRX_VERSION_INCLUDED

  // ========== for Windows, Linux, Mac =========

  #include "sys_version.h"

  // these predefined symbols should help developers to recognise build version and
  // architecture by simply using BRX SDK (this file is automatically included);
  // eliminates the need to define own symbols for all build configurations

  #undef __BRX             // if yet defined elsewhere
  #undef __BRXVER          // if yet defined elsewhere
  #undef __BRX13           // if yet defined elsewhere
  #undef __BRX14           // if yet defined elsewhere
  #undef __BRX15           // if yet defined elsewhere
  #undef __BRX16           // if yet defined elsewhere
  #undef __BRX_32BIT       // if yet defined elsewhere
  #undef __BRX_64BIT       // if yet defined elsewhere
  #undef __BRX13_32BIT     // if yet defined elsewhere
  #undef __BRX13_64BIT     // if yet defined elsewhere
  #undef __BRX14_32BIT     // if yet defined elsewhere
  #undef __BRX14_64BIT     // if yet defined elsewhere
  #undef __BRX15_32BIT     // if yet defined elsewhere
  #undef __BRX15_64BIT     // if yet defined elsewhere
  #undef __BRX16_32BIT     // if yet defined elsewhere
  #undef __BRX16_64BIT     // if yet defined elsewhere
  #undef __BRX17_32BIT     // if yet defined elsewhere
  #undef __BRX17_64BIT     // if yet defined elsewhere
  #undef __BRX18_32BIT     // if yet defined elsewhere
  #undef __BRX18_64BIT     // if yet defined elsewhere
  #undef __BRX19_32BIT     // if yet defined elsewhere
  #undef __BRX19_64BIT     // if yet defined elsewhere
  #undef __BRX20_32BIT     // if yet defined elsewhere
  #undef __BRX20_64BIT     // if yet defined elsewhere
  #undef __BRX21_32BIT     // if yet defined elsewhere
  #undef __BRX21_64BIT     // if yet defined elsewhere
  #undef __BRX22_32BIT     // if yet defined elsewhere
  #undef __BRX22_64BIT     // if yet defined elsewhere
  #undef __BRX23_32BIT     // if yet defined elsewhere
  #undef __BRX23_64BIT     // if yet defined elsewhere
  
  #define __BRX
  #define __BRX23
  #define __BRXVER         23

  #ifdef __SYS_64_BIT__
    #define __BRX_64BIT
    #define __BRX23_64BIT
  #else //!__SYS_64_BIT__
    #define __BRX_32BIT
    #define __BRX23_32BIT
  #endif

#endif // BRX_VERSION_INCLUDED
