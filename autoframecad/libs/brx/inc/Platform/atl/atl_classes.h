// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// all supported Windows ATL types and functions

#ifndef _BS_ATL_CLASSES_INCLUDED_
#define _BS_ATL_CLASSES_INCLUDED_

#include "atl_defs.h"


// ========== Platform specific ==========

#ifndef _WIN32 // on Linux/Mac

  // include all the classes that we support
  #include "atl_objmap.h"  // object map basics
  #include "atlsimpstr.h"




#endif // !_WIN32

#endif // _BS_ATL_CLASSES_INCLUDED_
