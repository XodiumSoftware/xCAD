// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "Misc/MiscGlobal.h"
#include "Misc/AcColorSettings.h"
#ifdef _WIN32
#include "Misc/AcChildFrmSettings.h"
#endif // _WIN32


class AcApStatusBar;
AcApStatusBar* acedGetApplicationStatusBar();

BOOL acedDrawingStatusBarsVisible();
BOOL acedShowDrawingStatusBars(BOOL = TRUE);

BOOL acedIsInputPending();

int acedGetWinNum(int,int);
int acedSetStatusBarProgressMeter(const ACHAR*,int,int);
int acedSetStatusBarProgressMeterPos(int);
void acedRestoreStatusBar();
HINSTANCE acedGetAcadResourceInstance();

BOOL acedGetCurrentColors(AcColorSettings*);
BOOL acedSetCurrentColors(AcColorSettings*);
BOOL acedGetSystemColors(AcColorSettings*);

BOOL acedRegisterExtendedTab(LPCTSTR,LPCTSTR);


typedef double acedDwgPoint[3];

BOOL acedCoordFromPixelToWorld(int,CPoint,acedDwgPoint);
BOOL acedCoordFromWorldToPixel(int,const acedDwgPoint,CPoint&);
void acedCoordFromPixelToWorld(const CPoint&,acedDwgPoint);


#ifdef _WIN32

class CDialogBar;

typedef BOOL (*AcedFilterWinMsgFn)(MSG*);
typedef void (*AcedOnIdleMsgFn)();
typedef void (*AcedWatchWinMsgFn)(const MSG*);
typedef void (*AcedOnModalFn)(bool);

const CString& acedGetRegistryCompany();

BOOL acedGetChildFrameSettings(AcChildFrmSettings*,CMDIChildWnd*);
BOOL acedGetIUnknownForCurrentCommand(LPUNKNOWN&);
BOOL acedRegisterFilterWinMsg(const AcedFilterWinMsgFn);
BOOL acedRegisterOnIdleWinMsg(const AcedOnIdleMsgFn);
BOOL acedRegisterWatchWinMsg(const AcedWatchWinMsgFn);
BOOL acedRegisterOnModal(const AcedOnModalFn);
BOOL acedRemoveFilterWinMsg(const AcedFilterWinMsgFn);
BOOL acedRemoveOnIdleWinMsg(const AcedOnIdleMsgFn);
BOOL acedRemoveWatchWinMsg(const AcedWatchWinMsgFn);
BOOL acedRemoveOnModal(const AcedOnModalFn);
BOOL acedSetChildFrameSettings(AcChildFrmSettings*,CMDIChildWnd*);
BOOL acedSetIUnknownForCurrentCommand(const LPUNKNOWN);
CDocument* acedGetAcadDoc();
CMDIFrameWnd* acedGetAcadFrame();
CView* acedGetAcadDwgView();
CWinApp* acedGetAcadWinApp();
CWnd* acedGetAcadDockCmdLine();
CWnd* acedGetAcadTextCmdLine();
HMENU acedGetMenu(LPCTSTR);

#ifdef _ARX_CUSTOM_DRAG_N_DROP_
BOOL acedAddDropTarget(COleDropTarget*);
BOOL acedEndOverrideDropTarget(COleDropTarget*);
BOOL acedRegisterCustomDropTarget(IDropTarget*);
BOOL acedRemoveDropTarget(COleDropTarget*);
BOOL acedRevokeCustomDropTarget();
BOOL acedStartOverrideDropTarget(COleDropTarget*);
#endif // _ARX_CUSTOM_DRAG_N_DROP_

#endif // _WIN32
