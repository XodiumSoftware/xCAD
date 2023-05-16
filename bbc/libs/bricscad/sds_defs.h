// sds_defs.h : defines for SDS

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH


#pragma once
#ifndef _SDS_DEFS_H_
#define _SDS_DEFS_H_

#include <stdlib.h>


#ifdef SDS_NAMESPACE
#define NS_SDS_START namespace SDS_NAMESPACE {
#define NS_SDS_END };
#else
#define NS_SDS_START
#define NS_SDS_END
#endif //SDS_NAMESPACE

NS_SDS_START

#if defined(__cplusplus)
    #ifndef	EXTERN_C
        #define EXTERN_C extern "C"
    #endif
#endif

#ifndef	EXTERN_C
    #define EXTERN_C
#endif

#if defined(__cplusplus)
    extern "C"
    {
#endif


#define adsart(a)  short code=(a)
//[AT] removed: conflict with wx headers // #define _(a)       a

#define SDS_X 0
#define SDS_Y 1
#define SDS_Z 2
#define SDS_T 3

#define SDS_TRUE  1
#define SDS_FALSE 0

#define PAUSE _T("\\")
    #define SDS_PAUSE PAUSE

#define RSG_NONULL     0x0001
#define RSG_NOZERO     0x0002
#define RSG_NONEG      0x0004
#define RSG_NOLIM      0x0008
#define RSG_GETZ       0x0010
#define RSG_DASH       0x0020
#define RSG_2D         0x0040
#define RSG_OTHER      0x0080
#define RSG_DDISTFIRST 0x0100
#define RSG_TRACKUCS   0x0200
#define RSG_NOORTHOZ   0x0400
#define RSG_NOOSNAP    0x0800
#define RSG_NOSNAP     0x1000
#define SDS_RSG_NONUL      RSG_NONULL
    #define SDS_RSG_NOZERO     RSG_NOZERO
    #define SDS_RSG_NONEG      RSG_NONEG
    #define SDS_RSG_NOLIM      RSG_NOLIM
    #define SDS_RSG_GETZ       RSG_GETZ
    #define SDS_RSG_DASH       RSG_DASH
    #define SDS_RSG_2D         RSG_2D
    #define SDS_RSG_DDISTFIRST RSG_DDISTFIRST
    #define SDS_RSG_TRACKUCS   RSG_TRACKUCS
    #define SDS_RSG_NOORTHOZ   RSG_NOORTHOZ
    #define SDS_RSG_NOOSNAP    RSG_NOOSNAP
    #define SDS_RSG_NOSNAP     RSG_NOSNAP

#define SDS_RSG_NOPMENU    0x010000
#define SDS_RSG_NOCANCEL   0x020000
#define SDS_RSG_NOVIEWCHG  0x040000
#define SDS_RSG_NODOCCHG   0x080000


#define RQSAVE  14
#define RQEND   15
#define RQQUIT  16
#define RQCFG   22
#define RQXLOAD 100
#define RQXUNLD 101
#define RQSUBR  102
#define RQHUP   105
#define RQXHELP 118
    #define SDS_RQSAVE  RQSAVE
    #define SDS_RQEND   RQEND
    #define SDS_RQQUIT  RQQUIT
    #define SDS_RQCFG   RQCFG
    #define SDS_RQXLOAD RQXLOAD
    #define SDS_RQXUNLD RQXUNLD
    #define SDS_RQSUBR  RQSUBR
    #define SDS_RQHUP   RQHUP
    #define SDS_RQXHELP RQXHELP


#define RSRSLT  1
#define RSERR   3
    #define SDS_RSRSLT  RSRSLT
    #define SDS_RSERR   RSERR


#define RTERROR       -5001
#define RTCAN         -5002
#define RTREJ         -5003
#define RTFAIL        -5004
#define RTKWORD       -5005
#define RTINPUTTRUNCATED  -5008 // input too long (does not fit into buffer)
#define RTNONE        5000
#define RTREAL        5001
#define RTPOINT       5002
#define RTSHORT       5003
#define RTANG         5004
#define RTSTR         5005
#define RTENAME       5006
#define RTPICKS       5007
#define RTORINT       5008
#define RT3DPOINT     5009
#define RTLONG        5010
#define RTVOID        5014
#define RTLB          5016
#define RTLE          5017
#define RTDOTE        5018
#define RTNIL         5019
#define RTDXF0        5020
#define RTT           5021
#define RTBINARY      5022
#define RTRESBUF      5023 
#define RTMODELESS    5027
#define RTNORM        5100
#define RTLONG_PTR    5030 // integer using pointer size
#define RTINT64       5031 // integer using 64-bit size

    #define SDS_RTERROR		RTERROR
    #define SDS_RTCAN		RTCAN
    #define SDS_RTREJ		RTREJ
    #define SDS_RTFAIL		RTFAIL
    #define SDS_RTKWORD		RTKWORD
    #define SDS_RTNONE		RTNONE
    #define SDS_RTREAL		RTREAL
    #define SDS_RTPOINT		RTPOINT
    #define SDS_RTSHORT		RTSHORT
    #define SDS_RTANG		RTANG
    #define SDS_RTSTR		RTSTR
    #define SDS_RTENAME		RTENAME
    #define SDS_RTPICKS		RTPICKS
    #define SDS_RTORINT		RTORINT
    #define SDS_RT3DPOINT	RT3DPOINT
    #define SDS_RTLONG		RTLONG
    #define SDS_RTVOID		RTVOID
    #define SDS_RTLB		RTLB
    #define SDS_RTLE		RTLE
    #define SDS_RTDOTE		RTDOTE
    #define SDS_RTNIL		RTNIL
    #define SDS_RTDXF0		RTDXF0
    #define SDS_RTT			RTT
    #define SDS_RTBINARY	RTBINARY
    #define SDS_RTRESBUF	RTRESBUF
    #define	SDS_RTMODELESS	RTMODELESS
    #define SDS_RTNORM		RTNORM
    #define SDS_RTLONG_PTR  RTLONG_PTR
    #define SDS_RTINT64     RTINT64

#define SDS_RTDRAGPT	5500


#define COND_OP_CODE		-4

#define CBR_SELECT			1
#define CBR_LOST_FOCUS		2
#define CBR_DRAG			3
#define CBR_DOUBLE_CLICK	4
    #define SDS_CBR_SELECT			CBR_SELECT
    #define SDS_CBR_LOST_FOCUS		CBR_LOST_FOCUS
    #define SDS_CBR_DRAG			CBR_DRAG
    #define SDS_CBR_DOUBLE_CLICK	CBR_DOUBLE_CLICK


#define DLGALLDONE	-1
#define DLGCANCEL	0
#define DLGOK		1
#define DLGSTATUS	2
    #define SDS_DLGCANCEL	DLGCANCEL
    #define SDS_DLGOK		DLGOK
    #define SDS_DLGALLDONE	DLGALLDONE
    #define SDS_DLGSTATUS	DLGSTATUS


#define BGLCOLOR	-2
#define DBGLCOLOR	-15
#define DFGLCOLOR	-16
#define LINELCOLOR	-18
    #define SDS_BGLCOLOR	BGLCOLOR
    #define SDS_DBGLCOLOR	DBGLCOLOR
    #define SDS_DFGLCOLOR	DFGLCOLOR
    #define SDS_LINELCOLOR	LINELCOLOR


#define LIST_CHANGE	1
#define LIST_APPEND	2
#define LIST_NEW	3
    #define SDS_LIST_CHANGE	LIST_CHANGE
    #define SDS_LIST_APPEND	LIST_APPEND
    #define SDS_LIST_NEW	LIST_NEW

//	 SDS xref actions 0 - 16
#define SDS_XREF_FIND		0
#define SDS_XREF_ATTACH		1
#define SDS_XREF_INSERT		2
#define SDS_XREF_EDIT_PATH	3
#define SDS_XREF_RELOAD		4
#define SDS_XREF_UNLOAD		5
#define SDS_XREF_DETACH		6
#define SDS_XREF_RENAME		7

//	 SDS xref action flags
#define SDS_XREF_OVERLAY	0x10
#define SDS_XREF_CROP_PATH	0x20
#define SDS_XREF_BIND		0x40
#define SDS_XREF_USERDEF	0x80


#define MODE_ENABLE		0
#define MODE_DISABLE	1
#define MODE_SETFOCUS	2
#define MODE_SETSEL		3
#define MODE_FLIP		4
    #define SDS_MODE_ENABLE		MODE_ENABLE
    #define SDS_MODE_DISABLE	MODE_DISABLE
    #define SDS_MODE_SETFOCUS	MODE_SETFOCUS
    #define SDS_MODE_SETSEL		MODE_SETSEL
    #define SDS_MODE_FLIP		MODE_FLIP


#define MAX_TILE_STR	40
#define TILE_STR_LIMIT	255
    #define SDS_MAX_TILE_STR	MAX_TILE_STR
    #define SDS_TILE_STR_LIMIT	TILE_STR_LIMIT


#define sds_name_set(nmFrom, nmTo)				(*(nmTo)=*(nmFrom),(nmTo)[1]=(nmFrom)[1])
#define sds_point_set(ptFrom, ptTo)				(*(ptTo)=*(ptFrom),(ptTo)[1]=(ptFrom)[1],(ptTo)[2]=(ptFrom)[2])
#define sds_name_clear(nmAnyName)				 nmAnyName[0]=nmAnyName[1]=0
#define sds_name_nil(nmAnyName)					(nmAnyName[0]==0 && nmAnyName[1]==0)
#define sds_name_equal(nmNameOne, nmNameTwo)	(nmNameOne[0]==nmNameTwo[0] && nmNameOne[1]==nmNameTwo[1])
    #define ads_name_set		sds_name_set
    #define ads_point_set		sds_point_set
    #define ads_name_clear		sds_name_clear
    #define ads_name_nil		sds_name_nil
    #define ads_name_equal		sds_name_equal


#undef _tmain
#define _tmain         SDS_main
#define ads_main	   SDS_main
//    #define acrxEntryPoint SDS_main

#define  OL_GOOD         0
#define  OL_ESNVALID     1
#define  OL_ENAMEVALID   2
#define  OL_ESSMAX       3
#define  OL_ESSVALID     4
#define  OL_EBDEVALID    5
#define  OL_EXDEVALID    6
#define  OL_ENTSELPICK   7
#define  OL_EEOEF        8
#define  OL_EEOBD        9
#define  OL_EEMPDB      10
#define  OL_EDELVPORT   11
#define  OL_EACQPLINE   12
#define  OL_EHANDLE     13
#define  OL_ENOHAND     14
#define  OL_ETRANS      15
#define  OL_EXSPACE     16
#define  OL_EDELENT     17
#define  OL_ETBLNAME    18
#define  OL_ETBLARG     19
#define  OL_ERDONLY     20
#define  OL_ENONZERO    21
#define  OL_ERANGE      22
#define  OL_ERGBUSY     23
#define  OL_EMMTYPE     24
#define  OL_EMMLAY      25
#define  OL_EMMLT       26
#define  OL_EMMCOLOR    27
#define  OL_EMMSTYLE    28
#define  OL_EMMSHAPE    29
#define  OL_EMMFTYPE    30
#define  OL_EMODDEL     31
#define  OL_EMODSEQ     32
#define  OL_EMODHAND    33
#define  OL_EMODVPVIS   34
#define  OL_EMMLL       35
#define  OL_EMKTYPE     36
#define  OL_EMKPLINE    37
#define  OL_EMKCMPLX    38
#define  OL_EMKBNAME    39
#define  OL_EMKBFLAG    40
#define  OL_EMKDBNAME   41
#define  OL_EMKNORM     42
#define  OL_EMKNOBNM    43
#define  OL_EMKNOBFLG   44
#define  OL_EMKANON     45
#define  OL_EMKBLOCK    46
#define  OL_EMKMANDF    47
#define  OL_EMMXDTYPE   48
#define  OL_EMMXDNEST   49
#define  OL_EMMXDAPPID  50
#define  OL_EMMXDSIZE   51
#define  OL_ENTSELNULL  52
#define  OL_EMXDAPPID   53
#define  OL_EMMVPORT    54
#define  OL_INVEXT      55
#define  OL_EFLTR1      56
#define  OL_EFLTR2      57
#define  OL_EFLTR3      58
#define  OL_EFLTR4      59
#define  OL_EFLTR5      60
#define  OL_EFLTR6      61
#define  OL_EFLTR7      62
#define  OL_EFLTR8      63
#define  OL_EFLTR9      64
#define  OL_EFLTR10     65
#define  OL_EFLTR11     66
#define  OL_EFLTR12     67
#define  OL_TABNOT      68
#define  OL_TABNOCAL    69
#define  OL_TABERR      70
#define  OL_ENEWRB      71
#define  OL_ENULLPTR    72
#define  OL_EOPEN       73
#define  OL_ELOADED     74
#define  OL_EMAXAPP     75
#define  OL_EEXEC       76
#define  OL_EVERSION    77
#define  OL_EDENIED     78
#define  OL_EREFUSE     79
#define  OL_ENOTLOADED  80
#define  OL_ENOMEM      81
#define  OL_EXFMVALID   82
#define  OL_ESYMNAM     83
#define  OL_ESYMVAL     84
#define  OL_NONDIALOG   85

// VBA related errors
#define  OL_VBAERROR   101

// for entmake errors where ACAD prints a message instead of setting ERRNO: 
#define  OL_EMKNESTBLK 510  // Cannot nest block definitions.
#define  OL_EMKINVCOMP 511  // Invalid complex object.


#define EOS       _T('\0')


#if defined(__cplusplus)
    namespace AcRx {

        typedef void (*FcnPtr) ();

        enum         DictIterType { kDictSorted   = 0,
                                    kDictCollated = 1 };

        enum         Ordering     { kLessThan     = -1,
                                    kEqual        = 0,
                                    kGreaterThan  = 1,
                                    kNotOrderable = 2 };

        enum         AppMsgCode   { kNullMsg         = 0,
                                    kInitAppMsg      = 1,
                                    kUnloadAppMsg    = 2,
                                    kLoadDwgMsg      = 3,
                                    kUnloadDwgMsg    = 4,
                                    kInvkSubrMsg     = 5,
                                    kCfgMsg          = 6,
                                    kEndMsg          = 7,
                                    kQuitMsg         = 8,
                                    kSaveMsg         = 9,
                                    kDependencyMsg   = 10,
                                    kNoDependencyMsg = 11,
                                    kOleUnloadAppMsg = 12,
                                    kPreQuitMsg      = 13,
                                    kInitDialogMsg   = 14,
                                    kEndDialogMsg    = 15,
                                    kSuspendMsg      = 16 };


        enum        AppRetCode   {	kRetOK          = 0,
                                    kRetError       = 3 };
    };
#endif

#define acdbSetDbmod		sds_setdbmod
#define ads_abort			sds_abort
#define ads_agetcfg			sds_agetcfg
#define ads_agetenv			sds_agetenv
#define ads_alert			sds_alert
#define ads_angle			sds_angle
#define ads_angtof			sds_angtof
#define ads_angtos			sds_angtos
#define ads_arxloaded		sds_arxloaded
#define ads_arxxload		sds_arxxload
#define ads_arxxunload		sds_arxxunload
#define ads_asetcfg			sds_asetcfg
#define ads_asetenv			sds_asetenv
#define ads_buildlist		sds_buildlist
#define ads_calloc			sds_calloc
#define ads_cmd				sds_cmd
#define ads_command			sds_command
#define ads_cvunit			sds_cvunit
#define ads_defun			sds_defun
#define ads_dictnext		sds_dictnext
#define ads_dictsearch		sds_dictsearch
#define ads_distance		sds_distance
#define ads_distof			sds_distof
#define ads_draggen			sds_draggen
#define ads_entdel			sds_entdel
#define ads_entget			sds_entget
#define ads_entgetx			sds_entgetx
#define ads_entlast			sds_entlast
#define ads_entmake			sds_entmake
#define ads_entmakex		sds_entmakex
#define ads_entmod			sds_entmod
#define ads_entnext			sds_entnext
#define ads_entsel			sds_entsel
#define ads_entupd			sds_entupd
#define ads_exit			sds_exit
#define ads_fail			sds_fail
#define ads_findfile		sds_findfile
#define ads_free			sds_free
#define ads_getangle		sds_getangle
#define ads_getappname		sds_getappname
#define ads_getargs			sds_getargs
#define ads_getcname		sds_getcname
#define ads_getcorner		sds_getcorner
#define ads_getdist			sds_getdist
#define ads_getfiled		sds_getfiled
#define ads_getfuncode		sds_getfuncode
#define ads_getinput		sds_getinput
#define ads_getint			sds_getint
#define ads_getkword		sds_getkword
#define ads_getorient		sds_getorient
#define ads_getpoint		sds_getpoint
#define ads_getreal			sds_getreal
#define ads_getstring		sds_getstring
#define ads_getsym			sds_getsym
#define ads_getvar			sds_getvar
#define ads_graphscr		sds_graphscr
#define ads_grclear			sds_grclear
#define ads_grdraw			sds_grdraw
#define ads_grread			sds_grread
#define ads_grtext			sds_grtext
#define ads_grvecs			sds_grvecs
#define ads_handent			sds_handent
#define ads_help			sds_help
#define ads_init			sds_init
#define ads_initget			sds_initget
#define ads_inters			sds_inters
#define ads_invoke			sds_invoke
#define ads_isalnum			sds_isalnum
#define ads_isalpha			sds_isalpha
#define ads_iscntrl			sds_iscntrl
#define ads_isdigit			sds_isdigit
#define ads_isgraph			sds_isgraph
#define ads_islower			sds_islower
#define ads_isprint			sds_isprint
#define ads_ispunct			sds_ispunct
#define ads_isspace			sds_isspace
#define ads_isupper			sds_isupper
#define ads_isxdigit		sds_isxdigit
#define ads_link			sds_link
#define ads_loaded			sds_loaded
#define ads_malloc			sds_malloc
#define ads_menucmd			sds_menucmd
#define ads__msize			sds__msize
#define ads_namedobjdict	sds_namedobjdict
#define ads_nentsel			sds_nentsel
#define ads_nentselp		sds_nentselp
#define ads_newrb			sds_newrb
#define ads_osnap			sds_osnap
#define ads_polar			sds_polar
#define ads_printf			sds_printf
#define ads_prompt			sds_prompt
#define ads_putsym			sds_putsym
#define ads_realloc			sds_realloc
#define ads_redraw			sds_redraw
#define ads_regapp			sds_regapp
#define ads_regappx			sds_regappx
#define ads_regfunc			sds_regfunc
#define ads_relrb			sds_relrb
#define ads_retint			sds_retint
#define ads_retlist			sds_retlist
#define ads_retname			sds_retname
#define ads_retnil			sds_retnil
#define ads_retpoint		sds_retpoint
#define ads_retreal			sds_retreal
#define ads_retstr			sds_retstr
#define ads_rett			sds_rett
#define ads_retval			sds_retval
#define ads_retvoid			sds_retvoid
#define ads_rtos			sds_rtos
#define ads_setfunhelp		sds_setfunhelp
#define ads_setvar			sds_setvar
#define ads_setview			sds_setview
#define ads_snvalid			sds_snvalid
#define ads_ssadd			sds_ssadd
#define ads_ssdel			sds_ssdel
#define ads_ssfree			sds_ssfree
#define ads_ssget			sds_ssget
#define ads_ssgetfirst		sds_ssgetfirst
#define ads_sslength		sds_sslength
#define ads_ssmemb			sds_ssmemb
#define ads_ssname			sds_ssname
#define ads_ssnamex			sds_ssnamex
#define ads_sssetfirst		sds_sssetfirst
#define ads_strdup			sds_xstrsave
#define ads_tablet			sds_tablet
#define ads_tblnext			sds_tblnext
#define ads_tblobjname		sds_tblobjname
#define ads_tblsearch		sds_tblsearch
#define ads_textbox			sds_textbox
#define ads_textpage		sds_textpage
#define ads_textscr			sds_textscr
#define ads_tolower			sds_tolower
#define ads_toupper			sds_toupper
#define ads_trans			sds_trans
#define ads_undef			sds_undef
#define ads_update			sds_update
#define ads_usrbrk			sds_usrbrk
#define ads_vports			sds_vports
#define ads_wcmatch			sds_wcmatch
#define ads_xdroom			sds_xdroom
#define ads_xdsize			sds_xdsize
#define ads_xformss			sds_xformss
#define ads_xload			sds_xload
#define ads_xstrcase		sds_xstrcase
#define ads_xstrsave		sds_xstrsave
#define ads_xunload			sds_xunload
#define adsw_acadMainWnd	sds_getmainhwnd

#ifdef _WIN32
    #define SDS_DLLEXPORT __declspec(dllexport)
#else
    #define SDS_DLLEXPORT
#endif

#ifdef _WINDOWS_
#define	ENTRYARG	HWND
#else
#define	ENTRYARG
#endif
void SDS_DLLEXPORT SDS_EntryPoint( ENTRYARG);


#undef  CALLB
#define CALLB

#define ads_hdlg sds_hdlg
#define ads_htile sds_htile
#define ads_callback_packet sds_callback_packet

#ifdef __cplusplus
    typedef void (*CLIENTFUNC) (sds_callback_packet *cpkt);
#else
    #define CLIENTFUNC void *
#endif

#define SDS_NULLCB ((CLIENTFUNC)0)
#define NULLCB           SDS_NULLCB


#define ads_action_tile            dlg_action_tile
#define ads_add_list               dlg_add_list
#define ads_client_data_tile       dlg_client_data_tile
#define ads_dimensions_tile        dlg_dimensions_tile
#define ads_done_dialog            dlg_done_dialog
#define ads_done_positioned_dialog dlg_done_positioned_dialog
#define ads_end_image              dlg_end_image
#define ads_end_list               dlg_end_list
#define ads_fill_image             dlg_fill_image
#define ads_get_attr               dlg_get_attr
#define ads_get_attr_string        dlg_get_attr_string
#define ads_get_list_string        dlg_get_list_string
#define ads_get_tile               dlg_get_tile
#define ads_load_dialog            dlg_load_dialog
#define ads_mode_tile              dlg_mode_tile
#define ads_new_dialog             dlg_new_dialog
#define ads_new_positioned_dialog  dlg_new_positioned_dialog
#define ads_set_tile               dlg_set_tile
#define ads_slide_image            dlg_slide_image
#define ads_start_dialog           dlg_start_dialog
#define ads_start_image            dlg_start_image
#define ads_start_list             dlg_start_list
#define ads_term_dialog            dlg_term_dialog
#define ads_unload_dialog          dlg_unload_dialog
#define ads_vector_image           dlg_vector_image


#if defined(__cplusplus)
    }
#endif

NS_SDS_END

#endif  // _SDS_DEFS_H_
