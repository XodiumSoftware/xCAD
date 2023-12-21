// License to copy and modify this file for usage in conjunction
// with Autodesk ARX API is explicitely expressed here, as long as the
// copyright statement remains unchanged !
// Please copy this file to your Autodesk ARX API or project folder(s).

// this header profides following features :
// it defines a number of useful macros, to manage multi-platform/version/architecture builds

#pragma once

#ifndef ARX_VERSION_INCLUDED
#define ARX_VERSION_INCLUDED

  #include "sys_version.h"

  // ========== for Windows, Mac =========

  #if defined(BRX_APP) || defined(__BRXTARGET) || defined(_BRICSCAD)
    #pragma message ("      You must not have 'BRX_APP' or '__BRXTARGET' or '_BRICSCAD' macro defined for ARX builds !")
  #endif

  // these predefined symbols should help developers to recognise build version and
  // architecture by simply using ARX SDK (this file must be included in client code !);
  // elimitaes the need to define own symbols for all build configurations

  #undef __ARX             // if yet defined elsewhere
  #undef __ARXVER          // if yet defined elsewhere
  #undef __ARX_32BIT       // if yet defined elsewhere
  #undef __ARX_64BIT       // if yet defined elsewhere
  #undef __ARX2000         // if yet defined elsewhere
  #undef __ARX2004         // if yet defined elsewhere
  #undef __ARX2007         // if yet defined elsewhere
  #undef __ARX2007_32BIT   // if yet defined elsewhere
  #undef __ARX2007_64BIT   // if yet defined elsewhere
  #undef __ARX2010         // if yet defined elsewhere
  #undef __ARX2010_32BIT   // if yet defined elsewhere
  #undef __ARX2010_64BIT   // if yet defined elsewhere
  #undef __ARX2013         // if yet defined elsewhere
  #undef __ARX2013_32BIT   // if yet defined elsewhere
  #undef __ARX2013_64BIT   // if yet defined elsewhere
  #undef __ARX2015         // if yet defined elsewhere
  #undef __ARX2015_32BIT   // if yet defined elsewhere
  #undef __ARX2015_64BIT   // if yet defined elsewhere

  #define __ARX

  #if (_MSC_VER >= 1700)
    #define __ARX2015
  #elif (_MSC_VER >= 1600)
    #define __ARX2013
  #elif (_MSC_VER >= 1500)
    #define __ARX2010
  #elif (_MSC_VER >= 1400)
    #define __ARX2007
  #elif (_MSC_VER >= 1300)
    #define __ARX2004
  #elif (_MSC_VER)
    #define __ARX2000
  #endif

  #ifdef __SYS_32_BIT__  // 32 bit builds
    #define __ARX_32BIT
    #ifdef  __ARX2015
    #define __ARX2015_32BIT
    #endif
    #ifdef  __ARX2013
    #define __ARX2013_32BIT
    #endif
    #ifdef  __ARX2010
    #define __ARX2010_32BIT
    #endif
    #ifdef  __ARX2007
    #define __ARX2007_32BIT
    #endif
  #endif

  #ifdef __SYS_64_BIT__  // 64 bit builds
    #define __ARX_64BIT
    #ifdef  __ARX2015
    #define __ARX2015_64BIT
    #endif
    #ifdef  __ARX2013
    #define __ARX2013_64BIT
    #endif
    #ifdef  __ARX2010
    #define __ARX2010_64BIT
    #endif
    #ifdef  __ARX2007
    #define __ARX2007_64BIT
    #endif
  #endif

#endif // ARX_VERSION_INCLUDED
