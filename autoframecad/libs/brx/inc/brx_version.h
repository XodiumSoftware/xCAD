// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

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
  #undef __BRX_32BIT       // if yet defined elsewhere
  #undef __BRX_64BIT       // if yet defined elsewhere
  #undef __BRX21_32BIT     // if yet defined elsewhere
  #undef __BRX21_64BIT     // if yet defined elsewhere
  #undef __BRX22_32BIT     // if yet defined elsewhere
  #undef __BRX22_64BIT     // if yet defined elsewhere
  #undef __BRX23_32BIT     // if yet defined elsewhere
  #undef __BRX23_64BIT     // if yet defined elsewhere
  #undef __BRX24_32BIT     // if yet defined elsewhere
  #undef __BRX24_64BIT     // if yet defined elsewhere
  
  #define __BRX
  #define __BRX24
  #define __BRXVER         24

  #ifdef __SYS_64_BIT__
    #define __BRX_64BIT
    #define __BRX24_64BIT
  #else //!__SYS_64_BIT__
    #define __BRX_32BIT
    #define __BRX24_32BIT
  #endif

#endif // BRX_VERSION_INCLUDED
