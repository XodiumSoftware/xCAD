// sds_types.h : typedefs and structs for SDS

// Copyright © Menhirs NV. All rights reserved. 

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
#ifndef _SDS_TYPES_H_
#define _SDS_TYPES_H_

#pragma pack(push, 8)

// ========== for Windows, Linux, Mac =========
#undef __SYS_64_BIT__
#undef __SYS_32_BIT__
#if defined ( _WIN64 ) || defined(__LP64__) || defined(_LP64) || defined(__64BITS__) || defined(__x86_64__)
  #define __SYS_64_BIT__
#else
  #define __SYS_32_BIT__
#endif


#ifdef __SYS_64_BIT__
  #define  __w64       // ignore, no 64bit checks
  #define   _W64       // ignore, no 64bit checks
#endif

#ifndef _WIN32 // on Linux/Mac
  #define  __w64       // ignore, no 64bit checks
  #define   _W64       // ignore, no 64bit checks
#endif


#ifdef SDS_NAMESPACE
#define NS_SDS_START namespace SDS_NAMESPACE {
#define NS_SDS_END };
#else
#define NS_SDS_START
#define NS_SDS_END
#endif //SDS_NAMESPACE

NS_SDS_START

#if defined(__cplusplus)
    extern "C"
    {
#endif

typedef double		ads_real;
typedef ads_real	ads_point[3];
typedef ads_real	*ads_pointp;
typedef ads_real	ads_matrix[4][4];

#ifdef __SYS_32_BIT__  // for 32 bit platforms
  typedef __w64 long  ads_longptr;
#else
  typedef __int64     ads_longptr;
#endif
typedef ads_longptr ads_name_longptr;
typedef ads_name_longptr  ads_name[2];
typedef ads_name_longptr* ads_namep;

#define sds_real    ads_real
#define sds_point   ads_point
#define sds_pointp  ads_pointp
#define sds_name_longptr ads_name_longptr
#define sds_name    ads_name
#define sds_namep   ads_namep
#define sds_matrix  ads_matrix
#define sds_longptr ads_longptr


typedef struct _sds_hdlg	*sds_hdlg;
typedef struct _sds_htile	*sds_htile;

typedef struct {
    sds_hdlg    dialog;
    sds_htile   tile;
    wchar_t*    value;
    void*       client_data;
    int         reason;
    long        x, y;
} sds_callback_packet;


struct sds_binary {
    short   clen;
    BYTE*   buf;
};
#define ads_binary sds_binary

union sds_u_val {
   sds_real             rreal;
   sds_real             rpoint[3];
   short                rint;
   wchar_t              *rstring;
   ads_name_longptr     rlname[2];  // 32 / 64 bit
   ads_name_longptr     mnLongPtr;  // since V13 (64 bit support)
   long                 rlong;
   __int64              mnInt64;    // since V13 (64 bit support)
   struct sds_binary    rbinary;
};
#define ads_u_val  sds_u_val

struct sds_resbuf {
    struct sds_resbuf   *rbnext;
    short               restype;
    union sds_u_val     resval;
};
#define resbuf sds_resbuf

struct sds_dobjll {
    BYTE                type;
    int                 color;
    short               npts;
    sds_real            *chain;
    struct sds_dobjll   *next;
};

struct sds_blockTree {
struct	sds_blockTree *p_next,*p_contents;
    wchar_t     *name;          // block name
    wchar_t     *path;          // NULL for block, actual file name for xref (not name of xref)
    sds_name    entity_name;    // Internal sds_name of the entity
    sds_name    tblrec_name;    // Internal sds_name of the block table record
    int         type;
    BYTE        unloaded;
    void        *bitmap, *wmf;  // bitmap & WMF image buffer
    int         bmpsz, wmfsz;   // bitmap & WMF buffer size
    void        *p_hook;        // Hook for adding expanded data to instances of this structure.
                                // Initialized to NULL. NOTE: sds_relBlockTree() will not delete p_hook.
                                // Not used by SDS functions. To be used it at own discretion.
};


#if defined(__cplusplus)
    }
#endif

NS_SDS_END

#pragma pack(pop)

#endif  // _SDS_TYPES_H_
