// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// COM CURRENCY type and related functionality

#pragma once

#ifndef _BS_COM_CURRENCY_INCLUDED_
#define _BS_COM_CURRENCY_INCLUDED_

#include "com_defs.h"


#ifndef _WIN32  // on Linux/Mac

  typedef union tagCY
  {
    struct
    {
      #ifdef _MAC
        long          Hi;
        unsigned long Lo;
      #else
        unsigned long Lo;
        long          Hi;
      #endif
    };
    LONGLONG int64;
  } CY;
  typedef CY CURRENCY;


#endif // !_WIN32

#endif // _BS_COM_CURRENCY_INCLUDED_
