// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmGlobal.h"
#include "AcDb/AcDbGlobal.h"
#include "Ads/AdsGlobal.h"

#ifdef __cplusplus
  #include "AcDb/AcDbFullSubentPath.h" //for AcDbFullSubentPathArray
#endif

#ifdef _WIN32
  #include <wtypes.h> //HINSTANCE
#else
  #include <wchar.h>
  #include <wctype.h>
#endif

//common forward declarations
#ifdef __cplusplus
class AcApDocument;
class AcDbXrefGraph;
class AcEdCommand;
class AcEdInputContextReactor;
class AcEdInputPointFilter;
class AcEdInputPointMonitor;
class AcEdSubSelectFilter;
class AcEdUIContext;
class AcGeMatrix3d;
class AcGePoint2d;
class AcGePoint3d;
class AcGeScale3d;
struct AcEdCommandStruc;
#endif //__cplusplus
struct IDispatch;

enum AcEdDrawOrderCmdType
{
    kDrawOrderNone = 0,
    kDrawOrderBottom,
    kDrawOrderTop,
    kDrawOrderBelow,
    kDrawOrderAbove
};

#ifdef __cplusplus

namespace AcEdSSGet
{
    enum AcEdSSGetFlags
    {
        kNormal = 0,
        kPickPoints = 1,
        kDuplicates = 2,
        kNestedEntities = 4,
        kSubEntities = 8,
        kSinglePick = 16,
        kPickfirstSet = 32,
        kPreviousSet = 64,
        kSubSelection = 128
    };

    enum AcEdSSGetModes
    {
        kWin = 1,
        kCross,
        kBox,
        kLast,
        kEntity,
        kAll,
        kFence,
        kCPoly,
        kWPoly,
        kPick,
        kEvery,
        kXten,
        kGroup,
        kPrevious
    };
};

#endif //__cplusplus

#define AcadGetIDispatch acedGetIDispatch

#ifdef __cplusplus
extern "C"
{
    Adesk::Boolean acedClearOLELock(int);
    Adesk::Boolean acedSetOLELock(int,int = 0);
    int acedCmdLookup(const ACHAR*,int,AcEdCommandStruc*,int = FALSE);
    int acedCmdLookup2(const ACHAR*,int,AcEdCommandStruc*,int = ACRX_CMD_DEFUN);

    bool acedPendingFiberlessDocSwitch(AcApDocument** = NULL);
    bool acedCmdCWasCancelled();
    bool acedPendingCmdCTokens();
    bool acedResumingInvocation();
    bool acedFiberWorld();
#endif //__cplusplus

    ACHAR* acedGetAppName();
    IDispatch* acedGetIDispatch(BOOL);
    int acedAlert(const ACHAR*);
    int acedAlert2(const ACHAR*, const ACHAR*); // BRX specific : title + message
    int acedArxLoad(const ACHAR*);
    int acedArxUnload(const ACHAR*);
    int acedCmdUndefine(const ACHAR*,int);

    int acedCmd(const struct resbuf*);
    int acedCommand(int, ...);
    #define  acedCmdS(rb)  acedCmd(rb)     /* for ARX2015 compatibility */
    #define  acedCommandS  acedCommand     /* for ARX2015 compatibility */

    typedef int (*AcEdCoroutineCallback)(void*);
    int acedCommandC(AcEdCoroutineCallback, void*, int, ...);
    int acedCmdC(AcEdCoroutineCallback, void*, const struct resbuf*);
    void acedCallBackOnCancel();

    int acedDefun(const ACHAR*,short);
    int acedDragGen(const ads_name,const ACHAR*,int,int (*fp)(ads_point,ads_matrix),ads_point);
    int acedEntSel(const ACHAR*,ads_name,ads_point);
    int acedFindFile(const ACHAR*,ACHAR*,size_t);
    int acedFindTrustedFile(const ACHAR*,ACHAR*,size_t);
    int acedFNSplit(const ACHAR*,ACHAR*,size_t,ACHAR*,size_t,ACHAR*,size_t);
    int acedGetAngle(const ads_point,const ACHAR*,ads_real*);
    int acedGetCfg(const ACHAR*,ACHAR*,int);
    int acedGetCName(const ACHAR*,ACHAR**);
    int acedGetCorner(const ads_point,const ACHAR*,ads_point);
    int acedGetDist(const ads_point,const ACHAR*,ads_real*);
    int acedGetEnv(const ACHAR*,ACHAR*,size_t);
    int acedGetFileD(const ACHAR*,const ACHAR*,const ACHAR*,int,struct resbuf*);
    int acedGetFileNavDialog(const ACHAR*,const ACHAR*,const ACHAR*,const ACHAR*,int,struct resbuf**);
    int acedGetFunCode();
    int acedGetInput(ACHAR*,size_t);
    int acedGetInt(const ACHAR*,int*);
    int acedGetIntInRange(const ACHAR*,int*,int,int);
    int acedGetKword(const ACHAR*,ACHAR*,size_t);
    int acedGetOrient(const ads_point,const ACHAR*,ads_real*);
    int acedGetPoint(const ads_point,const ACHAR*,ads_point);
    int acedGetReal(const ACHAR*,ads_real*);
    int acedGetString(int,const ACHAR*,ACHAR*,size_t);
    int acedGetSym(const ACHAR*,struct resbuf**);
    int acedGetVar(const ACHAR*,struct resbuf*);
    int acedGraphScr();
    int acedGrDraw(const ads_point,const ads_point,int,int);
    int acedGrRead(int,int*,struct resbuf*);
    int acedGrText(int,const ACHAR*,int);
    int acedGrVecs(const struct resbuf*,ads_matrix);
    int acedGrClear();
    int acedHelp(const ACHAR*,const ACHAR*,int);
    int acedInitGet(int,const ACHAR*);
    int acedInvoke(const struct resbuf*,struct resbuf**);
    int acedMenuCmd(const ACHAR*);
    int acedNEntSel(const ACHAR*,ads_name,ads_point,ads_point[4],struct resbuf**);
    int acedNEntSelP(const ACHAR*,ads_name,ads_point,int,ads_matrix,struct resbuf**);
    int acedOsnap(const ads_point,const ACHAR*,ads_point);
    int acedPopCommandDirectory(const ACHAR*);
    int acedPrompt(const ACHAR*);
    int acedPutSym(const ACHAR*,struct resbuf*);
    int acedRedraw(const ads_name,int);
    int acedRegFunc(int (*fp)(),int);
    int acedRetInt(int);
    int acedRetList(const struct resbuf*);
    int acedRetName(const ads_name,int);
    int acedRetNil();
    int acedRetPoint(const ads_point);
    int acedRetReal(ads_real);
    int acedRetStr(const ACHAR*);
    int acedRetT();
    int acedRetVal(const struct resbuf*);
    int acedRetVoid();
    int acedSetCfg(const ACHAR*,const ACHAR*);
    int acedSetEnv(const ACHAR*,const ACHAR*);
    int acedSetFunHelp(const ACHAR*,const ACHAR*,const ACHAR*,int);
    int acedSetVar(const ACHAR*,const struct resbuf*);
    int acedSetView(const struct resbuf*,int);
    int acedSSAdd(const ads_name,const ads_name,ads_name);
    int acedSSDel(const ads_name,const ads_name);
    int acedSSFree(const ads_name);
    int acedSSGet(const ACHAR*,const void*,const void*,const struct resbuf*,ads_name);
    int acedSSGetFirst(struct resbuf**,struct resbuf**);
    int acedSSGetKwordCallbackPtr(struct resbuf* (**fp)(const ACHAR*));
    int acedSSGetOtherCallbackPtr(struct resbuf* (**fp)(const ACHAR*));
#ifdef __cplusplus
    int acedSSLength(const ads_name, Adesk::Int32*);
#else
    int acedSSLength(const ads_name, long*);
#endif
    int acedSSName(const ads_name,int,ads_name);
    int acedSSNameX(struct resbuf**,const ads_name,int);
    int acedSSMemb(const ads_name,const ads_name);
    int acedSSSetFirst(const ads_name,const ads_name);
    int acedSSSetKwordCallbackPtr(struct resbuf* (*fp)(const ACHAR*));
    int acedSSSetOtherCallbackPtr(struct resbuf* (*fp)(const ACHAR*));
    int acedTablet(const struct resbuf*,struct resbuf**);
    int acedTextBox(const struct resbuf*,ads_point,ads_point);
    int acedTextPage();
    int acedTextScr();
    int acedTrans(const ads_point,const struct resbuf*,const struct resbuf*,int,ads_point);
    int acedUndef(const ACHAR*,short);
    int acedUpdate(int,ads_point,ads_point);
    int acedUsrBrk();
    int acedVports(struct resbuf**);
    int acedXformSS(const ads_name,ads_matrix);
    struct resbuf* acedArxLoaded();
    struct resbuf* acedGetArgs();
    void acedPostCommandPrompt();
#ifdef __cplusplus
} //extern "C"

int acedGetInput(AcString&);
int acedGetKword(const ACHAR*, AcString&);
int acedGetString(int, const ACHAR*, AcString&);
#endif //__cplusplus

#ifdef __cplusplus
Acad::ErrorStatus acedConvertEntityToHatch(AcDbHatch*,AcDbEntity*&,bool);
Acad::ErrorStatus acedCreateEnhancedViewportOnDrop(const ACHAR*,const ACHAR*,const AcGePoint2d,double,AcDbObjectId,AcDbObjectId&,AcDbObjectId&);
Acad::ErrorStatus acedCreateEnhancedViewportOnDropDWG(const ACHAR*,AcDbExtents*,const AcGePoint2d,double,AcDbObjectId,AcDbObjectId&,AcDbObjectId&);
Acad::ErrorStatus acedCreateViewportByView(AcDbDatabase*,const AcDbObjectId&,const AcGePoint2d&,double,AcDbObjectId&);
Acad::ErrorStatus acedDrawOrderInherit(AcDbObjectId,AcDbObjectIdArray&,AcEdDrawOrderCmdType);
Acad::ErrorStatus acedGetCommandForDocument(const AcApDocument*, AcString&, bool = false);
Acad::ErrorStatus acedGetCommandForDocument(AcApDocument*, ACHAR*&); //deprecated
Acad::ErrorStatus acedGetCurDwgXrefGraph(AcDbXrefGraph&,Adesk::Boolean = Adesk::kFalse);
Acad::ErrorStatus acedGetCurrentSelectionSet(AcDbObjectIdArray&);
Acad::ErrorStatus acedGetCurrentUCS(AcGeMatrix3d&);
Acad::ErrorStatus acedGetFullSubentPathsForCurrentSelection(const AcDbObjectId&,AcDbFullSubentPathArray&);
Acad::ErrorStatus acedMspace();
Acad::ErrorStatus acedPspace();
Acad::ErrorStatus acedRestoreCurrentView(const AcDbObjectId&);
Acad::ErrorStatus acedRestorePreviousUCS();
Acad::ErrorStatus acedSetCurrentUCS(const AcGeMatrix3d&);
Acad::ErrorStatus acedSetCurrentView(AcDbViewTableRecord*,AcDbViewport*);
Acad::ErrorStatus acedSetCurrentVPort(const AcDbViewport*);
Acad::ErrorStatus acedSetCurrentVPort(int);
Acad::ErrorStatus acedSyncFileOpen(const ACHAR*,const ACHAR* = NULL);
Acad::ErrorStatus acedVPLayer(const AcDbObjectId&,const AcDbObjectIdArray&,AcDb::VpFreezeOps);
Acad::ErrorStatus acedVports2VportTableRecords();
Acad::ErrorStatus acedVportTableRecords2Vports();
Acad::ErrorStatus acedXrefAttach(const ACHAR*,const ACHAR*,AcDbObjectId* = NULL,AcDbObjectId* = NULL,const AcGePoint3d* = NULL,const AcGeScale3d* = NULL,const double* = NULL,const bool = true,AcDbDatabase* = NULL,const ACHAR* = NULL);
Acad::ErrorStatus acedXrefBind(const ACHAR*,const bool = false,const bool = true,AcDbDatabase* = NULL);
Acad::ErrorStatus acedXrefCreateBlockname(const ACHAR*,ACHAR*&);
Acad::ErrorStatus acedXrefDetach(const ACHAR*,const bool = true,AcDbDatabase* = NULL);
Acad::ErrorStatus acedXrefOverlay(const ACHAR*,const ACHAR*,AcDbObjectId* = NULL,AcDbObjectId* = NULL,const AcGePoint3d* = NULL,const AcGeScale3d* = NULL,const double* = NULL,const bool = true,AcDbDatabase* = NULL,const ACHAR* = NULL);
Acad::ErrorStatus acedXrefReload(const AcDbObjectIdArray&,bool = true,AcDbDatabase* = NULL);
Acad::ErrorStatus acedXrefReload(const ACHAR*,const bool = true,AcDbDatabase* = NULL);
Acad::ErrorStatus acedXrefResolve(AcDbDatabase*,const bool = true);
Acad::ErrorStatus acedXrefUnload(const ACHAR*,const bool = true,AcDbDatabase* = NULL);
Acad::ErrorStatus acedXrefXBind(const AcDbObjectIdArray,const bool = true,AcDbDatabase* = NULL);
AcDbObjectId acedActiveViewportId();
AcDbObjectId acedGetCurViewportObjectId();
AcDbObjectId acedViewportIdFromNumber(int);
Adesk::Boolean acedAddDefaultContextMenu(AcEdUIContext*,const void*,const ACHAR* = NULL);
Adesk::Boolean acedAddObjectContextMenu(const AcRxClass*,AcEdUIContext*,const void*);
Adesk::Boolean acedCreateInternetShortcut(const ACHAR*,const ACHAR*);
Adesk::Boolean acedCreateShortcut(void*,const ACHAR*,const ACHAR*,const ACHAR*);
Adesk::Boolean acedGetUserFavoritesDir(ACHAR*);
Adesk::Boolean acedInitDialog(Adesk::Boolean = Adesk::kTrue);
Adesk::Boolean acedIsMenuGroupLoaded(const ACHAR*);
bool acedLoadPartialMenu(const TCHAR*);
bool acedUnloadPartialMenu(const TCHAR*);
void acedReloadMenus(bool);
Adesk::Boolean acedRemoveDefaultContextMenu(AcEdUIContext*);
Adesk::Boolean acedRemoveObjectContextMenu(const AcRxClass*,AcEdUIContext*);
Adesk::Boolean acedResolveInternetShortcut(const ACHAR*,ACHAR*);
Adesk::Boolean acedResolveShortcut(void*,const ACHAR*,ACHAR*);
Adesk::Boolean acedSetColorDialog(int&,Adesk::Boolean,int);
Adesk::Boolean acedSetColorDialogTrueColor(AcCmColor&,Adesk::Boolean,const AcCmColor&,AcCm::DialogTabs = (AcCm::DialogTabs) (AcCm::kACITab|AcCm::kTrueColorTab|AcCm::kColorBookTab));
Adesk::Boolean acedSetColorPrompt(ACHAR*,AcCmColor&,Adesk::Boolean);
bool acdbCanonicalToSystemRange(int,const AcString&,AcString&);
bool acdbSystemRangeToCanonical(int,const AcString&,AcString&);
bool acedIsUpdateDisplayPaused();
bool acedSetCMBaseAlias(LPCTSTR,AcadContextMenuMode);
Acad::ErrorStatus acedGetUnitsValueString(AcDb::UnitsValue, AcString&);
const AcString* acedGetUnitsValueString(AcDb::UnitsValue);
bool acedGetUnitsConversion(AcDb::UnitsValue, double&);
int acedEditMTextInteractive(AcDbMText*,bool = false,bool = false);
int acedGetFullInput(ACHAR*&); //deprecated
int acedGetFullKword(const ACHAR*,ACHAR*&); //deprecated
int acedGetFullString(int,const ACHAR*,ACHAR*&); //deprecated

int acedSSNameXEx(struct resbuf**,const ads_name,int,unsigned int = 0);
int acedSSSubentLength(const ads_name, Adesk::Int32, Adesk::Int32*);
int acedSSSubentName(const ads_name,Adesk::Int32,Adesk::Int32,AcDbFullSubentPath&);
int acedSSSubentNameX(struct resbuf**, const ads_name, const Adesk::Int32, const Adesk::Int32, unsigned int);
int acedSSSetSubentTypes(const AcArray<AcDb::SubentType>&);
int acedSSSubentAdd(const AcDbFullSubentPath&,const ads_name,ads_name);
int acedSSSubentDel(const AcDbFullSubentPath&,const ads_name);
int acedSSSubentMemb(const AcDbFullSubentPath&,const ads_name);
void acedDisableDefaultARXExceptionHandler(Adesk::Boolean = Adesk::kTrue);
void acedEditToleranceInteractive(AcDbFcf*);

// special struct for acedTraceBoundary() that can convert old-style bool argument to
// new-style enum argument without requiring source code changes
struct IslandDetection
{
    enum MaxDepth : unsigned int
    {
        eNested = 0,
        eIgnore = 1,
        eOuter = 2,
    } maxDepth;
    IslandDetection(bool detectIslands) : maxDepth(detectIslands ? eNested : eIgnore) {}
    IslandDetection(Adesk::Boolean detectIslands) : maxDepth(detectIslands ? eNested : eIgnore) {}
    IslandDetection(MaxDepth maxDepth) : maxDepth(maxDepth) {}
    IslandDetection(unsigned int maxDepth) : maxDepth((MaxDepth)maxDepth) {}
    operator unsigned int() const { return maxDepth; }
};
Acad::ErrorStatus acedTraceBoundary(const AcGePoint3d&, IslandDetection detectIslands, AcDbVoidPtrArray&);

void acedUpdateDisplayPause(bool);
#define acedEditor AcEditor::cast(acrxSysRegistry()->at(ACED_EDITOR_OBJ))
#define acedRegCmds AcEdCommandStack::cast(acrxSysRegistry()->at(ACRX_COMMAND_DOCK))
#define acedServices AcEdServices::cast(acrxServiceDictionary->at(ACED_SERVICES))
#define ACED_SERVICES ACRX_T("AcEdServices")
#define ACED_EDITOR_OBJ ACRX_T("AcEditor")

// Templatized helpers to deduce buffer size arguments
template<size_t cch> inline int acedGetEnv(const ACHAR* name, ACHAR(&sbuf)[cch]) { return acedGetEnv(name, sbuf, cch); }
template<size_t cch> inline int acedGetInput(ACHAR(&sbuf)[cch]) { return acedGetInput(sbuf, cch); }
template<size_t cch> inline int acedGetString(int mode, const ACHAR* prompt, ACHAR(&sbuf)[cch])
    { return acedGetString(mode, prompt, sbuf, cch); }
template<size_t cch> inline int acedFindFile(const ACHAR* name, ACHAR(&sbuf)[cch]) { return acedFindFile(name, sbuf, cch); }
template<size_t cch> inline int acedFindTrustedFile(const ACHAR* name, ACHAR(&sbuf)[cch]) { return acedFindTrustedFile(name, sbuf, cch); }
template<size_t cch> inline int acedGetKword(const ACHAR* prompt, ACHAR(&sbuf)[cch]) { return acedGetKword(prompt, sbuf, cch); }

template<size_t cchP, size_t cchN, size_t cchE>
inline int acedFNSplit(const ACHAR* path, ACHAR(&sbufP)[cchP], ACHAR(&sbufN)[cchN], ACHAR(&sbufE)[cchE])
    { return acedFNSplit(path, sbufP, cchP, sbufN, cchN, sbufE, cchE); }

#endif //__cplusplus

int acedIsDragging();
int acedNumberOfViewports();

LPCTSTR acedGetCMBaseAlias(enum AcadContextMenuMode);
unsigned long acedGetRGB(int);
void acedSendModelessOperationEnded(const ACHAR*);
void acedSendModelessOperationStart(const ACHAR*);
void acedUpdateDisplay();
