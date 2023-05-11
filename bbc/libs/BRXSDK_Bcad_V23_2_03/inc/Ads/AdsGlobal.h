// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "brx_platform_3264.h"
#include "Misc/MiscGlobal.h"

#ifndef _ADS_GLOBAL_H_
#define _ADS_GLOBAL_H_

#pragma pack(push, 8)

//required for code compatibility
#ifndef CALLB
#define CALLB
#endif

#define CBR_SELECT 1
#define CBR_LOST_FOCUS 2
#define CBR_DRAG 3
#define CBR_DOUBLE_CLICK 4

#define DLGALLDONE (-1)
#define DLGCANCEL 0
#define DLGOK 1
#define DLGSTATUS 2

#define LIST_CHANGE 1
#define LIST_APPEND 2
#define LIST_NEW 3

#define MODE_ENABLE 0
#define MODE_DISABLE 1
#define MODE_SETFOCUS 2
#define MODE_SETSEL 3
#define MODE_FLIP 4

#ifndef FALSE
  #define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#ifndef EOS
#define EOS ACRX_T('\0')
#endif

#define PAUSE ACRX_T("\\")

#define BAD_DIALOG NULL
#define MAX_TILE_STR 40
#define NULLCB ((CLIENTFUNC) NULL)
#define TILE_STR_LIMIT 2035

#ifdef X
#undef X
#endif
#ifdef Y
#undef Y
#endif
#ifdef Z
#undef Z
#endif
#ifdef T
#undef T
#endif

#ifndef _XYZT_DEFINED
#define _XYZT_DEFINED
enum
{
    X = 0,
    Y,
    Z
};
enum
{
    T = 3
};
#endif

typedef double ads_real;
typedef ads_real ads_point[3];
typedef ads_real* ads_pointp;
typedef ads_real ads_matrix[4][4];
typedef void* ads_hdlg;
typedef void* ads_htile;

#ifdef __SYS_32_BIT__  // for 32 bit platforms
  typedef __w64 long              ads_name_longptr;
  typedef __w64 ads_name_longptr  ads_name[2];
  typedef __w64 ads_name_longptr* ads_namep;
#else
  typedef __int64           ads_name_longptr;
  typedef ads_name_longptr  ads_name[2];
  typedef ads_name_longptr* ads_namep;
#endif

#undef ads_callback_packet
typedef struct
{
    ads_hdlg dialog;
    ads_htile tile;
    ACHAR* value;
    void* client_data;
    int reason;
    long x;
    long y;
} ads_callback_packet;

typedef void (*CLIENTFUNC)(ads_callback_packet*);

#undef ads_binary
struct ads_binary
{
    short clen;
    char* buf;
};

#undef ads_u_val
union ads_u_val
{
    short rint;
    long rlong;
  #ifdef __SYS_32_BIT__  // for 32 bit platforms
    __w64 long  rlname[2];
    __w64 long  mnLongPtr;   // since V13 (64 bit support)
  #else
    __int64     rlname[2];
    __int64     mnLongPtr;   // since V13 (64 bit support)
  #endif
    ads_real    rreal;
    ads_real    rpoint[3];
    ACHAR*      rstring;
    struct ads_binary rbinary;
    __int64     mnInt64;     // since V13 (64 bit support)
    unsigned char ihandle[8];
};

struct resbuf
{
    struct resbuf* rbnext;
    short restype;
    union ads_u_val resval;
};

typedef struct resbuf* pResbuf;
typedef const struct resbuf* kpResbuf;

enum
{
    RSG_NONULL = 1,
    RSG_NOZERO = 2,
    RSG_NONEG = 4,
    RSG_NOLIM = 8,
    RSG_GETZ = 16,
    RSG_DASH = 32,
    RSG_2D = 64,
    RSG_OTHER = 128,
    RSG_DDISTFIRST = 256,
    RSG_TRACKUCS = 512,
    RSG_NOORTHOZ = 1024,
    RSG_NOOSNAP = 2048
};

enum
{
    INP_NNULL = 1,
    INP_NZERO = 2,
    INP_NNEG = 4,
    INP_NLIM = 8,
    INP_DASH = 32,
    INP_NZCOORD = 64
};

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
    HWND adsw_acadDocWnd();
    HWND adsw_acadMainWnd();
#ifdef __cplusplus
}
#endif //__cplusplus
#define adsw_hwndAcad adsw_acadMainWnd()

#define RTINPUTTRUNCATED (-5008)
#define RTKWORD (-5005)
#define RTFAIL (-5004)
#define RTREJ (-5003)
#define RTCAN (-5002)
#define RTERROR (-5001)
#define RSRSLT 1
#define RSERR 3
#define RQSAVE 14
#define RQEND 15
#define RQQUIT 16
#define RQCFG 22
#define RQXLOAD 100
#define RQXUNLD 101
#define RQSUBR 102
#define RQHUP 105
#define RQXHELP 118
#define RTNONE 5000
#define RTREAL 5001
#define RTPOINT 5002
#define RTSHORT 5003
#define RTANG 5004
#define RTSTR 5005
#define RTENAME 5006
#define RTPICKS 5007
#define RTORINT 5008
#define RT3DPOINT 5009
#define RTLONG 5010
#define RTVOID 5014
#define RTLB 5016
#define RTLE 5017
#define RTDOTE 5018
#define RTNIL 5019
#define RTDXF0 5020
#define RTT 5021
#define RTRESBUF 5023
#define RTMODELESS 5027
#define RTLONG_PTR 5030
#define RTINT64 5031
#define RTNORM 5100

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus
    int ads_action_tile(ads_hdlg,const ACHAR*,CLIENTFUNC);
    int ads_add_list(const ACHAR*);
    int ads_client_data_tile(ads_hdlg,const ACHAR*,void*);
    int ads_dimensions_tile(ads_hdlg,const ACHAR*,short*,short*);
    int ads_done_dialog(ads_hdlg,int);
    int ads_done_positioned_dialog(ads_hdlg,int,int*,int*);
    int ads_end_image();
    int ads_end_list();
    int ads_fill_image(short,short,short,short,short);
    int ads_get_attr(ads_hdlg,const ACHAR*,ACHAR*,ACHAR*,int);
    int ads_get_attr_string(ads_htile,ACHAR*,ACHAR*,int);
    int ads_get_tile(ads_hdlg,const ACHAR*,ACHAR*,int);
    int ads_load_dialog(const ACHAR*,int*);
    int ads_mode_tile(ads_hdlg,const ACHAR*,short);
    int ads_new_dialog(const ACHAR*,int,CLIENTFUNC,ads_hdlg*);
    int ads_new_positioned_dialog(const ACHAR*,int,CLIENTFUNC,int,int,ads_hdlg*);
    int ads_set_tile(ads_hdlg,const ACHAR*,const ACHAR*);
    int ads_slide_image(short,short,short,short,const ACHAR*);
    int ads_start_dialog(ads_hdlg,int*);
    int ads_start_image(ads_hdlg,const ACHAR*);
    int ads_start_list(ads_hdlg,const ACHAR*,short,short);
    int ads_term_dialog();
    int ads_unload_dialog(int);
    int ads_vector_image(short,short,short,short,short);
    // BRX start
    int ads_redraw_dialog(); // workaround to force a visual update of DCL dialog
    // BRX end
#ifdef __cplusplus
}
#endif //__cplusplus

#pragma pack(pop)

#endif //_ADS_GLOBAL_H_
