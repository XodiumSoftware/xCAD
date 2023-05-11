// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#ifndef _WIN32 // Linux,Mac
  #include "brx_platform_linux.h"
#endif

// Export declaration macro (Windows + Linux,Mac; for BRX + client build)
#ifdef ATIL_API_MODULE
  #ifdef _WIN32  // Windows
    #define ATIL_IMPORTEXPORT __declspec(dllexport)
  #else   // !_WIN32
    #define ATIL_IMPORTEXPORT __attribute__((visibility("default")))
  #endif  // Linux,Mac
#else
  #define ATIL_IMPORTEXPORT
#endif // !ATIL_API_MODULE


#include <stdint.h>
//#include "Half.h"


namespace Atil
{;


#ifdef UNICODE
typedef wchar_t char_t;
#else
typedef char char_t;
#endif

typedef unsigned char Byte;
typedef signed char Int8;
typedef unsigned char UInt8;
typedef signed short Int16;
typedef unsigned short UInt16;
typedef signed int Int32;
typedef unsigned int UInt32;
#ifdef _WIN32
typedef signed __int64 Int64;
typedef unsigned __int64 UInt64;
#else
typedef signed long long Int64;
typedef unsigned long long UInt64;
#endif

#ifndef INT32_MAX
#define INT32_MAX (2147483647)
#endif
#ifndef INT32_MIN
#define INT32_MIN (-2147483647 - 1)
#endif
#ifndef UINT32_MAX
#define UINT32_MAX (4294967295)
#endif
#ifndef MAX_ALPHA
#define MAX_ALPHA (1)
#endif
#ifndef FLOAT_MAX
#define FLOAT_MAX (1E+37)
#endif
#ifndef NULL
#define NULL (0)
#endif


typedef unsigned char Data8;
typedef unsigned short Data16;
typedef unsigned int Data32;
typedef unsigned long long Data64;
typedef struct _ATIL_DATA128
{
    union
    {
        struct { unsigned int a; unsigned int b; unsigned int c; unsigned int d; } ui;
        struct { float a; float b; float c; float d; } fl;
        struct { Data64 high64; Data64 low64; } db;
    } value;
    bool operator== (const struct _ATIL_DATA128& rh) const { return (value.ui.a == rh.value.ui.a && value.ui.b == rh.value.ui.b && value.ui.c == rh.value.ui.c && value.ui.d == rh.value.ui.d); }
    bool operator!= (const struct _ATIL_DATA128& rh) const { return !operator==(rh); }
    void setToZero() { value.db.high64 = 0; value.db.low64 = 0; }
} Data128;

#define DATA32_MAX UINT32_MAX

typedef union _ATIL_LARGE_INTEGER
{
    struct
    {
        UInt32 LowPart;
        int HighPart;
    } s;
    struct
    {
        UInt32 LowPart;
        int HighPart;
    } u;
    UInt64 QuadPart;
} ATIL_LARGE_INTEGER;


#define Atil_max(l, r) ((l) >= (r) ? (l) : (r))
#define Atil_min(l, r) (((l) < (r)) ? (l) : (r))


enum Orientation
{
    kTopDownLeftRight = 0,
    kTopDownRightLeft = 1,
    kBottomUpLeftRight = 2,
    kBottomUpRightLeft = 3,
    kLeftRightTopDown = 4,
    kRightLeftTopDown = 5,
    kLeftRightBottomUp = 6,
    kRightLeftBottomUp = 7
};

const double kPi = 3.14159265358979323846;
const double kTwoPi = 6.28318530717958647692;
const double kHalfPi = 1.57079632679489661923;
const double kTolerance = 1.0e-10;
const double kEpsilon = 1.0e-10;


} //namespace Atil
