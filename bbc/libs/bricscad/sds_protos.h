// sds_protos.h : SDS API function prototypes

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once
#ifndef _SDS_PROTOS_H_
#define _SDS_PROTOS_H_

#if defined(_WIN32)
class CWnd;
class CView;
class CDocument;
class CWinApp;
struct IDispatch;
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

// prefix convention used in SDS API:
// ===================================================================
//      bs -   bitset : int representing a bitset
//      d -    double            
//      l -    long            
//      mx -   sds_matrix         
//      n -    int or short      
//      nm -   sds_name         
//      p -    pointer   : can be combined with other prefixes
//      pt -   sds_point         
//      rb -   sds_resbuf         
//      size - size_t            
//      sw -   switch : int that will only be zero or non-zero
//      sz -   pointer to string terminated by zero   

// FOLLOWING FUNCTIONS ARE NO LONGER SUPPORTED:
void                sds_abortintellicad(void);
int                    sds_angtof_absolute(const wchar_t *szAngle, int nUnitType, double *pdAngle);                                // not implemented - not exported
int                    sds_angtos_end(double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle);                                    // not exported
int                    sds_angtos_convert(int ignoremode, double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle);                // not exported
int                    sds_angtos_dim(int ignoremode, double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle, int nDimazin);    // not exported
int                    sds_init(int nARGC, wchar_t *nARGV[]);
int                    sds_link(int nRSMsg);
struct sds_resbuf *    sds_loaded(void);
int                    SDS_main(int nARGC, wchar_t *nARGV[]);    
int                    sds_xload(const wchar_t *szApplication);
int                    sds_xunload(const wchar_t *szApplication);
// --------------- END OF NO LONGER SUPPORTED

#if defined(_WIN32)

    int            sds_drawLinePattern(HDC h_dc, RECT rect, struct sds_resbuf *lineParam, BOOL bFill);
    IDispatch *    sds_getidispatch(BOOL bAddRef);
    CWnd *         sds_getmainwnd(void);
    HPALETTE       sds_getpalette(void);
    HINSTANCE      sds_getresourceinstance(void);
    CDocument *    sds_getviewdoc(void);
    HDC *          sds_getviewhdc(void);
    CView *        sds_getviewwnd(void);
    CWinApp *      sds_getwinapp(void);
    int            sds_previewdwg(wchar_t *dwgfile, HWND hWnd);
    void           sds_enableserverbusydialog(BOOL);
    void           sds_enablesnotrespondingdialog(BOOL);

#else
    typedef void* HANDLE;
    typedef HANDLE HWND;
#endif // defined (_WIN32)

HWND        sds_getmainhwnd(void);
HWND        sds_getviewhwnd(void);
HWND        sds_gettextcmdlinehwnd(void);
HWND        sds_getdockcmdlinehwnd(void);


int                    sds_getacadvalue(int nColor);
int                    sds_getrgbvalue(int nColor); 

void                   sds_abort(const wchar_t *szAbortMsg);
int                    sds_agetcfg(const wchar_t *szSymbol, wchar_t *szVariable);
int                    sds_agetenv(const wchar_t *szSymbol, wchar_t *szVariable);
int                    sds_agetenvb(const wchar_t *szSymbol, wchar_t *szVariable, int bufsize);
int                    sds_alert(const wchar_t *szAlertMsg);
double                 sds_angle(const sds_point ptStart, const sds_point ptEnd);
int                    sds_angtof(const wchar_t *szAngle, int nUnitType, double *pdAngle);
int                    sds_angtos(double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle);
int                    sds_angtosb(double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle, int bufsize);
int                    sds_angtosb_raw(double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle, int bufsize);
int                    sds_angtos_absolute(double dAngle, int nUnitType, int nPrecision, wchar_t *szAngle);
int                    sds_arxload(const wchar_t *szARXProgram);
struct sds_resbuf *    sds_arxloaded(void);
int                    sds_arxunload(const wchar_t *szARXProgram);
int                    sds_asetcfg(const wchar_t *szSymbol, const wchar_t *szValue);
int                    sds_asetenv(const wchar_t *szSymbol, const wchar_t *szValue);
int                    sds_getprfstring(const wchar_t *szPath, wchar_t *szValue);
int                    sds_setprfstring(const wchar_t *szPath, const wchar_t *szValue);

int                    sds_bbox(const sds_name entity, sds_point low, sds_point high);
int                    sds_bmpout(const wchar_t* pFile, int width, int height);
struct sds_resbuf *    sds_buildlist(int nRType, ...);
struct sds_resbuf *    sds_buildlistV(int nRType, va_list args);

int                    sds_callinmainthread(int (*fnDragEnts)(void *),void *pUserData);
void *                 sds_calloc(size_t sizeHowMany, size_t sizeBytesEach);
int                    sds_cmd(const struct sds_resbuf *prbCmdList);
int                    sds_cmdC(int (*fnClientCallback)(void*), void* pClientData, const struct sds_resbuf* prbCmdList);
int                    sds_cmdCV(int (*fnClientCallback)(void*), void* pClientData, int nRType, va_list args);
struct sds_resbuf *    sds_cmdArgs(int nRType, va_list args);
int                    sds_command(int nRType, ...);
int                    sds_commandV(int nRType, va_list args);
int                    sds_cviewport(sds_name nmViewport);
int                    sds_cvunit(double dOldNum, const wchar_t *szOldUnit, const wchar_t *szNewUnit, double *pdNewNum);

int                    sds_defun(const wchar_t *szFuncName, int nFuncCode);
int                    sds_dictadd(const sds_name nmDict, const wchar_t *szAddThis, const sds_name nmNonGraph);  
int                    sds_dictdel(const sds_name nmDict, const wchar_t *szDelThis);
struct sds_resbuf *    sds_dictnext(const sds_name nmDict, int swFirst);
int                    sds_dictrem(sds_name nmEntry, const sds_name nmDict, const wchar_t *szDelThis);
int                    sds_dictrename(const sds_name nmDict, const wchar_t *szOldName, const wchar_t *szNewName);
struct sds_resbuf *    sds_dictsearch(const sds_name nmDict, const wchar_t *szFindThis, int swFirst);
struct sds_dobjll *    sds_dispobjs(const sds_name nmEntity,int nDispMode);
double                 sds_distance(const sds_point ptFrom, const sds_point ptTo);
int                    sds_distof(const wchar_t *szDistance, int nUnitType, double *pdDistance);
int                    sds_draggen(const sds_name nmSelSet, const wchar_t *szDragMsg, int nCursor, int (*fnDragEnts)(sds_point ptCursorLoc, sds_matrix mxTransform), sds_point ptDestPoint);    //TODO

int                    sds_entdel(const sds_name nmEntity);
struct sds_resbuf *    sds_entget(const sds_name nmEntity);
struct sds_resbuf *    sds_entgetx(const sds_name nmEntity, const struct sds_resbuf *prbAppList);
int                    sds_enthandle(const sds_name nmEntity, wchar_t* handle);
int                    sds_entlast(sds_name nmLastEnt);
int                    sds_entmake(const struct sds_resbuf *prbEntList);
int                    sds_entmakex(const struct sds_resbuf *prbEntList, sds_name nmNewEnt);
int                    sds_entmod(const struct sds_resbuf *prbEntList);
int                    sds_entnext(const sds_name nmKnownEnt, sds_name nmNextEnt);
int                    sds_entsel(const wchar_t *szSelectMsg, sds_name nmEntity, sds_point ptSelected);
int                    sds_entseqend(const sds_name nmEntity, sds_name nmSeqendEntity);
int                    sds_entupd(const sds_name nmEntity);
void                   sds_exit(int /*swAbnormalExit*/);

void                   sds_fail(const wchar_t *szFailMsg);
int                    sds_findfile(const wchar_t *szLookFor, wchar_t *szPathFound);
int                    sds_findfileb(const wchar_t *szLookFor, wchar_t *szPathFound, int bufsize);
void                   sds_free(void *pMemLoc);
void                   sds_freedispobjs(struct sds_dobjll *pDispObjs);

int                    sds_getangle(const sds_point ptStart, const wchar_t *szAngleMsg, double *pdRadians);
wchar_t *              sds_getappname(void);
struct sds_resbuf *    sds_getargs(void);
int                    sds_getcfg(const wchar_t *szSymbol, wchar_t  *szVariable, int nLength);
int                    sds_getcname(const wchar_t *szOtherLang, wchar_t **pszEnglish);
int                    sds_getcorner(const sds_point ptStart, const wchar_t *szCornerMsg, sds_point ptOpposite);
int                    sds_getdist(const sds_point ptStart, const wchar_t *szDistMsg, double *pdDistance);
struct sds_resbuf *    sds_getdoclist(void);
int                    sds_getfiled(const wchar_t *szTitle, const wchar_t *szDefaultPath, const wchar_t *szExtension, int bsOptions, struct sds_resbuf *prbFileName);
int                    sds_getfilenavdialog(const wchar_t *szTitle, const wchar_t *szDefaultPath, const wchar_t *szExtension, const wchar_t *dlgname, int bsOptions, struct sds_resbuf **prbFileName);
int                    sds_getfuncode(void);
int                    sds_getinput(wchar_t *szEntry);
int                    sds_getinputb(wchar_t *szEntry, int bufsize);
int                    sds_getint(const wchar_t *szIntMsg, int *pnInteger);
int                    sds_getkword(const wchar_t *szKWordMsg, wchar_t *szKWord);
int                    sds_getkwordb(const wchar_t *szKWordMsg, wchar_t *szKWord, int bufsize);
const wchar_t *        sds_getlocalisedcolorstring(int iColorIdx);
int                    sds_getorient(const sds_point ptStart, const wchar_t *szOrientMsg, double *pdRadians);
int                    sds_getpoint(const sds_point ptReference, const wchar_t *szPointMsg, sds_point ptPoint);
int                    sds_getreal(const wchar_t *szRealMsg, double *pdReal);
int                    sds_getstring(int swSpaces, const wchar_t *szStringMsg, wchar_t *szString);
int                    sds_getstringb(int swSpaces, const wchar_t *szStringMsg, wchar_t *szString, int bufsize);
int                    sds_getsym(const wchar_t *szSymbol, struct sds_resbuf **pprbSymbolInfo);
int                    sds_getvar(const wchar_t *szSysVar, struct sds_resbuf *prbVarInfo);
int                    sds_graphscr(void);
int                    sds_grclear(void);
int                    sds_grarc(const sds_point ptCenter, double dRadius, double dStartAngle, double dEndAngle, int nColor, int swHighlight);
int                    sds_grdraw(const sds_point ptFrom, const sds_point ptTo, int nColor, int swHighlight);
int                    sds_grfill(const sds_point *pptPoints, int nNumPoints, int nColor, int swHighlight);
int                    sds_grread(int bsAllowed, int *pnInputType, struct sds_resbuf *prbInputValue);
int                    sds_grtext(int nWhere, const wchar_t *szTextMsg, int swHighlight);
int                    sds_grvecs(const struct sds_resbuf *prbVectList, sds_matrix mxDispTrans);

int                    sds_handent(const wchar_t *szEntHandle, sds_name nmEntity);
int                    sds_help(const wchar_t *szHelpFile, const wchar_t *szContextID, int nMapNumber);

BOOL                   sds_initdialog(BOOL bUseDialog);
int                    sds_initget(int bsAllowed, const wchar_t *szKeyWordList);
int                    sds_inters(const sds_point ptFrom1, const sds_point ptTo1, const sds_point ptFrom2, const sds_point ptTo2, int swFinite, sds_point ptIntersection);
int                    sds_invoke(const struct sds_resbuf *prbArguments,    struct sds_resbuf **pprbReturn);
int                    sds_isalnum(int nASCIIValue);
int                    sds_isalpha(int nASCIIValue);
int                    sds_iscntrl(int nASCIIValue);
int                    sds_isdigit(int nASCIIValue);
int                    sds_isgraph(int nASCIIValue);
int                    sds_islower(int nASCIIValue);
int                    sds_isprint(int nASCIIValue);
int                    sds_ispunct(int nASCIIValue);
int                    sds_isspace(int nASCIIValue);
int                    sds_isupper(int nASCIIValue);
int                    sds_isxdigit(int nASCIIValue);

int                    sds_layoutgetcur(sds_name nmLayout);
int                    sds_layoutmake(const wchar_t* szName, const sds_name nmSrcLayout);
int                    sds_layoutsearch(const wchar_t* szName, sds_name nmLayout);
int                    sds_layoutsetcur(const sds_name nmLayout);

void *                 sds_malloc(size_t sizeBytes);
int                    sds_menucmd(const wchar_t *szPartToDisplay);
int                    sds_menugroup(const wchar_t *pMenuGroupName);
int                    sds_msize(void *pvBuffer);

int                    sds_namedobjdict(sds_name nmDict);
int                    sds_nentsel(const wchar_t *szNEntMsg, sds_name nmEntity, sds_point ptEntPoint, sds_point ptECStoWCS[4], struct sds_resbuf **pprbNestBlkList);
int                    sds_nentselp(const wchar_t *szNEntMsg, sds_name nmEntity, sds_point ptEntPoint, int swUserPick, sds_matrix mxECStoWCS, struct sds_resbuf **pprbNestBlkList);
int                    sds_nentselpex(const wchar_t *szNEntMsg, sds_name nmEntity, sds_point ptEntPoint, int swUserPick, sds_matrix mxECStoWCS, struct sds_resbuf **pprbNestBlkList, unsigned int uTransSpaceFlag, sds_longptr* gsmarker);
struct sds_resbuf *    sds_newrb(int nTypeOrDXF);

int                    sds_osnap(const sds_point ptAperCtr, const wchar_t *szSnapModes, sds_point ptPoint);

void                   sds_polar(const sds_point ptPolarCtr, double dAngle, double dDistance, sds_point ptPoint);
int                    sds_popdbmod();
int                    sds_printf(const wchar_t *formatString, ...);
int                    sds_progresspercent(int iPercentDone);
int                    sds_progressstart(const wchar_t *displayMsg = NULL);
int                    sds_progressstop(void);
int                    sds_prompt(const wchar_t *promptMsg);
int                    sds_pushdbmod();
int                    sds_putsym(const wchar_t *szSymbol, struct sds_resbuf *prbSymbolInfo);

void *                 sds_realloc(void *pOldMemLoc, size_t sizeBytes);
int                    sds_redraw(const sds_name nmEntity, int nHowToDraw);
int                    sds_regapp(const wchar_t *szApplication);
int                    sds_regappx(const wchar_t *szApplication, int swSaveAsR12);
int                    sds_regen();
int                    sds_regfunc(int (*nFuncName)(void), int nFuncCode);
int                    sds_relrb(struct sds_resbuf *prbReleaseThis);
int                    sds_retint(int nReturnInt);
int                    sds_retlist(const struct sds_resbuf *prbReturnList);
int                    sds_retname(const sds_name nmReturnName, int nReturnType);
int                    sds_retnil(void);
int                    sds_retpoint(const sds_point ptReturn3D);
int                    sds_retreal(double dReturnReal);
int                    sds_retstr(const wchar_t *szReturnString);
int                    sds_rett(void);
int                    sds_retval(const struct sds_resbuf *prbReturnValue);
int                    sds_retvoid(void);
int                    sds_rp2pix(double dNumberX,double dNumberY,int *pPixelX,int *pPixelY);
int                    sds_rtos(double dNumber, int nUnitType, int nPrecision, wchar_t *szNumber);
int                    sds_rtosb(double dNumber, int nUnitType, int nPrecision, wchar_t *szNumber, int bufsize);

int                    sds_sendmessage(const wchar_t *szCommandMsg);
int                    sds_sendmessageex(const wchar_t *szCommandMsg, bool echo);
int                    sds_setcallbackfunc(int (* /*cbfnptr*/)(int flag,void *arg1,void *arg2,void *arg3));
int                    sds_setdbmod(int iBitMask);
int                    sds_setfunhelp(wchar_t *szFunctionName, wchar_t *szHelpFile, wchar_t *szContextID, int nMapNumber);
int                    sds_setvar(const wchar_t *szSysVar, const struct sds_resbuf *prbVarInfo);
int                    sds_setview(const struct sds_resbuf *prbViews, int nWhichVPort);
int                    sds_snvalid(const wchar_t *szTableName, int swAllowPipe);
int                    sds_ssadd(const sds_name nmEntToAdd, const sds_name nmSelSet, sds_name nmNewSet);
int                    sds_ssdel(const sds_name nmEntToDel, const sds_name nmSelSet);
int                    sds_ssfree(sds_name nmSetToFree);
int                    sds_ssget(const wchar_t *szSelMethod, const void *pFirstPoint, const void *pSecondPoint, const struct sds_resbuf *prbFilter, sds_name nmNewSet);
int                    sds_ssgetfirst(struct sds_resbuf **unused, struct sds_resbuf **pprbPickfirst);
int                    sds_ssgetkwordcallbackptr(struct sds_resbuf* (**fp)(const wchar_t*));
int                    sds_ssgetothercallbackptr(struct sds_resbuf* (**fp)(const wchar_t*));
int                    sds_sslength(const sds_name nmSelSet, long *plNumberOfEnts);
int                    sds_ssmemb(const sds_name nmEntity, const sds_name nmSelSet);
int                    sds_ssname(const sds_name nmSelSet, long lSetIndex, sds_name nmEntity);
int                    sds_ssnamex(struct sds_resbuf **pprbEntName, const sds_name nmSelSet, const long iIndex);
int                    sds_ssnamexex(struct sds_resbuf **pprbEntName, const sds_name nmSelSet, const long iIndex, unsigned int flags=0);
int                    sds_sssetfirst(const sds_name pickfirstset, const sds_name unused);
int                    sds_sssetkwordcallbackptr(struct sds_resbuf* (*fp)(const wchar_t*));
int                    sds_sssetothercallbackptr(struct sds_resbuf* (*fp)(const wchar_t*));
int                    sds_swapscreen(void);

int                    sds_tablet (const struct sds_resbuf *pArgs, struct sds_resbuf **ppResult);
struct sds_resbuf *    sds_tblnext(const wchar_t *szTable, int swFirst);
int                    sds_tblobjname(const wchar_t *szTable, const wchar_t *szEntInTable, sds_name nmEntName);
struct sds_resbuf *    sds_tblsearch(const wchar_t *szTable, const wchar_t *szFindThis, int swNextItem);
int                    sds_textbox(const struct sds_resbuf *prbTextEnt, sds_point ptCorner, sds_point ptOpposite);
int                    sds_textpage(void);
int                    sds_textscr(void);
int                    sds_tolower(int nASCIIValue);
int                    sds_toupper(int nASCIIValue);
int                    sds_trans(const sds_point ptVectOrPtFrom, const struct sds_resbuf *prbCoordFrom, const struct sds_resbuf *prbCoordTo, int swVectOrDisp, sds_point ptVectOrPtTo);

int                    sds_ucs2rp(sds_point ptSour3D,sds_point ptDest3D);
int                    sds_undef(const wchar_t *szFuncName, int nFuncCode);
int                    sds_update(int nWhichVPort,const sds_point ptCorner1,const sds_point ptCorner2);
int                    sds_usrbrk(void);

int                    sds_vbaload(const wchar_t *szDvbFile);
int                    sds_vbarun(const wchar_t *szMacro);
int                    sds_vports(struct sds_resbuf **prbViewSpecs);

int                    sds_wcmatch(const wchar_t *szCompareThis, const wchar_t *szToThis);
int                    sds_wcmatchex(const wchar_t *szCompareThis, const wchar_t *szToThis, BOOL bIgnoreCase);

int                    sds_xdroom(const sds_name nmEntity, long *plMemAvail);
int                    sds_xdsize(const struct sds_resbuf *prbEntData, long *plMemUsed);
int                    sds_xformss(const sds_name nmSetName, sds_matrix mxTransform);
int                    sds_xstrcase(wchar_t *szString);
wchar_t *              sds_xstrsave(wchar_t *szSource, wchar_t **pszDest);


/*-------------------------------------------------------------------------*//**
Display the Color Dialog

@param	defcol	<=	initial color
@param	retcol	=>	result color
@param	mode	<=	The mode of dialog

Possible colors:
Plain Color - format 0xc30000nn
True  Color - format 0xc2rrggbb

*//*--------------------------------------------------------------------------*/
int sds_getcolordialog(int defcol, int *retcol, int mode);

/*-------------------------------------------------------------------------*//**
Returns information about license.

@param  szUserName   <= buffer size must be >= 64 bytes
@param  szLicenseKey <= buffer size must be >= 25 bytes
@param  pLicenseID   <= license ID

@returns RTNORM for success, RTERROR for error
*//*------------------------------------------------------------------------*/
int sds_getlicenseinfo(wchar_t* szUserName, char* szLicenseKey, long* pLicenseID);


// DCL-related functions:
int dlg_action_tile(sds_hdlg hDialog,LPTSTR szControlKey,void *pfnControlFunc);
int dlg_add_list(LPTSTR szAddToList);
int dlg_client_data_tile(sds_hdlg hDialog, LPTSTR szControlKey, void *pApplicationData);
int dlg_dimensions_tile(sds_hdlg hDialog, LPTSTR szControlKey, short *nWidthLess1, short *nHeightLess1);
int dlg_done_dialog(sds_hdlg hDialog,long nMessage);
int dlg_done_positioned_dialog(sds_hdlg hDialog, int nMessage, int *nXPos, int *nYPos);
int dlg_end_image(void);
int dlg_end_list(void);
int dlg_fill_image(int nULCornerX, int nULCornerY, int nWidthLess1, int nHeightLess1, int nColor);
int dlg_get_attr(sds_hdlg hDialog, LPTSTR szControlKey, LPTSTR szAttribName, LPTSTR szAttribInfo, int lInfoMaxLength);
int dlg_get_attr_string(sds_htile hControl, LPTSTR szAttribName, LPTSTR szAttribInfo, long lInfoMaxLength);
int dlg_get_list_string(sds_hdlg hDialog, LPTSTR szControlKey, LPTSTR szListString, int nStringLength, int nWhichItem);
int dlg_get_tile(sds_hdlg hDialog,LPTSTR szControlKey,LPTSTR szControlInfo,long lInfoMaxLength);
int dlg_init_dialog(LPCTSTR pathOfBaseDCL = _T("base.dcl"), BOOL generateErrorLog = false,
                    LPCTSTR pathForErrorLog= _T(""), void* pCallbackFunction=0);
int dlg_load_dialog(LPTSTR szFileToLoad,int *nDialogFileID);
int dlg_mode_tile(sds_hdlg hDialog, LPTSTR szControlKey, int nTileState);
int dlg_new_dialog(LPTSTR szDialogName,int nDialogFileID,void *pfnDef_Callback,sds_hdlg *hDialog);
int dlg_new_positioned_dialog(LPTSTR szDialogName, int nDialogFileID, void *pfnDef_Callback, int nXPos, int nYPos, sds_hdlg *hDialog);
int dlg_set_audit_level(int auditLevel);
int dlg_set_default_callback(void* pCallbackFunction );
int dlg_set_tile(sds_hdlg hDialog, LPTSTR szControlKey, LPTSTR szControlInfo);
int dlg_set_window_text(sds_hdlg hDialog, const wchar_t *szText);
int dlg_slide_image(int nULCornerX, int nULCornerY, int nWidthLess1, int nHeightLess1, LPTSTR szSnapshotName);
int dlg_start_dialog(sds_hdlg hDialog, int *nMessage);
int dlg_start_image(sds_hdlg hDialog, LPTSTR szControlKey);
int dlg_start_list(sds_hdlg hDialog,LPTSTR szControlKey, int nChangeAddNew,int nWhichItem);
int dlg_term_dialog(void);
int dlg_unload_dialog(int nDialogFileID);
int dlg_vector_image(int nXVectStart, int nYVectStart, int nXVectEnd, int nYVectEnd, int nColor);


#if defined(__cplusplus)
    }
#endif

NS_SDS_END

#endif   // _SDS_PROTOS_H_
