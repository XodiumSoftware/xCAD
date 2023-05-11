// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// all supported Windows ATL types and functions

#pragma once

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
