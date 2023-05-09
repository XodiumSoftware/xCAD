// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#if defined(_AFXEXT) && defined(__cplusplus)
  #if defined(_DEBUG) && !defined(BRX_BCAD_DEBUG)
    #undef _DEBUG
    #include <afxole.h>
    #define _DEBUG
  #else
    #include <afxole.h>
  #endif
#endif

#include "MFC/CAdUi/CAdUiGlobal.h"

#define UM_ADUI_DRAGENTER 1144
#define UM_ADUI_DRAGOVER 1145
#define UM_ADUI_DRAGLEAVE 1146
#define UM_ADUI_DROP 1147
#define UM_ADUI_DROPEX 1148
#define UM_ADUI_DRAGSCROLL 1149

struct ADUI_DRAGDATA
{
    COleDataObject* mpDataObject;
    CWnd* mpWnd;
    DROPEFFECT mDropEffect;
    DROPEFFECT mDropList;
    DWORD mdwKeyState;
    POINTL mPoint;
};

typedef struct ADUI_DRAGDATA* PADUI_DRAGDATA;

/** _ */
class BRX_IMPORTEXPORT CAdUiDropTarget: public COleDropTarget
{
public:
    BOOL SetTargetWindowForMessages(CWnd*);
    CAdUiDropTarget();
    CAdUiDropTarget(int);
    ~CAdUiDropTarget();
protected:
    CWnd* mpTargetWnd;
    DWORD mdwKeyState;
    int mnId;
    virtual BOOL OnDrop(CWnd*,COleDataObject*,DROPEFFECT,CPoint);
    virtual DROPEFFECT OnDragEnter(CWnd*,COleDataObject*,DWORD,CPoint);
    virtual DROPEFFECT OnDragOver(CWnd*,COleDataObject*,DWORD,CPoint);
    virtual DROPEFFECT OnDragScroll(CWnd*,DWORD,CPoint);
    virtual DROPEFFECT OnDropEx(CWnd*,COleDataObject*,DROPEFFECT,DROPEFFECT,CPoint);
    virtual void OnDragLeave(CWnd*);
};
