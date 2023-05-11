// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcGe/AcGePoint3d.h"

const int nBlockFileSize = 260;

#define szClipSignature  _T("R15")

/** _ */
struct ClipboardInfo
{
    AcGePoint3d dptInsert;
    ACHAR chData[1];
    ACHAR szSignature[4];
    ACHAR szSourceFile[nBlockFileSize];
    ACHAR szTempFile[nBlockFileSize];
    DWORD m_dwThreadId;
    int nFlags;
    int nLen;
    int nType;
    RECT rectGDI;
    void* mpView;
};

const ACHAR* acedClipFormatName();
