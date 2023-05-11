// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// COM DECIMAL structure and related functionality

#pragma once

#ifndef _BS_COM_DECIMAL_INCLUDED_
#define _BS_COM_DECIMAL_INCLUDED_

#include "com_defs.h"


#ifndef _WIN32  // on Linux/Mac

  typedef struct tagDEC
  {
    USHORT wReserved;
    union
    {
      struct
      {
        char scale; // The number of decimal places for the number.
                    // Valid values are from 0 to 28. So 12.345 is represented as 12345 with a 3.
        char sign;  // 0 for positive numbers or DECIMAL_NEG for negative numbers.
                    // So -1 is represented as 1 with the DECIMAL_NEG bit set.
      };
      USHORT signscale;
    };
    ULONG Hi32;     // The high 32 bits of your number
    union
    {
      struct
      {
        #ifdef _MAC
          ULONG Mid32;
          ULONG Lo32;
        #else
          ULONG Lo32;
          ULONG Mid32;
        #endif
      };
      DWORDLONG Lo64; // The low 64 bits of your number. This is an _int64.
    };
  } DECIMAL;

  #define DECIMAL_NEG ((BYTE)0x80)


#endif // !_WIN32

#endif // _BS_COM_DECIMAL_INCLUDED_
